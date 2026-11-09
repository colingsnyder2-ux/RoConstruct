// from server: 100% by auto
// roc 2010-06 008c8590  unit: RBX::AdornRbxGfx  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c8590
//
// 008c8590  83ec08               sub esp, 8
// 008c8593  53                   push ebx
// 008c8594  55                   push ebp
// 008c8595  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 008c859b  56                   push esi
// 008c859c  8bf1                 mov esi, ecx
// 008c859e  8b4618               mov eax, dword ptr [esi + 0x18]
// 008c85a1  8b18                 mov ebx, dword ptr [eax]
// 008c85a3  8b06                 mov eax, dword ptr [esi]
// 008c85a5  57                   push edi
// 008c85a6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008c85aa  85ff                 test edi, edi
// 008c85ac  7404                 je 0x8c85b2
// 008c85ae  3bf8                 cmp edi, eax
// 008c85b0  7406                 je 0x8c85b8
// 008c85b2  ffd5                 call ebp
// 008c85b4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008c85b8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 008c85bc  7562                 jne 0x8c8620
// 008c85be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008c85c2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 008c85c5  8b06                 mov eax, dword ptr [esi]
// 008c85c7  85c9                 test ecx, ecx
// 008c85c9  7404                 je 0x8c85cf
// 008c85cb  3bc8                 cmp ecx, eax
// 008c85cd  7406                 je 0x8c85d5
// 008c85cf  ffd5                 call ebp
// 008c85d1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008c85d5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 008c85d9  7545                 jne 0x8c8620
// 008c85db  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 008c85de  8b5104               mov edx, dword ptr [ecx + 4]
// 008c85e1  52                   push edx
// 008c85e2  8bce                 mov ecx, esi
// 008c85e4  e8e7fbffff           call 0x8c81d0
// 008c85e9  8b4618               mov eax, dword ptr [esi + 0x18]
// 008c85ec  894004               mov dword ptr [eax + 4], eax
// 008c85ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 008c85f2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 008c85f9  8900                 mov dword ptr [eax], eax
// 008c85fb  8b4618               mov eax, dword ptr [esi + 0x18]
// 008c85fe  894008               mov dword ptr [eax + 8], eax
// 008c8601  8b4618               mov eax, dword ptr [esi + 0x18]
// 008c8604  8b16                 mov edx, dword ptr [esi]
// 008c8606  8b08                 mov ecx, dword ptr [eax]
// 008c8608  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008c860c  5f                   pop edi
// 008c860d  5e                   pop esi
// 008c860e  5d                   pop ebp
// 008c860f  894804               mov dword ptr [eax + 4], ecx
// 008c8612  8910                 mov dword ptr [eax], edx
// 008c8614  5b                   pop ebx
// 008c8615  83c408               add esp, 8
// 008c8618  c21400               ret 0x14
// 008c861b  eb03                 jmp 0x8c8620
// 008c861d  8d4900               lea ecx, [ecx]
// 008c8620  85ff                 test edi, edi
// 008c8622  7406                 je 0x8c862a
// 008c8624  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 008c8628  7406                 je 0x8c8630
// 008c862a  ffd5                 call ebp
// 008c862c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008c8630  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 008c8634  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 008c8638  741d                 je 0x8c8657
// 008c863a  8d4c2420             lea ecx, [esp + 0x20]
// 008c863e  e8ade7ffff           call 0x8c6df0
// 008c8643  53                   push ebx
// 008c8644  57                   push edi
// 008c8645  8d442418             lea eax, [esp + 0x18]
// 008c8649  50                   push eax
// 008c864a  8bce                 mov ecx, esi
// 008c864c  e8bff1ffff           call 0x8c7810
// 008c8651  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008c8655  ebc9                 jmp 0x8c8620
// 008c8657  8b36                 mov esi, dword ptr [esi]
// 008c8659  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008c865d  5f                   pop edi
// 008c865e  8930                 mov dword ptr [eax], esi
// 008c8660  5e                   pop esi
// 008c8661  5d                   pop ebp
// 008c8662  895804               mov dword ptr [eax + 4], ebx
// 008c8665  5b                   pop ebx
// 008c8666  83c408               add esp, 8
// 008c8669  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
