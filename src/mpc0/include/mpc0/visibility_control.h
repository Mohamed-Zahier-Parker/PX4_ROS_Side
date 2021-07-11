#ifndef MPC0__VISIBILITY_CONTROL_H_
#define MPC0__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define MPC0_EXPORT __attribute__ ((dllexport))
    #define MPC0_IMPORT __attribute__ ((dllimport))
  #else
    #define MPC0_EXPORT __declspec(dllexport)
    #define MPC0_IMPORT __declspec(dllimport)
  #endif
  #ifdef MPC0_BUILDING_LIBRARY
    #define MPC0_PUBLIC MPC0_EXPORT
  #else
    #define MPC0_PUBLIC MPC0_IMPORT
  #endif
  #define MPC0_PUBLIC_TYPE MPC0_PUBLIC
  #define MPC0_LOCAL
#else
  #define MPC0_EXPORT __attribute__ ((visibility("default")))
  #define MPC0_IMPORT
  #if __GNUC__ >= 4
    #define MPC0_PUBLIC __attribute__ ((visibility("default")))
    #define MPC0_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define MPC0_PUBLIC
    #define MPC0_LOCAL
  #endif
  #define MPC0_PUBLIC_TYPE
#endif
#endif  // MPC0__VISIBILITY_CONTROL_H_
// Generated 04-Jul-2021 17:00:24
// Copyright 2019-2020 The MathWorks, Inc.
