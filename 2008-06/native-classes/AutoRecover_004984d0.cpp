// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: object layouts below come from the disassembly only. This is a draft, not a byte match.
// INFERRED: the target is a boost::signal-style invoker. It walks a slot vector, copies each
// 8-byte shared_ptr-like entry, and calls the mf2 functor for each one.
// INFERRED: the 4th stack arg (+0x40) is a G3D aligned buffer, freed with alignedFree on exit.
#include <intrin.h>

struct SharedCount {
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use;
    long weak;
};

struct SlotEntry {
    void* px;
    SharedCount* pn;
};

struct SlotData {
    SlotEntry* first;  // +0x00
    int pad[2];
    SlotEntry* cur;    // +0x0c
    SlotEntry* end;    // +0x10
};

struct SlotHolder {
    SlotData* px;
    SharedCount* pn;
};

struct SlotList {
    char pad[0x108];
    void* head;        // +0x108
};

extern "C" void __fastcall fn_004915b0(SlotList* self, int unusedEdx, SlotHolder* out);
extern "C" void __fastcall fn_00496910(void* self, int unusedEdx, int arg);
extern "C" void fn_00507d20(void* p);

extern "C" void __fastcall fn_004984d0(SlotList* self, int unusedEdx,
                                       int a0, int a1, int a2, void* buf,
                                       int a4, int a5, int a6, int a7)
{
    if (self->head) {
        SlotHolder holder;
        fn_004915b0(self, 0, &holder);
        SlotData* d = holder.px;
        for (SlotEntry* it = d->cur; it != d->end; ++it) {
            SlotEntry copy = *it;
            if (copy.pn)
                _InterlockedIncrement(&copy.pn->weak);
            // INFERRED: forwarded arg is the 3rd stack arg ([esp+0x48] at the call)
            fn_00496910(&copy, 0, a2);
        }
        if (holder.pn) {
            if (_InterlockedDecrement(&holder.pn->use) == 0) {
                holder.pn->dispose();
                if (_InterlockedDecrement(&holder.pn->weak) == 0)
                    holder.pn->destroy();
            }
        }
    }
    fn_00507d20(buf);
}
