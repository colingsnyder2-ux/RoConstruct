// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNATIVE_SIMJOB_PENDING
// INFERRED: RBX::HUMAN::Dead::sub_00666da0 (placeholder name for 00666da0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#define NATIVE_SIMJOB_PENDING
#include "humanoid/HumanoidStates3.h"

void* RBX::HUMAN::Dead::sub_00666da0(unsigned int flags)
{
    this->Dead::~Dead();
    if (flags & 1)
        operator delete(this);
    return this;
}
