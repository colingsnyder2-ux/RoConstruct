// from server: 71% by Intel
struct KernelJoint
{
    bool __cdecl func(float a1, int a2, int a3, int a4, float a5);
};

extern "C" bool __stdcall sub_8F0C20(int a1, int a2, int a3, int a4, int a5, float a6);
extern "C" bool __stdcall sub_8F1000(int a1, int a2, int a3, int a4, int a5, float a6);

bool KernelJoint::func(float a1, int a2, int a3, int a4, float a5)
{
    if (sub_8F0C20(a2, a3, a4, 0, 0, a1))
        return true;

    return sub_8F1000(a2, a3, a4, 0, 0, a5) != 0;
}
