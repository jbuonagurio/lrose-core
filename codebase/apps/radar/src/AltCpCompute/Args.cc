// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
// ** Copyright UCAR (c) 1990 - 2016                                         
// ** University Corporation for Atmospheric Research (UCAR)                 
// ** National Center for Atmospheric Research (NCAR)                        
// ** Boulder, Colorado, USA                                                 
// ** BSD licence applies - redistribution and use in source and binary      
// ** forms, with or without modification, are permitted provided that       
// ** the following conditions are met:                                      
// ** 1) If the software is modified to produce derivative works,            
// ** such modified software should be clearly marked, so as not             
// ** to confuse it with the version available from UCAR.                    
// ** 2) Redistributions of source code must retain the above copyright      
// ** notice, this list of conditions and the following disclaimer.          
// ** 3) Redistributions in binary form must reproduce the above copyright   
// ** notice, this list of conditions and the following disclaimer in the    
// ** documentation and/or other materials provided with the distribution.   
// ** 4) Neither the name of UCAR nor the names of its contributors,         
// ** if any, may be used to endorse or promote products derived from        
// ** this software without specific prior written permission.               
// ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  
// ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      
// ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
//////////////////////////////////////////////////////////
// Args.cc
//
// command line args
//
// Mike Dixon, RAP, NCAR, P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// Sept 2006
//
//////////////////////////////////////////////////////////

#include "Args.hh"
#include <cstring>
#include <cstdlib>
#include <toolsa/DateTime.hh>
using namespace std;

// constructor

Args::Args()

{
  TDRP_init_override(&override);
}

// destructor

Args::~Args()

{
  TDRP_free_override(&override);
}

// parse

int Args::parse(int argc, char **argv, string &prog_name)

