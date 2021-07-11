/*
 * MPC0_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MPC0".
 *
 * Model version              : 1.855
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C++ source code generated on : Sun Jul  4 17:00:16 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MPC0_types_h_
#define RTW_HEADER_MPC0_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_struct_qYRJtcce7MM7XuQ3AAWdMD_
#define DEFINED_TYPEDEF_FOR_struct_qYRJtcce7MM7XuQ3AAWdMD_

typedef struct {
  real_T MaxIterations;
  real_T ConstraintTolerance;
  boolean_T UseWarmStart;
} struct_qYRJtcce7MM7XuQ3AAWdMD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_SmvKLCDySlKdToNTroAGyF_
#define DEFINED_TYPEDEF_FOR_struct_SmvKLCDySlKdToNTroAGyF_

typedef struct {
  real_T MaxIterations;
  real_T ConstraintTolerance;
  real_T OptimalityTolerance;
  real_T ComplementarityTolerance;
  real_T StepTolerance;
} struct_SmvKLCDySlKdToNTroAGyF;

#endif

/* Parameters (default storage) */
typedef struct P_MPC0_T_ P_MPC0_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_MPC0_T RT_MODEL_MPC0_T;

#endif                                 /* RTW_HEADER_MPC0_types_h_ */
