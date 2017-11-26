/* Include files */

#include "sharedTrackingLibrary_sfun.h"
#include "c2_sharedTrackingLibrary.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "sharedTrackingLibrary_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[9] = { "pS", "nargin", "nargout", "x",
  "P", "Q", "unused", "xNew", "PNew" };

/* Function Declarations */
static void initialize_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance);
static void initialize_params_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance);
static void enable_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance);
static void disable_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance);
static void set_sim_state_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance);
static void sf_gateway_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance);
static void mdl_start_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance);
static void initSimStructsc2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance);
static void c2_batteryStateFcn_invoke(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, real_T c2_b_x[2], real_T c2_xNext[2]);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c2_b_PNew, const char_T *c2_identifier, real_T
  c2_y[4]);
static void c2_b_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[4]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c2_b_xNew, const char_T *c2_identifier, real_T
  c2_y[2]);
static void c2_d_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[2]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_e_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_localLowerCholesky(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, real_T c2_A[4], real_T c2_b_A[4], int32_T *c2_info);
static void c2_check_forloop_overflow_error
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance, boolean_T
   c2_overflow);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_f_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static c2_swDHwngkV09umpvRH3XXilD c2_g_emlrt_marshallIn
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance, const mxArray *c2_u,
   const emlrtMsgIdentifier *c2_parentId);
static void c2_h_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  char_T c2_y[15]);
static boolean_T c2_i_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_j_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_sharedTrackingLibrary, const
  char_T *c2_identifier);
static uint8_T c2_k_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static int32_T c2_b_localLowerCholesky(SFc2_sharedTrackingLibraryInstanceStruct *
  chartInstance, real_T c2_A[4]);
static void init_dsm_address_info(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_sharedTrackingLibrary(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_sharedTrackingLibrary = 0U;
}

static void initialize_params_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  const mxArray *c2_m0 = NULL;
  static const char * c2_fieldNames[5] = { "FcnName", "HasAdditiveNoise",
    "Alpha", "Beta", "Kappa" };

  const mxArray *c2_mxField;
  c2_swDHwngkV09umpvRH3XXilD c2_r0;
  c2_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  sf_mex_check_bus_parameter(c2_m0, 0, NULL, 5, c2_fieldNames, "pS",
    "swDHwngkV09umpvRH3XXilD");
  c2_mxField = sf_mex_getfield(c2_m0, "FcnName", "pS", 0);
  sf_mex_import_named("pS", sf_mex_dup(c2_mxField), c2_r0.FcnName, 1, 10, 0U, 1,
                      0U, 2, 1, 15);
  c2_mxField = sf_mex_getfield(c2_m0, "HasAdditiveNoise", "pS", 0);
  sf_mex_import_named("pS", sf_mex_dup(c2_mxField), &c2_r0.HasAdditiveNoise, 1,
                      11, 0U, 0, 0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "Alpha", "pS", 0);
  sf_mex_import_named("pS", sf_mex_dup(c2_mxField), &c2_r0.Alpha, 1, 0, 0U, 0,
                      0U, 0);
  c2_mxField = sf_mex_getfield(c2_m0, "Beta", "pS", 0);
  sf_mex_import_named("pS", sf_mex_dup(c2_mxField), &c2_r0.Beta, 1, 0, 0U, 0, 0U,
                      0);
  c2_mxField = sf_mex_getfield(c2_m0, "Kappa", "pS", 0);
  sf_mex_import_named("pS", sf_mex_dup(c2_mxField), &c2_r0.Kappa, 1, 0, 0U, 0,
                      0U, 0);
  sf_mex_destroy(&c2_m0);
  chartInstance->c2_pS = c2_r0;
}

