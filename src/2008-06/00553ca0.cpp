// from server: 100% by auto
// roc 2008-06 00553ca0  unit: RBX::RenderBase::AggregateChunk  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00553ca0
//
// 00553ca0  83ec08               sub esp, 8
// 00553ca3  53                   push ebx
// 00553ca4  55                   push ebp
// 00553ca5  8b2d90288000         mov ebp, dword ptr [0x802890]
// 00553cab  56                   push esi
// 00553cac  8bf1                 mov esi, ecx
// 00553cae  8b4618               mov eax, dword ptr [esi + 0x18]
// 00553cb1  8b18                 mov ebx, dword ptr [eax]
// 00553cb3  8b06                 mov eax, dword ptr [esi]
// 00553cb5  57                   push edi
// 00553cb6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00553cba  85ff                 test edi, edi
// 00553cbc  7404                 je 0x553cc2
// 00553cbe  3bf8                 cmp edi, eax
// 00553cc0  7406                 je 0x553cc8
// 00553cc2  ffd5                 call ebp
// 00553cc4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00553cc8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 00553ccc  7562                 jne 0x553d30
// 00553cce  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00553cd2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00553cd5  8b06                 mov eax, dword ptr [esi]
// 00553cd7  85c9                 test ecx, ecx
// 00553cd9  7404                 je 0x553cdf
// 00553cdb  3bc8                 cmp ecx, eax
// 00553cdd  7406                 je 0x553ce5
// 00553cdf  ffd5                 call ebp
// 00553ce1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00553ce5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00553ce9  7545                 jne 0x553d30
// 00553ceb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00553cee  8b5104               mov edx, dword ptr [ecx + 4]
// 00553cf1  52                   push edx
// 00553cf2  8bce                 mov ecx, esi
// 00553cf4  e837ededff           call 0x432a30
// 00553cf9  8b4618               mov eax, dword ptr [esi + 0x18]
// 00553cfc  894004               mov dword ptr [eax + 4], eax
// 00553cff  8b4618               mov eax, dword ptr [esi + 0x18]
// 00553d02  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00553d09  8900                 mov dword ptr [eax], eax
// 00553d0b  8b4618               mov eax, dword ptr [esi + 0x18]
// 00553d0e  894008               mov dword ptr [eax + 8], eax
// 00553d11  8b4618               mov eax, dword ptr [esi + 0x18]
// 00553d14  8b16                 mov edx, dword ptr [esi]
// 00553d16  8b08                 mov ecx, dword ptr [eax]
// 00553d18  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00553d1c  5f                   pop edi
// 00553d1d  5e                   pop esi
// 00553d1e  5d                   pop ebp
// 00553d1f  894804               mov dword ptr [eax + 4], ecx
// 00553d22  8910                 mov dword ptr [eax], edx
// 00553d24  5b                   pop ebx
// 00553d25  83c408               add esp, 8
// 00553d28  c21400               ret 0x14
// 00553d2b  eb03                 jmp 0x553d30
// 00553d2d  8d4900               lea ecx, [ecx]
// 00553d30  85ff                 test edi, edi
// 00553d32  7406                 je 0x553d3a
// 00553d34  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00553d38  7406                 je 0x553d40
// 00553d3a  ffd5                 call ebp
// 00553d3c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00553d40  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00553d44  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00553d48  741d                 je 0x553d67
// 00553d4a  8d4c2420             lea ecx, [esp + 0x20]
// 00553d4e  e84da21300           call 0x68dfa0
// 00553d53  53                   push ebx
// 00553d54  57                   push edi
// 00553d55  8d442418             lea eax, [esp + 0x18]
// 00553d59  50                   push eax
// 00553d5a  8bce                 mov ecx, esi
// 00553d5c  e86ffcffff           call 0x5539d0
// 00553d61  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00553d65  ebc9                 jmp 0x553d30
// 00553d67  8b36                 mov esi, dword ptr [esi]
// 00553d69  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00553d6d  5f                   pop edi
// 00553d6e  8930                 mov dword ptr [eax], esi
// 00553d70  5e                   pop esi
// 00553d71  5d                   pop ebp
// 00553d72  895804               mov dword ptr [eax + 4], ebx
// 00553d75  5b                   pop ebx
// 00553d76  83c408               add esp, 8
// 00553d79  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
