// from server: 100% by auto
// roc 2009-12 004809a0  unit: RBX::AdornRbxGfx  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004809a0
//
// 004809a0  83ec08               sub esp, 8
// 004809a3  53                   push ebx
// 004809a4  55                   push ebp
// 004809a5  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 004809ab  56                   push esi
// 004809ac  8bf1                 mov esi, ecx
// 004809ae  8b4618               mov eax, dword ptr [esi + 0x18]
// 004809b1  8b18                 mov ebx, dword ptr [eax]
// 004809b3  8b06                 mov eax, dword ptr [esi]
// 004809b5  57                   push edi
// 004809b6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004809ba  85ff                 test edi, edi
// 004809bc  7404                 je 0x4809c2
// 004809be  3bf8                 cmp edi, eax
// 004809c0  7406                 je 0x4809c8
// 004809c2  ffd5                 call ebp
// 004809c4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004809c8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004809cc  7562                 jne 0x480a30
// 004809ce  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004809d2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004809d5  8b06                 mov eax, dword ptr [esi]
// 004809d7  85c9                 test ecx, ecx
// 004809d9  7404                 je 0x4809df
// 004809db  3bc8                 cmp ecx, eax
// 004809dd  7406                 je 0x4809e5
// 004809df  ffd5                 call ebp
// 004809e1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004809e5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004809e9  7545                 jne 0x480a30
// 004809eb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004809ee  8b5104               mov edx, dword ptr [ecx + 4]
// 004809f1  52                   push edx
// 004809f2  8bce                 mov ecx, esi
// 004809f4  e8a7fbffff           call 0x4805a0
// 004809f9  8b4618               mov eax, dword ptr [esi + 0x18]
// 004809fc  894004               mov dword ptr [eax + 4], eax
// 004809ff  8b4618               mov eax, dword ptr [esi + 0x18]
// 00480a02  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00480a09  8900                 mov dword ptr [eax], eax
// 00480a0b  8b4618               mov eax, dword ptr [esi + 0x18]
// 00480a0e  894008               mov dword ptr [eax + 8], eax
// 00480a11  8b4618               mov eax, dword ptr [esi + 0x18]
// 00480a14  8b16                 mov edx, dword ptr [esi]
// 00480a16  8b08                 mov ecx, dword ptr [eax]
// 00480a18  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00480a1c  5f                   pop edi
// 00480a1d  5e                   pop esi
// 00480a1e  5d                   pop ebp
// 00480a1f  894804               mov dword ptr [eax + 4], ecx
// 00480a22  8910                 mov dword ptr [eax], edx
// 00480a24  5b                   pop ebx
// 00480a25  83c408               add esp, 8
// 00480a28  c21400               ret 0x14
// 00480a2b  eb03                 jmp 0x480a30
// 00480a2d  8d4900               lea ecx, [ecx]
// 00480a30  85ff                 test edi, edi
// 00480a32  7406                 je 0x480a3a
// 00480a34  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00480a38  7406                 je 0x480a40
// 00480a3a  ffd5                 call ebp
// 00480a3c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00480a40  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00480a44  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00480a48  741d                 je 0x480a67
// 00480a4a  8d4c2420             lea ecx, [esp + 0x20]
// 00480a4e  e82de6ffff           call 0x47f080
// 00480a53  53                   push ebx
// 00480a54  57                   push edi
// 00480a55  8d442418             lea eax, [esp + 0x18]
// 00480a59  50                   push eax
// 00480a5a  8bce                 mov ecx, esi
// 00480a5c  e8fff0ffff           call 0x47fb60
// 00480a61  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00480a65  ebc9                 jmp 0x480a30
// 00480a67  8b36                 mov esi, dword ptr [esi]
// 00480a69  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00480a6d  5f                   pop edi
// 00480a6e  8930                 mov dword ptr [eax], esi
// 00480a70  5e                   pop esi
// 00480a71  5d                   pop ebp
// 00480a72  895804               mov dword ptr [eax + 4], ebx
// 00480a75  5b                   pop ebx
// 00480a76  83c408               add esp, 8
// 00480a79  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