static void enable_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_hoistedGlobal;
  const mxArray *c2_d_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(3, 1), false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", *chartInstance->c2_PNew, 0, 0U, 1U,
    0U, 2, 2, 2), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", *chartInstance->c2_xNew, 0, 0U, 1U,
    0U, 1, 2), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_sharedTrackingLibrary;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[4];
  int32_T c2_i0;
  real_T c2_dv1[2];
  int32_T c2_i1;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "PNew",
                      c2_dv0);
  for (c2_i0 = 0; c2_i0 < 4; c2_i0++) {
    (*chartInstance->c2_PNew)[c2_i0] = c2_dv0[c2_i0];
  }

  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
                        "xNew", c2_dv1);
  for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
    (*chartInstance->c2_xNew)[c2_i1] = c2_dv1[c2_i1];
  }

  chartInstance->c2_is_active_c2_sharedTrackingLibrary = c2_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
     "is_active_c2_sharedTrackingLibrary");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_sharedTrackingLibrary(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  real_T c2_b_x[2];
  int32_T c2_i7;
  real_T c2_b_P[4];
  boolean_T c2_b_unused;
  real_T c2_b_Q[4];
  uint32_T c2_debug_family_var_map[9];
  c2_swDHwngkV09umpvRH3XXilD c2_b_pS;
  real_T c2_nargin = 4.0;
  real_T c2_nargout = 2.0;
  real_T c2_b_xNew[2];
  real_T c2_b_PNew[4];
  static c2_swDHwngkV09umpvRH3XXilD c2_r1 = { { 'b', 'a', 't', 't', 'e', 'r',
      'y', 'S', 't', 'a', 't', 'e', 'F', 'c', 'n' },/* FcnName */
    true,                              /* HasAdditiveNoise */
    1.0,                               /* Alpha */
    2.0,                               /* Beta */
    0.0                                /* Kappa */
  };

  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
  int32_T c2_i11;
  real_T c2_c_Q[4];
  int32_T c2_i12;
  real_T c2_X1[2];
  int32_T c2_p;
  real_T c2_sqrtP[4];
  const mxArray *c2_y = NULL;
  static char_T c2_cv0[59] = { 's', 'h', 'a', 'r', 'e', 'd', '_', 't', 'r', 'a',
    'c', 'k', 'i', 'n', 'g', ':', 'U', 'n', 's', 'c', 'e', 'n', 't', 'e', 'd',
    'K', 'a', 'l', 'm', 'a', 'n', 'F', 'i', 'l', 't', 'e', 'r', ':', 'S', 't',
    'a', 't', 'e', 'C', 'o', 'v', 'a', 'r', 'i', 'a', 'n', 'c', 'e', 'N', 'o',
    't', 'P', 'S', 'D' };

  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  real_T c2_X2state[8];
  int32_T c2_kkC;
  int32_T c2_i19;
  int32_T c2_kk;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  real_T c2_tempY[2];
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  real_T c2_b_X2state[2];
  int32_T c2_b_kk;
  real_T c2_c_X2state[2];
  int32_T c2_c_kk;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  real_T c2_Y2[8];
  int32_T c2_d_kk;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  real_T c2_b_Y2[2];
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  real_T c2_b_tempY[4];
  int32_T c2_i43;
  real_T c2_c_Y2[4];
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  int32_T c2_i48;
  int32_T c2_i49;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_unused, 3U);
  for (c2_i2 = 0; c2_i2 < 4; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_Q)[c2_i2], 2U);
  }

  for (c2_i3 = 0; c2_i3 < 4; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_P)[c2_i3], 1U);
  }

  for (c2_i4 = 0; c2_i4 < 2; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_x)[c2_i4], 0U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
    c2_b_x[c2_i5] = (*chartInstance->c2_x)[c2_i5];
  }

  for (c2_i6 = 0; c2_i6 < 4; c2_i6++) {
    c2_b_P[c2_i6] = (*chartInstance->c2_P)[c2_i6];
  }

  for (c2_i7 = 0; c2_i7 < 4; c2_i7++) {
    c2_b_Q[c2_i7] = (*chartInstance->c2_Q)[c2_i7];
  }

  c2_b_unused = *chartInstance->c2_unused;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_pS, 0U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 1U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 2U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_x, 3U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_P, 4U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_Q, 5U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_unused, 6U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_xNew, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_PNew, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  c2_b_pS = c2_r1;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  for (c2_i8 = 0; c2_i8 < 2; c2_i8++) {
    c2_b_xNew[c2_i8] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  for (c2_i9 = 0; c2_i9 < 4; c2_i9++) {
    c2_b_PNew[c2_i9] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  CV_EML_IF(0, 1, 0, true);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  for (c2_i10 = 0; c2_i10 < 4; c2_i10++) {
    c2_c_Q[c2_i10] = c2_b_Q[c2_i10];
  }

  for (c2_i11 = 0; c2_i11 < 2; c2_i11++) {
    c2_X1[c2_i11] = c2_b_x[c2_i11];
  }

  for (c2_i12 = 0; c2_i12 < 4; c2_i12++) {
    c2_sqrtP[c2_i12] = c2_b_P[c2_i12];
  }

  c2_p = c2_b_localLowerCholesky(chartInstance, c2_sqrtP);
  if (!((real_T)c2_p > 0.0)) {
  } else {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 59),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c2_y));
  }

  for (c2_i13 = 0; c2_i13 < 4; c2_i13++) {
    c2_sqrtP[c2_i13] *= 1.4142135623730951;
  }

  c2_i14 = 0;
  for (c2_i15 = 0; c2_i15 < 2; c2_i15++) {
    for (c2_i17 = 0; c2_i17 < 2; c2_i17++) {
      c2_X2state[c2_i17 + c2_i14] = c2_sqrtP[c2_i17 + c2_i14];
    }

    c2_i14 += 2;
  }

  c2_i16 = 0;
  for (c2_i18 = 0; c2_i18 < 2; c2_i18++) {
    for (c2_i19 = 0; c2_i19 < 2; c2_i19++) {
      c2_X2state[(c2_i19 + c2_i16) + 4] = -c2_sqrtP[c2_i19 + c2_i16];
    }

    c2_i16 += 2;
  }

  for (c2_kkC = 0; c2_kkC < 4; c2_kkC++) {
    c2_i20 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 187, 172, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 187U, 172U, 1.0 + (real_T)c2_kkC), 1, 4) - 1;
    c2_i21 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 187, 172, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 187U, 172U, 1.0 + (real_T)c2_kkC), 1, 4) - 1;
    for (c2_i22 = 0; c2_i22 < 2; c2_i22++) {
      c2_b_X2state[c2_i22] = c2_X2state[c2_i22 + (c2_i20 << 1)] + c2_X1[c2_i22];
    }

    for (c2_i25 = 0; c2_i25 < 2; c2_i25++) {
      c2_X2state[c2_i25 + (c2_i21 << 1)] = c2_b_X2state[c2_i25];
    }
  }

  for (c2_kk = 0; c2_kk < 4; c2_kk++) {
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 187, 172, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 187U, 172U, 1.0 + (real_T)c2_kk), 1, 4);
    CV_EML_FCN(0, 1);
    for (c2_i24 = 0; c2_i24 < 2; c2_i24++) {
      c2_c_X2state[c2_i24] = c2_X2state[c2_i24 + (c2_kk << 1)];
    }

    c2_batteryStateFcn_invoke(chartInstance, c2_c_X2state, c2_tempY);
    c2_i26 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 187, 172, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 187U, 172U, 1.0 + (real_T)c2_kk), 1, 4) - 1;
    for (c2_i27 = 0; c2_i27 < 2; c2_i27++) {
      c2_Y2[c2_i27 + (c2_i26 << 1)] = c2_tempY[c2_i27];
    }
  }

  CV_EML_FCN(0, 1);
  c2_batteryStateFcn_invoke(chartInstance, c2_X1, c2_tempY);
  for (c2_i23 = 0; c2_i23 < 2; c2_i23++) {
    c2_X1[c2_i23] = c2_tempY[c2_i23] * 0.0;
  }

  c2_b_kk = 0;
  for (c2_c_kk = 0; c2_c_kk < 4; c2_c_kk++) {
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 187, 172, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 187U, 172U, 1.0 + (real_T)c2_c_kk), 1, 4);
    for (c2_i29 = 0; c2_i29 < 2; c2_i29++) {
      c2_X1[c2_i29] += c2_Y2[c2_i29 + c2_b_kk] * 0.25;
    }

    c2_b_kk += 2;
  }

  for (c2_i28 = 0; c2_i28 < 2; c2_i28++) {
    c2_tempY[c2_i28] -= c2_X1[c2_i28];
  }

  for (c2_d_kk = 0; c2_d_kk < 4; c2_d_kk++) {
    c2_i31 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 187, 172, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 187U, 172U, 1.0 + (real_T)c2_d_kk), 1, 4) - 1;
    c2_i32 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 187, 172, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 187U, 172U, 1.0 + (real_T)c2_d_kk), 1, 4) - 1;
    for (c2_i33 = 0; c2_i33 < 2; c2_i33++) {
      c2_b_Y2[c2_i33] = c2_Y2[c2_i33 + (c2_i31 << 1)] - c2_X1[c2_i33];
    }

    for (c2_i35 = 0; c2_i35 < 2; c2_i35++) {
      c2_Y2[c2_i35 + (c2_i32 << 1)] = c2_b_Y2[c2_i35];
    }
  }

  for (c2_i30 = 0; c2_i30 < 2; c2_i30++) {
    c2_b_xNew[c2_i30] = c2_X1[c2_i30];
  }

  for (c2_i34 = 0; c2_i34 < 2; c2_i34++) {
    c2_i37 = 0;
    for (c2_i38 = 0; c2_i38 < 2; c2_i38++) {
      c2_b_tempY[c2_i37 + c2_i34] = c2_tempY[c2_i34] * c2_tempY[c2_i38];
      c2_i37 += 2;
    }
  }

  for (c2_i36 = 0; c2_i36 < 2; c2_i36++) {
    c2_i40 = 0;
    for (c2_i42 = 0; c2_i42 < 2; c2_i42++) {
      c2_c_Y2[c2_i40 + c2_i36] = 0.0;
      c2_i44 = 0;
      for (c2_i46 = 0; c2_i46 < 4; c2_i46++) {
        c2_c_Y2[c2_i40 + c2_i36] += c2_Y2[c2_i44 + c2_i36] * c2_Y2[c2_i44 +
          c2_i42];
        c2_i44 += 2;
      }

      c2_i40 += 2;
    }
  }

  c2_i39 = 0;
  for (c2_i41 = 0; c2_i41 < 2; c2_i41++) {
    for (c2_i43 = 0; c2_i43 < 2; c2_i43++) {
      c2_b_PNew[c2_i43 + c2_i39] = (2.0 * c2_b_tempY[c2_i43 + c2_i39] + 0.25 *
        c2_c_Y2[c2_i43 + c2_i39]) + c2_c_Q[c2_i43 + c2_i39];
    }

    c2_i39 += 2;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i45 = 0; c2_i45 < 2; c2_i45++) {
    (*chartInstance->c2_xNew)[c2_i45] = c2_b_xNew[c2_i45];
  }

  for (c2_i47 = 0; c2_i47 < 4; c2_i47++) {
    (*chartInstance->c2_PNew)[c2_i47] = c2_b_PNew[c2_i47];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_sharedTrackingLibraryMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c2_i48 = 0; c2_i48 < 2; c2_i48++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_xNew)[c2_i48], 4U);
  }

  for (c2_i49 = 0; c2_i49 < 4; c2_i49++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_PNew)[c2_i49], 5U);
  }
}

