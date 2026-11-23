// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the Instance and PropertyDescriptor declarations below are minimal local stand-ins,
// because the real headers were not shown.
namespace RBX {
namespace Reflection { class PropertyDescriptor; }
class Instance {
public:
    void raisePropertyChanged(const Reflection::PropertyDescriptor& desc);
};
}

extern "C" int __stdcall fn_00448f40(int a1);

// INFERRED: global float constant at 0x8163a4 (upper bound)
extern "C" const float dat_008163a4;
// INFERRED: static property descriptor at 0x96d464
extern "C" RBX::Reflection::PropertyDescriptor dat_0096d464;

// INFERRED: unnamed target, so it is exposed as a C-linkage fastcall free function (this in ecx).
// It looks like a clamped float setter: the field at +0x144 is the lower bound
// and the field at +0x148 is the value.
extern "C" void __fastcall fn_00448fd0(RBX::Instance* self, int unusedEdx, float v)
{
    char* base = reinterpret_cast<char*>(self);
    float* minp = reinterpret_cast<float*>(base + 0x144);
    float* valp = reinterpret_cast<float*>(base + 0x148);

    const float* pick = minp;
    if (!(v > *minp)) {
        // INFERRED: the call takes the float bits as its single stack argument
        union { float f; int i; } u;
        u.f = v;
        fn_00448f40(u.i);
    }
    if (!(v <= *minp))
        pick = &v;

    float lo = *pick;
    float hi = dat_008163a4;
    const float* res = (hi > lo) ? &lo : &hi;
    float r = *res;

    if (*valp != r) {
        *valp = r;
        self->raisePropertyChanged(dat_0096d464);
    }
}
