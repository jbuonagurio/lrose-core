// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c) 1992 - 2016
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Boulder, Colorado, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// Params.hh
//
// TDRP header file for 'Params' class.
//
// Code for program Dsr2Radx
//
// This header file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.hh
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @class Params
 *
 * @author automatically generated
 *
 */

#ifndef Params_hh
#define Params_hh

using namespace std;

#include <tdrp/tdrp.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>

// Class definition

class Params {

public:

  // enum typedefs

  typedef enum {
    DEBUG_OFF = 0,
    DEBUG_NORM = 1,
    DEBUG_VERBOSE = 2,
    DEBUG_EXTRA = 3
  } debug_t;

  typedef enum {
    LOGICAL_AND = 0,
    LOGICAL_OR = 1
  } logical_t;

  typedef enum {
    END_OF_VOL_FLAG = 0,
    CHANGE_IN_VOL_NUM = 1,
    CHANGE_IN_SWEEP_NUM = 2,
    LAST_SWEEP_IN_VOL = 3,
    AUTOMATIC = 4,
    ELAPSED_TIME = 5
  } end_of_vol_decision_t;

  typedef enum {
    OUTPUT_FLOAT = 0,
    OUTPUT_SHORT = 1,
    OUTPUT_BYTE = 2
  } output_encoding_t;

  typedef enum {
    OUTPUT_FORMAT_CFRADIAL = 0,
    OUTPUT_FORMAT_FORAY = 1,
    OUTPUT_FORMAT_DORADE = 2,
    OUTPUT_FORMAT_UF = 3
  } output_format_t;

  typedef enum {
    START_AND_END_TIMES = 0,
    START_TIME_ONLY = 1,
    END_TIME_ONLY = 2
  } filename_mode_t;

  typedef enum {
    CLASSIC = 0,
    OFFSET_64BIT = 1,
    NETCDF4_CLASSIC = 2,
    NETCDF4 = 3
  } netcdf_style_t;

  // struct typedefs

  typedef struct {
    double latitudeDeg;
    double longitudeDeg;
    double altitudeKm;
  } radar_location_t;

  typedef struct {
    char* name;
    double min_valid_value;
    double max_valid_value;
    logical_t combination_method;
  } censoring_field_t;

  typedef struct {
    char* dsr_name;
    char* output_name;
    char* long_name;
    char* standard_name;
    char* output_units;
    output_encoding_t output_encoding;
  } output_field_t;

  typedef struct {
    char* output_dir;
    output_format_t format;
  } output_data_set_t;

  ///////////////////////////
  // Member functions
  //

  ////////////////////////////////////////////
  // Default constructor
  //

  Params ();

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params (const Params&);

  ////////////////////////////////////////////
  // Destructor
  //

  ~Params ();

  ////////////////////////////////////////////
  // Assignment
  //

  void operator=(const Params&);

