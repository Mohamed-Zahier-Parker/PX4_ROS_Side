/*
 * MPC0.h
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

#ifndef RTW_HEADER_MPC0_h_
#define RTW_HEADER_MPC0_h_
#include <cmath>
#include <cstring>
#include <cfloat>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "MPC0_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T last_x[10];                   /* '<S2>/last_x' */
  real_T last_mv[2];                   /* '<S2>/last_mv' */
  real_T umin_scale4[2];               /* '<S2>/umin_scale4' */
  real_T ymin_scale1[2];               /* '<S2>/ymin_scale1' */
  real_T ymin_scale2;                  /* '<S2>/ymin_scale2' */
  real_T extmv_scale[2];               /* '<S2>/ext.mv_scale' */
  real_T extmv_scale1[2];              /* '<S2>/ext.mv_scale1' */
  real_T MathFunction[2];              /* '<S2>/Math Function' */
  real_T MathFunction1[2];             /* '<S2>/Math Function1' */
  real_T MathFunction2[2];             /* '<S2>/Math Function2' */
  real_T umin_scale1[2];               /* '<S2>/umin_scale1' */
  real_T xk1[10];                      /* '<S22>/optimizer' */
  real_T u[2];                         /* '<S22>/optimizer' */
  real_T cost;                         /* '<S22>/optimizer' */
  real_T useq[40];                     /* '<S22>/optimizer' */
  real_T xseq[200];                    /* '<S22>/optimizer' */
  real_T yseq[40];                     /* '<S22>/optimizer' */
  real_T status;                       /* '<S22>/optimizer' */
  real_T xest[10];                     /* '<S22>/optimizer' */
  boolean_T Memory[16];                /* '<S2>/Memory' */
  boolean_T iAout[16];                 /* '<S22>/optimizer' */
} B_MPC0_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T last_mv_DSTATE[2];            /* '<S2>/last_mv' */
  real_T last_x_PreviousInput[10];     /* '<S2>/last_x' */
  boolean_T Memory_PreviousInput[16];  /* '<S2>/Memory' */
} DW_MPC0_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T moorx[2];                     /* '<Root>/mo or x' */
  real_T ref_out[38];                  /* '<Root>/ref' */
} ExtU_MPC0_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T mv[2];                        /* '<Root>/mv' */
} ExtY_MPC0_T;

/* Parameters (default storage) */
struct P_MPC0_T_ {
  real_T last_x_InitialCondition[10];  /* Expression: lastx+xoff
                                        * Referenced by: '<S2>/last_x'
                                        */
  real_T last_mv_InitialCondition[2];  /* Expression: lastu+uoff
                                        * Referenced by: '<S2>/last_mv'
                                        */
  real_T md_zero_Value;                /* Expression: zeros(1,1)
                                        * Referenced by: '<S1>/md_zero'
                                        */
  real_T umin_zero_Value[2];           /* Expression: zeros(2,1)
                                        * Referenced by: '<S1>/umin_zero'
                                        */
  real_T umax_zero_Value[2];           /* Expression: zeros(2,1)
                                        * Referenced by: '<S1>/umax_zero'
                                        */
  real_T ymin_zero_Value[2];           /* Expression: zeros(2,1)
                                        * Referenced by: '<S1>/ymin_zero'
                                        */
  real_T ymax_zero_Value[2];           /* Expression: zeros(2,1)
                                        * Referenced by: '<S1>/ymax_zero'
                                        */
  real_T E_zero_Value[2];              /* Expression: zeros(1,2)
                                        * Referenced by: '<S1>/E_zero'
                                        */
  real_T umin_scale4_Gain[2];      /* Expression: MVscale(:,ones(1,max(nCC,1)))'
                                    * Referenced by: '<S2>/umin_scale4'
                                    */
  real_T F_zero_Value[2];              /* Expression: zeros(1,2)
                                        * Referenced by: '<S1>/F_zero'
                                        */
  real_T ymin_scale1_Gain[2];       /* Expression: Yscale(:,ones(1,max(nCC,1)))'
                                     * Referenced by: '<S2>/ymin_scale1'
                                     */
  real_T G_zero_Value;                 /* Expression: zeros(1,1)
                                        * Referenced by: '<S1>/G_zero'
                                        */
  real_T S_zero_Value;                 /* Expression: zeros(1,1)
                                        * Referenced by: '<S1>/S_zero'
                                        */
  real_T ymin_scale2_Gain;         /* Expression: MDscale(:,ones(1,max(nCC,1)))'
                                    * Referenced by: '<S2>/ymin_scale2'
                                    */
  real_T switch_zero_Value;            /* Expression: zeros(1,1)
                                        * Referenced by: '<S1>/switch_zero'
                                        */
  real_T extmv_zero_Value[2];          /* Expression: zeros(2,1)
                                        * Referenced by: '<S1>/ext.mv_zero'
                                        */
  real_T extmv_scale_Gain[2];          /* Expression: RMVscale
                                        * Referenced by: '<S2>/ext.mv_scale'
                                        */
  real_T mvtarget_zero_Value[2];       /* Expression: zeros(2,1)
                                        * Referenced by: '<S1>/mv.target_zero'
                                        */
  real_T extmv_scale1_Gain[2];         /* Expression: RMVscale
                                        * Referenced by: '<S2>/ext.mv_scale1'
                                        */
  real_T ywt_zero_Value[2];            /* Expression: zeros(2,1)
                                        * Referenced by: '<S1>/y.wt_zero'
                                        */
  real_T uwt_zero_Value[2];            /* Expression: zeros(2,1)
                                        * Referenced by: '<S1>/u.wt_zero'
                                        */
  real_T duwt_zero_Value[2];           /* Expression: zeros(2,1)
                                        * Referenced by: '<S1>/du.wt_zero'
                                        */
  real_T ecrwt_zero_Value;             /* Expression: zeros(1,1)
                                        * Referenced by: '<S1>/ecr.wt_zero'
                                        */
  real_T umin_scale1_Gain[2];          /* Expression: MVscale
                                        * Referenced by: '<S2>/umin_scale1'
                                        */
  boolean_T Memory_InitialCondition[16];/* Expression: iA
                                         * Referenced by: '<S2>/Memory'
                                         */
};

