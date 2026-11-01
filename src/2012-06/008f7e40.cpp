// from server: 81% by Intel
struct VAnimationTrack_EventDesc
{
    void func_008f7e40(float a1, float a2, float a3, float a4);
};

void VAnimationTrack_EventDesc::func_008f7e40(float a1, float a2, float a3, float a4)
{
    double val = *reinterpret_cast<double*>(reinterpret_cast<char*>(this) + 0x90);
    if (a1 <= val)
        return;

    *reinterpret_cast<double*>(reinterpret_cast<char*>(this) + 0x90) = val;
    *reinterpret_cast<double*>(reinterpret_cast<char*>(this) + 0xA8) = val;
    *reinterpret_cast<double*>(reinterpret_cast<char*>(this) + 0xB0) = 0.0;
    *reinterpret_cast<double*>(reinterpret_cast<char*>(this) + 0xB8) = val + a2;
    *reinterpret_cast<double*>(reinterpret_cast<char*>(this) + 0xC0) = a3;
    *reinterpret_cast<double*>(reinterpret_cast<char*>(this) + 0x98) = a4;
    *reinterpret_cast<double*>(reinterpret_cast<char*>(this) + 0xC8) = a4;
}
