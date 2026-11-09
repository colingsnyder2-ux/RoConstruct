// from server: 100% by auto
// roc 2009-06 00645590  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00645590
//
// 00645590  83ec08               sub esp, 8
// 00645593  53                   push ebx
// 00645594  55                   push ebp
// 00645595  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 0064559b  56                   push esi
// 0064559c  8bf1                 mov esi, ecx
// 0064559e  8b4618               mov eax, dword ptr [esi + 0x18]
// 006455a1  8b18                 mov ebx, dword ptr [eax]
// 006455a3  8b06                 mov eax, dword ptr [esi]
// 006455a5  57                   push edi
// 006455a6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006455aa  85ff                 test edi, edi
// 006455ac  7404                 je 0x6455b2
// 006455ae  3bf8                 cmp edi, eax
// 006455b0  7406                 je 0x6455b8
// 006455b2  ffd5                 call ebp
// 006455b4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006455b8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006455bc  7562                 jne 0x645620
// 006455be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006455c2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006455c5  8b06                 mov eax, dword ptr [esi]
// 006455c7  85c9                 test ecx, ecx
// 006455c9  7404                 je 0x6455cf
// 006455cb  3bc8                 cmp ecx, eax
// 006455cd  7406                 je 0x6455d5
// 006455cf  ffd5                 call ebp
// 006455d1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006455d5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006455d9  7545                 jne 0x645620
// 006455db  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006455de  8b5104               mov edx, dword ptr [ecx + 4]
// 006455e1  52                   push edx
// 006455e2  8bce                 mov ecx, esi
// 006455e4  e857fbffff           call 0x645140
// 006455e9  8b4618               mov eax, dword ptr [esi + 0x18]
// 006455ec  894004               mov dword ptr [eax + 4], eax
// 006455ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 006455f2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006455f9  8900                 mov dword ptr [eax], eax
// 006455fb  8b4618               mov eax, dword ptr [esi + 0x18]
// 006455fe  894008               mov dword ptr [eax + 8], eax
// 00645601  8b4618               mov eax, dword ptr [esi + 0x18]
// 00645604  8b16                 mov edx, dword ptr [esi]
// 00645606  8b08                 mov ecx, dword ptr [eax]
// 00645608  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0064560c  5f                   pop edi
// 0064560d  5e                   pop esi
// 0064560e  5d                   pop ebp
// 0064560f  894804               mov dword ptr [eax + 4], ecx
// 00645612  8910                 mov dword ptr [eax], edx
// 00645614  5b                   pop ebx
// 00645615  83c408               add esp, 8
// 00645618  c21400               ret 0x14
// 0064561b  eb03                 jmp 0x645620
// 0064561d  8d4900               lea ecx, [ecx]
// 00645620  85ff                 test edi, edi
// 00645622  7406                 je 0x64562a
// 00645624  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00645628  7406                 je 0x645630
// 0064562a  ffd5                 call ebp
// 0064562c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00645630  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00645634  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00645638  741d                 je 0x645657
// 0064563a  8d4c2420             lea ecx, [esp + 0x20]
// 0064563e  e8dd750b00           call 0x6fcc20
// 00645643  53                   push ebx
// 00645644  57                   push edi
// 00645645  8d442418             lea eax, [esp + 0x18]
// 00645649  50                   push eax
// 0064564a  8bce                 mov ecx, esi
// 0064564c  e88ff7ffff           call 0x644de0
// 00645651  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00645655  ebc9                 jmp 0x645620
// 00645657  8b36                 mov esi, dword ptr [esi]
// 00645659  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0064565d  5f                   pop edi
// 0064565e  8930                 mov dword ptr [eax], esi
// 00645660  5e                   pop esi
// 00645661  5d                   pop ebp
// 00645662  895804               mov dword ptr [eax + 4], ebx
// 00645665  5b                   pop ebx
// 00645666  83c408               add esp, 8
// 00645669  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
