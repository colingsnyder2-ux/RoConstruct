#pragma once
// 2008-06 native RBX::Constants (inactive). Declared under a non-colliding name: the original path v8kernel/Constants.h
// is the donor header. A unit must not include both this header and the donor v8kernel/Constants.h.
// The 2008 binary has these functions at fixed addresses:
//   kernelDt()              00649310: fld dword ptr [0x845c68]; ret
//   kernelStepsPerWorldStep 006492d0: mov eax, 0x13; ret
//   worldStepsPerUiStep     0063e420: mov eax, 8; ret
// The donor header declares many more static methods (optimized out); only the three above are proven in 2008.
#include <G3D/Vector3.h>

namespace RBX
{
    class Constants
    {
    public:
        // 00649310: returns kernel step time (float from 0x845c68)
        static const float kernelDt();

        // 006492d0: returns 19 (0x13)
        static const int kernelStepsPerWorldStep();

        // 0063e420: returns 8
        static const int worldStepsPerUiStep();

        // INFERRED: other donor static methods not proven in 2008 binary
        // static const int uiStepsPerSec();
        // static const int worldStepsPerSec();
        // static const int kernelStepsPerSec();
        // static const int kernelStepsPerUiStep();
        // static const float uiDt();
        // static const float worldDt();
        // static const G3D::Vector3& getKmsGravity();
        // static const float getKmsMaxJointForce(float, float);
        // static const float getElasticMultiplier(float);
        // static const float getJointK(const G3D::Vector3&, bool);
    };
}