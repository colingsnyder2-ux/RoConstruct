// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// The disassembly calls this through an import slot ([0x802890]).
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: checked (SECURE_SCL) tree const_iterator = { container*, node* }.
struct TreeIter {
    void* cont;
    char* ptr;
};

// INFERRED: destination output iterator passed and returned by value (two words).
struct DestIter {
    int a;
    int b;
};

extern "C" int __fastcall fn_00587710(void* self, int unusedEdx, int a1, int a2, int a3, int a4);
// INFERRED: _Tree::const_iterator::_Inc, __thiscall on the iterator
extern "C" void __fastcall fn_005b7250(void* self, int unusedEdx);

// INFERRED: checked std::copy / _Copy_opt over a map<InstanceHandle,int> range
// into an insert-style output iterator; returns the output pointer in eax.
extern "C" DestIter* fn_00588240(DestIter* out, TreeIter first, TreeIter last, DestIter dest)
{
    TreeIter it = first;
    for (;;) {
        if (!it.cont || it.cont != last.cont)
            _invalid_parameter_noinfo();
        if (it.ptr == last.ptr)
            break;
        if (!it.cont)
            _invalid_parameter_noinfo();
        char* head = *(char**)it.cont;
        if (it.ptr == *(char**)(head + 0x18))
            _invalid_parameter_noinfo();

        void* valp = it.ptr + 0xc;
        fn_00587710(&dest.b, 0, 0, (int)&dest.a, (int)&valp, 0);
        fn_005b7250(&it, 0);
    }
    out->a = dest.a;
    out->b = dest.b;
    return out;
}
