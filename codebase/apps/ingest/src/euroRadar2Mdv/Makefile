###########################################################################
#
# Copyright (c) 1995, UCAR
# University Corporation for Atmospheric Research(UCAR)
# National Center for Atmospheric Research(NCAR)
# Research Applications Program(RAP)
# P.O.Box 3000, Boulder, Colorado, 80307-3000, USA
# All rights reserved. Licenced use only.
# Do not copy or distribute without authorization
# Tue 1 Jul 19103 21:20:6 UTC
#
# Makefile
#
# Niles Oien January 2004.
#
###########################################################################

include $(RAP_MAKE_INC_DIR)/rap_make_macros

TARGET_FILE = euroRadar2Mdv

LOC_INCLUDES = $(NETCDF4_INCS)

LOC_LIBS = -lMdv -lRadx -ldsserver -leuclid \
	-ldidss -lcidd -lrapformats -ltoolsa \
	-ldataport -ltdrp -lrapmath $(NETCDF4_LIBS) \
	-lbz2 -lz -lpthread -lm

LOC_LDFLAGS = $(NETCDF4_LDFLAGS)

LOC_CFLAGS =

HDRS = \
        $(PARAMS_HH) \
	Args.hh \
	euroRadar2Mdv.hh \
	GermanProj.hh

CPPC_SRCS = \
        $(PARAMS_CC) \
	Main.cc \
	Args.cc \
	euroRadar2Mdv.cc \
	GermanProj.cc
#
# tdrp macros
#
include $(RAP_MAKE_INC_DIR)/rap_make_tdrp_macros

#
# standard C++ targets
#
include $(RAP_MAKE_INC_DIR)/rap_make_c++_targets

#
# tdrp targets
#
include $(RAP_MAKE_INC_DIR)/rap_make_tdrp_c++_targets

#
# local targets
#

# DO NOT DELETE THIS LINE -- make depend depends on it.

