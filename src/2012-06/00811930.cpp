// from server: 60% by Intel
// roc-repair: genuine WinNT.h definitions (no SDK shipped)
typedef unsigned long DWORD;
class RBX_Motor {
public:
    float getVelocity();
};

float RBX_Motor::getVelocity()
{
    return *(float*)((DWORD)this + 0xa8);
}