{

  int iret = 0;
  char tmp_str[4096];

  // loop through args
  
  for (int i =  1; i < argc; i++) {
    
    if (!strcmp(argv[i], "--") ||
	!strcmp(argv[i], "-h") ||
	!strcmp(argv[i], "-help") ||
	!strcmp(argv[i], "-man")) {
      
      usage(prog_name, cout);
      exit (0);
      
    } else if (!strcmp(argv[i], "-d") ||
               !strcmp(argv[i], "-debug")) {
      
      sprintf(tmp_str, "debug = DEBUG_NORM;");
      TDRP_add_override(&override, tmp_str);

    } else if (!strcmp(argv[i], "-v") ||
               !strcmp(argv[i], "-verbose")) {

      sprintf(tmp_str, "debug = DEBUG_VERBOSE;");
      TDRP_add_override(&override, tmp_str);
      
    } else if (!strcmp(argv[i], "-vv") ||
               !strcmp(argv[i], "-extra")) {

      sprintf(tmp_str, "debug = DEBUG_EXTRA;");
      TDRP_add_override(&override, tmp_str);
      
    } else if (!strcmp(argv[i], "-write_pairs")) {

      sprintf(tmp_str, "write_data_pairs = TRUE;");
      TDRP_add_override(&override, tmp_str);
      
    } else if (!strcmp(argv[i], "-instance")) {
      
      if (i < argc - 1) {
	sprintf(tmp_str, "instance = %s;", argv[++i]);
	TDRP_add_override(&override, tmp_str);
        sprintf(tmp_str, "register_with_procmap = true;");
        TDRP_add_override(&override, tmp_str);
      } else {
	iret = -1;
      }
      
    } else if (!strcmp(argv[i], "-nsamples")) {
      
      if (i < argc - 1) {
	sprintf(tmp_str, "n_samples = %s;", argv[++i]);
	TDRP_add_override(&override, tmp_str);
      } else {
	iret = -1;
      }

    } else if (!strcmp(argv[i], "-cf_start")) {
      
      if (i < argc - 1) {
	startTime = DateTime::parseDateTime(argv[++i]);
	if (startTime == DateTime::NEVER) {
	  iret = -1;
	} else {
	  sprintf(tmp_str, "cfradial_mode = CFRADIAL_ARCHIVE;");
	  TDRP_add_override(&override, tmp_str);
          sprintf(tmp_str, "input_mode = CFRADIAL_INPUT;");
          TDRP_add_override(&override, tmp_str);
	}
      } else {
	iret = -1;
      }
	
    } else if (!strcmp(argv[i], "-cf_end")) {
      
      if (i < argc - 1) {
	endTime = DateTime::parseDateTime(argv[++i]);
	if (endTime == DateTime::NEVER) {
	  iret = -1;
	} else {
	  sprintf(tmp_str, "cfradial_mode = CFRADIAL_ARCHIVE;");
	  TDRP_add_override(&override, tmp_str);
          sprintf(tmp_str, "input_mode = CFRADIAL_INPUT;");
          TDRP_add_override(&override, tmp_str);
	}
      } else {
	iret = -1;
      }
	
    } else if (!strcmp(argv[i], "-f")) {
      
      cerr << "ERROR: -f arg deprecated" << endl;
      cerr << "  Use -cf for cfradial files" << endl;
      cerr << "  or -tsf for time series files" << endl;

      iret = -1;

    } else if (!strcmp(argv[i], "-cf")) {
      
      if (i < argc - 1) {
	// load up file list vector. Break at next arg which
	// start with -
	for (int j = i + 1; j < argc; j++) {
	  if (argv[j][0] == '-') {
	    break;
	  } else {
	    inputFileList.push_back(argv[j]);
	  }
	}
      } else {
	iret = -1;
      }

      if (inputFileList.size() < 1) {
        cerr << "ERROR - with -cf you must specify files to be read" << endl;
        iret = -1;
      } else {
        sprintf(tmp_str, "cfradial_mode = CFRADIAL_FILELIST;");
        TDRP_add_override(&override, tmp_str);
        sprintf(tmp_str, "input_mode = CFRADIAL_INPUT;");
        TDRP_add_override(&override, tmp_str);
      }

    } else if (!strcmp(argv[i], "-tsf")) {
      
      if (i < argc - 1) {
	// load up file list vector. Break at next arg which
	// start with -
	for (int j = i + 1; j < argc; j++) {
	  if (argv[j][0] == '-') {
	    break;
	  } else {
	    inputFileList.push_back(argv[j]);
	  }
	}
      } else {
	iret = -1;
      }

      if (inputFileList.size() < 1) {
        cerr << "ERROR - with -tsf you must specify files to be read" << endl;
        iret = -1;
      } else {
        sprintf(tmp_str, "input_mode = TS_FILE_INPUT;");
        TDRP_add_override(&override, tmp_str);
      }

    } // if
    
  } // i

  if (iret) {
    usage(prog_name, cerr);
  }

  return (iret);
    
}

void Args::usage(string &prog_name, ostream &out)
{

  out << "Usage: " << prog_name << " [options as below]\n"
      << "options:\n"
      << "       [ --, -h, -help, -man ] produce this list.\n"
      << "       [ -d, -debug ] print debug messages\n"
      << "       [ -cf_end \"yyyy mm dd hh mm ss\"] start time\n"
      << "         Sets end time for cfradial files, sets mode to ARCHIVE\n"
      << "       [ -cf_start \"yyyy mm dd hh mm ss\"] start time\n"
      << "         Sets start time for cfradial files, sets mode to ARCHIVE\n"
      << "       [ -cf files ] specify input cfradial file list\n"
      << "       [ -tsf files ] specify input tsarchive file list\n"
      << "         Read files instead of TsApi.\n"
      << "       [ -instance ?] instance for procmap\n"
      << "         Forces register with procmap\n"
      << "       [ -nsamples ?] specify number of samples\n"
      << "       [ -v, -verbose ] print verbose debug messages\n"
      << "       [ -vv, -extra ] print extra verbose debug messages\n"
      << "       [ -write_pairs ] write data pairs to stdout\n"
      << endl;
  
}
