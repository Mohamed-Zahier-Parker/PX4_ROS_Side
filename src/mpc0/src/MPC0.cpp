/*
 * MPC0.cpp
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

/* Block signals (default storage) */
B_MPC0_T MPC0_B;

/* Block states (default storage) */
DW_MPC0_T MPC0_DW;

/* External inputs (root inport signals with default storage) */
ExtU_MPC0_T MPC0_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_MPC0_T MPC0_Y;

/* Real-time model */
RT_MODEL_MPC0_T MPC0_M_ = RT_MODEL_MPC0_T();
RT_MODEL_MPC0_T *const MPC0_M = &MPC0_M_;

/* Forward declaration for local functions */
static void MPC0_Unconstrained(const real_T b_Hinv[81], const real_T f[9],
  real_T x[9], int16_T n);
static real_T MPC0_norm(const real_T x[9]);
static void MPC0_abs(const real_T x[9], real_T y[9]);
static real_T MPC0_maximum(const real_T x[9]);
static void MPC0_abs_a(const real_T x[16], real_T y[16]);
static void MPC0_maximum2(const real_T x[16], real_T y, real_T ex[16]);
static real_T MPC0_xnrm2(int32_T n, const real_T x[81], int32_T ix0);
static void MPC0_xgemv(int32_T b_m, int32_T n, const real_T b_A[81], int32_T ia0,
  const real_T x[81], int32_T ix0, real_T y[9]);
static void MPC0_xgerc(int32_T b_m, int32_T n, real_T alpha1, int32_T ix0, const
  real_T y[9], real_T b_A[81], int32_T ia0);
static void MPC0_xgeqrf(real_T b_A[81], real_T tau[9]);
static void MPC0_qr(const real_T b_A[81], real_T Q[81], real_T R[81]);
static real_T MPC0_KWIKfactor(const real_T b_Ac[144], const int16_T iC[16],
  int16_T nA, const real_T b_Linv[81], real_T RLinv[81], real_T D[81], real_T
  b_H[81], int16_T n);
static real_T MPC0_mtimes(const real_T b_A[9], const real_T B[9]);
static void MPC0_DropConstraint(int16_T kDrop, int16_T iA[16], int16_T *nA,
  int16_T iC[16]);
static void MPC0_qpkwik(const real_T b_Linv[81], const real_T b_Hinv[81], const
  real_T f[9], const real_T b_Ac[144], const real_T b[16], int16_T iA[16],
  int16_T maxiter, real_T FeasTol, real_T x[9], real_T lambda[16], real_T
  *status);
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (MPC0_M->Timing.TaskCounters.TID[1])++;
  if ((MPC0_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.04s, 0.0s] */
    MPC0_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Function for MATLAB Function: '<S22>/optimizer' */
static void MPC0_Unconstrained(const real_T b_Hinv[81], const real_T f[9],
  real_T x[9], int16_T n)
{
  real_T b_Hinv_0;
  int32_T i;
  int32_T i_0;
  int32_T i_1;
  for (i = 1; i - 1 < n; i++) {
    i_0 = static_cast<int16_T>(i);
    b_Hinv_0 = 0.0;
    for (i_1 = 0; i_1 < 9; i_1++) {
      b_Hinv_0 += -b_Hinv[(9 * i_1 + i_0) - 1] * f[i_1];
    }

    x[static_cast<int16_T>(i) - 1] = b_Hinv_0;
  }
}

/* Function for MATLAB Function: '<S22>/optimizer' */
static real_T MPC0_norm(const real_T x[9])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 9; k++) {
    absxk = std::abs(x[k]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * std::sqrt(y);
}

/* Function for MATLAB Function: '<S22>/optimizer' */
static void MPC0_abs(const real_T x[9], real_T y[9])
{
  int32_T k;
  for (k = 0; k < 9; k++) {
    y[k] = std::abs(x[k]);
  }
}

/* Function for MATLAB Function: '<S22>/optimizer' */
static real_T MPC0_maximum(const real_T x[9])
{
  real_T ex;
  int32_T idx;
  int32_T k;
  boolean_T exitg1;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    while (idx + 1 <= 9) {
      if (ex < x[idx]) {
        ex = x[idx];
      }

      idx++;
    }
  }

  return ex;
}

/* Function for MATLAB Function: '<S22>/optimizer' */
static void MPC0_abs_a(const real_T x[16], real_T y[16])
{
  int32_T k;
  for (k = 0; k < 16; k++) {
    y[k] = std::abs(x[k]);
  }
}

/* Function for MATLAB Function: '<S22>/optimizer' */
static void MPC0_maximum2(const real_T x[16], real_T y, real_T ex[16])
{
  real_T u0;
  int32_T k;
  for (k = 0; k < 16; k++) {
    u0 = x[k];
    if ((!(u0 > y)) && (!rtIsNaN(y))) {
      u0 = y;
    }

    ex[k] = u0;
  }
}

