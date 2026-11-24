// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <set>

extern "C" int __fastcall fn_00553620(void* self, int unusedEdx, int a1, int a2, int a3, int a4);

// INFERRED: class unknown; member at +4 is a container, helper takes (bool, this, set copy, 0)
struct Fn005534e0Obj {
    int pad0;
    int member4;
};

extern "C" void __fastcall fn_005534e0(Fn005534e0Obj* self, int unusedEdx, const std::set<int>& arg1)
{
    std::set<int> copy(arg1);
    bool flag = false;
    fn_00553620(&self->member4, 0, (int)flag, (int)self, (int)&copy, 0);
}
