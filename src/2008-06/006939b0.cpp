// from server: 100% by auto
// roc 2008-06 006939b0  unit: Ogre::RbxSceneManager  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006939b0
//
// 006939b0  83ec08               sub esp, 8
// 006939b3  53                   push ebx
// 006939b4  55                   push ebp
// 006939b5  8b2d90288000         mov ebp, dword ptr [0x802890]
// 006939bb  56                   push esi
// 006939bc  8bf1                 mov esi, ecx
// 006939be  8b4618               mov eax, dword ptr [esi + 0x18]
// 006939c1  8b18                 mov ebx, dword ptr [eax]
// 006939c3  8b06                 mov eax, dword ptr [esi]
// 006939c5  57                   push edi
// 006939c6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006939ca  85ff                 test edi, edi
// 006939cc  7404                 je 0x6939d2
// 006939ce  3bf8                 cmp edi, eax
// 006939d0  7406                 je 0x6939d8
// 006939d2  ffd5                 call ebp
// 006939d4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006939d8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006939dc  7562                 jne 0x693a40
// 006939de  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006939e2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006939e5  8b06                 mov eax, dword ptr [esi]
// 006939e7  85c9                 test ecx, ecx
// 006939e9  7404                 je 0x6939ef
// 006939eb  3bc8                 cmp ecx, eax
// 006939ed  7406                 je 0x6939f5
// 006939ef  ffd5                 call ebp
// 006939f1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006939f5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006939f9  7545                 jne 0x693a40
// 006939fb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006939fe  8b5104               mov edx, dword ptr [ecx + 4]
// 00693a01  52                   push edx
// 00693a02  8bce                 mov ecx, esi
// 00693a04  e8e7c5ffff           call 0x68fff0
// 00693a09  8b4618               mov eax, dword ptr [esi + 0x18]
// 00693a0c  894004               mov dword ptr [eax + 4], eax
// 00693a0f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00693a12  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00693a19  8900                 mov dword ptr [eax], eax
// 00693a1b  8b4618               mov eax, dword ptr [esi + 0x18]
// 00693a1e  894008               mov dword ptr [eax + 8], eax
// 00693a21  8b4618               mov eax, dword ptr [esi + 0x18]
// 00693a24  8b16                 mov edx, dword ptr [esi]
// 00693a26  8b08                 mov ecx, dword ptr [eax]
// 00693a28  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00693a2c  5f                   pop edi
// 00693a2d  5e                   pop esi
// 00693a2e  5d                   pop ebp
// 00693a2f  894804               mov dword ptr [eax + 4], ecx
// 00693a32  8910                 mov dword ptr [eax], edx
// 00693a34  5b                   pop ebx
// 00693a35  83c408               add esp, 8
// 00693a38  c21400               ret 0x14
// 00693a3b  eb03                 jmp 0x693a40
// 00693a3d  8d4900               lea ecx, [ecx]
// 00693a40  85ff                 test edi, edi
// 00693a42  7406                 je 0x693a4a
// 00693a44  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00693a48  7406                 je 0x693a50
// 00693a4a  ffd5                 call ebp
// 00693a4c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00693a50  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00693a54  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00693a58  741d                 je 0x693a77
// 00693a5a  8d4c2420             lea ecx, [esp + 0x20]
// 00693a5e  e87d99ffff           call 0x68d3e0
// 00693a63  53                   push ebx
// 00693a64  57                   push edi
// 00693a65  8d442418             lea eax, [esp + 0x18]
// 00693a69  50                   push eax
// 00693a6a  8bce                 mov ecx, esi
// 00693a6c  e81fe5ffff           call 0x691f90
// 00693a71  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00693a75  ebc9                 jmp 0x693a40
// 00693a77  8b36                 mov esi, dword ptr [esi]
// 00693a79  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00693a7d  5f                   pop edi
// 00693a7e  8930                 mov dword ptr [eax], esi
// 00693a80  5e                   pop esi
// 00693a81  5d                   pop ebp
// 00693a82  895804               mov dword ptr [eax + 4], ebx
// 00693a85  5b                   pop ebx
// 00693a86  83c408               add esp, 8
// 00693a89  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
