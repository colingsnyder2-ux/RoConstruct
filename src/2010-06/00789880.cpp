// from server: 100% by auto
// roc 2010-06 00789880  unit: RBX::HUMAN::GettingUp  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00789880
//
// 00789880  83ec08               sub esp, 8
// 00789883  53                   push ebx
// 00789884  56                   push esi
// 00789885  8bf1                 mov esi, ecx
// 00789887  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0078988a  57                   push edi
// 0078988b  85db                 test ebx, ebx
// 0078988d  7504                 jne 0x789893
// 0078988f  33c9                 xor ecx, ecx
// 00789891  eb16                 jmp 0x7898a9
// 00789893  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00789896  2bcb                 sub ecx, ebx
// 00789898  b867666666           mov eax, 0x66666667
// 0078989d  f7e9                 imul ecx
// 0078989f  c1fa04               sar edx, 4
// 007898a2  8bca                 mov ecx, edx
// 007898a4  c1e91f               shr ecx, 0x1f
// 007898a7  03ca                 add ecx, edx
// 007898a9  8b7e10               mov edi, dword ptr [esi + 0x10]
// 007898ac  8bd7                 mov edx, edi
// 007898ae  2bd3                 sub edx, ebx
// 007898b0  b867666666           mov eax, 0x66666667
// 007898b5  f7ea                 imul edx
// 007898b7  c1fa04               sar edx, 4
// 007898ba  8bc2                 mov eax, edx
// 007898bc  c1e81f               shr eax, 0x1f
// 007898bf  03c2                 add eax, edx
// 007898c1  3bc1                 cmp eax, ecx
// 007898c3  7332                 jae 0x7898f7
// 007898c5  8b542418             mov edx, dword ptr [esp + 0x18]
// 007898c9  c644240c00           mov byte ptr [esp + 0xc], 0
// 007898ce  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007898d2  51                   push ecx
// 007898d3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007898d7  52                   push edx
// 007898d8  8d4608               lea eax, [esi + 8]
// 007898db  50                   push eax
// 007898dc  51                   push ecx
// 007898dd  6a01                 push 1
// 007898df  57                   push edi
// 007898e0  e83bedffff           call 0x788620
// 007898e5  83c418               add esp, 0x18
// 007898e8  83c728               add edi, 0x28
// 007898eb  897e10               mov dword ptr [esi + 0x10], edi
// 007898ee  5f                   pop edi
// 007898ef  5e                   pop esi
// 007898f0  5b                   pop ebx
// 007898f1  83c408               add esp, 8
// 007898f4  c20400               ret 4
// 007898f7  3bdf                 cmp ebx, edi
// 007898f9  7606                 jbe 0x789901
// 007898fb  ff150ca99e00         call dword ptr [0x9ea90c]
// 00789901  8b542418             mov edx, dword ptr [esp + 0x18]
// 00789905  8b06                 mov eax, dword ptr [esi]
// 00789907  52                   push edx
// 00789908  57                   push edi
// 00789909  50                   push eax
// 0078990a  8d442418             lea eax, [esp + 0x18]
// 0078990e  50                   push eax
// 0078990f  8bce                 mov ecx, esi
// 00789911  e8dafdffff           call 0x7896f0
// 00789916  5f                   pop edi
// 00789917  5e                   pop esi
// 00789918  5b                   pop ebx
// 00789919  83c408               add esp, 8
// 0078991c  c20400               ret 4
// standard library vector<pod40> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod40>
struct E { int v[10]; };
#include <vector>
template class std::vector<E>;
