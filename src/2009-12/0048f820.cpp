// from server: 100% by auto
// roc 2009-12 0048f820  unit: RBX::RbxTextureProxy  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048f820
//
// 0048f820  83ec08               sub esp, 8
// 0048f823  53                   push ebx
// 0048f824  55                   push ebp
// 0048f825  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0048f82b  56                   push esi
// 0048f82c  8bf1                 mov esi, ecx
// 0048f82e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048f831  8b18                 mov ebx, dword ptr [eax]
// 0048f833  8b06                 mov eax, dword ptr [esi]
// 0048f835  57                   push edi
// 0048f836  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0048f83a  85ff                 test edi, edi
// 0048f83c  7404                 je 0x48f842
// 0048f83e  3bf8                 cmp edi, eax
// 0048f840  7406                 je 0x48f848
// 0048f842  ffd5                 call ebp
// 0048f844  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0048f848  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0048f84c  7562                 jne 0x48f8b0
// 0048f84e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0048f852  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0048f855  8b06                 mov eax, dword ptr [esi]
// 0048f857  85c9                 test ecx, ecx
// 0048f859  7404                 je 0x48f85f
// 0048f85b  3bc8                 cmp ecx, eax
// 0048f85d  7406                 je 0x48f865
// 0048f85f  ffd5                 call ebp
// 0048f861  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0048f865  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0048f869  7545                 jne 0x48f8b0
// 0048f86b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0048f86e  8b5104               mov edx, dword ptr [ecx + 4]
// 0048f871  52                   push edx
// 0048f872  8bce                 mov ecx, esi
// 0048f874  e827da2100           call 0x6ad2a0
// 0048f879  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048f87c  894004               mov dword ptr [eax + 4], eax
// 0048f87f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048f882  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0048f889  8900                 mov dword ptr [eax], eax
// 0048f88b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048f88e  894008               mov dword ptr [eax + 8], eax
// 0048f891  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048f894  8b16                 mov edx, dword ptr [esi]
// 0048f896  8b08                 mov ecx, dword ptr [eax]
// 0048f898  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048f89c  5f                   pop edi
// 0048f89d  5e                   pop esi
// 0048f89e  5d                   pop ebp
// 0048f89f  894804               mov dword ptr [eax + 4], ecx
// 0048f8a2  8910                 mov dword ptr [eax], edx
// 0048f8a4  5b                   pop ebx
// 0048f8a5  83c408               add esp, 8
// 0048f8a8  c21400               ret 0x14
// 0048f8ab  eb03                 jmp 0x48f8b0
// 0048f8ad  8d4900               lea ecx, [ecx]
// 0048f8b0  85ff                 test edi, edi
// 0048f8b2  7406                 je 0x48f8ba
// 0048f8b4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0048f8b8  7406                 je 0x48f8c0
// 0048f8ba  ffd5                 call ebp
// 0048f8bc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0048f8c0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0048f8c4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0048f8c8  741d                 je 0x48f8e7
// 0048f8ca  8d4c2420             lea ecx, [esp + 0x20]
// 0048f8ce  e82df8ffff           call 0x48f100
// 0048f8d3  53                   push ebx
// 0048f8d4  57                   push edi
// 0048f8d5  8d442418             lea eax, [esp + 0x18]
// 0048f8d9  50                   push eax
// 0048f8da  8bce                 mov ecx, esi
// 0048f8dc  e8dffbffff           call 0x48f4c0
// 0048f8e1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0048f8e5  ebc9                 jmp 0x48f8b0
// 0048f8e7  8b36                 mov esi, dword ptr [esi]
// 0048f8e9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048f8ed  5f                   pop edi
// 0048f8ee  8930                 mov dword ptr [eax], esi
// 0048f8f0  5e                   pop esi
// 0048f8f1  5d                   pop ebp
// 0048f8f2  895804               mov dword ptr [eax + 4], ebx
// 0048f8f5  5b                   pop ebx
// 0048f8f6  83c408               add esp, 8
// 0048f8f9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
