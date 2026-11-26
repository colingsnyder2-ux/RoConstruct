// from server: 100% by Xemicl
// roc 2012-06 00744ee0  unit: boost::Vbad_lexical_cast::U?$error_info_injector::?$clone_impl  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00744ee0
//
// 00744ee0  6aff                 push -1
// 00744ee2  684316ac00           push 0xac1643
// 00744ee7  64a100000000         mov eax, dword ptr fs:[0]
// 00744eed  50                   push eax
// 00744eee  64892500000000       mov dword ptr fs:[0], esp
// 00744ef5  83ec20               sub esp, 0x20
// 00744ef8  53                   push ebx
// 00744ef9  56                   push esi
// 00744efa  57                   push edi
// 00744efb  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 00744eff  33db                 xor ebx, ebx
// 00744f01  895c240c             mov dword ptr [esp + 0xc], ebx
// 00744f05  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 00744f09  57                   push edi
// 00744f0a  56                   push esi
// 00744f0b  895c243c             mov dword ptr [esp + 0x3c], ebx
// 00744f0f  e80cf3ffff           call 0x744220
// 00744f14  83c408               add esp, 8
// 00744f17  68402fb500           push 0xb52f40
// 00744f1c  8bce                 mov ecx, esi
// 00744f1e  895c2438             mov dword ptr [esp + 0x38], ebx
// 00744f22  c744241001000000     mov dword ptr [esp + 0x10], 1
// 00744f2a  ff155c26b200         call dword ptr [0xb2265c]
// 00744f30  83c704               add edi, 4
// 00744f33  8d442410             lea eax, [esp + 0x10]
// 00744f37  57                   push edi
// 00744f38  50                   push eax
// 00744f39  e8e2f2ffff           call 0x744220
// 00744f3e  83c408               add esp, 8
// 00744f41  50                   push eax
// 00744f42  8bce                 mov ecx, esi
// 00744f44  c744243801000000     mov dword ptr [esp + 0x38], 1
// 00744f4c  ff15e026b200         call dword ptr [0xb226e0]
// 00744f52  8d4c2410             lea ecx, [esp + 0x10]
// 00744f56  885c2434             mov byte ptr [esp + 0x34], bl
// 00744f5a  ff153c26b200         call dword ptr [0xb2263c]
// 00744f60  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00744f64  5f                   pop edi
// 00744f65  8bc6                 mov eax, esi
// 00744f67  5e                   pop esi
// 00744f68  5b                   pop ebx
// 00744f69  64890d00000000       mov dword ptr fs:[0], ecx
// 00744f70  83c42c               add esp, 0x2c
// 00744f73  c3                   ret 
// copied from an identical function in another client (function ?toString@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ABUVector2@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
std::string formatFloat(const float& value);
struct Vector2 { float x, y; };
std::string toString(const Vector2& v)
{
    std::string s = formatFloat(v.x);
    s += ", ";
    s += formatFloat(v.y);
    return s;
}