// from server: 100% by Yeetserama
// roc 2010-06 00434230  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00434230
//
// 00434230  56                   push esi
// 00434231  8bf1                 mov esi, ecx
// 00434233  e8383d3700           call 0x7a7f70
// 00434238  83f8ff               cmp eax, -1
// 0043423b  7506                 jne 0x434243
// 0043423d  0bc0                 or eax, eax
// 0043423f  5e                   pop esi
// 00434240  c20400               ret 4
// 00434243  6a06                 push 6
// 00434245  8bce                 mov ecx, esi
// 00434247  e8a4f53c00           call 0x8037f0
// 0043424c  e8ff023900           call 0x7c4550
// 00434251  83c004               add eax, 4
// 00434254  50                   push eax
// 00434255  ff1580a39e00         call dword ptr [0x9ea380]
// 0043425b  e8f0023900           call 0x7c4550
// 00434260  50                   push eax
// 00434261  8bce                 mov ecx, esi
// 00434263  e828da3c00           call 0x801c90
// 00434268  33c0                 xor eax, eax
// 0043426a  5e                   pop esi
// 0043426b  c20400               ret 4
// copied from an identical function in another client (function ?Create@S@ns_ROCX000006@@QAEHPAX@Z)

namespace ns_ROCX000006 {
// from server: 100% by king_originala
extern "C" long (__stdcall *InterlockedIncrement)(volatile long *);
extern long * __cdecl GetSharedObject();

struct S {
    int QueryState();
    void SetMode(int);
    void SetSharedObject(long *);
    int Create(void *);
};

int S::Create(void *)
{
    if (QueryState() == -1)
        return -1;

    SetMode(6);
    InterlockedIncrement(GetSharedObject() + 1);
    SetSharedObject(GetSharedObject());
    return 0;
}
}
