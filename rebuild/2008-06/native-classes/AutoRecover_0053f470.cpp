// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <set>

extern "C" int __fastcall fn_0053f4e0(void* self, int unusedEdx, int a1);

// INFERRED: object owns a std::set<int> at offset 8; element values are used as object pointers.
struct fn_0053f470_Owner {
    char pad[8];
    std::set<int> items;
};

// INFERRED: the stack argument is passed through unchanged to fn_0053f4e0; the return value is unused.
extern "C" void __fastcall fn_0053f470(fn_0053f470_Owner* self, int unusedEdx, int arg)
{
    std::set<int>::iterator it = self->items.begin();
    std::set<int>::iterator last = self->items.end();
    for (; it != last; ++it) {
        if (fn_0053f4e0((void*)(*it), 0, arg))
            break;
    }
}