static void mdl_start_c2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc2_sharedTrackingLibrary
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_batteryStateFcn_invoke(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, real_T c2_b_x[2], real_T c2_xNext[2])
{
  _ssFcnCallExecArgInfo c2_args[2];
  c2_args[0U].dataPtr = (void *)c2_b_x;
  c2_args[1U].dataPtr = (void *)c2_xNext;
  slcsInvokeSimulinkFunction(chartInstance->S, "batteryStateFcn", &c2_args[0U]);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)(c2_machineNumber);
  (void)(c2_chartNumber);
  (void)(c2_instanceNumber);
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i50;
  int32_T c2_i51;
  const mxArray *c2_y = NULL;
  int32_T c2_i52;
  real_T c2_u[4];
  SFc2_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc2_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i50 = 0;
  for (c2_i51 = 0; c2_i51 < 2; c2_i51++) {
    for (c2_i52 = 0; c2_i52 < 2; c2_i52++) {
      c2_u[c2_i52 + c2_i50] = (*(real_T (*)[4])c2_inData)[c2_i52 + c2_i50];
    }

    c2_i50 += 2;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c2_b_PNew, const char_T *c2_identifier, real_T
  c2_y[4])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_PNew), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_PNew);
}

static void c2_b_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[4])
{
  real_T c2_dv2[4];
  int32_T c2_i53;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv2, 1, 0, 0U, 1, 0U, 2, 2, 2);
  for (c2_i53 = 0; c2_i53 < 4; c2_i53++) {
    c2_y[c2_i53] = c2_dv2[c2_i53];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_PNew;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[4];
  int32_T c2_i54;
  int32_T c2_i55;
  int32_T c2_i56;
  SFc2_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc2_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c2_b_PNew = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_PNew), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_PNew);
  c2_i54 = 0;
  for (c2_i55 = 0; c2_i55 < 2; c2_i55++) {
    for (c2_i56 = 0; c2_i56 < 2; c2_i56++) {
      (*(real_T (*)[4])c2_outData)[c2_i56 + c2_i54] = c2_y[c2_i56 + c2_i54];
    }

    c2_i54 += 2;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i57;
  const mxArray *c2_y = NULL;
  real_T c2_u[2];
  SFc2_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc2_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i57 = 0; c2_i57 < 2; c2_i57++) {
    c2_u[c2_i57] = (*(real_T (*)[2])c2_inData)[c2_i57];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c2_b_xNew, const char_T *c2_identifier, real_T
  c2_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_xNew), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_xNew);
}