/* Real-time Model Data Structure */
struct tag_RTM_MPC0_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern P_MPC0_T MPC0_P;

#ifdef __cplusplus

}
#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern B_MPC0_T MPC0_B;

#ifdef __cplusplus

}
#endif

/* Block states (default storage) */
extern DW_MPC0_T MPC0_DW;

#ifdef __cplusplus

extern "C" {

#endif

  /* External inputs (root inport signals with default storage) */
  extern ExtU_MPC0_T MPC0_U;

  /* External outputs (root outports fed by signals with default storage) */
  extern ExtY_MPC0_T MPC0_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void MPC0_initialize(void);
  extern void MPC0_step(void);
  extern void MPC0_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_MPC0_T *const MPC0_M;

#ifdef __cplusplus

}
#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Conversion14' : Unused code path elimination
 * Block '<S2>/Data Type Conversion15' : Unused code path elimination
 * Block '<S3>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S4>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S5>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S6>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S7>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S8>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S9>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S10>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S11>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S12>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S13>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S14>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S15>/Vector Dimension Check' : Unused code path elimination
 * Block '<S16>/Vector Dimension Check' : Unused code path elimination
 * Block '<S17>/Vector Dimension Check' : Unused code path elimination
 * Block '<S18>/Vector Dimension Check' : Unused code path elimination
 * Block '<S19>/Vector Dimension Check' : Unused code path elimination
 * Block '<S20>/Vector Dimension Check' : Unused code path elimination
 * Block '<S21>/Vector Dimension Check' : Unused code path elimination
 * Block '<S2>/constant' : Unused code path elimination
 * Block '<S2>/umin_scale2' : Unused code path elimination
 * Block '<S2>/umin_scale3' : Unused code path elimination
 * Block '<S2>/umin_scale5' : Unused code path elimination
 * Block '<S2>/ym_zero' : Unused code path elimination
 * Block '<S1>/m_zero' : Unused code path elimination
 * Block '<S1>/p_zero' : Unused code path elimination
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion10' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion11' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion12' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion13' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion6' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion9' : Eliminate redundant data type conversion
 * Block '<S2>/E Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/F Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/G Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/Reshape' : Reshape block reduction
 * Block '<S2>/Reshape1' : Reshape block reduction
 * Block '<S2>/Reshape2' : Reshape block reduction
 * Block '<S2>/Reshape3' : Reshape block reduction
 * Block '<S2>/Reshape4' : Reshape block reduction
 * Block '<S2>/Reshape5' : Reshape block reduction
 * Block '<S2>/S Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/mo or x Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Moving_Platform_Landing_land_point_tracking/MPC Controller')    - opens subsystem Moving_Platform_Landing_land_point_tracking/MPC Controller
 * hilite_system('Moving_Platform_Landing_land_point_tracking/MPC Controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Moving_Platform_Landing_land_point_tracking'
 * '<S1>'   : 'Moving_Platform_Landing_land_point_tracking/MPC Controller'
 * '<S2>'   : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC'
 * '<S3>'   : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Matrix Signal Check'
 * '<S4>'   : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Matrix Signal Check1'
 * '<S5>'   : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Matrix Signal Check2'
 * '<S6>'   : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Preview Signal Check'
 * '<S7>'   : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Preview Signal Check1'
 * '<S8>'   : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Preview Signal Check2'
 * '<S9>'   : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Preview Signal Check3'
 * '<S10>'  : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Preview Signal Check4'
 * '<S11>'  : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Preview Signal Check5'
 * '<S12>'  : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Preview Signal Check6'
 * '<S13>'  : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Preview Signal Check7'
 * '<S14>'  : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Preview Signal Check8'
 * '<S15>'  : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Scalar Signal Check'
 * '<S16>'  : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Scalar Signal Check1'
 * '<S17>'  : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Scalar Signal Check2'
 * '<S18>'  : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Vector Signal Check'
 * '<S19>'  : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Vector Signal Check1'
 * '<S20>'  : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Vector Signal Check11'
 * '<S21>'  : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/MPC Vector Signal Check6'
 * '<S22>'  : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/optimizer'
 * '<S23>'  : 'Moving_Platform_Landing_land_point_tracking/MPC Controller/MPC/optimizer/optimizer'
 */
#endif                                 /* RTW_HEADER_MPC0_h_ */
