// from server: 100% by auto
// roc 2008-06 00696ba0  unit: Ogre::RbxSceneManager  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00696ba0
//
// 00696ba0  8b542404             mov edx, dword ptr [esp + 4]
// 00696ba4  56                   push esi
// 00696ba5  8bf1                 mov esi, ecx
// 00696ba7  81faffffff3f         cmp edx, 0x3fffffff
// 00696bad  7605                 jbe 0x696bb4
// 00696baf  e88c01e3ff           call 0x4c6d40
// 00696bb4  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00696bb7  85c9                 test ecx, ecx
// 00696bb9  7504                 jne 0x696bbf
// 00696bbb  33c0                 xor eax, eax
// 00696bbd  eb08                 jmp 0x696bc7
// 00696bbf  8b4614               mov eax, dword ptr [esi + 0x14]
// 00696bc2  2bc1                 sub eax, ecx
// 00696bc4  c1f802               sar eax, 2
// 00696bc7  3bc2                 cmp eax, edx
// 00696bc9  7377                 jae 0x696c42
// 00696bcb  53                   push ebx
// 00696bcc  57                   push edi
// 00696bcd  6a00                 push 0
// 00696bcf  52                   push edx
// 00696bd0  e87b9fd8ff           call 0x420b50
// 00696bd5  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00696bd8  83c408               add esp, 8
// 00696bdb  8bd8                 mov ebx, eax
// 00696bdd  397e0c               cmp dword ptr [esi + 0xc], edi
// 00696be0  7606                 jbe 0x696be8
// 00696be2  ff1590288000         call dword ptr [0x802890]
// 00696be8  55                   push ebp
// 00696be9  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 00696bec  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 00696bef  7606                 jbe 0x696bf7
// 00696bf1  ff1590288000         call dword ptr [0x802890]
// 00696bf7  2bfd                 sub edi, ebp
// 00696bf9  c1ff02               sar edi, 2
// 00696bfc  85ff                 test edi, edi
// 00696bfe  7614                 jbe 0x696c14
// 00696c00  8d04bd00000000       lea eax, [edi*4]
// 00696c07  50                   push eax
// 00696c08  55                   push ebp
// 00696c09  50                   push eax
// 00696c0a  53                   push ebx
// 00696c0b  ff1550288000         call dword ptr [0x802850]
// 00696c11  83c410               add esp, 0x10
// 00696c14  8b460c               mov eax, dword ptr [esi + 0xc]
// 00696c17  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00696c1a  2bf8                 sub edi, eax
// 00696c1c  c1ff02               sar edi, 2
// 00696c1f  5d                   pop ebp
// 00696c20  85c0                 test eax, eax
// 00696c22  7409                 je 0x696c2d
// 00696c24  50                   push eax
// 00696c25  e8509a0000           call 0x6a067a
// 00696c2a  83c404               add esp, 4
// 00696c2d  8b442410             mov eax, dword ptr [esp + 0x10]
// 00696c31  8d14bb               lea edx, [ebx + edi*4]
// 00696c34  8d0c83               lea ecx, [ebx + eax*4]
// 00696c37  5f                   pop edi
// 00696c38  895e0c               mov dword ptr [esi + 0xc], ebx
// 00696c3b  894e14               mov dword ptr [esi + 0x14], ecx
// 00696c3e  895610               mov dword ptr [esi + 0x10], edx
// 00696c41  5b                   pop ebx
// 00696c42  5e                   pop esi
// 00696c43  c20400               ret 4
// standard library vector<ptr> (function ?reserve@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
