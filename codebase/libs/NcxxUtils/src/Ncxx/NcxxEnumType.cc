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
//////////////////////////////////////////////////////////////////////
//  Ncxx C++ classes for NetCDF4
//
//  Copied from code by:
//
//    Lynton Appel, of the Culham Centre for Fusion Energy (CCFE)
//    in Oxfordshire, UK.
//    The netCDF-4 C++ API was developed for use in managing
//    fusion research data from CCFE's innovative MAST
//    (Mega Amp Spherical Tokamak) experiment.
// 
//  Offical NetCDF codebase is at:
//
//    https://github.com/Unidata/netcdf-cxx4
//
//  Modification for LROSE made by:
//
//    Mike Dixon, EOL, NCAR
//    P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
//  The base code makes extensive use of exceptions.
//  Additional methods have been added to return error conditions. 
//
//  December 2016
//
//////////////////////////////////////////////////////////////////////

#include <NcxxUtils/NcxxEnumType.hh>
#include <NcxxUtils/NcxxGroup.hh>
#include <NcxxUtils/NcxxCheck.hh>
#include <NcxxUtils/NcxxByte.hh>
#include <NcxxUtils/NcxxUbyte.hh>
#include <NcxxUtils/NcxxChar.hh>
#include <NcxxUtils/NcxxShort.hh>
#include <NcxxUtils/NcxxUshort.hh>
#include <NcxxUtils/NcxxInt.hh>
#include <NcxxUtils/NcxxUint.hh>
#include <NcxxUtils/NcxxInt64.hh>
#include <NcxxUtils/NcxxUint64.hh>
#include <NcxxUtils/NcxxFloat.hh>
#include <NcxxUtils/NcxxDouble.hh>
#include <NcxxUtils/NcxxString.hh>
#include <NcxxUtils/NcxxException.hh>
using namespace std;
using namespace netCDF;
using namespace netCDF::exceptions;

// Class represents a netCDF variable.

// assignment operator
NcxxEnumType& NcxxEnumType::operator=(const NcxxEnumType& rhs)
{
  NcxxType::operator=(rhs);    // assign base class parts
  return *this;
}

// assignment operator
NcxxEnumType& NcxxEnumType::operator=(const NcxxType& rhs)
{
  if (&rhs != this) {
    // check the rhs is the base of an Enum type
    if(getTypeClass() != NC_ENUM) throw NcxxException("The NcxxType object must be the base of an Enum type.",__FILE__,__LINE__);
    // assign base class parts
    NcxxType::operator=(rhs);
  }
  return *this;
}

// The copy constructor.
NcxxEnumType::NcxxEnumType(const NcxxEnumType& rhs): 
  NcxxType(rhs)
{
}


// Constructor generates a null object.
NcxxEnumType::NcxxEnumType() :
  NcxxType()   // invoke base class constructor
{}
  
// constructor
NcxxEnumType::NcxxEnumType(const NcxxGroup& grp, const string& name):
  NcxxType(grp,name)
{}
  

// constructor
NcxxEnumType::NcxxEnumType(const NcxxType& ncType): 
  NcxxType(ncType)
{
  // check the nctype object is the base of an Enum type
  if(getTypeClass() != NC_ENUM) throw NcxxException("The NcxxType object must be the base of an Enum type.",__FILE__,__LINE__);
}

// Returns the base type.
NcxxType NcxxEnumType::getBaseType() const
{
  char charName[NC_MAX_NAME+1];
  nc_type base_nc_typep;
  size_t *base_sizep=NULL;
  size_t *num_membersp=NULL;
  ncxxCheck(nc_inq_enum(groupId,myId,charName,&base_nc_typep,base_sizep,num_membersp),__FILE__,__LINE__);
  switch (base_nc_typep) {
  case NC_BYTE    : return ncByte;
  case NC_UBYTE   : return ncUbyte;
  case NC_CHAR    : return ncChar;
  case NC_SHORT   : return ncShort;
  case NC_USHORT  : return ncUshort;
  case NC_INT     : return ncInt;
  case NC_UINT    : return ncUint;  
  case NC_INT64   : return ncInt64; 
  case NC_UINT64  : return ncUint64;
  case NC_FLOAT   : return ncFloat;
  case NC_DOUBLE  : return ncDouble;
  case NC_STRING  : return ncString;
  default:  
    // this is a user defined type
    return NcxxType(getParentGroup(),base_nc_typep);
  }
}

  
// Returns number of members in this NcxxEnumType object.
size_t   NcxxEnumType::getMemberCount() const{
  char charName[NC_MAX_NAME+1];
  nc_type* base_nc_typep=NULL;
  size_t* base_sizep=NULL;
  size_t num_membersp;
  ncxxCheck(nc_inq_enum(groupId,myId,charName,base_nc_typep,base_sizep,&num_membersp),__FILE__,__LINE__);
  return num_membersp;
};
  
// Returns the member name for the given zero-based index.
string NcxxEnumType::getMemberNameFromIndex(int index) const{
  void* value=NULL;
  char charName[NC_MAX_NAME+1];
  ncxxCheck(nc_inq_enum_member(groupId,myId,index,charName,value),__FILE__,__LINE__);
  return static_cast<string> (charName);
};
