// from server: 100% by auto
// roc 2010-06 0090a000  unit: Ogre::RbxCluster::VRbxPartBinding::?$sp_counted_impl_p  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0090a000
//
// 0090a000  83ec08               sub esp, 8
// 0090a003  53                   push ebx
// 0090a004  55                   push ebp
// 0090a005  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0090a00b  56                   push esi
// 0090a00c  8bf1                 mov esi, ecx
// 0090a00e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0090a011  8b18                 mov ebx, dword ptr [eax]
// 0090a013  8b06                 mov eax, dword ptr [esi]
// 0090a015  57                   push edi
// 0090a016  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0090a01a  85ff                 test edi, edi
// 0090a01c  7404                 je 0x90a022
// 0090a01e  3bf8                 cmp edi, eax
// 0090a020  7406                 je 0x90a028
// 0090a022  ffd5                 call ebp
// 0090a024  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0090a028  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0090a02c  7562                 jne 0x90a090
// 0090a02e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0090a032  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0090a035  8b06                 mov eax, dword ptr [esi]
// 0090a037  85c9                 test ecx, ecx
// 0090a039  7404                 je 0x90a03f
// 0090a03b  3bc8                 cmp ecx, eax
// 0090a03d  7406                 je 0x90a045
// 0090a03f  ffd5                 call ebp
// 0090a041  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0090a045  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0090a049  7545                 jne 0x90a090
// 0090a04b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0090a04e  8b5104               mov edx, dword ptr [ecx + 4]
// 0090a051  52                   push edx
// 0090a052  8bce                 mov ecx, esi
// 0090a054  e847fbffff           call 0x909ba0
// 0090a059  8b4618               mov eax, dword ptr [esi + 0x18]
// 0090a05c  894004               mov dword ptr [eax + 4], eax
// 0090a05f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0090a062  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0090a069  8900                 mov dword ptr [eax], eax
// 0090a06b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0090a06e  894008               mov dword ptr [eax + 8], eax
// 0090a071  8b4618               mov eax, dword ptr [esi + 0x18]
// 0090a074  8b16                 mov edx, dword ptr [esi]
// 0090a076  8b08                 mov ecx, dword ptr [eax]
// 0090a078  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0090a07c  5f                   pop edi
// 0090a07d  5e                   pop esi
// 0090a07e  5d                   pop ebp
// 0090a07f  894804               mov dword ptr [eax + 4], ecx
// 0090a082  8910                 mov dword ptr [eax], edx
// 0090a084  5b                   pop ebx
// 0090a085  83c408               add esp, 8
// 0090a088  c21400               ret 0x14
// 0090a08b  eb03                 jmp 0x90a090
// 0090a08d  8d4900               lea ecx, [ecx]
// 0090a090  85ff                 test edi, edi
// 0090a092  7406                 je 0x90a09a
// 0090a094  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0090a098  7406                 je 0x90a0a0
// 0090a09a  ffd5                 call ebp
// 0090a09c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0090a0a0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0090a0a4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0090a0a8  741d                 je 0x90a0c7
// 0090a0aa  8d4c2420             lea ecx, [esp + 0x20]
// 0090a0ae  e83deaffff           call 0x908af0
// 0090a0b3  53                   push ebx
// 0090a0b4  57                   push edi
// 0090a0b5  8d442418             lea eax, [esp + 0x18]
// 0090a0b9  50                   push eax
// 0090a0ba  8bce                 mov ecx, esi
// 0090a0bc  e8dff7ffff           call 0x9098a0
// 0090a0c1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0090a0c5  ebc9                 jmp 0x90a090
// 0090a0c7  8b36                 mov esi, dword ptr [esi]
// 0090a0c9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0090a0cd  5f                   pop edi
// 0090a0ce  8930                 mov dword ptr [eax], esi
// 0090a0d0  5e                   pop esi
// 0090a0d1  5d                   pop ebp
// 0090a0d2  895804               mov dword ptr [eax + 4], ebx
// 0090a0d5  5b                   pop ebx
// 0090a0d6  83c408               add esp, 8
// 0090a0d9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