static void c2_d_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[2])
{
  real_T c2_dv3[2];
  int32_T c2_i58;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv3, 1, 0, 0U, 1, 0U, 1, 2);
  for (c2_i58 = 0; c2_i58 < 2; c2_i58++) {
    c2_y[c2_i58] = c2_dv3[c2_i58];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_xNew;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[2];
  int32_T c2_i59;
  SFc2_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc2_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c2_b_xNew = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_xNew), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_xNew);
  for (c2_i59 = 0; c2_i59 < 2; c2_i59++) {
    (*(real_T (*)[2])c2_outData)[c2_i59] = c2_y[c2_i59];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  boolean_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc2_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(boolean_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc2_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_e_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc2_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_swDHwngkV09umpvRH3XXilD c2_u;
  const mxArray *c2_y = NULL;
  int32_T c2_i60;
  const mxArray *c2_b_y = NULL;
  char_T c2_b_u[15];
  boolean_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_e_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_f_u;
  const mxArray *c2_f_y = NULL;
  SFc2_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc2_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(c2_swDHwngkV09umpvRH3XXilD *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c2_i60 = 0; c2_i60 < 15; c2_i60++) {
    c2_b_u[c2_i60] = c2_u.FcnName[c2_i60];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 15),
                false);
  sf_mex_addfield(c2_y, c2_b_y, "FcnName", "FcnName", 0);
  c2_c_u = c2_u.HasAdditiveNoise;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_c_y, "HasAdditiveNoise", "HasAdditiveNoise", 0);
  c2_d_u = c2_u.Alpha;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_d_y, "Alpha", "Alpha", 0);
  c2_e_u = c2_u.Beta;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_e_y, "Beta", "Beta", 0);
  c2_f_u = c2_u.Kappa;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c2_y, c2_f_y, "Kappa", "Kappa", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_sharedTrackingLibrary_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static void c2_localLowerCholesky(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, real_T c2_A[4], real_T c2_b_A[4], int32_T *c2_info)
{
  int32_T c2_i61;
  for (c2_i61 = 0; c2_i61 < 4; c2_i61++) {
    c2_b_A[c2_i61] = c2_A[c2_i61];
  }

  *c2_info = c2_b_localLowerCholesky(chartInstance, c2_b_A);
}

