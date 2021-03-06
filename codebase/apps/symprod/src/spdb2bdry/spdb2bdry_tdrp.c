/*******************************************
 * spdb2bdry_tdrp.c
 *
 * TDRP C code file 'spdb2bdry' module.
 *
 * Code for program spdb2bdry
 *
 * This file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#include "spdb2bdry_tdrp.h"
#include <string.h>

/*
 * file scope variables
 */

static TDRPtable Table[6];
static spdb2bdry_tdrp_struct *Params;
static char *Module = "spdb2bdry";

/*************************************************************
 * spdb2bdry_tdrp_load_from_args()
 *
 * Loads up TDRP using the command line args.
 *
 * Check TDRP_usage() for command line actions associated with
 * this function.
 *
 *   argc, argv: command line args
 *
 *   spdb2bdry_tdrp_struct *params: loads up this struct
 * 
 *   char **override_list: A null-terminated list of overrides
 *     to the parameter file.
 *     An override string has exactly the format of an entry
 *     in the parameter file itself.
 *
 *   char **params_path_p: if non-NULL, this is set to point to
 *                         the path of the params file used.
 *
 *  Returns 0 on success, -1 on failure.
 */

int spdb2bdry_tdrp_load_from_args(int argc, char **argv,
                         spdb2bdry_tdrp_struct *params,
                         char **override_list,
                         char **params_path_p)
{
  Params = params;
  spdb2bdry_tdrp_init(Params);
  if (tdrpLoadFromArgs(argc, argv,
                       Table, Params,
                       override_list, params_path_p)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * spdb2bdry_tdrp_load()
 *
 * Loads up TDRP for a given module.
 *
 * This version of load gives the programmer the option to load
 * up more than one module for a single application. It is a
 * lower-level routine than spdb2bdry_tdrp_load_from_args,
 * and hence more flexible, but the programmer must do more work.
 *
 *   char *param_file_path: the parameter file to be read in.
 *
 *   spdb2bdry_tdrp_struct *params: loads up this struct
 *
 *   char **override_list: A null-terminated list of overrides
 *     to the parameter file.
 *     An override string has exactly the format of an entry
 *     in the parameter file itself.
 *
 *  expand_env: flag to control environment variable
 *                expansion during tokenization.
 *              If TRUE, environment expansion is set on.
 *              If FALSE, environment expansion is set off.
 *
 *  Returns 0 on success, -1 on failure.
 */

int spdb2bdry_tdrp_load(char *param_file_path,
               spdb2bdry_tdrp_struct *params,
               char **override_list,
               int expand_env, int debug)
{
  Params = params;
  spdb2bdry_tdrp_init(Params);
  if (tdrpLoad(param_file_path, Table,
               params, override_list,
               expand_env, debug)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * spdb2bdry_tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See spdb2bdry_tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

int spdb2bdry_tdrp_load_defaults(spdb2bdry_tdrp_struct *params,
                        int expand_env)
{
  Params = params;
  spdb2bdry_tdrp_init(Params);
  if (tdrpLoad(NULL, Table,
               params, NULL,
               expand_env, FALSE)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * spdb2bdry_tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

void spdb2bdry_tdrp_sync(void)
{
  tdrpUser2Table(Table, Params);
}

/*************************************************************
 * spdb2bdry_tdrp_print()
 * 
 * Print params file
 *
 * The modes supported are:
 *
 *   PRINT_SHORT:   main comments only, no help or descriptions
 *                  structs and arrays on a single line
 *   PRINT_NORM:    short + descriptions and help
 *   PRINT_LONG:    norm  + arrays and structs expanded
 *   PRINT_VERBOSE: long  + private params included
 */

void spdb2bdry_tdrp_print(FILE *out, tdrp_print_mode_t mode)
{
  tdrpPrint(out, Table, Module, mode);
}

/*************************************************************
 * spdb2bdry_tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

int spdb2bdry_tdrp_check_all_set(FILE *out)
{
  return (tdrpCheckAllSet(out, Table, Params));
}

/*************************************************************
 * spdb2bdry_tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

int spdb2bdry_tdrp_check_is_set(char *param_name)
{
  return (tdrpCheckIsSet(param_name, Table, Params));
}

/*************************************************************
 * spdb2bdry_tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

void spdb2bdry_tdrp_free_all(void)
{
  tdrpFreeAll(Table, Params);
}

/*************************************************************
 * spdb2bdry_tdrp_array_realloc()
 *
 * Realloc 1D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int spdb2bdry_tdrp_array_realloc(char *param_name, int new_array_n)
{
  if (tdrpArrayRealloc(Table, Params, param_name, new_array_n)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * spdb2bdry_tdrp_array2D_realloc()
 *
 * Realloc 2D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int spdb2bdry_tdrp_array2D_realloc(char *param_name,
                          int new_array_n1,
                          int new_array_n2)
{
  if (tdrpArray2DRealloc(Table, Params, param_name,
			 new_array_n1, new_array_n2)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * spdb2bdry_tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *spdb2bdry_tdrp_table(void)
{
  return (Table);
}

/*************************************************************
 * spdb2bdry_tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *spdb2bdry_tdrp_init(spdb2bdry_tdrp_struct *params)

{

  TDRPtable *tt = Table;

  spdb2bdry_tdrp_struct pp; /* for computing byte_offsets */

  /* zero out struct, and store size */

  memset(params, 0, sizeof(spdb2bdry_tdrp_struct));
  params->struct_size = sizeof(spdb2bdry_tdrp_struct);

  /* Parameter 'input_path' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("input_path");
  tt->descr = tdrpStrDup("Path for spdb directory");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.input_path) - (char *) &pp;
  tt->single_val.s = tdrpStrDup(".");
  tt++;
  
  /* Parameter 'output_file_path' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("output_file_path");
  tt->descr = tdrpStrDup("Output file path");
  tt->help = tdrpStrDup("All data will be written to this file");
  tt->val_offset = (char *) &(pp.output_file_path) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("./temp");
  tt++;
  
  /* Parameter 'start_time' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("start_time");
  tt->descr = tdrpStrDup("Start time");
  tt->help = tdrpStrDup("Needs to be in this format:  HH:MM MM/DD/YYYY");
  tt->val_offset = (char *) &(pp.start_time) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("00:00 01/01/1999");
  tt++;
  
  /* Parameter 'end_time' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("end_time");
  tt->descr = tdrpStrDup("End time");
  tt->help = tdrpStrDup("Needs to be in this format: HH:MM MM/DD/YYYY");
  tt->val_offset = (char *) &(pp.end_time) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("00:00 01/01/1999");
  tt++;
  
  /* Parameter 'rm_duplicates' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("rm_duplicates");
  tt->descr = tdrpStrDup("Remove duplicates");
  tt->help = tdrpStrDup("If two boundaries occur at the same data time, with the same description string, with the same number of points and the same latitude and longitude for the first point, don't print the second one");
  tt->val_offset = (char *) &(pp.rm_duplicates) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* trailing entry has param_name set to NULL */
  
  tt->param_name = NULL;
  
  return (Table);

}
