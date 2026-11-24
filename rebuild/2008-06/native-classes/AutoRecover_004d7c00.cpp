// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <intrin.h>
// INFERRED: slot list layout from disassembly: {begin@+0, end@+0xc/+0x10 of data_t}; vector of 8-byte shared_ptr-like entries.
struct SpCount { void** vtbl; long use; long weak; };
struct SlotEntry { void* px; SpCount* pn; };
struct SlotData { SlotEntry* begin; int pad[2]; SlotEntry* cur; SlotEntry* end; };

extern "C" int __fastcall fn_004d7c00(void* self, int unusedEdx, int a1, int a2);
extern "C" void __fastcall fn_004e6300(void* self, int unusedEdx, int arg);
extern "C" void fn_004915b0(void* slot, SlotData** out);

extern "C" int __fastcall fn_004d7c00(void* self, int unusedEdx, int a1, int a2)
{
    // INFERRED: signal member at +0x108; null means no slots connected
    char* sig = (char*)self + 0x108;
    if (*(int*)sig != 0) {
        SlotData* d;
        fn_004915b0(sig, &d);
        for (SlotEntry* it = d->cur; it != d->end; ++it) {
            SlotEntry tmp = *it;
            if (tmp.pn)
                _InterlockedIncrement(&tmp.pn->use);
            fn_004e6300(&tmp, 0, a1);
            fn_004d7c00(it->px, 0, a1, a2);
        }
    }
    return 0;
}
