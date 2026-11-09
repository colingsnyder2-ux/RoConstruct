// from server: 100% by auto
// roc 2010-06 00743670  unit: RBX::VHttp::?$sp_counted_impl_p  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00743670
//
// 00743670  83ec08               sub esp, 8
// 00743673  53                   push ebx
// 00743674  56                   push esi
// 00743675  8bf1                 mov esi, ecx
// 00743677  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0074367a  57                   push edi
// 0074367b  85db                 test ebx, ebx
// 0074367d  7504                 jne 0x743683
// 0074367f  33c9                 xor ecx, ecx
// 00743681  eb16                 jmp 0x743699
// 00743683  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00743686  2bcb                 sub ecx, ebx
// 00743688  b867666666           mov eax, 0x66666667
// 0074368d  f7e9                 imul ecx
// 0074368f  c1fa04               sar edx, 4
// 00743692  8bca                 mov ecx, edx
// 00743694  c1e91f               shr ecx, 0x1f
// 00743697  03ca                 add ecx, edx
// 00743699  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0074369c  8bd7                 mov edx, edi
// 0074369e  2bd3                 sub edx, ebx
// 007436a0  b867666666           mov eax, 0x66666667
// 007436a5  f7ea                 imul edx
// 007436a7  c1fa04               sar edx, 4
// 007436aa  8bc2                 mov eax, edx
// 007436ac  c1e81f               shr eax, 0x1f
// 007436af  03c2                 add eax, edx
// 007436b1  3bc1                 cmp eax, ecx
// 007436b3  7332                 jae 0x7436e7
// 007436b5  8b542418             mov edx, dword ptr [esp + 0x18]
// 007436b9  c644240c00           mov byte ptr [esp + 0xc], 0
// 007436be  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007436c2  51                   push ecx
// 007436c3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007436c7  52                   push edx
// 007436c8  8d4608               lea eax, [esi + 8]
// 007436cb  50                   push eax
// 007436cc  51                   push ecx
// 007436cd  6a01                 push 1
// 007436cf  57                   push edi
// 007436d0  e8abe7ffff           call 0x741e80
// 007436d5  83c418               add esp, 0x18
// 007436d8  83c728               add edi, 0x28
// 007436db  897e10               mov dword ptr [esi + 0x10], edi
// 007436de  5f                   pop edi
// 007436df  5e                   pop esi
// 007436e0  5b                   pop ebx
// 007436e1  83c408               add esp, 8
// 007436e4  c20400               ret 4
// 007436e7  3bdf                 cmp ebx, edi
// 007436e9  7606                 jbe 0x7436f1
// 007436eb  ff150ca99e00         call dword ptr [0x9ea90c]
// 007436f1  8b542418             mov edx, dword ptr [esp + 0x18]
// 007436f5  8b06                 mov eax, dword ptr [esi]
// 007436f7  52                   push edx
// 007436f8  57                   push edi
// 007436f9  50                   push eax
// 007436fa  8d442418             lea eax, [esp + 0x18]
// 007436fe  50                   push eax
// 007436ff  8bce                 mov ecx, esi
// 00743701  e80afeffff           call 0x743510
// 00743706  5f                   pop edi
// 00743707  5e                   pop esi
// 00743708  5b                   pop ebx
// 00743709  83c408               add esp, 8
// 0074370c  c20400               ret 4
// standard library vector<pod40> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod40>
struct E { int v[10]; };
#include <vector>
template class std::vector<E>;
