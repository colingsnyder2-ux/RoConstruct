// from server: 100% by auto
// roc 2010-06 006ac930  unit: RBX::PriorityThreadPool::PriorityThreadPoolData  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006ac930
//
// 006ac930  83ec08               sub esp, 8
// 006ac933  53                   push ebx
// 006ac934  56                   push esi
// 006ac935  8bf1                 mov esi, ecx
// 006ac937  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 006ac93a  57                   push edi
// 006ac93b  85db                 test ebx, ebx
// 006ac93d  7504                 jne 0x6ac943
// 006ac93f  33c9                 xor ecx, ecx
// 006ac941  eb16                 jmp 0x6ac959
// 006ac943  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 006ac946  2bcb                 sub ecx, ebx
// 006ac948  b867666666           mov eax, 0x66666667
// 006ac94d  f7e9                 imul ecx
// 006ac94f  c1fa04               sar edx, 4
// 006ac952  8bca                 mov ecx, edx
// 006ac954  c1e91f               shr ecx, 0x1f
// 006ac957  03ca                 add ecx, edx
// 006ac959  8b7e10               mov edi, dword ptr [esi + 0x10]
// 006ac95c  8bd7                 mov edx, edi
// 006ac95e  2bd3                 sub edx, ebx
// 006ac960  b867666666           mov eax, 0x66666667
// 006ac965  f7ea                 imul edx
// 006ac967  c1fa04               sar edx, 4
// 006ac96a  8bc2                 mov eax, edx
// 006ac96c  c1e81f               shr eax, 0x1f
// 006ac96f  03c2                 add eax, edx
// 006ac971  3bc1                 cmp eax, ecx
// 006ac973  7332                 jae 0x6ac9a7
// 006ac975  8b542418             mov edx, dword ptr [esp + 0x18]
// 006ac979  c644240c00           mov byte ptr [esp + 0xc], 0
// 006ac97e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006ac982  51                   push ecx
// 006ac983  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006ac987  52                   push edx
// 006ac988  8d4608               lea eax, [esi + 8]
// 006ac98b  50                   push eax
// 006ac98c  51                   push ecx
// 006ac98d  6a01                 push 1
// 006ac98f  57                   push edi
// 006ac990  e8cbeaffff           call 0x6ab460
// 006ac995  83c418               add esp, 0x18
// 006ac998  83c728               add edi, 0x28
// 006ac99b  897e10               mov dword ptr [esi + 0x10], edi
// 006ac99e  5f                   pop edi
// 006ac99f  5e                   pop esi
// 006ac9a0  5b                   pop ebx
// 006ac9a1  83c408               add esp, 8
// 006ac9a4  c20400               ret 4
// 006ac9a7  3bdf                 cmp ebx, edi
// 006ac9a9  7606                 jbe 0x6ac9b1
// 006ac9ab  ff150ca99e00         call dword ptr [0x9ea90c]
// 006ac9b1  8b542418             mov edx, dword ptr [esp + 0x18]
// 006ac9b5  8b06                 mov eax, dword ptr [esi]
// 006ac9b7  52                   push edx
// 006ac9b8  57                   push edi
// 006ac9b9  50                   push eax
// 006ac9ba  8d442418             lea eax, [esp + 0x18]
// 006ac9be  50                   push eax
// 006ac9bf  8bce                 mov ecx, esi
// 006ac9c1  e8eafdffff           call 0x6ac7b0
// 006ac9c6  5f                   pop edi
// 006ac9c7  5e                   pop esi
// 006ac9c8  5b                   pop ebx
// 006ac9c9  83c408               add esp, 8
// 006ac9cc  c20400               ret 4
// standard library vector<pod40> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod40>
struct E { int v[10]; };
#include <vector>
template class std::vector<E>;
