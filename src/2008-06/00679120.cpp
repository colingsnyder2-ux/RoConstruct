// from server: 100% by auto
// roc 2008-06 00679120  unit: Ogre::RbxSceneManagerFactory  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00679120
//
// 00679120  83ec08               sub esp, 8
// 00679123  53                   push ebx
// 00679124  55                   push ebp
// 00679125  56                   push esi
// 00679126  8bf1                 mov esi, ecx
// 00679128  8b4610               mov eax, dword ptr [esi + 0x10]
// 0067912b  57                   push edi
// 0067912c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0067912f  8bc8                 mov ecx, eax
// 00679131  2bcf                 sub ecx, edi
// 00679133  f7c1fcffffff         test ecx, 0xfffffffc
// 00679139  7504                 jne 0x67913f
// 0067913b  33db                 xor ebx, ebx
// 0067913d  eb27                 jmp 0x679166
// 0067913f  3bf8                 cmp edi, eax
// 00679141  7606                 jbe 0x679149
// 00679143  ff1590288000         call dword ptr [0x802890]
// 00679149  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0067914d  8b06                 mov eax, dword ptr [esi]
// 0067914f  85c9                 test ecx, ecx
// 00679151  7404                 je 0x679157
// 00679153  3bc8                 cmp ecx, eax
// 00679155  7406                 je 0x67915d
// 00679157  ff1590288000         call dword ptr [0x802890]
// 0067915d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00679161  2bdf                 sub ebx, edi
// 00679163  c1fb02               sar ebx, 2
// 00679166  8b542428             mov edx, dword ptr [esp + 0x28]
// 0067916a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0067916e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00679172  52                   push edx
// 00679173  6a01                 push 1
// 00679175  50                   push eax
// 00679176  51                   push ecx
// 00679177  8bce                 mov ecx, esi
// 00679179  e812e9e4ff           call 0x4c7a90
// 0067917e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00679181  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00679184  7606                 jbe 0x67918c
// 00679186  ff1590288000         call dword ptr [0x802890]
// 0067918c  8b36                 mov esi, dword ptr [esi]
// 0067918e  8bee                 mov ebp, esi
// 00679190  897c2414             mov dword ptr [esp + 0x14], edi
// 00679194  85f6                 test esi, esi
// 00679196  7518                 jne 0x6791b0
// 00679198  ff1590288000         call dword ptr [0x802890]
// 0067919e  33c0                 xor eax, eax
// 006791a0  8d3c9f               lea edi, [edi + ebx*4]
// 006791a3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 006791a6  7713                 ja 0x6791bb
// 006791a8  85f6                 test esi, esi
// 006791aa  7408                 je 0x6791b4
// 006791ac  8b36                 mov esi, dword ptr [esi]
// 006791ae  eb06                 jmp 0x6791b6
// 006791b0  8b06                 mov eax, dword ptr [esi]
// 006791b2  ebec                 jmp 0x6791a0
// 006791b4  33f6                 xor esi, esi
// 006791b6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 006791b9  7306                 jae 0x6791c1
// 006791bb  ff1590288000         call dword ptr [0x802890]
// 006791c1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006791c5  897804               mov dword ptr [eax + 4], edi
// 006791c8  5f                   pop edi
// 006791c9  5e                   pop esi
// 006791ca  8928                 mov dword ptr [eax], ebp
// 006791cc  5d                   pop ebp
// 006791cd  5b                   pop ebx
// 006791ce  83c408               add esp, 8
// 006791d1  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
