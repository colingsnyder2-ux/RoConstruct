// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: boost::signal emission loop over slot list at this+0x108, then G3D alignedFree of arg3.
// INFERRED: __thiscall with 8 stack args (ret 0x20) can only be a member function, so the target is a member of a stand-in class.
#include <windows.h>

struct SlotData {
    struct Item { void* fn; long* refcount; };
    Item* begin;   // +0x00
    int pad[2];
    Item* cur;     // +0x0c
    Item* end;     // +0x10
};

extern "C" void __fastcall fn_004915b0(void* slot, int unusedEdx, void** out);
extern "C" void __fastcall fn_00496910(void* fn, int unusedEdx, void* a);
extern "C" void __cdecl fn_00507d20(void* p);

struct fn_004984d0_Holder {
    char pad[0x108];
    void* slot;
    void run(int a0, int a1, void* a2, void* a3, int a4, int a5, int a6, int a7);
};

void fn_004984d0_Holder::run(int a0, int a1, void* a2, void* a3, int a4, int a5, int a6, int a7)
{
    if (slot) {
        void* data = 0;
        fn_004915b0(&slot, 0, &data);
        SlotData* d = (SlotData*)data;
        for (SlotData::Item* it = d->cur; it != d->end; ++it) {
            if (it->refcount)
                InterlockedIncrement(it->refcount + 1);
            fn_00496910(it->fn, 0, a2);
        }
    }
    fn_00507d20(a3);
}
