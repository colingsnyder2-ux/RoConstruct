// from server: 100% by auto
// roc 2010-06 00731f70  unit: lua_exception  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00731f70
//
// 00731f70  83ec08               sub esp, 8
// 00731f73  53                   push ebx
// 00731f74  56                   push esi
// 00731f75  8bf1                 mov esi, ecx
// 00731f77  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00731f7a  57                   push edi
// 00731f7b  85db                 test ebx, ebx
// 00731f7d  7504                 jne 0x731f83
// 00731f7f  33c9                 xor ecx, ecx
// 00731f81  eb16                 jmp 0x731f99
// 00731f83  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00731f86  2bcb                 sub ecx, ebx
// 00731f88  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00731f8d  f7e9                 imul ecx
// 00731f8f  c1fa02               sar edx, 2
// 00731f92  8bca                 mov ecx, edx
// 00731f94  c1e91f               shr ecx, 0x1f
// 00731f97  03ca                 add ecx, edx
// 00731f99  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00731f9c  8bd7                 mov edx, edi
// 00731f9e  2bd3                 sub edx, ebx
// 00731fa0  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00731fa5  f7ea                 imul edx
// 00731fa7  c1fa02               sar edx, 2
// 00731faa  8bc2                 mov eax, edx
// 00731fac  c1e81f               shr eax, 0x1f
// 00731faf  03c2                 add eax, edx
// 00731fb1  3bc1                 cmp eax, ecx
// 00731fb3  7332                 jae 0x731fe7
// 00731fb5  8b542418             mov edx, dword ptr [esp + 0x18]
// 00731fb9  c644240c00           mov byte ptr [esp + 0xc], 0
// 00731fbe  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00731fc2  51                   push ecx
// 00731fc3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00731fc7  52                   push edx
// 00731fc8  8d4608               lea eax, [esi + 8]
// 00731fcb  50                   push eax
// 00731fcc  51                   push ecx
// 00731fcd  6a01                 push 1
// 00731fcf  57                   push edi
// 00731fd0  e88bf1ffff           call 0x731160
// 00731fd5  83c418               add esp, 0x18
// 00731fd8  83c718               add edi, 0x18
// 00731fdb  897e10               mov dword ptr [esi + 0x10], edi
// 00731fde  5f                   pop edi
// 00731fdf  5e                   pop esi
// 00731fe0  5b                   pop ebx
// 00731fe1  83c408               add esp, 8
// 00731fe4  c20400               ret 4
// 00731fe7  3bdf                 cmp ebx, edi
// 00731fe9  7606                 jbe 0x731ff1
// 00731feb  ff150ca99e00         call dword ptr [0x9ea90c]
// 00731ff1  8b542418             mov edx, dword ptr [esp + 0x18]
// 00731ff5  8b06                 mov eax, dword ptr [esi]
// 00731ff7  52                   push edx
// 00731ff8  57                   push edi
// 00731ff9  50                   push eax
// 00731ffa  8d442418             lea eax, [esp + 0x18]
// 00731ffe  50                   push eax
// 00731fff  8bce                 mov ecx, esi
// 00732001  e80afeffff           call 0x731e10
// 00732006  5f                   pop edi
// 00732007  5e                   pop esi
// 00732008  5b                   pop ebx
// 00732009  83c408               add esp, 8
// 0073200c  c20400               ret 4
// standard library vector<pod24> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