  ////////////////////////////////////////////
  // loadFromArgs()
  //
  // Loads up TDRP using the command line args.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   char **params_path_p:
  //     If this is non-NULL, it is set to point to the path
  //     of the params file used.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadFromArgs(int argc, char **argv,
                   char **override_list,
                   char **params_path_p,
                   bool defer_exit = false);

  bool exitDeferred() { return (_exitDeferred); }

  ////////////////////////////////////////////
  // loadApplyArgs()
  //
  // Loads up TDRP using the params path passed in, and applies
  // the command line args for printing and checking.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   const char *param_file_path: the parameter file to be read in
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadApplyArgs(const char *params_path,
                    int argc, char **argv,
                    char **override_list,
                    bool defer_exit = false);

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  static bool isArgValid(const char *arg);

  ////////////////////////////////////////////
  // load()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to load
  // up more than one class for a single application. It is a
  // lower-level routine than loadFromArgs, and hence more
  // flexible, but the programmer must do more work.
  //
  //   const char *param_file_path: the parameter file to be read in.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int load(const char *param_file_path,
           char **override_list,
           int expand_env, int debug);

  ////////////////////////////////////////////
  // loadFromBuf()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to
  // load up more than one module for a single application,
  // using buffers which have been read from a specified source.
  //
  //   const char *param_source_str: a string which describes the
  //     source of the parameter information. It is used for
  //     error reporting only.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   const char *inbuf: the input buffer
  //
  //   int inlen: length of the input buffer
  //
  //   int start_line_num: the line number in the source which
  //     corresponds to the start of the buffer.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadFromBuf(const char *param_source_str,
                  char **override_list,
                  const char *inbuf, int inlen,
                  int start_line_num,
                  int expand_env, int debug);

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadDefaults(int expand_env);

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void sync() const;

  ////////////////////////////////////////////
  // print()
  // 
  // Print params file
  //
  // The modes supported are:
  //
  //   PRINT_SHORT:   main comments only, no help or descriptions
  //                  structs and arrays on a single line
  //   PRINT_NORM:    short + descriptions and help
  //   PRINT_LONG:    norm  + arrays and structs expanded
  //   PRINT_VERBOSE: long  + private params included
  //

  void print(FILE *out, tdrp_print_mode_t mode = PRINT_NORM);

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int checkAllSet(FILE *out);

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int checkIsSet(const char *param_name);

  ////////////////////////////////////////////
  // arrayRealloc()
  //
  // Realloc 1D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int arrayRealloc(const char *param_name,
                   int new_array_n);

  ////////////////////////////////////////////
  // array2DRealloc()
  //
  // Realloc 2D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int array2DRealloc(const char *param_name,
                     int new_array_n1,
                     int new_array_n2);

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void freeAll(void);

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  static void usage(ostream &out);

  ///////////////////////////
  // Data Members
  //

  char _start_; // start of data region
                // needed for zeroing out data
                // and computing offsets

  debug_t debug;

  char* instance;

  int procmap_register_interval;

  char* input_fmq_url;

  tdrp_bool_t seek_to_end_of_input;

  tdrp_bool_t use_input_scan_mode;

  char* site_name;

  tdrp_bool_t override_radar_name;

  char* radar_name;

  tdrp_bool_t override_radar_location;

  radar_location_t radar_location;

  tdrp_bool_t apply_azimuth_offset;

  double azimuth_offset;

  tdrp_bool_t apply_elevation_offset;

  double elevation_offset;

  tdrp_bool_t apply_censoring;

  censoring_field_t *_censoring_fields;
  int censoring_fields_n;

  int censoring_min_valid_run;

  tdrp_bool_t filter_using_gate_spacing;

  double specified_gate_spacing;

  tdrp_bool_t filter_using_start_range;

  double specified_start_range;

  tdrp_bool_t filter_using_elev;

  double specified_min_elev;

  double specified_max_elev;

  tdrp_bool_t filter_using_sweep_number;

  int specified_min_sweep_number;

  int specified_max_sweep_number;

  tdrp_bool_t filter_antenna_stationary;

  double min_angle_change_for_moving_antenna;

  tdrp_bool_t clear_transition_flag_on_all_rays;

  tdrp_bool_t filter_antenna_transitions;

  tdrp_bool_t filter_when_scan_idle;

  tdrp_bool_t filter_when_scan_pointing;

  tdrp_bool_t convert_to_predominant_gate_geometry;

  tdrp_bool_t find_sweep_numbers_using_histogram;

  tdrp_bool_t use_target_angles_for_hist;

  double hist_angle_resolution;

  int hist_search_width;

  tdrp_bool_t crop_above_max_height;

  double max_height_km_msl;

  tdrp_bool_t remove_test_pulse;

  int ngates_test_pulse;

  tdrp_bool_t check_min_rays_in_sweep;

  int min_rays_in_sweep;

  tdrp_bool_t compute_ppi_fixed_angles_from_measured_elevation;

  tdrp_bool_t compute_rhi_fixed_angles_from_measured_azimuth;

  tdrp_bool_t increment_sweep_num_when_pol_mode_changes;

  tdrp_bool_t increment_sweep_num_when_prt_mode_changes;

  tdrp_bool_t adjust_sur_sweep_limits_using_angles;

  tdrp_bool_t adjust_sector_sweep_limits_using_angles;

  tdrp_bool_t adjust_rhi_sweep_limits_using_angles;

  tdrp_bool_t force_sur_sweep_transitions_at_fixed_azimuth;

  double sur_sweep_transitions_azimuth_deg;

  tdrp_bool_t trim_surveillance_sweeps_to_360deg;

  end_of_vol_decision_t end_of_vol_decision;

  int last_sweep_in_vol;

  tdrp_bool_t write_end_of_vol_when_data_stops;

  int nsecs_no_data_for_end_of_vol;

  int nsecs_per_volume;

  int min_rays_in_vol;

  int max_rays_in_vol;

  tdrp_bool_t set_end_of_vol_from_elev_change;

  tdrp_bool_t vol_starts_at_bottom;

  double elev_change_for_end_of_vol;

  int nrays_history;

  double el_accuracy;

  double az_accuracy;

  double min_az_change_ppi;

  double min_el_change_rhi;

  int max_az_change_per_sweep;

  int min_rays_per_ppi_vol;

  int min_rays_per_rhi_vol;

  tdrp_bool_t debug_auto_detection;

  output_field_t *_output_fields;
  int output_fields_n;

  output_data_set_t *_output_data_set;
  int output_data_set_n;

  filename_mode_t output_filename_mode;

  tdrp_bool_t append_day_dir_to_output_dir;

  tdrp_bool_t append_year_dir_to_output_dir;

  tdrp_bool_t separate_output_dirs_by_scan_type;

  char* surveillance_subdir;

  char* sector_subdir;

  char* rhi_subdir;

  char* vert_subdir;

  char* sun_subdir;

  char* solar_scan_name;

  double min_elevation_for_vert_files;

  double min_vert_fraction_for_vert_files;

  char* output_filename_prefix;

  tdrp_bool_t include_instrument_name_in_file_name;

  tdrp_bool_t include_site_name_in_file_name;

  tdrp_bool_t include_subsecs_in_file_name;

  tdrp_bool_t include_scan_type_in_file_name;

  tdrp_bool_t include_vol_num_in_file_name;

  tdrp_bool_t use_hyphen_in_file_name_datetime_part;

  tdrp_bool_t write_master_ldata_info;

  tdrp_bool_t write_individual_ldata_info;

  netcdf_style_t netcdf_style;

  tdrp_bool_t output_native_byte_order;

  tdrp_bool_t output_compressed;

  int output_compression_level;

  char* ncf_title;

  char* ncf_institution;

  char* ncf_references;

  char* ncf_source;

  char* ncf_history;

  char* ncf_comment;

  tdrp_bool_t override_missing_metadata_values;

  double missing_metadata_double;

  float missing_metadata_float;

  int missing_metadata_int;

  int missing_metadata_char;

  tdrp_bool_t override_missing_field_values;

  double missing_field_fl64;

  double missing_field_fl32;

  int missing_field_si32;

  int missing_field_si16;

  int missing_field_si08;

  char _end_; // end of data region
              // needed for zeroing out data

private:

  void _init();

  mutable TDRPtable _table[148];

  const char *_className;

  bool _exitDeferred;

};

#endif

