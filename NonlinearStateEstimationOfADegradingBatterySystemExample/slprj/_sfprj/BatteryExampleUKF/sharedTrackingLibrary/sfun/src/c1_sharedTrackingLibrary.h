#ifndef __c1_sharedTrackingLibrary_h__
#define __c1_sharedTrackingLibrary_h__

/* Type Definitions */
#ifndef struct_tag_sjHMwlQwsKjeklylkLkVdsH
#define struct_tag_sjHMwlQwsKjeklylkLkVdsH

struct tag_sjHMwlQwsKjeklylkLkVdsH
{
  char_T FcnName[21];
  boolean_T HasAdditiveNoise;
  real_T Alpha;
  real_T Beta;
  real_T Kappa;
};

#endif                                 /*struct_tag_sjHMwlQwsKjeklylkLkVdsH*/

#ifndef typedef_c1_sjHMwlQwsKjeklylkLkVdsH
#define typedef_c1_sjHMwlQwsKjeklylkLkVdsH

typedef struct tag_sjHMwlQwsKjeklylkLkVdsH c1_sjHMwlQwsKjeklylkLkVdsH;

#endif                                 /*typedef_c1_sjHMwlQwsKjeklylkLkVdsH*/

#ifndef typedef_SFc1_sharedTrackingLibraryInstanceStruct
#define typedef_SFc1_sharedTrackingLibraryInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_sharedTrackingLibrary;
  c1_sjHMwlQwsKjeklylkLkVdsH c1_pM;
  void *c1_fEmlrtCtx;
  real_T (*c1_x)[2];
  real_T (*c1_xNew)[2];
  real_T (*c1_P)[4];
  real_T (*c1_PNew)[4];
  real_T *c1_yMeas;
  real_T *c1_R;
  boolean_T *c1_blockOrdering;
  boolean_T *c1_b_blockOrdering;
} SFc1_sharedTrackingLibraryInstanceStruct;

#endif                                 /*typedef_SFc1_sharedTrackingLibraryInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_sharedTrackingLibrary_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_sharedTrackingLibrary_get_check_sum(mxArray *plhs[]);
extern void c1_sharedTrackingLibrary_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
