// from server: 100% by EspClaude
// roc 2009-06 0044cdc0  unit: CRobloxControlColorSelector  size: 201 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044cdc0
//
// 0044cdc0  6aff                 push -1
// 0044cdc2  68e80d8500           push 0x850de8
// 0044cdc7  64a100000000         mov eax, dword ptr fs:[0]
// 0044cdcd  50                   push eax
// 0044cdce  64892500000000       mov dword ptr fs:[0], esp
// 0044cdd5  51                   push ecx
// 0044cdd6  56                   push esi
// 0044cdd7  8bf1                 mov esi, ecx
// 0044cdd9  57                   push edi
// 0044cdda  89742408             mov dword ptr [esp + 8], esi
// 0044cdde  e8fd532d00           call 0x7221e0
// 0044cde3  33c0                 xor eax, eax
// 0044cde5  88867c010000         mov byte ptr [esi + 0x17c], al
// 0044cdeb  89442414             mov dword ptr [esp + 0x14], eax
// 0044cdef  c70634788b00         mov dword ptr [esi], 0x8b7834
// 0044cdf5  c74620d4778b00       mov dword ptr [esi + 0x20], 0x8b77d4
// 0044cdfc  8b0d5cb3a300         mov ecx, dword ptr [0xa3b35c]
// 0044ce02  2b0d58b3a300         sub ecx, dword ptr [0xa3b358]
// 0044ce08  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044ce0d  f7e9                 imul ecx
// 0044ce0f  d1fa                 sar edx, 1
// 0044ce11  8bc2                 mov eax, edx
// 0044ce13  c1e81f               shr eax, 0x1f
// 0044ce16  03c2                 add eax, edx
// 0044ce18  753e                 jne 0x44ce58
// 0044ce1a  53                   push ebx
// 0044ce1b  55                   push ebp
// 0044ce1c  e8bf571f00           call 0x6425e0
// 0044ce21  8b5810               mov ebx, dword ptr [eax + 0x10]
// 0044ce24  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 0044ce2a  39580c               cmp dword ptr [eax + 0xc], ebx
// 0044ce2d  7602                 jbe 0x44ce31
// 0044ce2f  ffd5                 call ebp
// 0044ce31  e8aa571f00           call 0x6425e0
// 0044ce36  8b780c               mov edi, dword ptr [eax + 0xc]
// 0044ce39  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0044ce3c  7602                 jbe 0x44ce40
// 0044ce3e  ffd5                 call ebp
// 0044ce40  3bfb                 cmp edi, ebx
// 0044ce42  7412                 je 0x44ce56
// 0044ce44  8b0f                 mov ecx, dword ptr [edi]
// 0044ce46  51                   push ecx
// 0044ce47  e8a4feffff           call 0x44ccf0
// 0044ce4c  83c704               add edi, 4
// 0044ce4f  83c404               add esp, 4
// 0044ce52  3bfb                 cmp edi, ebx
// 0044ce54  75ee                 jne 0x44ce44
// 0044ce56  5d                   pop ebp
// 0044ce57  5b                   pop ebx
// 0044ce58  83cfff               or edi, 0xffffffff
// 0044ce5b  6a10                 push 0x10
// 0044ce5d  8bce                 mov ecx, esi
// 0044ce5f  89be74010000         mov dword ptr [esi + 0x174], edi
// 0044ce65  89be80010000         mov dword ptr [esi + 0x180], edi
// 0044ce6b  e8d02b2d00           call 0x71fa40
// 0044ce70  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044ce74  89be78010000         mov dword ptr [esi + 0x178], edi
// 0044ce7a  5f                   pop edi
// 0044ce7b  8bc6                 mov eax, esi
// 0044ce7d  5e                   pop esi
// 0044ce7e  64890d00000000       mov dword ptr fs:[0], ecx
// 0044ce85  83c410               add esp, 0x10
// 0044ce88  c3                   ret 
// copied from an identical function in another client (function ??0CRobloxControlColorSelector@@QAE@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
#include <algorithm>

namespace RBX {
class BrickColor {
public:
    int number;
    static const std::vector<BrickColor>& colorPalette();
};
}

class PartA {
public:
    virtual ~PartA();
    char pad[0x1c];
};
class PartB {
public:
    virtual void onB();
};

class ControlBase : public PartA, public PartB {
public:
    ControlBase();
    virtual ~ControlBase();
    void SetFlags(unsigned flags);
    char pad[0x174 - 0x24];
};

struct ColorEntry {
    int a, b, c;
};

class CRobloxControlColorSelector : public ControlBase {
public:
    int m_174;
    int m_178;
    bool m_17c;
    int m_180;
    CRobloxControlColorSelector();
    virtual ~CRobloxControlColorSelector();
    virtual void onB();
    static std::vector<ColorEntry> colors;
    static void addColor(RBX::BrickColor color);
};

CRobloxControlColorSelector::CRobloxControlColorSelector()
    : m_17c(false)
{
    if (colors.empty())
        std::for_each(RBX::BrickColor::colorPalette().begin(), RBX::BrickColor::colorPalette().end(), &addColor);
    m_174 = -1;
    m_180 = -1;
    SetFlags(0x10);
    m_178 = -1;
}