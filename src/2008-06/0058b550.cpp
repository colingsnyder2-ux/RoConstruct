// from server: 100% by auto
// roc 2008-06 0058b550  unit: RBX::Reflection::UTuple::?$holder  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0058b550
//
// 0058b550  83ec08               sub esp, 8
// 0058b553  53                   push ebx
// 0058b554  55                   push ebp
// 0058b555  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0058b55b  56                   push esi
// 0058b55c  8bf1                 mov esi, ecx
// 0058b55e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0058b561  8b18                 mov ebx, dword ptr [eax]
// 0058b563  8b06                 mov eax, dword ptr [esi]
// 0058b565  57                   push edi
// 0058b566  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0058b56a  85ff                 test edi, edi
// 0058b56c  7404                 je 0x58b572
// 0058b56e  3bf8                 cmp edi, eax
// 0058b570  7406                 je 0x58b578
// 0058b572  ffd5                 call ebp
// 0058b574  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0058b578  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0058b57c  7562                 jne 0x58b5e0
// 0058b57e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0058b582  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0058b585  8b06                 mov eax, dword ptr [esi]
// 0058b587  85c9                 test ecx, ecx
// 0058b589  7404                 je 0x58b58f
// 0058b58b  3bc8                 cmp ecx, eax
// 0058b58d  7406                 je 0x58b595
// 0058b58f  ffd5                 call ebp
// 0058b591  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0058b595  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0058b599  7545                 jne 0x58b5e0
// 0058b59b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0058b59e  8b5104               mov edx, dword ptr [ecx + 4]
// 0058b5a1  52                   push edx
// 0058b5a2  8bce                 mov ecx, esi
// 0058b5a4  e807eeffff           call 0x58a3b0
// 0058b5a9  8b4618               mov eax, dword ptr [esi + 0x18]
// 0058b5ac  894004               mov dword ptr [eax + 4], eax
// 0058b5af  8b4618               mov eax, dword ptr [esi + 0x18]
// 0058b5b2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0058b5b9  8900                 mov dword ptr [eax], eax
// 0058b5bb  8b4618               mov eax, dword ptr [esi + 0x18]
// 0058b5be  894008               mov dword ptr [eax + 8], eax
// 0058b5c1  8b4618               mov eax, dword ptr [esi + 0x18]
// 0058b5c4  8b16                 mov edx, dword ptr [esi]
// 0058b5c6  8b08                 mov ecx, dword ptr [eax]
// 0058b5c8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0058b5cc  5f                   pop edi
// 0058b5cd  5e                   pop esi
// 0058b5ce  5d                   pop ebp
// 0058b5cf  894804               mov dword ptr [eax + 4], ecx
// 0058b5d2  8910                 mov dword ptr [eax], edx
// 0058b5d4  5b                   pop ebx
// 0058b5d5  83c408               add esp, 8
// 0058b5d8  c21400               ret 0x14
// 0058b5db  eb03                 jmp 0x58b5e0
// 0058b5dd  8d4900               lea ecx, [ecx]
// 0058b5e0  85ff                 test edi, edi
// 0058b5e2  7406                 je 0x58b5ea
// 0058b5e4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0058b5e8  7406                 je 0x58b5f0
// 0058b5ea  ffd5                 call ebp
// 0058b5ec  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0058b5f0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0058b5f4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0058b5f8  741d                 je 0x58b617
// 0058b5fa  8d4c2420             lea ecx, [esp + 0x20]
// 0058b5fe  e8ed5a0c00           call 0x6510f0
// 0058b603  53                   push ebx
// 0058b604  57                   push edi
// 0058b605  8d442418             lea eax, [esp + 0x18]
// 0058b609  50                   push eax
// 0058b60a  8bce                 mov ecx, esi
// 0058b60c  e8dfedffff           call 0x58a3f0
// 0058b611  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0058b615  ebc9                 jmp 0x58b5e0
// 0058b617  8b36                 mov esi, dword ptr [esi]
// 0058b619  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0058b61d  5f                   pop edi
// 0058b61e  8930                 mov dword ptr [eax], esi
// 0058b620  5e                   pop esi
// 0058b621  5d                   pop ebp
// 0058b622  895804               mov dword ptr [eax + 4], ebx
// 0058b625  5b                   pop ebx
// 0058b626  83c408               add esp, 8
// 0058b629  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