static void c2_check_forloop_overflow_error
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance, boolean_T
   c2_overflow)
{
  const mxArray *c2_y = NULL;
  static char_T c2_cv1[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c2_b_y = NULL;
  static char_T c2_cv2[5] = { 'i', 'n', 't', '3', '2' };

  (void)chartInstance;
  if (!c2_overflow) {
  } else {
    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c2_y, 14, c2_b_y));
  }
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc2_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_f_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i62;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i62, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i62;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc2_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static c2_swDHwngkV09umpvRH3XXilD c2_g_emlrt_marshallIn
  (SFc2_sharedTrackingLibraryInstanceStruct *chartInstance, const mxArray *c2_u,
   const emlrtMsgIdentifier *c2_parentId)
{
  c2_swDHwngkV09umpvRH3XXilD c2_y;
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[5] = { "FcnName", "HasAdditiveNoise",
    "Alpha", "Beta", "Kappa" };

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  sf_mex_check_struct(c2_parentId, c2_u, 5, c2_fieldNames, 0U, NULL);
  c2_thisId.fIdentifier = "FcnName";
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u,
    "FcnName", "FcnName", 0)), &c2_thisId, c2_y.FcnName);
  c2_thisId.fIdentifier = "HasAdditiveNoise";
  c2_y.HasAdditiveNoise = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c2_u, "HasAdditiveNoise", "HasAdditiveNoise", 0)),
    &c2_thisId);
  c2_thisId.fIdentifier = "Alpha";
  c2_y.Alpha = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "Alpha", "Alpha", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "Beta";
  c2_y.Beta = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "Beta", "Beta", 0)), &c2_thisId);
  c2_thisId.fIdentifier = "Kappa";
  c2_y.Kappa = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c2_u, "Kappa", "Kappa", 0)), &c2_thisId);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_h_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  char_T c2_y[15])
{
  char_T c2_cv3[15];
  int32_T c2_i63;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_cv3, 1, 10, 0U, 1, 0U, 2, 1,
                15);
  for (c2_i63 = 0; c2_i63 < 15; c2_i63++) {
    c2_y[c2_i63] = c2_cv3[c2_i63];
  }

  sf_mex_destroy(&c2_u);
}

