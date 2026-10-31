// from server: 100% by EspClaude
// roc 2009-06 0044c440  unit: CRobloxControlColorSelector  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044c440
//
// 0044c440  56                   push esi
// 0044c441  57                   push edi
// 0044c442  8bf9                 mov edi, ecx
// 0044c444  8bb778010000         mov esi, dword ptr [edi + 0x178]
// 0044c44a  83feff               cmp esi, -1
// 0044c44d  743f                 je 0x44c48e
// 0044c44f  8b0d5cb3a300         mov ecx, dword ptr [0xa3b35c]
// 0044c455  2b0d58b3a300         sub ecx, dword ptr [0xa3b358]
// 0044c45b  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044c460  f7e9                 imul ecx
// 0044c462  d1fa                 sar edx, 1
// 0044c464  8bc2                 mov eax, edx
// 0044c466  c1e81f               shr eax, 0x1f
// 0044c469  03c2                 add eax, edx
// 0044c46b  3bf0                 cmp esi, eax
// 0044c46d  7206                 jb 0x44c475
// 0044c46f  ff15ace98900         call dword ptr [0x89e9ac]
// 0044c475  8b1558b3a300         mov edx, dword ptr [0xa3b358]
// 0044c47b  8d0c76               lea ecx, [esi + esi*2]
// 0044c47e  8b048a               mov eax, dword ptr [edx + ecx*4]
// 0044c481  898780010000         mov dword ptr [edi + 0x180], eax
// 0044c487  c6877c01000001       mov byte ptr [edi + 0x17c], 1
// 0044c48e  8bcf                 mov ecx, edi
// 0044c490  5f                   pop edi
// 0044c491  5e                   pop esi
// 0044c492  e9295a2d00           jmp 0x721ec0
// copied from an identical function in another client (function ?update@S@ns_ROCX000019@@QAEXXZ)

namespace ns_ROCX000019 {
struct Entry {
    unsigned color;
    unsigned data[2];
};

extern Entry* entries_begin;
extern Entry* entries_end;
extern "C" void (__cdecl* invalid_parameter_noinfo)();

struct S {
    char padding[0x178];
    unsigned index;
    unsigned char selected;
    char padding2[3];
    unsigned color;

    void update();
    void finish();
};

void S::update()
{
    unsigned i = index;
    if (i != (unsigned)-1) {
        if (i >= (unsigned)(entries_end - entries_begin))
            invalid_parameter_noinfo();
        color = entries_begin[i].color;
        selected = 1;
    }
    finish();
}
}
