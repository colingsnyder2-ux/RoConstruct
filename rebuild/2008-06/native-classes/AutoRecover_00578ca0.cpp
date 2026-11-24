// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: unmatched draft. I could not check the header paths, the class layout or the Mark/Array types against the real headers.
#include "v8datamodel/Workspace.h"
#include "util/Profiling.h"
#include "G3D/Array.h"
#include "G3D/Vector4.h"

struct RenderHost;                // INFERRED: class that owns the 0x204 and 0x20c members
struct RenderState { char pad[0x1b4]; int mode; };

extern "C" int  __fastcall fn_00574fe0(RenderHost* self, int unusedEdx);
extern "C" void* fn_00577690();
extern "C" void __fastcall fn_00578c20(RenderHost* self, int unusedEdx, void* state);
extern "C" void __fastcall fn_005571b0(char* self, int unusedEdx, float step);     // INFERRED: p = this+0x20c object
extern "C" void __fastcall fn_005a0e30(void* ws, int unusedEdx);
extern "C" void __fastcall fn_00557150(char* self, int unusedEdx, float step);
extern bool g_974e61;  // INFERRED: global byte at 0x974e61

struct StepState {
    G3D::Array<G3D::Vector4> arr;   // INFERRED: copied from fn_00577690() result
    bool a, b;
};

extern "C" void __fastcall fn_00578ca0(RenderHost* self, int unusedEdx, float dt)
{
    char* s = (char*)self;
    bool flag = false;
    switch (fn_00574fe0(self, 0)) {
    case 0: case 3: case 4:
        flag = ((RenderState*)*(void**)(s + 0x20c))->mode == 1;
        break;
    case 1: case 2:
        flag = g_974e61;
        break;
    }

    StepState st;
    char* src = (char*)fn_00577690();
    st.arr = *(G3D::Array<G3D::Vector4>*)src;
    st.a = src[0xc];
    st.b = src[0xd];

    if (g_974e61) fn_00578c20(self, 0, &flag);

    RBX::Workspace* ws = *(RBX::Workspace**)(s + 0x204);
    if (flag) {
        {
            RBX::Profiling::Mark m(**(RBX::Profiling::CodeProfiler**)((char*)ws + 0x42c), true);
            ws->step(dt);
        }
        {
            RBX::Profiling::Mark m(**(RBX::Profiling::CodeProfiler**)((char*)*(void**)(s + 0x204) + 0x434), true);
            fn_005571b0(*(void**)(s + 0x20c), dt);
        }
    } else {
        {
            RBX::Profiling::Mark m(**(RBX::Profiling::CodeProfiler**)((char*)ws + 0x430), true);
            fn_005a0e30(*(void**)(s + 0x204), 0);
        }
    }
    {
        RBX::Profiling::Mark m(**(RBX::Profiling::CodeProfiler**)((char*)*(void**)(s + 0x204) + 0x438), true);
        fn_00557150(*(void**)(s + 0x20c), dt);
    }
}
