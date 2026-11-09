// from server: 100% by auto
// roc 2010-06 004ed570  unit: RBX::Network::Replicator::NewInstanceItem  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ed570
//
// 004ed570  83ec08               sub esp, 8
// 004ed573  53                   push ebx
// 004ed574  55                   push ebp
// 004ed575  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 004ed57b  56                   push esi
// 004ed57c  8bf1                 mov esi, ecx
// 004ed57e  8b4618               mov eax, dword ptr [esi + 0x18]
// 004ed581  8b18                 mov ebx, dword ptr [eax]
// 004ed583  8b06                 mov eax, dword ptr [esi]
// 004ed585  57                   push edi
// 004ed586  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ed58a  85ff                 test edi, edi
// 004ed58c  7404                 je 0x4ed592
// 004ed58e  3bf8                 cmp edi, eax
// 004ed590  7406                 je 0x4ed598
// 004ed592  ffd5                 call ebp
// 004ed594  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ed598  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004ed59c  7562                 jne 0x4ed600
// 004ed59e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004ed5a2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004ed5a5  8b06                 mov eax, dword ptr [esi]
// 004ed5a7  85c9                 test ecx, ecx
// 004ed5a9  7404                 je 0x4ed5af
// 004ed5ab  3bc8                 cmp ecx, eax
// 004ed5ad  7406                 je 0x4ed5b5
// 004ed5af  ffd5                 call ebp
// 004ed5b1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ed5b5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004ed5b9  7545                 jne 0x4ed600
// 004ed5bb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004ed5be  8b5104               mov edx, dword ptr [ecx + 4]
// 004ed5c1  52                   push edx
// 004ed5c2  8bce                 mov ecx, esi
// 004ed5c4  e837ebffff           call 0x4ec100
// 004ed5c9  8b4618               mov eax, dword ptr [esi + 0x18]
// 004ed5cc  894004               mov dword ptr [eax + 4], eax
// 004ed5cf  8b4618               mov eax, dword ptr [esi + 0x18]
// 004ed5d2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004ed5d9  8900                 mov dword ptr [eax], eax
// 004ed5db  8b4618               mov eax, dword ptr [esi + 0x18]
// 004ed5de  894008               mov dword ptr [eax + 8], eax
// 004ed5e1  8b4618               mov eax, dword ptr [esi + 0x18]
// 004ed5e4  8b16                 mov edx, dword ptr [esi]
// 004ed5e6  8b08                 mov ecx, dword ptr [eax]
// 004ed5e8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ed5ec  5f                   pop edi
// 004ed5ed  5e                   pop esi
// 004ed5ee  5d                   pop ebp
// 004ed5ef  894804               mov dword ptr [eax + 4], ecx
// 004ed5f2  8910                 mov dword ptr [eax], edx
// 004ed5f4  5b                   pop ebx
// 004ed5f5  83c408               add esp, 8
// 004ed5f8  c21400               ret 0x14
// 004ed5fb  eb03                 jmp 0x4ed600
// 004ed5fd  8d4900               lea ecx, [ecx]
// 004ed600  85ff                 test edi, edi
// 004ed602  7406                 je 0x4ed60a
// 004ed604  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004ed608  7406                 je 0x4ed610
// 004ed60a  ffd5                 call ebp
// 004ed60c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ed610  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004ed614  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004ed618  741d                 je 0x4ed637
// 004ed61a  8d4c2420             lea ecx, [esp + 0x20]
// 004ed61e  e8dd83ffff           call 0x4e5a00
// 004ed623  53                   push ebx
// 004ed624  57                   push edi
// 004ed625  8d442418             lea eax, [esp + 0x18]
// 004ed629  50                   push eax
// 004ed62a  8bce                 mov ecx, esi
// 004ed62c  e88fe6ffff           call 0x4ebcc0
// 004ed631  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ed635  ebc9                 jmp 0x4ed600
// 004ed637  8b36                 mov esi, dword ptr [esi]
// 004ed639  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ed63d  5f                   pop edi
// 004ed63e  8930                 mov dword ptr [eax], esi
// 004ed640  5e                   pop esi
// 004ed641  5d                   pop ebp
// 004ed642  895804               mov dword ptr [eax + 4], ebx
// 004ed645  5b                   pop ebx
// 004ed646  83c408               add esp, 8
// 004ed649  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
