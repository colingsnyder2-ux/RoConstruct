// from server: 100% by auto
// roc 2009-12 007bd5b0  unit: RBX::GuiLayerCollector  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007bd5b0
//
// 007bd5b0  83ec08               sub esp, 8
// 007bd5b3  53                   push ebx
// 007bd5b4  56                   push esi
// 007bd5b5  8bf1                 mov esi, ecx
// 007bd5b7  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 007bd5ba  57                   push edi
// 007bd5bb  85db                 test ebx, ebx
// 007bd5bd  7504                 jne 0x7bd5c3
// 007bd5bf  33c9                 xor ecx, ecx
// 007bd5c1  eb16                 jmp 0x7bd5d9
// 007bd5c3  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007bd5c6  2bcb                 sub ecx, ebx
// 007bd5c8  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007bd5cd  f7e9                 imul ecx
// 007bd5cf  c1fa02               sar edx, 2
// 007bd5d2  8bca                 mov ecx, edx
// 007bd5d4  c1e91f               shr ecx, 0x1f
// 007bd5d7  03ca                 add ecx, edx
// 007bd5d9  8b7e10               mov edi, dword ptr [esi + 0x10]
// 007bd5dc  8bd7                 mov edx, edi
// 007bd5de  2bd3                 sub edx, ebx
// 007bd5e0  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007bd5e5  f7ea                 imul edx
// 007bd5e7  c1fa02               sar edx, 2
// 007bd5ea  8bc2                 mov eax, edx
// 007bd5ec  c1e81f               shr eax, 0x1f
// 007bd5ef  03c2                 add eax, edx
// 007bd5f1  3bc1                 cmp eax, ecx
// 007bd5f3  7332                 jae 0x7bd627
// 007bd5f5  8b542418             mov edx, dword ptr [esp + 0x18]
// 007bd5f9  c644240c00           mov byte ptr [esp + 0xc], 0
// 007bd5fe  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007bd602  51                   push ecx
// 007bd603  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007bd607  52                   push edx
// 007bd608  8d4608               lea eax, [esi + 8]
// 007bd60b  50                   push eax
// 007bd60c  51                   push ecx
// 007bd60d  6a01                 push 1
// 007bd60f  57                   push edi
// 007bd610  e8dbf7ffff           call 0x7bcdf0
// 007bd615  83c418               add esp, 0x18
// 007bd618  83c718               add edi, 0x18
// 007bd61b  897e10               mov dword ptr [esi + 0x10], edi
// 007bd61e  5f                   pop edi
// 007bd61f  5e                   pop esi
// 007bd620  5b                   pop ebx
// 007bd621  83c408               add esp, 8
// 007bd624  c20400               ret 4
// 007bd627  3bdf                 cmp ebx, edi
// 007bd629  7606                 jbe 0x7bd631
// 007bd62b  ff1560b79800         call dword ptr [0x98b760]
// 007bd631  8b542418             mov edx, dword ptr [esp + 0x18]
// 007bd635  8b06                 mov eax, dword ptr [esi]
// 007bd637  52                   push edx
// 007bd638  57                   push edi
// 007bd639  50                   push eax
// 007bd63a  8d442418             lea eax, [esp + 0x18]
// 007bd63e  50                   push eax
// 007bd63f  8bce                 mov ecx, esi
// 007bd641  e8bafeffff           call 0x7bd500
// 007bd646  5f                   pop edi
// 007bd647  5e                   pop esi
// 007bd648  5b                   pop ebx
// 007bd649  83c408               add esp, 8
// 007bd64c  c20400               ret 4
// standard library vector<pod24> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
