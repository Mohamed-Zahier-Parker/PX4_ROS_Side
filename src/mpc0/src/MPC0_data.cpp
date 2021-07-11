/*
 * MPC0_data.cpp
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

#include "MPC0.h"
#include "MPC0_private.h"

/* Block parameters (default storage) */
P_MPC0_T MPC0_P = {
  /* Expression: lastx+xoff
   * Referenced by: '<S2>/last_x'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: lastu+uoff
   * Referenced by: '<S2>/last_mv'
   */
  { 0.0, 0.0 },

  /* Expression: zeros(1,1)
   * Referenced by: '<S1>/md_zero'
   */
  0.0,

  /* Expression: zeros(2,1)
   * Referenced by: '<S1>/umin_zero'
   */
  { 0.0, 0.0 },

  /* Expression: zeros(2,1)
   * Referenced by: '<S1>/umax_zero'
   */
  { 0.0, 0.0 },

  /* Expression: zeros(2,1)
   * Referenced by: '<S1>/ymin_zero'
   */
  { 0.0, 0.0 },

  /* Expression: zeros(2,1)
   * Referenced by: '<S1>/ymax_zero'
   */
  { 0.0, 0.0 },

  /* Expression: zeros(1,2)
   * Referenced by: '<S1>/E_zero'
   */
  { 0.0, 0.0 },

  /* Expression: MVscale(:,ones(1,max(nCC,1)))'
   * Referenced by: '<S2>/umin_scale4'
   */
  { 4.0, 40.0 },

  /* Expression: zeros(1,2)
   * Referenced by: '<S1>/F_zero'
   */
  { 0.0, 0.0 },

  /* Expression: Yscale(:,ones(1,max(nCC,1)))'
   * Referenced by: '<S2>/ymin_scale1'
   */
  { 1.0, 1.0 },

  /* Expression: zeros(1,1)
   * Referenced by: '<S1>/G_zero'
   */
  0.0,

  /* Expression: zeros(1,1)
   * Referenced by: '<S1>/S_zero'
   */
  0.0,

  /* Expression: MDscale(:,ones(1,max(nCC,1)))'
   * Referenced by: '<S2>/ymin_scale2'
   */
  1.0,

  /* Expression: zeros(1,1)
   * Referenced by: '<S1>/switch_zero'
   */
  0.0,

  /* Expression: zeros(2,1)
   * Referenced by: '<S1>/ext.mv_zero'
   */
  { 0.0, 0.0 },

  /* Expression: RMVscale
   * Referenced by: '<S2>/ext.mv_scale'
   */
  { 0.25, 0.025 },

  /* Expression: zeros(2,1)
   * Referenced by: '<S1>/mv.target_zero'
   */
  { 0.0, 0.0 },

  /* Expression: RMVscale
   * Referenced by: '<S2>/ext.mv_scale1'
   */
  { 0.25, 0.025 },

  /* Expression: zeros(2,1)
   * Referenced by: '<S1>/y.wt_zero'
   */
  { 0.0, 0.0 },

  /* Expression: zeros(2,1)
   * Referenced by: '<S1>/u.wt_zero'
   */
  { 0.0, 0.0 },

  /* Expression: zeros(2,1)
   * Referenced by: '<S1>/du.wt_zero'
   */
  { 0.0, 0.0 },

  /* Expression: zeros(1,1)
   * Referenced by: '<S1>/ecr.wt_zero'
   */
  0.0,

  /* Expression: MVscale
   * Referenced by: '<S2>/umin_scale1'
   */
  { 4.0, 40.0 },

  /* Expression: iA
   * Referenced by: '<S2>/Memory'
   */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};