/* Function for MATLAB Function: '<S22>/optimizer' */
static real_T MPC0_xnrm2(int32_T n, const real_T x[81], int32_T ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = std::abs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * std::sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T y;
  a = std::abs(u0);
  y = std::abs(u1);
  if (a < y) {
    a /= y;
    y *= std::sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = std::sqrt(y * y + 1.0) * a;
  } else {
    if (!rtIsNaN(y)) {
      y = a * 1.4142135623730951;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S22>/optimizer' */
static void MPC0_xgemv(int32_T b_m, int32_T n, const real_T b_A[81], int32_T ia0,
  const real_T x[81], int32_T ix0, real_T y[9])
{
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T d;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  if ((b_m != 0) && (n != 0)) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n - 1) * 9 + ia0;
    for (iac = ia0; iac <= b; iac += 9) {
      ix = ix0;
      c = 0.0;
      d = (iac + b_m) - 1;
      for (ia = iac; ia <= d; ia++) {
        c += b_A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[b_iy] += c;
      b_iy++;
    }
  }
}

/* Function for MATLAB Function: '<S22>/optimizer' */
static void MPC0_xgerc(int32_T b_m, int32_T n, real_T alpha1, int32_T ix0, const
  real_T y[9], real_T b_A[81], int32_T ia0)
{
  real_T temp;
  int32_T b;
  int32_T ijA;
  int32_T ix;
  int32_T j;
  int32_T jA;
  int32_T jy;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y[jy] != 0.0) {
        temp = y[jy] * alpha1;
        ix = ix0;
        b = b_m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          b_A[ijA] += b_A[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += 9;
    }
  }
}

/* Function for MATLAB Function: '<S22>/optimizer' */
static void MPC0_xgeqrf(real_T b_A[81], real_T tau[9])
{
  real_T work[9];
  real_T b;
  real_T b_atmp;
  real_T xnorm;
  int32_T coltop;
  int32_T exitg1;
  int32_T i;
  int32_T ia;
  int32_T ii;
  int32_T knt;
  int32_T lastc;
  boolean_T exitg2;
  std::memset(&tau[0], 0, 9U * sizeof(real_T));
  std::memset(&work[0], 0, 9U * sizeof(real_T));
  for (i = 0; i < 9; i++) {
    ii = i * 9 + i;
    if (i + 1 < 9) {
      b_atmp = b_A[ii];
      b = 0.0;
      xnorm = MPC0_xnrm2(8 - i, b_A, ii + 2);
      if (xnorm != 0.0) {
        xnorm = rt_hypotd_snf(b_A[ii], xnorm);
        if (b_A[ii] >= 0.0) {
          xnorm = -xnorm;
        }

        if (std::abs(xnorm) < 1.0020841800044864E-292) {
          knt = -1;
          lastc = ii - i;
          do {
            knt++;
            for (coltop = ii + 1; coltop < lastc + 9; coltop++) {
              b_A[coltop] *= 9.9792015476736E+291;
            }

            xnorm *= 9.9792015476736E+291;
            b_atmp *= 9.9792015476736E+291;
          } while (!(std::abs(xnorm) >= 1.0020841800044864E-292));

          xnorm = rt_hypotd_snf(b_atmp, MPC0_xnrm2(8 - i, b_A, ii + 2));
          if (b_atmp >= 0.0) {
            xnorm = -xnorm;
          }

          b = (xnorm - b_atmp) / xnorm;
          b_atmp = 1.0 / (b_atmp - xnorm);
          lastc = ii - i;
          for (coltop = ii + 1; coltop < lastc + 9; coltop++) {
            b_A[coltop] *= b_atmp;
          }

          for (lastc = 0; lastc <= knt; lastc++) {
            xnorm *= 1.0020841800044864E-292;
          }

          b_atmp = xnorm;
        } else {
          b = (xnorm - b_A[ii]) / xnorm;
          b_atmp = 1.0 / (b_A[ii] - xnorm);
          knt = ii - i;
          for (lastc = ii + 1; lastc < knt + 9; lastc++) {
            b_A[lastc] *= b_atmp;
          }

          b_atmp = xnorm;
        }
      }

      tau[i] = b;
      b_A[ii] = b_atmp;
      b_atmp = b_A[ii];
      b_A[ii] = 1.0;
      if (tau[i] != 0.0) {
        knt = 9 - i;
        lastc = ii - i;
        while ((knt > 0) && (b_A[lastc + 8] == 0.0)) {
          knt--;
          lastc--;
        }

        lastc = 8 - i;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          coltop = ((lastc - 1) * 9 + ii) + 9;
          ia = coltop;
          do {
            exitg1 = 0;
            if (ia + 1 <= coltop + knt) {
              if (b_A[ia] != 0.0) {
                exitg1 = 1;
              } else {
                ia++;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        knt = 0;
        lastc = 0;
      }

      if (knt > 0) {
        MPC0_xgemv(knt, lastc, b_A, ii + 10, b_A, ii + 1, work);
        MPC0_xgerc(knt, lastc, -tau[i], ii + 1, work, b_A, ii + 10);
      }

      b_A[ii] = b_atmp;
    } else {
      tau[8] = 0.0;
    }
  }
}

/* Function for MATLAB Function: '<S22>/optimizer' */
static void MPC0_qr(const real_T b_A[81], real_T Q[81], real_T R[81])
{
  real_T c_A[81];
  real_T tau[9];
  real_T work[9];
  int32_T coltop;
  int32_T d_i;
  int32_T exitg1;
  int32_T ia;
  int32_T iaii;
  int32_T itau;
  int32_T lastc;
  int32_T lastv;
  boolean_T exitg2;
  std::memcpy(&c_A[0], &b_A[0], 81U * sizeof(real_T));
  MPC0_xgeqrf(c_A, tau);
  for (itau = 0; itau < 9; itau++) {
    for (d_i = 0; d_i <= itau; d_i++) {
      R[d_i + 9 * itau] = c_A[9 * itau + d_i];
    }

    for (d_i = itau + 1; d_i + 1 < 10; d_i++) {
      R[d_i + 9 * itau] = 0.0;
    }

    work[itau] = 0.0;
  }

  itau = 8;
  for (d_i = 8; d_i >= 0; d_i--) {
    iaii = (d_i * 9 + d_i) + 10;
    if (d_i + 1 < 9) {
      c_A[iaii - 10] = 1.0;
      if (tau[itau] != 0.0) {
        lastv = 9 - d_i;
        lastc = iaii - d_i;
        while ((lastv > 0) && (c_A[lastc - 2] == 0.0)) {
          lastv--;
          lastc--;
        }

        lastc = 8 - d_i;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          coltop = (lastc - 1) * 9 + iaii;
          ia = coltop;
          do {
            exitg1 = 0;
            if (ia <= (coltop + lastv) - 1) {
              if (c_A[ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                ia++;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = 0;
        lastc = 0;
      }

      if (lastv > 0) {
        MPC0_xgemv(lastv, lastc, c_A, iaii, c_A, iaii - 9, work);
        MPC0_xgerc(lastv, lastc, -tau[itau], iaii - 9, work, c_A, iaii);
      }

      lastv = (iaii - d_i) - 1;
      for (lastc = iaii - 9; lastc < lastv; lastc++) {
        c_A[lastc] *= -tau[itau];
      }
    }

    c_A[iaii - 10] = 1.0 - tau[itau];
    for (lastv = 0; lastv < d_i; lastv++) {
      c_A[(iaii - lastv) - 11] = 0.0;
    }

    itau--;
  }

  for (itau = 0; itau < 9; itau++) {
    std::memcpy(&Q[itau * 9], &c_A[itau * 9], 9U * sizeof(real_T));
  }
}

/* Function for MATLAB Function: '<S22>/optimizer' */
static real_T MPC0_KWIKfactor(const real_T b_Ac[144], const int16_T iC[16],
  int16_T nA, const real_T b_Linv[81], real_T RLinv[81], real_T D[81], real_T
  b_H[81], int16_T n)
{
  real_T QQ[81];
  real_T RR[81];
  real_T TL[81];
  real_T Status;
  real_T b_Linv_0;
  int32_T exitg1;
  int32_T f_i;
  int32_T f_i_0;
  int32_T i;
  int32_T i_0;
  int32_T i_1;
  int16_T b_j;
  int16_T c_k;
  Status = 1.0;
  std::memset(&RLinv[0], 0, 81U * sizeof(real_T));
  for (i = 1; i - 1 < nA; i++) {
    f_i_0 = iC[static_cast<int16_T>(i) - 1];
    i_0 = static_cast<int16_T>(i) - 1;
    for (i_1 = 0; i_1 < 9; i_1++) {
      RLinv[i_1 + 9 * i_0] = 0.0;
      for (f_i = 0; f_i < 9; f_i++) {
        RLinv[i_1 + 9 * i_0] += b_Ac[((f_i << 4) + f_i_0) - 1] * b_Linv[9 * f_i
          + i_1];
      }
    }
  }

  MPC0_qr(RLinv, QQ, RR);
  i = 1;
  do {
    exitg1 = 0;
    if (i - 1 <= nA - 1) {
      if (std::abs(RR[((static_cast<int16_T>(i) - 1) * 9 + static_cast<int16_T>
                       (i)) - 1]) < 1.0E-12) {
        Status = -2.0;
        exitg1 = 1;
      } else {
        i++;
      }
    } else {
      for (i = 1; i - 1 < n; i++) {
        for (f_i = 1; f_i - 1 < n; f_i++) {
          i_0 = static_cast<int16_T>(i);
          f_i_0 = static_cast<int16_T>(f_i);
          b_Linv_0 = 0.0;
          for (i_1 = 0; i_1 < 9; i_1++) {
            b_Linv_0 += b_Linv[(i_0 - 1) * 9 + i_1] * QQ[(f_i_0 - 1) * 9 + i_1];
          }

          TL[(static_cast<int16_T>(i) + 9 * (static_cast<int16_T>(f_i) - 1)) - 1]
            = b_Linv_0;
        }
      }

      std::memset(&RLinv[0], 0, 81U * sizeof(real_T));
      for (b_j = nA; b_j > 0; b_j = static_cast<int16_T>(b_j - 1)) {
        RLinv[(b_j + 9 * (b_j - 1)) - 1] = 1.0;
        for (c_k = b_j; c_k <= nA; c_k = static_cast<int16_T>(c_k + 1)) {
          RLinv[(b_j + 9 * (c_k - 1)) - 1] /= RR[((b_j - 1) * 9 + b_j) - 1];
        }

        if (b_j > 1) {
          for (i = 1; i - 1 <= b_j - 2; i++) {
            for (c_k = b_j; c_k <= nA; c_k = static_cast<int16_T>(c_k + 1)) {
              RLinv[(static_cast<int16_T>(i) + 9 * (c_k - 1)) - 1] -= RR[((b_j -
                1) * 9 + static_cast<int16_T>(i)) - 1] * RLinv[((c_k - 1) * 9 +
                b_j) - 1];
            }
          }
        }
      }

      for (i = 1; i - 1 < n; i++) {
        for (b_j = static_cast<int16_T>(i); b_j <= n; b_j = static_cast<int16_T>
             (b_j + 1)) {
          b_H[(static_cast<int16_T>(i) + 9 * (b_j - 1)) - 1] = 0.0;
          i_1 = nA + 1;
          if (i_1 > 32767) {
            i_1 = 32767;
          }

          for (c_k = static_cast<int16_T>(i_1); c_k <= n; c_k =
               static_cast<int16_T>(c_k + 1)) {
            b_H[(static_cast<int16_T>(i) + 9 * (b_j - 1)) - 1] -= TL[((c_k - 1) *
              9 + static_cast<int16_T>(i)) - 1] * TL[((c_k - 1) * 9 + b_j) - 1];
          }

          b_H[(b_j + 9 * (static_cast<int16_T>(i) - 1)) - 1] = b_H[((b_j - 1) *
            9 + static_cast<int16_T>(i)) - 1];
        }
      }

      for (i = 1; i - 1 < nA; i++) {
        for (f_i = 1; f_i - 1 < n; f_i++) {
          D[(static_cast<int16_T>(f_i) + 9 * (static_cast<int16_T>(i) - 1)) - 1]
            = 0.0;
          for (b_j = static_cast<int16_T>(i); b_j <= nA; b_j =
               static_cast<int16_T>(b_j + 1)) {
            D[(static_cast<int16_T>(f_i) + 9 * (static_cast<int16_T>(i) - 1)) -
              1] += TL[((b_j - 1) * 9 + static_cast<int16_T>(f_i)) - 1] * RLinv
              [((b_j - 1) * 9 + static_cast<int16_T>(i)) - 1];
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return Status;
}

/* Function for MATLAB Function: '<S22>/optimizer' */
static real_T MPC0_mtimes(const real_T b_A[9], const real_T B[9])
{
  real_T b_C;
  int32_T k;
  b_C = 0.0;
  for (k = 0; k < 9; k++) {
    b_C += b_A[k] * B[k];
  }

  return b_C;
}

/* Function for MATLAB Function: '<S22>/optimizer' */
static void MPC0_DropConstraint(int16_T kDrop, int16_T iA[16], int16_T *nA,
  int16_T iC[16])
{
  int32_T tmp;
  int16_T b;
  int16_T i;
  iA[iC[kDrop - 1] - 1] = 0;
  if (kDrop < *nA) {
    tmp = *nA - 1;
    if (tmp < -32768) {
      tmp = -32768;
    }

    b = static_cast<int16_T>(tmp);
    for (i = kDrop; i <= b; i = static_cast<int16_T>(i + 1)) {
      iC[i - 1] = iC[i];
    }
  }

  iC[*nA - 1] = 0;
  tmp = *nA - 1;
  if (tmp < -32768) {
    tmp = -32768;
  }

  *nA = static_cast<int16_T>(tmp);
}

/* Function for MATLAB Function: '<S22>/optimizer' */
static void MPC0_qpkwik(const real_T b_Linv[81], const real_T b_Hinv[81], const
  real_T f[9], const real_T b_Ac[144], const real_T b[16], int16_T iA[16],
  int16_T maxiter, real_T FeasTol, real_T x[9], real_T lambda[16], real_T
  *status)
{
  real_T D[81];
  real_T RLinv[81];
  real_T U[81];
  real_T b_H[81];
  real_T Opt[18];
  real_T Rhs[18];
  real_T cTol[16];
  real_T tmp[16];
  real_T b_Ac_0[9];
  real_T r[9];
  real_T z[9];
  real_T Xnorm0;
  real_T b_Ac_1;
  real_T cMin;
  real_T cVal;
  real_T rMin;
  real_T t;
  int32_T exitg1;
  int32_T exitg3;
  int32_T i;
  int32_T i_0;
  int32_T i_1;
  int32_T kNext_0;
  int32_T tmp_0;
  int16_T iC[16];
  int16_T iSave;
  int16_T kDrop;
  int16_T kNext;
  int16_T nA;
  uint16_T b_x;
  uint16_T q;
  boolean_T ColdReset;
  boolean_T DualFeasible;
  boolean_T cTolComputed;
  boolean_T exitg2;
  boolean_T exitg4;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  *status = 1.0;
  std::memset(&lambda[0], 0, sizeof(real_T) << 4U);
  std::memset(&x[0], 0, 9U * sizeof(real_T));
  std::memset(&r[0], 0, 9U * sizeof(real_T));
  rMin = 0.0;
  cTolComputed = false;
  for (i = 0; i < 16; i++) {
    cTol[i] = 1.0;
    iC[i] = 0;
  }

  nA = 0;
  for (i = 0; i < 16; i++) {
    if (iA[i] == 1) {
      i_1 = nA + 1;
      if (i_1 > 32767) {
        i_1 = 32767;
      }

      nA = static_cast<int16_T>(i_1);
      iC[nA - 1] = static_cast<int16_T>(i + 1);
    }
  }

  guard1 = false;
  if (nA > 0) {
    std::memset(&Opt[0], 0, 18U * sizeof(real_T));
    for (i = 0; i < 9; i++) {
      Rhs[i] = f[i];
      Rhs[i + 9] = 0.0;
    }

    DualFeasible = false;
    i_1 = 3 * nA;
    if (i_1 > 32767) {
      i_1 = 32767;
    }

    kNext = static_cast<int16_T>(i_1);
    if (kNext <= 50) {
      kNext = 50;
    }

    q = static_cast<uint16_T>(kNext / 10U);
    b_x = static_cast<uint16_T>(static_cast<uint32_T>(kNext) - q * 10);
    if ((b_x > 0) && (b_x >= 5)) {
      q = static_cast<uint16_T>(q + 1);
    }

    ColdReset = false;
    do {
      exitg3 = 0;
      if ((!DualFeasible) && (nA > 0) && (static_cast<int32_T>(*status) <=
           maxiter)) {
        Xnorm0 = MPC0_KWIKfactor(b_Ac, iC, nA, b_Linv, RLinv, D, b_H, 9);
        if (Xnorm0 < 0.0) {
          if (ColdReset) {
            *status = -2.0;
            exitg3 = 2;
          } else {
            nA = 0;
            for (i = 0; i < 16; i++) {
              iA[i] = 0;
              iC[i] = 0;
            }

            ColdReset = true;
          }
        } else {
          for (i = 1; i - 1 < nA; i++) {
            i_1 = static_cast<int16_T>(i) + 9;
            if (i_1 > 32767) {
              i_1 = 32767;
            }

            Rhs[i_1 - 1] = b[iC[static_cast<int16_T>(i) - 1] - 1];
            for (kNext = static_cast<int16_T>(i); kNext <= nA; kNext =
                 static_cast<int16_T>(kNext + 1)) {
              U[(kNext + 9 * (static_cast<int16_T>(i) - 1)) - 1] = 0.0;
              for (kNext_0 = 1; kNext_0 - 1 < nA; kNext_0++) {
                U[(kNext + 9 * (static_cast<int16_T>(i) - 1)) - 1] += RLinv[((
                  static_cast<int16_T>(kNext_0) - 1) * 9 + kNext) - 1] * RLinv
                  [((static_cast<int16_T>(kNext_0) - 1) * 9 +
                    static_cast<int16_T>(i)) - 1];
              }

              U[(static_cast<int16_T>(i) + 9 * (kNext - 1)) - 1] = U[((
                static_cast<int16_T>(i) - 1) * 9 + kNext) - 1];
            }
          }

          for (i = 0; i < 9; i++) {
            i_0 = i + 1;
            Xnorm0 = 0.0;
            for (i_1 = 0; i_1 < 9; i_1++) {
              Xnorm0 += b_H[(9 * i_1 + i_0) - 1] * Rhs[i_1];
            }

            Opt[i] = Xnorm0;
            for (kNext_0 = 1; kNext_0 - 1 < nA; kNext_0++) {
              i_1 = static_cast<int16_T>(kNext_0) + 9;
              if (i_1 > 32767) {
                i_1 = 32767;
              }

              Opt[i] += D[(static_cast<int16_T>(kNext_0) - 1) * 9 + i] * Rhs[i_1
                - 1];
            }
          }

          for (i = 1; i - 1 < nA; i++) {
            i_0 = static_cast<int16_T>(i);
            Xnorm0 = 0.0;
            for (i_1 = 0; i_1 < 9; i_1++) {
              Xnorm0 += D[(i_0 - 1) * 9 + i_1] * Rhs[i_1];
            }

            i_1 = static_cast<int16_T>(i) + 9;
            if (i_1 > 32767) {
              i_1 = 32767;
            }

            Opt[i_1 - 1] = Xnorm0;
            for (kNext_0 = 1; kNext_0 - 1 < nA; kNext_0++) {
              i_1 = static_cast<int16_T>(i) + 9;
              if (i_1 > 32767) {
                i_1 = 32767;
              }

              i_0 = static_cast<int16_T>(i) + 9;
              if (i_0 > 32767) {
                i_0 = 32767;
              }

              tmp_0 = static_cast<int16_T>(kNext_0) + 9;
              if (tmp_0 > 32767) {
                tmp_0 = 32767;
              }

              Opt[i_1 - 1] = U[((static_cast<int16_T>(kNext_0) - 1) * 9 +
                                static_cast<int16_T>(i)) - 1] * Rhs[tmp_0 - 1] +
                Opt[i_0 - 1];
            }
          }

          Xnorm0 = -1.0E-12;
          kDrop = 0;
          for (i = 1; i - 1 < nA; i++) {
            i_1 = static_cast<int16_T>(i) + 9;
            if (i_1 > 32767) {
              i_1 = 32767;
            }

            lambda[iC[static_cast<int16_T>(i) - 1] - 1] = Opt[i_1 - 1];
            i_1 = static_cast<int16_T>(i) + 9;
            if (i_1 > 32767) {
              i_1 = 32767;
            }

            if ((Opt[i_1 - 1] < Xnorm0) && (static_cast<int16_T>(i) <= nA)) {
              kDrop = static_cast<int16_T>(i);
              i_1 = static_cast<int16_T>(i) + 9;
              if (i_1 > 32767) {
                i_1 = 32767;
              }

              Xnorm0 = Opt[i_1 - 1];
            }
          }

          if (kDrop <= 0) {
            DualFeasible = true;
            std::memcpy(&x[0], &Opt[0], 9U * sizeof(real_T));
          } else {
            (*status)++;
            if (static_cast<int32_T>(*status) > q) {
              nA = 0;
              for (i = 0; i < 16; i++) {
                iA[i] = 0;
                iC[i] = 0;
              }

              ColdReset = true;
            } else {
              lambda[iC[kDrop - 1] - 1] = 0.0;
              MPC0_DropConstraint(kDrop, iA, &nA, iC);
            }
          }
        }
      } else {
        if (nA <= 0) {
          std::memset(&lambda[0], 0, sizeof(real_T) << 4U);
          MPC0_Unconstrained(b_Hinv, f, x, 9);
        }

        exitg3 = 1;
      }
    } while (exitg3 == 0);

    if (exitg3 == 1) {
      guard1 = true;
    }
  } else {
    MPC0_Unconstrained(b_Hinv, f, x, 9);
    guard1 = true;
  }

  if (guard1) {
    Xnorm0 = MPC0_norm(x);
    exitg2 = false;
    while ((!exitg2) && (static_cast<int32_T>(*status) <= maxiter)) {
      cMin = -FeasTol;
      kNext = 0;
      for (i = 0; i < 16; i++) {
        t = cTol[i];
        if (!cTolComputed) {
          i_0 = i + 1;
          for (i_1 = 0; i_1 < 9; i_1++) {
            b_Ac_0[i_1] = b_Ac[((i_1 << 4) + i_0) - 1] * x[i_1];
          }

          MPC0_abs(b_Ac_0, z);
          cVal = MPC0_maximum(z);
          if ((t > cVal) || rtIsNaN(cVal)) {
            cVal = t;
          }

          t = cVal;
        }

        if (iA[i] == 0) {
          i_0 = i + 1;
          b_Ac_1 = 0.0;
          for (i_1 = 0; i_1 < 9; i_1++) {
            b_Ac_1 += b_Ac[((i_1 << 4) + i_0) - 1] * x[i_1];
          }

          cVal = (b_Ac_1 - b[i]) / t;
          if (cVal < cMin) {
            cMin = cVal;
            kNext = static_cast<int16_T>(i + 1);
          }
        }

        cTol[i] = t;
      }

      cTolComputed = true;
      if (kNext <= 0) {
        exitg2 = true;
      } else if (static_cast<int32_T>(*status) == maxiter) {
        *status = 0.0;
        exitg2 = true;
      } else {
        do {
          exitg1 = 0;
          if ((kNext > 0) && (static_cast<int32_T>(*status) <= maxiter)) {
            guard2 = false;
            if (nA == 0) {
              kNext_0 = kNext;
              for (i_1 = 0; i_1 < 9; i_1++) {
                z[i_1] = 0.0;
                for (i_0 = 0; i_0 < 9; i_0++) {
                  cMin = z[i_1];
                  cMin += b_Ac[((i_0 << 4) + kNext_0) - 1] * b_Hinv[9 * i_0 +
                    i_1];
                  z[i_1] = cMin;
                }
              }

              guard2 = true;
            } else {
              cMin = MPC0_KWIKfactor(b_Ac, iC, nA, b_Linv, RLinv, D, b_H, 9);
              if (cMin <= 0.0) {
                *status = -2.0;
                exitg1 = 1;
              } else {
                kNext_0 = kNext;
                for (i_1 = 0; i_1 < 81; i_1++) {
                  U[i_1] = -b_H[i_1];
                }

                for (i_1 = 0; i_1 < 9; i_1++) {
                  z[i_1] = 0.0;
                  for (i_0 = 0; i_0 < 9; i_0++) {
                    cMin = z[i_1];
                    cMin += b_Ac[((i_0 << 4) + kNext_0) - 1] * U[9 * i_0 + i_1];
                    z[i_1] = cMin;
                  }
                }

                for (i = 1; i - 1 < nA; i++) {
                  kNext_0 = kNext;
                  i_0 = static_cast<int16_T>(i);
                  b_Ac_1 = 0.0;
                  for (i_1 = 0; i_1 < 9; i_1++) {
                    b_Ac_1 += b_Ac[((i_1 << 4) + kNext_0) - 1] * D[(i_0 - 1) * 9
                      + i_1];
                  }

                  r[static_cast<int16_T>(i) - 1] = b_Ac_1;
                }

                guard2 = true;
              }
            }

            if (guard2) {
              kDrop = 0;
              cMin = 0.0;
              DualFeasible = true;
              ColdReset = true;
              if (nA > 0) {
                i = 0;
                exitg4 = false;
                while ((!exitg4) && (i <= nA - 1)) {
                  if (r[i] >= 1.0E-12) {
                    ColdReset = false;
                    exitg4 = true;
                  } else {
                    i++;
                  }
                }
              }

              ColdReset = ((nA == 0) || ColdReset);
              if (!ColdReset) {
                for (i = 1; i - 1 < nA; i++) {
                  if (r[static_cast<int16_T>(i) - 1] > 1.0E-12) {
                    cVal = lambda[iC[static_cast<int16_T>(i) - 1] - 1] / r[
                      static_cast<int16_T>(i) - 1];
                    if ((kDrop == 0) || (cVal < rMin)) {
                      rMin = cVal;
                      kDrop = static_cast<int16_T>(i);
                    }
                  }
                }

                if (kDrop > 0) {
                  cMin = rMin;
                  DualFeasible = false;
                }
              }

              kNext_0 = kNext;
              for (i_1 = 0; i_1 < 9; i_1++) {
                b_Ac_0[i_1] = b_Ac[((i_1 << 4) + kNext_0) - 1];
              }

              cVal = MPC0_mtimes(z, b_Ac_0);
              if (cVal <= 0.0) {
                cVal = 0.0;
                ColdReset = true;
              } else {
                kNext_0 = kNext;
                b_Ac_1 = 0.0;
                for (i_1 = 0; i_1 < 9; i_1++) {
                  b_Ac_1 += b_Ac[((i_1 << 4) + kNext_0) - 1] * x[i_1];
                }

                cVal = (b[kNext - 1] - b_Ac_1) / cVal;
                ColdReset = false;
              }

              if (DualFeasible && ColdReset) {
                *status = -1.0;
                exitg1 = 1;
              } else {
                if (ColdReset) {
                  t = cMin;
                } else if (DualFeasible) {
                  t = cVal;
                } else if ((cMin < cVal) || rtIsNaN(cVal)) {
                  t = cMin;
                } else {
                  t = cVal;
                }

                for (i = 1; i - 1 < nA; i++) {
                  lambda[iC[static_cast<int16_T>(i) - 1] - 1] -= r
                    [static_cast<int16_T>(i) - 1] * t;
                  if ((iC[static_cast<int16_T>(i) - 1] <= 16) && (lambda[iC[
                       static_cast<int16_T>(i) - 1] - 1] < 0.0)) {
                    lambda[iC[static_cast<int16_T>(i) - 1] - 1] = 0.0;
                  }
                }

                lambda[kNext - 1] += t;
                if (t == cMin) {
                  MPC0_DropConstraint(kDrop, iA, &nA, iC);
                }

                if (!ColdReset) {
                  for (i_1 = 0; i_1 < 9; i_1++) {
                    cMin = x[i_1];
                    cMin += t * z[i_1];
                    x[i_1] = cMin;
                  }

                  if (t == cVal) {
                    if (nA == 9) {
                      *status = -1.0;
                      exitg1 = 1;
                    } else {
                      i_1 = nA + 1;
                      if (i_1 > 32767) {
                        i_1 = 32767;
                      }

                      nA = static_cast<int16_T>(i_1);
                      iC[nA - 1] = kNext;
                      kDrop = nA;
                      while ((kDrop > 1) && (!(iC[kDrop - 1] > iC[kDrop - 2])))
                      {
                        iSave = iC[kDrop - 1];
                        iC[kDrop - 1] = iC[kDrop - 2];
                        iC[kDrop - 2] = iSave;
                        kDrop = static_cast<int16_T>(kDrop - 1);
                      }

                      iA[kNext - 1] = 1;
                      kNext = 0;
                      (*status)++;
                    }
                  } else {
                    (*status)++;
                  }
                } else {
                  (*status)++;
                }
              }
            }
          } else {
            cMin = MPC0_norm(x);
            if (std::abs(cMin - Xnorm0) > 0.001) {
              Xnorm0 = cMin;
              MPC0_abs_a(b, tmp);
              MPC0_maximum2(tmp, 1.0, cTol);
              cTolComputed = false;
            }

            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
    }
  }
}

/* Model step function */
void MPC0_step(void)
{
  static const real_T b_Kr_0[304] = { 0.00922148024140119, 0.057198957433601844,
    -0.0328087894089355, 0.21677755295619894, -0.22892969275042793,
    0.45678076090533748, -0.671013508601796, 0.75958253084584182,
    -1.4329849249673916, 1.1119187972286366, -2.5678062548555283,
    1.5043545212215328, -4.1074334637826384, 1.9305087688384757,
    -6.0647518716247486, 2.386239601179085, -8.4366343572811253,
    2.8689044303093532, -11.207451460810512, 3.3767521973095898,
    -14.352555315371609, 3.9084645971356271, -17.841431967004059,
    4.462839476708754, -21.640357317929066, 5.0385963654121388,
    -25.714497501435506, 5.63427856040685, -30.029467113393963,
    6.248225668895711, -34.552403325599144, 6.8785929974555877,
    -39.252636506318666, 7.5233981957402518, -44.102044574079031,
    8.1805800773050326, -49.075174260249568, 8.8480588875813222,
    -8.76959426290293E-5, -0.15295409389932849, -0.0013098361349456471,
    -0.58068323545379485, -0.0062083004229944337, -1.2415059135078821,
    -0.01842442394451007, -2.09964725617942, -0.042359357693481064,
    -3.1243877184044884, -0.08294473196316586, -4.2893426080910677,
    -0.14548592591502657, -5.5718494523441287, -0.23554977299222893,
    -6.9524449343054169, -0.35887708694022424, -8.4144168552785441,
    -0.52130747945446032, -9.9434194650572181, -0.72870940483367208,
    -11.527142719662328, -0.98691228208442883, -13.155027717984984,
    -1.3016401138970308, -14.818021863547608, -1.67844750725181,
    -16.508368297866678, -2.1226596741973967, -18.219424938433658,
    -2.6393181038856284, -19.945509087832026, -3.233133359753432,
    -21.681764104894761, -3.908446034942584, -23.424045074609776,
    -4.6691964159526718, -25.168820801076109, -0.0, -0.0, 0.00922148024140119,
    0.057198957433601844, -0.0328087894089355, 0.21677755295619894,
    -0.22892969275042793, 0.45678076090533748, -0.671013508601796,
    0.75958253084584182, -1.4329849249673916, 1.1119187972286366,
    -2.5678062548555283, 1.5043545212215328, -4.1074334637826384,
    1.9305087688384757, -6.0647518716247486, 2.386239601179085,
    -8.4366343572811253, 2.8689044303093532, -11.207451460810512,
    3.3767521973095898, -14.352555315371609, 3.9084645971356271,
    -17.841431967004059, 4.462839476708754, -21.640357317929066,
    5.0385963654121388, -25.714497501435506, 5.63427856040685,
    -30.029467113393963, 6.248225668895711, -34.552403325599144,
    6.8785929974555877, -39.252636506318666, 7.5233981957402518,
    -44.102044574079031, 8.1805800773050326, -0.0, -0.0, -8.76959426290293E-5,
    -0.15295409389932849, -0.0013098361349456471, -0.58068323545379485,
    -0.0062083004229944337, -1.2415059135078821, -0.01842442394451007,
    -2.09964725617942, -0.042359357693481064, -3.1243877184044884,
    -0.08294473196316586, -4.2893426080910677, -0.14548592591502657,
    -5.5718494523441287, -0.23554977299222893, -6.9524449343054169,
    -0.35887708694022424, -8.4144168552785441, -0.52130747945446032,
    -9.9434194650572181, -0.72870940483367208, -11.527142719662328,
    -0.98691228208442883, -13.155027717984984, -1.3016401138970308,
    -14.818021863547608, -1.67844750725181, -16.508368297866678,
    -2.1226596741973967, -18.219424938433658, -2.6393181038856284,
    -19.945509087832026, -3.233133359753432, -21.681764104894761,
    -3.908446034942584, -23.424045074609776, -0.0, -0.0, -0.0, -0.0,
    0.00922148024140119, 0.057198957433601844, -0.0328087894089355,
    0.21677755295619894, -0.22892969275042793, 0.45678076090533748,
    -0.671013508601796, 0.75958253084584182, -1.4329849249673916,
    1.1119187972286366, -2.5678062548555283, 1.5043545212215328,
    -4.1074334637826384, 1.9305087688384757, -6.0647518716247486,
    2.386239601179085, -8.4366343572811253, 2.8689044303093532,
    -11.207451460810512, 3.3767521973095898, -14.352555315371609,
    3.9084645971356271, -17.841431967004059, 4.462839476708754,
    -21.640357317929066, 5.0385963654121388, -25.714497501435506,
    5.63427856040685, -30.029467113393963, 6.248225668895711,
    -34.552403325599144, 6.8785929974555877, -39.252636506318666,
    7.5233981957402518, -0.0, -0.0, -0.0, -0.0, -8.76959426290293E-5,
    -0.15295409389932849, -0.0013098361349456471, -0.58068323545379485,
    -0.0062083004229944337, -1.2415059135078821, -0.01842442394451007,
    -2.09964725617942, -0.042359357693481064, -3.1243877184044884,
    -0.08294473196316586, -4.2893426080910677, -0.14548592591502657,
    -5.5718494523441287, -0.23554977299222893, -6.9524449343054169,
    -0.35887708694022424, -8.4144168552785441, -0.52130747945446032,
    -9.9434194650572181, -0.72870940483367208, -11.527142719662328,
    -0.98691228208442883, -13.155027717984984, -1.3016401138970308,
    -14.818021863547608, -1.67844750725181, -16.508368297866678,
    -2.1226596741973967, -18.219424938433658, -2.6393181038856284,
    -19.945509087832026, -3.233133359753432, -21.681764104894761, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, 0.00922148024140119, 0.057198957433601844,
    -0.0328087894089355, 0.21677755295619894, -0.22892969275042793,
    0.45678076090533748, -0.671013508601796, 0.75958253084584182,
    -1.4329849249673916, 1.1119187972286366, -2.5678062548555283,
    1.5043545212215328, -4.1074334637826384, 1.9305087688384757,
    -6.0647518716247486, 2.386239601179085, -8.4366343572811253,
    2.8689044303093532, -11.207451460810512, 3.3767521973095898,
    -14.352555315371609, 3.9084645971356271, -17.841431967004059,
    4.462839476708754, -21.640357317929066, 5.0385963654121388,
    -25.714497501435506, 5.63427856040685, -30.029467113393963,
    6.248225668895711, -34.552403325599144, 6.8785929974555877, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -8.76959426290293E-5, -0.15295409389932849,
    -0.0013098361349456471, -0.58068323545379485, -0.0062083004229944337,
    -1.2415059135078821, -0.01842442394451007, -2.09964725617942,
    -0.042359357693481064, -3.1243877184044884, -0.08294473196316586,
    -4.2893426080910677, -0.14548592591502657, -5.5718494523441287,
    -0.23554977299222893, -6.9524449343054169, -0.35887708694022424,
    -8.4144168552785441, -0.52130747945446032, -9.9434194650572181,
    -0.72870940483367208, -11.527142719662328, -0.98691228208442883,
    -13.155027717984984, -1.3016401138970308, -14.818021863547608,
    -1.67844750725181, -16.508368297866678, -2.1226596741973967,
    -18.219424938433658, -2.6393181038856284, -19.945509087832026 };

  static const real_T b_Ac[144] = { -1.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0,
    -0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, -0.0, -1.0, -0.0, -1.0, -0.0,
    -1.0, -0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, -0.0, -0.0, -1.0,
    -0.0, -1.0, -0.0, -1.0, -0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, -0.0,
    -0.0, -0.0, -1.0, -0.0, -1.0, -0.0, -1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    1.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -1.0, -0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 1.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, -1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -1.0, -0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T c_a_0[100] = { 0.99737656643208716, -0.0021748409823629257,
    0.0023222016494080424, 3.2705136155697068E-5, 0.0, 0.0017677194421271839,
    0.0019132500534667048, 0.00082033462725160963, 0.00082033462725160952, 0.0,
    0.37522468778009188, 0.78809723183597058, -1.7030695764332207,
    -0.0382095324110113, 0.0, -1.253339970212574, -1.4488131331864331,
    -0.65404644893914443, -0.65404644893914432, 0.0, -0.031148558612237594,
    0.022249251747157434, 0.47100873933126253, 0.0287775688420578, 0.0,
    -0.079955776671172471, -0.12307388722218181, 0.0022544555567769946,
    0.002254455556776995, 0.0, -0.35936616385915537, -0.033358812007693209,
    -1.531886103800099, 0.96753406461039937, 0.0, -1.3555119521213694,
    -1.8183143566262729, 0.72160147768991012, 0.72160147768991, 0.0,
    0.0058137119652113762, -6.75180645564347E-6, 4.9444415604742737E-6,
    5.1493395538796149E-8, 0.85214378896621135, 3.8196216485584789E-6,
    4.0139045063543789E-6, 1.6817895378534162E-6, 1.681789537853416E-6, 0.0,
    -0.0017234854398168915, -0.0040408005222068158, 0.0082136760206214347,
    0.00025434549530290753, 0.0, 0.62061126047894555, -0.08154658556353464,
    0.0017179067175713653, 0.0017179067175713653, 0.0, -0.0041999502157228311,
    0.0049375700260958551, 0.19600401623601488, 0.0043868639316002557, 0.0,
    -0.011530795104894083, 1.0107072665396506, -0.00032014407737566714,
    -0.00032014407737566709, 0.0, 0.00072113260932504407,
    -0.00073265135220421638, -0.034263380695806353, -0.00072825540186540762, 0.0,
    -0.030305270983607045, -0.040672569762578416, 1.000028991594351,
    2.8991594350977482E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  static const real_T b_Hinv[81] = { 54.559906373669314, 8.8473999277185573,
    -126.13278086788577, -15.054856316496185, 78.731993596921043,
    0.26646678808736451, -5.7800142797379328, 6.4151495293079757, 0.0,
    8.8473999277185573, 44.544263011491964, -13.292466570366704,
    -108.86491140658148, -3.8307480743635827, 80.4475268495169,
    8.7748431987392941, -15.701076383193991, 0.0, -126.13278086788577,
    -13.292466570366704, 348.3777762948194, 28.938305107478289,
    -309.86147273329732, -14.436961963120925, 86.299301302180936,
    -1.732627863641127, 0.0, -15.054856316496185, -108.86491140658148,
    28.938305107478289, 306.62061673920317, -7.5177903036095586,
    -284.49867444967884, -7.0535299694676779, 86.435946225501439, 0.0,
    78.731993596921043, -3.8307480743635827, -309.86147273329732,
    -7.5177903036095586, 403.89771827625827, 31.707956984369527,
    -175.41913752676723, -21.100359269387596, 0.0, 0.26646678808736451,
    80.4475268495169, -14.436961963120925, -284.49867444967884,
    31.707956984369527, 337.64996027405647, -18.018931234122643,
    -134.67503478063151, 0.0, -5.7800142797379328, 8.7748431987392941,
    86.299301302180936, -7.0535299694676779, -175.41913752676723,
    -18.018931234122643, 97.6687517923142, 17.146195348616967, 0.0,
    6.4151495293079757, -15.701076383193991, -1.732627863641127,
    86.435946225501439, -21.100359269387596, -134.67503478063151,
    17.146195348616967, 64.955070279351276, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 9.9999999999999974E-6 };

  static const real_T b_Linv[81] = { 0.052630840448374683, 0.017464265317407419,
    -1.2038621151299089, -0.41529454915597341, 6.9017429846731249,
    2.016879609534846, -0.77436400472150491, 0.79597651679289882, 0.0, 0.0,
    0.0505313990020227, 0.013648386674559287, -1.1907503219743234,
    -0.20202832809719032, 6.1233582719328359, 1.3386589408351357,
    -1.9481522655547776, 0.0, 0.0, 0.0, 1.3836104119448305, 0.48831380330048207,
    -15.619008306254587, -4.6278309575612147, 8.98935435716824,
    -0.21498035010700015, 0.0, 0.0, 0.0, 0.0, 1.3274592242460943,
    0.23727371092990435, -13.423952016235052, -3.0950051534177905,
    10.724766911192285, 0.0, 0.0, 0.0, 0.0, 0.0, 8.950518044266218,
    2.6841838727827967, -17.599055263688033, -2.618082462083728, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 7.4243414127437486, 1.8165130335961572, -16.710158445085131,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 9.65104497804776, 2.12745919444141, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 8.0594708436318125, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.003162277660168379 };

  static const real_T b_Kx_0[80] = { -27.621166403883105, -1811.0469199677257,
    24.44576388451598, 2069.0494679814192, -1.4998727151366293,
    8.4121153149909169, 73.4685277078986, -33.797442718303678, 311.3011607252223,
    -71.392052944868922, 190.45371326657602, 430.39506652828953,
    -3.5266241304487229, -275.55306563035509, 6.6791663714513083,
    -1.1840782900806432, -21.367219106136808, 11.446306840655938,
    22.681017508202324, 206.81877613842926, -24.4863815571993,
    -1548.7693987933676, 20.433649855833561, 1760.6508465912011,
    -1.338774961438121, 7.03796639127527, 63.718646272799027,
    -29.501455246479217, 262.22598646497272, -62.543994057287605,
    166.62236712493231, 392.86436266579267, -3.0998735071672403,
    -257.12509453832877, 5.9190752370339359, -1.0737656006837939,
    -19.543837325497552, 10.543491140962361, 18.011821092249651,
    181.64995533735313, -21.671344436085043, -1307.707822278293,
    16.82625929133189, 1478.7228062439833, -1.1861829668184882,
    5.8029388063290872, 54.560925599302017, -25.440326044778438,
    218.12394189089366, -54.363413979982575, 144.56585089900389,
    354.33895430931676, -2.692300981055785, -236.35726556320981,
    5.1957668869405618, -0.95800461909811119, -17.678375929069951,
    9.6126881137617382, 14.103375057307066, 158.22591026274335,
    -19.135757284900272, -1088.5759336834681, 13.630676104910979,
    1223.9566013315825, -1.0427306934425631, 4.7085671768704582,
    46.05370504319658, -21.639725930095565, 178.871305384575,
    -46.840015784242325, 124.26468716005527, 315.57733412726776,
    -2.3112896907886205, -213.9927940923468, 4.5136711155944,
    -0.84089375829209334, -15.800525992341743, 8.66601706902386,
    10.870241697553633, 136.54414615784859 };

  static const real_T a[20] = { -0.012405576084443226, -0.0022457269707014792,
    -0.032330427884046463, 0.0075293115686910685, 0.19495768688905107,
    -0.020953740514346553, -0.045793990363913406, -0.035362902055126433,
    0.11474361614998844, 0.0028569719427344537, 0.12042141428196382,
    -0.0018621372143752025, 0.0041017653456599723, -0.0042159130342073131,
    1.9426051459130464, 0.010332972309689836, -0.0069012905887470919,
    -1.7020135521263184E-5, -0.00954860414170881, 0.036647129980731316 };

  static const real_T d_a_0[20] = { -0.007145877889717561, 0.0072673555048277695,
    0.34060857231519187, 0.0072175869972266838, 0.0, 0.30136826314162279,
    0.40422681352687173, -0.16028801037083584, -0.00028801037083582142, 0.0,
    0.019108587407485007, -1.4881545674967912E-5, 8.2389432862073822E-6,
    6.76946615068951E-8, 5.9142484413515461, 6.4209068419213469E-6,
    6.627639897197673E-6, 2.7389681803998348E-6, 2.7389681803998348E-6, 0.0 };

  static const real_T e_a[20] = { -0.01357804422662688, -0.0028302165591876588,
    -0.030901437545722867, 0.0062594185324248248, 0.16613198199384943,
    -0.016231996752783608, -0.049618250314561768, -0.02856602743302741,
    0.12154049077208447, 0.0028569719427302986, 0.13209898011882995,
    -0.0015864762603471189, 0.010583637239518395, -0.0039134452998898089,
    1.655378909503606, 0.014433795102944964, 0.0022800066471915935,
    -0.001710044825221139, -0.011241628831410434, 0.036647129980731351 };

  static const real_T b_Ku1_0[16] = { 361.00888164030175, -124.76948656810615,
    -124.76948656810615, 434.75186603292656, 315.34116702999819,
    -112.84891706628822, -114.97845549974201, 392.45801209350265,
    272.13972984755458, -101.30684769199266, -104.88451291986003,
    351.21148408140454, 231.67759223995535, -90.186059790186619,
    -94.615821420236188, 311.24064127363533 };

  static const real_T b_Mlim_0[16] = { 0.5, 0.83474500000000007, 0.5,
    0.83474500000000007, 0.5, 0.83474500000000007, 0.5, 0.83474500000000007, 0.5,
    0.16525499999999999, 0.5, 0.16525499999999999, 0.5, 0.16525499999999999, 0.5,
    0.16525499999999999 };

  static const int8_T b_Mu1[32] = { -1, 0, -1, 0, -1, 0, -1, 0, 1, 0, 1, 0, 1, 0,
    1, 0, 0, -1, 0, -1, 0, -1, 0, -1, 0, 1, 0, 1, 0, 1, 0, 1 };

  static const int8_T b_a[20] = { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 1 };

  real_T rseq[38];
  real_T b_Mlim[16];
  real_T unusedU0[16];
  real_T c_a[10];
  real_T f[9];
  real_T zopt[9];
  real_T old_u[2];
  real_T y_innov[2];
  real_T b_Kr;
  real_T b_Ku1;
  real_T b_Kx;
  real_T d_a;
  real_T *xk;
  int32_T b_i;
  int32_T i;
  int16_T iAnew[16];
  if (MPC0_M->Timing.TaskCounters.TID[1] == 0) {
    /* Memory: '<S2>/last_x' */
    std::memcpy(&MPC0_B.last_x[0], &MPC0_DW.last_x_PreviousInput[0], 10U *
                sizeof(real_T));

    /* Gain: '<S2>/ymin_scale2' incorporates:
     *  Constant: '<S1>/S_zero'
     */
    MPC0_B.ymin_scale2 = MPC0_P.ymin_scale2_Gain * MPC0_P.S_zero_Value;

    /* UnitDelay: '<S2>/last_mv' */
    MPC0_B.last_mv[0] = MPC0_DW.last_mv_DSTATE[0];

    /* Gain: '<S2>/umin_scale4' incorporates:
     *  Constant: '<S1>/E_zero'
     */
    MPC0_B.umin_scale4[0] = MPC0_P.umin_scale4_Gain[0] * MPC0_P.E_zero_Value[0];

    /* Gain: '<S2>/ymin_scale1' incorporates:
     *  Constant: '<S1>/F_zero'
     */
    MPC0_B.ymin_scale1[0] = MPC0_P.ymin_scale1_Gain[0] * MPC0_P.F_zero_Value[0];

    /* Gain: '<S2>/ext.mv_scale' incorporates:
     *  Constant: '<S1>/ext.mv_zero'
     */
    MPC0_B.extmv_scale[0] = MPC0_P.extmv_scale_Gain[0] *
      MPC0_P.extmv_zero_Value[0];

    /* Gain: '<S2>/ext.mv_scale1' incorporates:
     *  Constant: '<S1>/mv.target_zero'
     */
    MPC0_B.extmv_scale1[0] = MPC0_P.extmv_scale1_Gain[0] *
      MPC0_P.mvtarget_zero_Value[0];

    /* Math: '<S2>/Math Function' incorporates:
     *  Constant: '<S1>/y.wt_zero'
     */
    MPC0_B.MathFunction[0] = MPC0_P.ywt_zero_Value[0];

    /* Math: '<S2>/Math Function1' incorporates:
     *  Constant: '<S1>/u.wt_zero'
     */
    MPC0_B.MathFunction1[0] = MPC0_P.uwt_zero_Value[0];

    /* Math: '<S2>/Math Function2' incorporates:
     *  Constant: '<S1>/du.wt_zero'
     */
    MPC0_B.MathFunction2[0] = MPC0_P.duwt_zero_Value[0];

    /* UnitDelay: '<S2>/last_mv' */
    MPC0_B.last_mv[1] = MPC0_DW.last_mv_DSTATE[1];

    /* Gain: '<S2>/umin_scale4' incorporates:
     *  Constant: '<S1>/E_zero'
     */
    MPC0_B.umin_scale4[1] = MPC0_P.umin_scale4_Gain[1] * MPC0_P.E_zero_Value[1];

    /* Gain: '<S2>/ymin_scale1' incorporates:
     *  Constant: '<S1>/F_zero'
     */
    MPC0_B.ymin_scale1[1] = MPC0_P.ymin_scale1_Gain[1] * MPC0_P.F_zero_Value[1];

    /* Gain: '<S2>/ext.mv_scale' incorporates:
     *  Constant: '<S1>/ext.mv_zero'
     */
    MPC0_B.extmv_scale[1] = MPC0_P.extmv_scale_Gain[1] *
      MPC0_P.extmv_zero_Value[1];

    /* Gain: '<S2>/ext.mv_scale1' incorporates:
     *  Constant: '<S1>/mv.target_zero'
     */
    MPC0_B.extmv_scale1[1] = MPC0_P.extmv_scale1_Gain[1] *
      MPC0_P.mvtarget_zero_Value[1];

    /* Math: '<S2>/Math Function' incorporates:
     *  Constant: '<S1>/y.wt_zero'
     */
    MPC0_B.MathFunction[1] = MPC0_P.ywt_zero_Value[1];

    /* Math: '<S2>/Math Function1' incorporates:
     *  Constant: '<S1>/u.wt_zero'
     */
    MPC0_B.MathFunction1[1] = MPC0_P.uwt_zero_Value[1];

    /* Math: '<S2>/Math Function2' incorporates:
     *  Constant: '<S1>/du.wt_zero'
     */
    MPC0_B.MathFunction2[1] = MPC0_P.duwt_zero_Value[1];
    for (i = 0; i < 16; i++) {
      /* Memory: '<S2>/Memory' */
      MPC0_B.Memory[i] = MPC0_DW.Memory_PreviousInput[i];
    }

    /* MATLAB Function: '<S22>/optimizer' incorporates:
     *  Inport: '<Root>/mo or x'
     *  Inport: '<Root>/ref'
     */
    /* :  coder.extrinsic('mpcblock_optimizer_double_mex'); */
    /* :  coder.extrinsic('mpcblock_optimizer_single_mex'); */
    /* :  coder.extrinsic('mpcblock_refmd_double_mex'); */
    /* :  coder.extrinsic('mpcblock_refmd_single_mex'); */
    /* :  isSimulation = coder.target('Sfun') && ~coder.target('RtwForRapid') && ~coder.target('RtwForSim'); */
    /* :  isAdaptive = false; */
    /* :  isLTV = false; */
    /* :  isDouble = isa(ref,'double'); */
    /* :  ZERO = zeros('like',ref); */
    /* :  ONE = ones('like',ref); */
    /* :  if isSimulation */
    /* :  else */
    /* :  [rseq, vseq, v] = mpcblock_refmd(ref,md,nv,ny,p,yoff,voff,no_md,no_ref,openloopflag, RYscale, RMDscale); */
    std::memset(&rseq[0], 0, 38U * sizeof(real_T));

    /* :  old_u = old_u - uoff; */
    for (i = 0; i < 2; i++) {
      for (b_i = 0; b_i < 19; b_i++) {
        rseq[i + (b_i << 1)] = MPC0_U.ref_out[19 * i + b_i];
      }

      old_u[i] = MPC0_B.last_mv[i];
    }

    /* :  if no_mv==ONE */
    /* :  delmv = zeros(nu,1,'like',ref); */
    /* :  xk = xk - xoff; */
    /* :  if CustomEstimation==ONE */
    /* :  else */
    /* :  ym = ym.*RYscale(myindex) - myoff; */
    /* :  xk = xk + Bu*delmv; */
    xk = &MPC0_B.last_x[0];

    /* :  ym_est = C(myindex,:)*xk + Dv(myindex,:)*v; */
    /* :  y_innov = ym - ym_est; */
    for (b_i = 0; b_i < 2; b_i++) {
      b_Ku1 = 0.0;
      for (i = 0; i < 10; i++) {
        b_Ku1 += static_cast<real_T>(b_a[(i << 1) + b_i]) * xk[i];
      }

      y_innov[b_i] = MPC0_U.moorx[b_i] - b_Ku1;
    }

    /* :  xest = xk + M*y_innov; */
    for (b_i = 0; b_i < 10; b_i++) {
      b_Ku1 = a[b_i] * y_innov[0];
      b_Ku1 += a[b_i + 10] * y_innov[1];
      MPC0_B.xest[b_i] = xk[b_i] + b_Ku1;
    }

    /* :  if no_uref==ONE */
    /* :  utargetValue = utarget; */
    /* :  if no_cc~=ONE */
    /* :  return_sequence = (return_mvseq || return_xseq || return_ovseq)*ONE; */
    /* :  if isSimulation */
    /* :  else */
    /* :  [u, cost, useq, status, iAout] = mpcblock_optimizer(... */
    /* :              rseq, vseq, umin, umax, ymin, ymax, switch_in, xest, old_u, iA, ... */
    /* :              isQP, nu, ny, degrees, Hinv, Kx, Ku1, Kut, Kr, Kv, Mlim, ... */
    /* :              Mx, Mu1, Mv, z_degrees, utargetValue, p, uoff, voff, yoff, ... */
    /* :              false, CustomSolverCodeGen, UseSuboptimalSolution, ... */
    /* :              UseActiveSetSolver, ASOptions, IPOptions, nxQP, openloopflag, ... */
    /* :              no_umin, no_umax, no_ymin, no_ymax, no_cc, switch_inport, ... */
    /* :              no_switch, enable_value, return_cost, H, return_sequence, Linv, Ac, ... */
    /* :              ywt, uwt, duwt, rhoeps, no_ywt, no_uwt, no_duwt, no_rhoeps,... */
    /* :              Wy, Wdu, Jm, SuJm, Su1, Sx, Hv, Wu, I1, ... */
    /* :              isAdaptive, isLTV, A, Bu, Bv, C, Dv, ... */
    /* :              Mrows, nCC, Ecc, Fcc, Scc, Gcc, RYscale, RMVscale, m); */
    std::memset(&f[0], 0, 9U * sizeof(real_T));
    for (i = 0; i < 8; i++) {
      b_Kx = 0.0;
      for (b_i = 0; b_i < 10; b_i++) {
        b_Kx += b_Kx_0[10 * i + b_i] * MPC0_B.xest[b_i];
      }

      b_Kr = 0.0;
      for (b_i = 0; b_i < 38; b_i++) {
        b_Kr += b_Kr_0[38 * i + b_i] * rseq[b_i];
      }

      b_Ku1 = b_Ku1_0[i << 1] * old_u[0];
      b_Ku1 += b_Ku1_0[(i << 1) + 1] * old_u[1];
      f[i] = (b_Kx + b_Kr) + b_Ku1;
    }

    for (i = 0; i < 16; i++) {
      iAnew[i] = MPC0_B.Memory[i];
      b_Ku1 = 0.0;
      for (b_i = 0; b_i < 10; b_i++) {
        b_Ku1 += 0.0 * MPC0_B.xest[b_i];
      }

      b_Kx = b_Mlim_0[i] + b_Ku1;
      b_Kr = static_cast<real_T>(b_Mu1[i]) * old_u[0];
      b_Kr += static_cast<real_T>(b_Mu1[i + 16]) * old_u[1];
      b_Mlim[i] = -(b_Kx + b_Kr);
    }

    MPC0_qpkwik(b_Linv, b_Hinv, f, b_Ac, b_Mlim, iAnew, 120, 1.0E-6, zopt,
                unusedU0, &b_Kx);
    if ((b_Kx < 0.0) || (b_Kx == 0.0)) {
      std::memset(&zopt[0], 0, 9U * sizeof(real_T));
    }

    MPC0_B.u[0] = old_u[0] + zopt[0];
    MPC0_B.u[1] = old_u[1] + zopt[1];
    MPC0_B.cost = 0.0;
    std::memset(&MPC0_B.useq[0], 0, 40U * sizeof(real_T));
    MPC0_B.status = b_Kx;
    for (i = 0; i < 16; i++) {
      MPC0_B.iAout[i] = (iAnew[i] != 0);
    }

    /* :  if return_xseq || return_ovseq */
    /* :  else */
    /* :  yseq = zeros(p+1,ny,'like',rseq); */
    std::memset(&MPC0_B.yseq[0], 0, 40U * sizeof(real_T));

    /* :  xseq = zeros(p+1,nxQP,'like',rseq); */
    std::memset(&MPC0_B.xseq[0], 0, 200U * sizeof(real_T));

    /* :  if CustomEstimation==ONE */
    /* :  else */
    /* :  xk1 = A*xk + Bu*(u - uoff) + Bv*v + L*y_innov; */
    /* :  xk1 = xk1 + xoff; */
    /* :  xest = xest + xoff; */
    b_Kx = MPC0_B.u[0];
    b_Kr = MPC0_B.u[1];

    /* Gain: '<S2>/umin_scale1' */
    MPC0_B.umin_scale1[0] = MPC0_P.umin_scale1_Gain[0] * MPC0_B.u[0];

    /* Outport: '<Root>/mv' */
    MPC0_Y.mv[0] = MPC0_B.umin_scale1[0];

    /* Gain: '<S2>/umin_scale1' */
    MPC0_B.umin_scale1[1] = MPC0_P.umin_scale1_Gain[1] * MPC0_B.u[1];

    /* Outport: '<Root>/mv' */
    MPC0_Y.mv[1] = MPC0_B.umin_scale1[1];
    for (i = 0; i < 10; i++) {
      /* MATLAB Function: '<S22>/optimizer' */
      c_a[i] = 0.0;
      for (b_i = 0; b_i < 10; b_i++) {
        b_Ku1 = c_a[i];
        b_Ku1 += c_a_0[10 * b_i + i] * xk[b_i];
        c_a[i] = b_Ku1;
      }

      d_a = d_a_0[i] * b_Kx;
      b_Ku1 = e_a[i] * y_innov[0];
      d_a += d_a_0[i + 10] * b_Kr;
      b_Ku1 += e_a[i + 10] * y_innov[1];
      MPC0_B.xk1[i] = (c_a[i] + d_a) + b_Ku1;

      /* Update for Memory: '<S2>/last_x' */
      MPC0_DW.last_x_PreviousInput[i] = MPC0_B.xk1[i];
    }

    /* Update for UnitDelay: '<S2>/last_mv' */
    MPC0_DW.last_mv_DSTATE[0] = MPC0_B.u[0];
    MPC0_DW.last_mv_DSTATE[1] = MPC0_B.u[1];

    /* Update for Memory: '<S2>/Memory' */
    for (i = 0; i < 16; i++) {
      MPC0_DW.Memory_PreviousInput[i] = MPC0_B.iAout[i];
    }

    /* End of Update for Memory: '<S2>/Memory' */
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(MPC0_M->rtwLogInfo, (&MPC0_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(MPC0_M)!=-1) &&
        !((rtmGetTFinal(MPC0_M)-MPC0_M->Timing.taskTime0) >
          MPC0_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(MPC0_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++MPC0_M->Timing.clockTick0)) {
    ++MPC0_M->Timing.clockTickH0;
  }

  MPC0_M->Timing.taskTime0 = MPC0_M->Timing.clockTick0 *
    MPC0_M->Timing.stepSize0 + MPC0_M->Timing.clockTickH0 *
    MPC0_M->Timing.stepSize0 * 4294967296.0;
  rate_scheduler();
}

/* Model initialize function */
void MPC0_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(MPC0_M, 500.0);
  MPC0_M->Timing.stepSize0 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    MPC0_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(MPC0_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(MPC0_M->rtwLogInfo, (NULL));
    rtliSetLogT(MPC0_M->rtwLogInfo, "tout");
    rtliSetLogX(MPC0_M->rtwLogInfo, "");
    rtliSetLogXFinal(MPC0_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(MPC0_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(MPC0_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(MPC0_M->rtwLogInfo, 0);
    rtliSetLogDecimation(MPC0_M->rtwLogInfo, 1);
    rtliSetLogY(MPC0_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(MPC0_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(MPC0_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) std::memset((static_cast<void *>(&MPC0_B)), 0,
                     sizeof(B_MPC0_T));

  /* states (dwork) */
  (void) std::memset(static_cast<void *>(&MPC0_DW), 0,
                     sizeof(DW_MPC0_T));

  /* external inputs */
  (void)std::memset(&MPC0_U, 0, sizeof(ExtU_MPC0_T));

  /* external outputs */
  (void) std::memset(&MPC0_Y.mv[0], 0,
                     2U*sizeof(real_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(MPC0_M->rtwLogInfo, 0.0, rtmGetTFinal(MPC0_M),
    MPC0_M->Timing.stepSize0, (&rtmGetErrorStatus(MPC0_M)));

  {
    int32_T i;

    /* InitializeConditions for Memory: '<S2>/last_x' */
    std::memcpy(&MPC0_DW.last_x_PreviousInput[0],
                &MPC0_P.last_x_InitialCondition[0], 10U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S2>/last_mv' */
    MPC0_DW.last_mv_DSTATE[0] = MPC0_P.last_mv_InitialCondition[0];
    MPC0_DW.last_mv_DSTATE[1] = MPC0_P.last_mv_InitialCondition[1];

    /* InitializeConditions for Memory: '<S2>/Memory' */
    for (i = 0; i < 16; i++) {
      MPC0_DW.Memory_PreviousInput[i] = MPC0_P.Memory_InitialCondition[i];
    }

    /* End of InitializeConditions for Memory: '<S2>/Memory' */
  }
}

/* Model terminate function */
void MPC0_terminate(void)
{
  /* (no terminate code required) */
}
