// from server: 100% by auto
// roc 2010-06 00771730  unit: RBX::ScoreHud  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00771730
//
// 00771730  83ec08               sub esp, 8
// 00771733  53                   push ebx
// 00771734  55                   push ebp
// 00771735  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0077173b  56                   push esi
// 0077173c  8bf1                 mov esi, ecx
// 0077173e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00771741  8b18                 mov ebx, dword ptr [eax]
// 00771743  8b06                 mov eax, dword ptr [esi]
// 00771745  57                   push edi
// 00771746  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0077174a  85ff                 test edi, edi
// 0077174c  7404                 je 0x771752
// 0077174e  3bf8                 cmp edi, eax
// 00771750  7406                 je 0x771758
// 00771752  ffd5                 call ebp
// 00771754  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00771758  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0077175c  7562                 jne 0x7717c0
// 0077175e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00771762  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00771765  8b06                 mov eax, dword ptr [esi]
// 00771767  85c9                 test ecx, ecx
// 00771769  7404                 je 0x77176f
// 0077176b  3bc8                 cmp ecx, eax
// 0077176d  7406                 je 0x771775
// 0077176f  ffd5                 call ebp
// 00771771  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00771775  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00771779  7545                 jne 0x7717c0
// 0077177b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0077177e  8b5104               mov edx, dword ptr [ecx + 4]
// 00771781  52                   push edx
// 00771782  8bce                 mov ecx, esi
// 00771784  e8a7f1ffff           call 0x770930
// 00771789  8b4618               mov eax, dword ptr [esi + 0x18]
// 0077178c  894004               mov dword ptr [eax + 4], eax
// 0077178f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00771792  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00771799  8900                 mov dword ptr [eax], eax
// 0077179b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0077179e  894008               mov dword ptr [eax + 8], eax
// 007717a1  8b4618               mov eax, dword ptr [esi + 0x18]
// 007717a4  8b16                 mov edx, dword ptr [esi]
// 007717a6  8b08                 mov ecx, dword ptr [eax]
// 007717a8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007717ac  5f                   pop edi
// 007717ad  5e                   pop esi
// 007717ae  5d                   pop ebp
// 007717af  894804               mov dword ptr [eax + 4], ecx
// 007717b2  8910                 mov dword ptr [eax], edx
// 007717b4  5b                   pop ebx
// 007717b5  83c408               add esp, 8
// 007717b8  c21400               ret 0x14
// 007717bb  eb03                 jmp 0x7717c0
// 007717bd  8d4900               lea ecx, [ecx]
// 007717c0  85ff                 test edi, edi
// 007717c2  7406                 je 0x7717ca
// 007717c4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 007717c8  7406                 je 0x7717d0
// 007717ca  ffd5                 call ebp
// 007717cc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007717d0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007717d4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 007717d8  741d                 je 0x7717f7
// 007717da  8d4c2420             lea ecx, [esp + 0x20]
// 007717de  e8cdddffff           call 0x76f5b0
// 007717e3  53                   push ebx
// 007717e4  57                   push edi
// 007717e5  8d442418             lea eax, [esp + 0x18]
// 007717e9  50                   push eax
// 007717ea  8bce                 mov ecx, esi
// 007717ec  e8dfecffff           call 0x7704d0
// 007717f1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007717f5  ebc9                 jmp 0x7717c0
// 007717f7  8b36                 mov esi, dword ptr [esi]
// 007717f9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007717fd  5f                   pop edi
// 007717fe  8930                 mov dword ptr [eax], esi
// 00771800  5e                   pop esi
// 00771801  5d                   pop ebp
// 00771802  895804               mov dword ptr [eax + 4], ebx
// 00771805  5b                   pop ebx
// 00771806  83c408               add esp, 8
// 00771809  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