static boolean_T c2_i_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  boolean_T c2_y;
  boolean_T c2_b0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_b0, 1, 11, 0U, 0, 0U, 0);
  c2_y = c2_b0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_pS;
  emlrtMsgIdentifier c2_thisId;
  c2_swDHwngkV09umpvRH3XXilD c2_y;
  SFc2_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc2_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c2_b_pS = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_pS), &c2_thisId);
  sf_mex_destroy(&c2_b_pS);
  *(c2_swDHwngkV09umpvRH3XXilD *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_j_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_sharedTrackingLibrary, const
  char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_sharedTrackingLibrary), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_sharedTrackingLibrary);
  return c2_y;
}

static uint8_T c2_k_emlrt_marshallIn(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static int32_T c2_b_localLowerCholesky(SFc2_sharedTrackingLibraryInstanceStruct *
  chartInstance, real_T c2_A[4])
{
  int32_T c2_info;
  int32_T c2_b_info;
  int32_T c2_j;
  int32_T c2_jj;
  real_T c2_d;
  int32_T c2_jmax;
  int32_T c2_ix;
  int32_T c2_iy;
  real_T c2_ajj;
  boolean_T c2_overflow;
  boolean_T c2_b_overflow;
  int32_T c2_kkC;
  int32_T c2_k;
  boolean_T c2_c_overflow;
  boolean_T c2_d_overflow;
  int32_T c2_kkR;
  real_T c2_alpha1;
  real_T c2_beta1;
  boolean_T c2_e_overflow;
  char_T c2_TRANSA;
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  real_T c2_z;
  ptrdiff_t c2_lda_t;
  int32_T c2_b;
  ptrdiff_t c2_incx_t;
  boolean_T c2_f_overflow;
  ptrdiff_t c2_incy_t;
  int32_T c2_b_k;
  boolean_T exitg1;
  c2_b_info = 0;
  c2_j = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_j + 1 < 3)) {
    c2_jj = c2_j + (c2_j << 1);
    c2_d = 0.0;
    if (c2_j < 1) {
    } else {
      c2_ix = c2_j;
      c2_iy = c2_j;
      c2_b_overflow = ((!(1 > c2_j)) && (c2_j > 2147483646));
      if (c2_b_overflow) {
        c2_check_forloop_overflow_error(chartInstance, c2_b_overflow);
      }

      for (c2_k = 1; c2_k <= c2_j; c2_k++) {
        c2_d += c2_A[c2_ix] * c2_A[c2_iy];
        c2_ix += 2;
        c2_iy += 2;
      }
    }

    c2_ajj = c2_A[c2_jj] - c2_d;
    if (c2_ajj > 0.0) {
      c2_ajj = muDoubleScalarSqrt(c2_ajj);
      c2_A[c2_jj] = c2_ajj;
      if (c2_j + 1 < 2) {
        c2_c_overflow = ((!(1 > c2_j)) && (c2_j > 2147483646));
        if (c2_c_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_c_overflow);
        }

        if ((1 - c2_j < 1) || (c2_j < 1)) {
        } else {
          c2_alpha1 = -1.0;
          c2_beta1 = 1.0;
          c2_TRANSA = 'N';
          c2_m_t = (ptrdiff_t)(1 - c2_j);
          c2_n_t = (ptrdiff_t)c2_j;
          c2_lda_t = (ptrdiff_t)2;
          c2_incx_t = (ptrdiff_t)2;
          c2_incy_t = (ptrdiff_t)1;
          dgemv(&c2_TRANSA, &c2_m_t, &c2_n_t, &c2_alpha1, &c2_A[c2_j + 1],
                &c2_lda_t, &c2_A[c2_j], &c2_incx_t, &c2_beta1, &c2_A[c2_jj + 1],
                &c2_incy_t);
        }

        c2_e_overflow = ((!(1 > c2_j)) && (c2_j > 2147483646));
        if (c2_e_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_e_overflow);
        }

        c2_z = 1.0 / c2_ajj;
        c2_b = (c2_jj - c2_j) + 2;
        c2_f_overflow = ((!(c2_jj + 2 > c2_b)) && (c2_b > 2147483646));
        if (c2_f_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_f_overflow);
        }

        for (c2_b_k = c2_jj + 1; c2_b_k + 1 <= c2_b; c2_b_k++) {
          c2_A[c2_b_k] *= c2_z;
        }
      }

      c2_j++;
    } else {
      c2_A[c2_jj] = c2_ajj;
      c2_b_info = c2_j + 1;
      exitg1 = true;
    }
  }

  c2_info = c2_b_info;
  if (c2_b_info == 0) {
    c2_jmax = 2;
  } else {
    c2_jmax = c2_b_info - 1;
  }

  c2_overflow = ((!(2 > c2_jmax)) && (c2_jmax > 2147483646));
  if (c2_overflow) {
    c2_check_forloop_overflow_error(chartInstance, c2_overflow);
  }

  for (c2_kkC = 1; c2_kkC + 1 <= c2_jmax; c2_kkC++) {
    c2_d_overflow = ((!(1 > c2_kkC)) && (c2_kkC > 2147483646));
    if (c2_d_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_d_overflow);
    }

    for (c2_kkR = 1; c2_kkR <= c2_kkC; c2_kkR++) {
      c2_A[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
             chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
             (chartInstance->S, 1U, 0U, 0U, (real_T)c2_kkR), 1, 2) +
            ((sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
               chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)
               sf_integer_check(chartInstance->S, 1U, 0U, 0U, (real_T)(c2_kkC +
                 1)), 1, 2) - 1) << 1)) - 1] = 0.0;
    }
  }

  return c2_info;
}

