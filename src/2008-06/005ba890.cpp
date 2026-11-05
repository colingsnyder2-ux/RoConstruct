// from server: 100% by auto
// roc 2008-06 005ba890  unit: RBX::Soundscape::SoundChannel  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ba890
//
// 005ba890  83ec08               sub esp, 8
// 005ba893  53                   push ebx
// 005ba894  55                   push ebp
// 005ba895  8b2d90288000         mov ebp, dword ptr [0x802890]
// 005ba89b  56                   push esi
// 005ba89c  8bf1                 mov esi, ecx
// 005ba89e  8b4618               mov eax, dword ptr [esi + 0x18]
// 005ba8a1  8b18                 mov ebx, dword ptr [eax]
// 005ba8a3  8b06                 mov eax, dword ptr [esi]
// 005ba8a5  57                   push edi
// 005ba8a6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005ba8aa  85ff                 test edi, edi
// 005ba8ac  7404                 je 0x5ba8b2
// 005ba8ae  3bf8                 cmp edi, eax
// 005ba8b0  7406                 je 0x5ba8b8
// 005ba8b2  ffd5                 call ebp
// 005ba8b4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005ba8b8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 005ba8bc  7562                 jne 0x5ba920
// 005ba8be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005ba8c2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 005ba8c5  8b06                 mov eax, dword ptr [esi]
// 005ba8c7  85c9                 test ecx, ecx
// 005ba8c9  7404                 je 0x5ba8cf
// 005ba8cb  3bc8                 cmp ecx, eax
// 005ba8cd  7406                 je 0x5ba8d5
// 005ba8cf  ffd5                 call ebp
// 005ba8d1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005ba8d5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 005ba8d9  7545                 jne 0x5ba920
// 005ba8db  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005ba8de  8b5104               mov edx, dword ptr [ecx + 4]
// 005ba8e1  52                   push edx
// 005ba8e2  8bce                 mov ecx, esi
// 005ba8e4  e817f5ffff           call 0x5b9e00
// 005ba8e9  8b4618               mov eax, dword ptr [esi + 0x18]
// 005ba8ec  894004               mov dword ptr [eax + 4], eax
// 005ba8ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 005ba8f2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005ba8f9  8900                 mov dword ptr [eax], eax
// 005ba8fb  8b4618               mov eax, dword ptr [esi + 0x18]
// 005ba8fe  894008               mov dword ptr [eax + 8], eax
// 005ba901  8b4618               mov eax, dword ptr [esi + 0x18]
// 005ba904  8b16                 mov edx, dword ptr [esi]
// 005ba906  8b08                 mov ecx, dword ptr [eax]
// 005ba908  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005ba90c  5f                   pop edi
// 005ba90d  5e                   pop esi
// 005ba90e  5d                   pop ebp
// 005ba90f  894804               mov dword ptr [eax + 4], ecx
// 005ba912  8910                 mov dword ptr [eax], edx
// 005ba914  5b                   pop ebx
// 005ba915  83c408               add esp, 8
// 005ba918  c21400               ret 0x14
// 005ba91b  eb03                 jmp 0x5ba920
// 005ba91d  8d4900               lea ecx, [ecx]
// 005ba920  85ff                 test edi, edi
// 005ba922  7406                 je 0x5ba92a
// 005ba924  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005ba928  7406                 je 0x5ba930
// 005ba92a  ffd5                 call ebp
// 005ba92c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005ba930  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005ba934  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005ba938  741d                 je 0x5ba957
// 005ba93a  8d4c2420             lea ecx, [esp + 0x20]
// 005ba93e  e81df6e4ff           call 0x409f60
// 005ba943  53                   push ebx
// 005ba944  57                   push edi
// 005ba945  8d442418             lea eax, [esp + 0x18]
// 005ba949  50                   push eax
// 005ba94a  8bce                 mov ecx, esi
// 005ba94c  e8dff0ffff           call 0x5b9a30
// 005ba951  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005ba955  ebc9                 jmp 0x5ba920
// 005ba957  8b36                 mov esi, dword ptr [esi]
// 005ba959  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005ba95d  5f                   pop edi
// 005ba95e  8930                 mov dword ptr [eax], esi
// 005ba960  5e                   pop esi
// 005ba961  5d                   pop ebp
// 005ba962  895804               mov dword ptr [eax + 4], ebx
// 005ba965  5b                   pop ebx
// 005ba966  83c408               add esp, 8
// 005ba969  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
