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
/////////////////////////////////////////////////////////////
// OutputFile.hh
//
// OutputFile class - handles the output to MDV files
//
// Mike Dixon, RAP, NCAR, P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// Sept 2003
//
///////////////////////////////////////////////////////////////

#ifndef OutputFile_HH
#define OutputFile_HH

#include "Params.hh"
#include <string>
#include <Mdv/DsMdvx.hh>
using namespace std;

class OutputFile {
  
public:
  
  // constructor
  
  OutputFile(const string &prog_name, const Params &params);
  
  // destructor
  
  virtual ~OutputFile();
  
  // write
  
  int write(time_t start_time,
	    time_t end_time,
	    time_t centroid_time,
	    const Mdvx::master_header_t &mhdrIn,
	    const Mdvx::field_header_t &fhdrIn,
	    const Mdvx::vlevel_header_t &vhdrIn,
	    const fl32 *frac,
	    const fl32 *mean,
	    const fl32 *sdev,
	    const fl32 *corr);

protected:
private:
  
  const string &_progName;
  const Params &_params;
  
  int _nFields;
  int _fracFieldNum;
  int _meanFieldNum;
  int _sdevFieldNum;
  int _corrFieldNum;

};

#endif
