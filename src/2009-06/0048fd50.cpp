// from server: 100% by auto
// roc 2009-06 0048fd50  unit: Ogre::TextureCompositor  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048fd50
//
// 0048fd50  83ec08               sub esp, 8
// 0048fd53  53                   push ebx
// 0048fd54  55                   push ebp
// 0048fd55  56                   push esi
// 0048fd56  8bf1                 mov esi, ecx
// 0048fd58  8b4610               mov eax, dword ptr [esi + 0x10]
// 0048fd5b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0048fd5e  8bc8                 mov ecx, eax
// 0048fd60  2bcb                 sub ecx, ebx
// 0048fd62  57                   push edi
// 0048fd63  f7c1c0ffffff         test ecx, 0xffffffc0
// 0048fd69  7504                 jne 0x48fd6f
// 0048fd6b  33ff                 xor edi, edi
// 0048fd6d  eb27                 jmp 0x48fd96
// 0048fd6f  3bd8                 cmp ebx, eax
// 0048fd71  7606                 jbe 0x48fd79
// 0048fd73  ff15ace98900         call dword ptr [0x89e9ac]
// 0048fd79  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0048fd7d  8b06                 mov eax, dword ptr [esi]
// 0048fd7f  85c9                 test ecx, ecx
// 0048fd81  7404                 je 0x48fd87
// 0048fd83  3bc8                 cmp ecx, eax
// 0048fd85  7406                 je 0x48fd8d
// 0048fd87  ff15ace98900         call dword ptr [0x89e9ac]
// 0048fd8d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0048fd91  2bfb                 sub edi, ebx
// 0048fd93  c1ff06               sar edi, 6
// 0048fd96  8b542428             mov edx, dword ptr [esp + 0x28]
// 0048fd9a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0048fd9e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0048fda2  52                   push edx
// 0048fda3  6a01                 push 1
// 0048fda5  50                   push eax
// 0048fda6  51                   push ecx
// 0048fda7  8bce                 mov ecx, esi
// 0048fda9  e802fcffff           call 0x48f9b0
// 0048fdae  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0048fdb1  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0048fdb4  7606                 jbe 0x48fdbc
// 0048fdb6  ff15ace98900         call dword ptr [0x89e9ac]
// 0048fdbc  8b36                 mov esi, dword ptr [esi]
// 0048fdbe  8bee                 mov ebp, esi
// 0048fdc0  895c2414             mov dword ptr [esp + 0x14], ebx
// 0048fdc4  85f6                 test esi, esi
// 0048fdc6  751a                 jne 0x48fde2
// 0048fdc8  ff15ace98900         call dword ptr [0x89e9ac]
// 0048fdce  33c0                 xor eax, eax
// 0048fdd0  c1e706               shl edi, 6
// 0048fdd3  03fb                 add edi, ebx
// 0048fdd5  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0048fdd8  7713                 ja 0x48fded
// 0048fdda  85f6                 test esi, esi
// 0048fddc  7408                 je 0x48fde6
// 0048fdde  8b36                 mov esi, dword ptr [esi]
// 0048fde0  eb06                 jmp 0x48fde8
// 0048fde2  8b06                 mov eax, dword ptr [esi]
// 0048fde4  ebea                 jmp 0x48fdd0
// 0048fde6  33f6                 xor esi, esi
// 0048fde8  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0048fdeb  7306                 jae 0x48fdf3
// 0048fded  ff15ace98900         call dword ptr [0x89e9ac]
// 0048fdf3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048fdf7  897804               mov dword ptr [eax + 4], edi
// 0048fdfa  5f                   pop edi
// 0048fdfb  5e                   pop esi
// 0048fdfc  8928                 mov dword ptr [eax], ebp
// 0048fdfe  5d                   pop ebp
// 0048fdff  5b                   pop ebx
// 0048fe00  83c408               add esp, 8
// 0048fe03  c21000               ret 0x10
// standard library vector<pod64> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
