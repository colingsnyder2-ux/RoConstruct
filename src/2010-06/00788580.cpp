// from server: 100% by auto
// roc 2010-06 00788580  unit: RBX::HUMAN::GettingUp  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00788580
//
// 00788580  83ec08               sub esp, 8
// 00788583  53                   push ebx
// 00788584  56                   push esi
// 00788585  8bf1                 mov esi, ecx
// 00788587  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0078858a  57                   push edi
// 0078858b  85db                 test ebx, ebx
// 0078858d  7504                 jne 0x788593
// 0078858f  33c9                 xor ecx, ecx
// 00788591  eb16                 jmp 0x7885a9
// 00788593  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00788596  2bcb                 sub ecx, ebx
// 00788598  b867666666           mov eax, 0x66666667
// 0078859d  f7e9                 imul ecx
// 0078859f  c1fa03               sar edx, 3
// 007885a2  8bca                 mov ecx, edx
// 007885a4  c1e91f               shr ecx, 0x1f
// 007885a7  03ca                 add ecx, edx
// 007885a9  8b7e10               mov edi, dword ptr [esi + 0x10]
// 007885ac  8bd7                 mov edx, edi
// 007885ae  2bd3                 sub edx, ebx
// 007885b0  b867666666           mov eax, 0x66666667
// 007885b5  f7ea                 imul edx
// 007885b7  c1fa03               sar edx, 3
// 007885ba  8bc2                 mov eax, edx
// 007885bc  c1e81f               shr eax, 0x1f
// 007885bf  03c2                 add eax, edx
// 007885c1  3bc1                 cmp eax, ecx
// 007885c3  7332                 jae 0x7885f7
// 007885c5  8b542418             mov edx, dword ptr [esp + 0x18]
// 007885c9  c644240c00           mov byte ptr [esp + 0xc], 0
// 007885ce  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007885d2  51                   push ecx
// 007885d3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007885d7  52                   push edx
// 007885d8  8d4608               lea eax, [esi + 8]
// 007885db  50                   push eax
// 007885dc  51                   push ecx
// 007885dd  6a01                 push 1
// 007885df  57                   push edi
// 007885e0  e87befffff           call 0x787560
// 007885e5  83c418               add esp, 0x18
// 007885e8  83c714               add edi, 0x14
// 007885eb  897e10               mov dword ptr [esi + 0x10], edi
// 007885ee  5f                   pop edi
// 007885ef  5e                   pop esi
// 007885f0  5b                   pop ebx
// 007885f1  83c408               add esp, 8
// 007885f4  c20400               ret 4
// 007885f7  3bdf                 cmp ebx, edi
// 007885f9  7606                 jbe 0x788601
// 007885fb  ff150ca99e00         call dword ptr [0x9ea90c]
// 00788601  8b542418             mov edx, dword ptr [esp + 0x18]
// 00788605  8b06                 mov eax, dword ptr [esi]
// 00788607  52                   push edx
// 00788608  57                   push edi
// 00788609  50                   push eax
// 0078860a  8d442418             lea eax, [esp + 0x18]
// 0078860e  50                   push eax
// 0078860f  8bce                 mov ecx, esi
// 00788611  e83af8ffff           call 0x787e50
// 00788616  5f                   pop edi
// 00788617  5e                   pop esi
// 00788618  5b                   pop ebx
// 00788619  83c408               add esp, 8
// 0078861c  c20400               ret 4
// standard library vector<pod20> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