static void init_dsm_address_info(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_sharedTrackingLibraryInstanceStruct
  *chartInstance)
{
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_x = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_xNew = (real_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_P = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_Q = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_unused = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_PNew = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_sharedTrackingLibrary_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1695643145U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3524741911U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2709562951U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(201101828U);
}

mxArray* sf_c2_sharedTrackingLibrary_get_post_codegen_info(void);
mxArray *sf_c2_sharedTrackingLibrary_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("M0D0WSM5SQwWV70WtI9eQH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(2);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(2);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(2);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c2_sharedTrackingLibrary_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_sharedTrackingLibrary_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.blas.BLASApi"));
  return(mxcell3p);
}

mxArray *sf_c2_sharedTrackingLibrary_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("client_server");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("batteryStateFcn");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_sharedTrackingLibrary_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_sharedTrackingLibrary_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString(
      "hdoxhkO3vmbxsVBnm33KaG");
    mwSize exp_dims[2] = { 1, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);

    {
      mxArray* mxFcnName = mxCreateString("batteryStateFcn");
      mxSetCell(mxExportedFunctionsUsedByThisChart, 0, mxFcnName);
    }

    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c2_sharedTrackingLibrary(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[8],T\"PNew\",},{M[1],M[13],T\"xNew\",},{M[8],M[0],T\"is_active_c2_sharedTrackingLibrary\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_sharedTrackingLibrary_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_sharedTrackingLibraryInstanceStruct *chartInstance =
      (SFc2_sharedTrackingLibraryInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _sharedTrackingLibraryMachineNumber_,
           2,
           1,
           1,
           0,
           7,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_sharedTrackingLibraryMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_sharedTrackingLibraryMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _sharedTrackingLibraryMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,1,1,0,"P");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Q");
          _SFD_SET_DATA_PROPS(3,1,1,0,"unused");
          _SFD_SET_DATA_PROPS(4,2,0,1,"xNew");
          _SFD_SET_DATA_PROPS(5,2,0,1,"PNew");
          _SFD_SET_DATA_PROPS(6,10,0,0,"pS");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,3,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,564);
        _SFD_CV_INIT_EML_FCN(0,1,"",331,-1,358);
        _SFD_CV_INIT_EML_FCN(0,2,"",517,-1,550);
        _SFD_CV_INIT_EML_IF(0,1,0,160,182,361,560);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)c2_e_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _sharedTrackingLibraryMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_sharedTrackingLibraryInstanceStruct *chartInstance =
      (SFc2_sharedTrackingLibraryInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c2_x);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c2_xNew);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c2_P);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c2_Q);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c2_unused);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c2_PNew);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)&chartInstance->c2_pS);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sfxNGSxYvMvZdzVzXEGw5lD";
}

