// from server: 100% by Xemicl
// roc 2012-06 00702650  unit: RBX::ChangeHistoryService  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00702650
//
// 00702650  56                   push esi
// 00702651  8bf1                 mov esi, ecx
// 00702653  8b4e04               mov ecx, dword ptr [esi + 4]
// 00702656  ff157824b200         call dword ptr [0xb22478]
// 0070265c  83f8ff               cmp eax, -1
// 0070265f  7423                 je 0x702684
// 00702661  0fbec0               movsx eax, al
// 00702664  80b80098da0000       cmp byte ptr [eax + 0xda9800], 0
// 0070266b  7417                 je 0x702684
// 0070266d  8b4e04               mov ecx, dword ptr [esi + 4]
// 00702670  ff157c24b200         call dword ptr [0xb2247c]
// 00702676  8b4e04               mov ecx, dword ptr [esi + 4]
// 00702679  ff157824b200         call dword ptr [0xb22478]
// 0070267f  83f8ff               cmp eax, -1
// 00702682  75dd                 jne 0x702661
// 00702684  5e                   pop esi
// 00702685  c3                   ret 
// copied from an identical function in another client (function ?skip@Reader_0061d930@@QAEXXZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <streambuf>
extern bool table_0061d930[];
struct Reader_0061d930 {
    int pad;
    std::streambuf* buf;
    void skip();
};
void Reader_0061d930::skip()
{
    int c = buf->sgetc();
    while (c != -1 && table_0061d930[(char)c]) {
        buf->sbumpc();
        c = buf->sgetc();
    }
}