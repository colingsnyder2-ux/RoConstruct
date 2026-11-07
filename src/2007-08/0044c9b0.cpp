// from server: 100% by Intel
// from server: 98% by EspClaude
// roc 2007-08 0044c9b0  unit: CRobloxControlColorSelector  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044c9b0
//
// 0044c9b0  6aff                 push -1
// 0044c9b2  68c8027400           push 0x7402c8
// 0044c9b7  64a100000000         mov eax, dword ptr fs:[0]
// 0044c9bd  50                   push eax
// 0044c9be  83ec08               sub esp, 8
// 0044c9c1  53                   push ebx
// 0044c9c2  55                   push ebp
// 0044c9c3  56                   push esi
// 0044c9c4  57                   push edi
// 0044c9c5  a188518b00           mov eax, dword ptr [0x8b5188]
// 0044c9ca  33c4                 xor eax, esp
// 0044c9cc  50                   push eax
// 0044c9cd  8d44241c             lea eax, [esp + 0x1c]
// 0044c9d1  64a300000000         mov dword ptr fs:[0], eax
// 0044c9d7  8bf9                 mov edi, ecx
// 0044c9d9  897c2414             mov dword ptr [esp + 0x14], edi
// 0044c9dd  e82efe1e00           call 0x63c810
// 0044c9e2  33c9                 xor ecx, ecx
// 0044c9e4  c707b40a7900         mov dword ptr [edi], 0x790ab4
// 0044c9ea  c74720540a7900       mov dword ptr [edi + 0x20], 0x790a54
// 0044c9f1  888f70010000         mov byte ptr [edi + 0x170], cl
// 0044c9f7  a1bcbe8b00           mov eax, dword ptr [0x8bbebc]
// 0044c9fc  3bc1                 cmp eax, ecx
// 0044c9fe  894c2424             mov dword ptr [esp + 0x24], ecx
// 0044ca02  741a                 je 0x44ca1e
// 0044ca04  8b0dc0be8b00         mov ecx, dword ptr [0x8bbec0]
// 0044ca0a  2bc8                 sub ecx, eax
// 0044ca0c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044ca11  f7e9                 imul ecx
// 0044ca13  d1fa                 sar edx, 1
// 0044ca15  8bc2                 mov eax, edx
// 0044ca17  c1e81f               shr eax, 0x1f
// 0044ca1a  03c2                 add eax, edx
// 0044ca1c  753a                 jne 0x44ca58
// 0044ca1e  e8ed9b1300           call 0x586610
// 0044ca23  8b5808               mov ebx, dword ptr [eax + 8]
// 0044ca26  395804               cmp dword ptr [eax + 4], ebx
// 0044ca29  8b2dd8e67700         mov ebp, dword ptr [0x77e6d8]
// 0044ca2f  7602                 jbe 0x44ca33
// 0044ca31  ffd5                 call ebp
// 0044ca33  e8d89b1300           call 0x586610
// 0044ca38  8b7004               mov esi, dword ptr [eax + 4]
// 0044ca3b  3b7008               cmp esi, dword ptr [eax + 8]
// 0044ca3e  7602                 jbe 0x44ca42
// 0044ca40  ffd5                 call ebp
// 0044ca42  3bf3                 cmp esi, ebx
// 0044ca44  7412                 je 0x44ca58
// 0044ca46  8b0e                 mov ecx, dword ptr [esi]
// 0044ca48  51                   push ecx
// 0044ca49  e882feffff           call 0x44c8d0
// 0044ca4e  83c604               add esi, 4
// 0044ca51  83c404               add esp, 4
// 0044ca54  3bf3                 cmp esi, ebx
// 0044ca56  75ee                 jne 0x44ca46
// 0044ca58  83ceff               or esi, 0xffffffff
// 0044ca5b  6a10                 push 0x10
// 0044ca5d  8bcf                 mov ecx, edi
// 0044ca5f  89b768010000         mov dword ptr [edi + 0x168], esi
// 0044ca65  89b774010000         mov dword ptr [edi + 0x174], esi
// 0044ca6b  e8b0d61e00           call 0x63a120
// 0044ca70  89b76c010000         mov dword ptr [edi + 0x16c], esi
// 0044ca76  8bc7                 mov eax, edi
// 0044ca78  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0044ca7c  64890d00000000       mov dword ptr fs:[0], ecx
// 0044ca83  59                   pop ecx
// 0044ca84  5f                   pop edi
// 0044ca85  5e                   pop esi
// 0044ca86  5d                   pop ebp
// 0044ca87  5b                   pop ebx
// 0044ca88  83c414               add esp, 0x14
// 0044ca8b  c3                   ret 

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
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
    char pad[0x168 - 0x24];
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