static void sf_opaque_initialize_c2_sharedTrackingLibrary(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_sharedTrackingLibraryInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_sharedTrackingLibrary
    ((SFc2_sharedTrackingLibraryInstanceStruct*) chartInstanceVar);
  initialize_c2_sharedTrackingLibrary((SFc2_sharedTrackingLibraryInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_sharedTrackingLibrary(void *chartInstanceVar)
{
  enable_c2_sharedTrackingLibrary((SFc2_sharedTrackingLibraryInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_sharedTrackingLibrary(void *chartInstanceVar)
{
  disable_c2_sharedTrackingLibrary((SFc2_sharedTrackingLibraryInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_sharedTrackingLibrary(void *chartInstanceVar)
{
  sf_gateway_c2_sharedTrackingLibrary((SFc2_sharedTrackingLibraryInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_sharedTrackingLibrary(SimStruct*
  S)
{
  return get_sim_state_c2_sharedTrackingLibrary
    ((SFc2_sharedTrackingLibraryInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_sharedTrackingLibrary(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c2_sharedTrackingLibrary
    ((SFc2_sharedTrackingLibraryInstanceStruct*)sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c2_sharedTrackingLibrary(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_sharedTrackingLibraryInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_sharedTrackingLibrary_optimization_info();
    }

    finalize_c2_sharedTrackingLibrary((SFc2_sharedTrackingLibraryInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_sharedTrackingLibrary
    ((SFc2_sharedTrackingLibraryInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_sharedTrackingLibrary(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_sharedTrackingLibrary
      ((SFc2_sharedTrackingLibraryInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_sharedTrackingLibrary(SimStruct *S)
{
  /* Actual parameters from chart:
     pS
   */
  const char_T *rtParamNames[] = { "pS" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* Set overwritable ports for inplace optimization */
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortDirectFeedThrough(S, 2, 1);
  ssSetInputPortDirectFeedThrough(S, 3, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_sharedTrackingLibrary_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 2);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2213813290U));
  ssSetChecksum1(S,(3473116410U));
  ssSetChecksum2(S,(3378639265U));
  ssSetChecksum3(S,(3471286126U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c2_sharedTrackingLibrary(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_sharedTrackingLibrary(SimStruct *S)
{
  SFc2_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc2_sharedTrackingLibraryInstanceStruct *)utMalloc(sizeof
    (SFc2_sharedTrackingLibraryInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_sharedTrackingLibraryInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  if (ssGetSampleTime(S, 0) == CONTINUOUS_SAMPLE_TIME && ssGetOffsetTime(S, 0) ==
      0 && ssGetNumContStates(ssGetRootSS(S)) > 0) {
    sf_error_out_about_continuous_sample_time_with_persistent_vars(S);
  }

  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_sharedTrackingLibrary;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_sharedTrackingLibrary;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_sharedTrackingLibrary;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_sharedTrackingLibrary;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_sharedTrackingLibrary;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_sharedTrackingLibrary;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_sharedTrackingLibrary;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_sharedTrackingLibrary;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_sharedTrackingLibrary;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_sharedTrackingLibrary;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_sharedTrackingLibrary;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c2_sharedTrackingLibrary(chartInstance);
}

void c2_sharedTrackingLibrary_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_sharedTrackingLibrary(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_sharedTrackingLibrary(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_sharedTrackingLibrary(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_sharedTrackingLibrary_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
