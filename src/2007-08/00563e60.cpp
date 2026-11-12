// from server: 100% by EspClaude
// from server: 54% by colin
// roc 2007-08 00563e60  unit: RBX::WeldSelectionVerb  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00563e60
//
// 00563e60  51                   push ecx
// 00563e61  56                   push esi
// 00563e62  8bf1                 mov esi, ecx
// 00563e64  6a01                 push 1
// 00563e66  8d4e14               lea ecx, [esi + 0x14]
// 00563e69  e892e4ffff           call 0x562300
// 00563e6e  8b8004010000         mov eax, dword ptr [eax + 0x104]
// 00563e74  8b4804               mov ecx, dword ptr [eax + 4]
// 00563e77  85c9                 test ecx, ecx
// 00563e79  740a                 je 0x563e85
// 00563e7b  8b4008               mov eax, dword ptr [eax + 8]
// 00563e7e  2bc1                 sub eax, ecx
// 00563e80  c1f803               sar eax, 3
// 00563e83  7505                 jne 0x563e8a
// 00563e85  32c0                 xor al, al
// 00563e87  5e                   pop esi
// 00563e88  59                   pop ecx
// 00563e89  c3                   ret 
// 00563e8a  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00563e8d  85c9                 test ecx, ecx
// 00563e8f  7407                 je 0x563e98
// 00563e91  e8aaceeaff           call 0x410d40
// 00563e96  eb02                 jmp 0x563e9a
// 00563e98  33c0                 xor eax, eax
// 00563e9a  8b8004010000         mov eax, dword ptr [eax + 0x104]
// 00563ea0  8b4804               mov ecx, dword ptr [eax + 4]
// 00563ea3  85c9                 test ecx, ecx
// 00563ea5  750b                 jne 0x563eb2
// 00563ea7  33c0                 xor eax, eax
// 00563ea9  3bc8                 cmp ecx, eax
// 00563eab  1bc0                 sbb eax, eax
// 00563ead  f7d8                 neg eax
// 00563eaf  5e                   pop esi
// 00563eb0  59                   pop ecx
// 00563eb1  c3                   ret 
// 00563eb2  8b4008               mov eax, dword ptr [eax + 8]
// 00563eb5  2bc1                 sub eax, ecx
// 00563eb7  c1f803               sar eax, 3
// 00563eba  33c9                 xor ecx, ecx
// 00563ebc  3bc8                 cmp ecx, eax
// 00563ebe  1bc0                 sbb eax, eax
// 00563ec0  f7d8                 neg eax
// 00563ec2  5e                   pop esi
// 00563ec3  59                   pop ecx
// 00563ec4  c3                   ret 
#include <vector>

struct Elem { int a; int b; };
typedef std::vector<Elem> ElemVec;

struct Target {
    char pad[0x104];
    ElemVec* items;
};

struct Helper562300 {
    Target* method(int);
};

struct Helper410D40 {
    Target* method();
};

struct WeldSelectionVerb {
    char pad[0x14];
    Helper562300 field14;
    char pad2[0x20 - 0x15];
    Helper410D40* field20;
    bool method();
};

bool WeldSelectionVerb::method() {
    if (field14.method(1)->items->size() == 0)
        return false;
    Target* t = field20 ? field20->method() : 0;
    return t->items->size() > 0;
}
