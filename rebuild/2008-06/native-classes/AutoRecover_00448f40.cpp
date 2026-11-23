// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <algorithm>

namespace RBX {
namespace Reflection {
class PropertyDescriptor;
}
class Instance {
public:
    void raisePropertyChanged(const Reflection::PropertyDescriptor& desc);
};
}

extern "C" int __stdcall fn_00448fd0(int a1);

// INFERRED: descriptor object at 0x0096d448 (property descriptor for this setter)
extern "C" char g_desc_0096d448[];

// INFERRED: unnamed target, a float property setter on an Instance-derived object
// (value at +0x144, upper bound at +0x148). Value is clamped to [0, max].
extern "C" void __fastcall fn_00448f40(char* self, int unusedEdx, float v)
{
    float& maxValue = *reinterpret_cast<float*>(self + 0x148);
    float& curValue = *reinterpret_cast<float*>(self + 0x144);

    if (v > maxValue) {
        // INFERRED: callee takes the float bits as its argument (pushed from st0)
        float tmp = v;
        fn_00448fd0(*reinterpret_cast<int*>(&tmp));
    }

    v = std::min(maxValue, v);
    float zero = 0.0f;
    v = std::max(zero, v);

    if (curValue != v) {
        curValue = v;
        reinterpret_cast<RBX::Instance*>(self)->raisePropertyChanged(
            *reinterpret_cast<const RBX::Reflection::PropertyDescriptor*>(g_desc_0096d448));
    }
}
