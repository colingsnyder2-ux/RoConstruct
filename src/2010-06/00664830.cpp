// from server: 100% by auto
// roc 2010-06 00664830  unit: RBX::Network::VPlayer::?$RemoteEventDesc  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00664830
//
// 00664830  83ec08               sub esp, 8
// 00664833  53                   push ebx
// 00664834  55                   push ebp
// 00664835  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0066483b  56                   push esi
// 0066483c  8bf1                 mov esi, ecx
// 0066483e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00664841  8b18                 mov ebx, dword ptr [eax]
// 00664843  8b06                 mov eax, dword ptr [esi]
// 00664845  57                   push edi
// 00664846  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0066484a  85ff                 test edi, edi
// 0066484c  7404                 je 0x664852
// 0066484e  3bf8                 cmp edi, eax
// 00664850  7406                 je 0x664858
// 00664852  ffd5                 call ebp
// 00664854  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00664858  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0066485c  7562                 jne 0x6648c0
// 0066485e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00664862  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00664865  8b06                 mov eax, dword ptr [esi]
// 00664867  85c9                 test ecx, ecx
// 00664869  7404                 je 0x66486f
// 0066486b  3bc8                 cmp ecx, eax
// 0066486d  7406                 je 0x664875
// 0066486f  ffd5                 call ebp
// 00664871  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00664875  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00664879  7545                 jne 0x6648c0
// 0066487b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0066487e  8b5104               mov edx, dword ptr [ecx + 4]
// 00664881  52                   push edx
// 00664882  8bce                 mov ecx, esi
// 00664884  e827f8ffff           call 0x6640b0
// 00664889  8b4618               mov eax, dword ptr [esi + 0x18]
// 0066488c  894004               mov dword ptr [eax + 4], eax
// 0066488f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00664892  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00664899  8900                 mov dword ptr [eax], eax
// 0066489b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0066489e  894008               mov dword ptr [eax + 8], eax
// 006648a1  8b4618               mov eax, dword ptr [esi + 0x18]
// 006648a4  8b16                 mov edx, dword ptr [esi]
// 006648a6  8b08                 mov ecx, dword ptr [eax]
// 006648a8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006648ac  5f                   pop edi
// 006648ad  5e                   pop esi
// 006648ae  5d                   pop ebp
// 006648af  894804               mov dword ptr [eax + 4], ecx
// 006648b2  8910                 mov dword ptr [eax], edx
// 006648b4  5b                   pop ebx
// 006648b5  83c408               add esp, 8
// 006648b8  c21400               ret 0x14
// 006648bb  eb03                 jmp 0x6648c0
// 006648bd  8d4900               lea ecx, [ecx]
// 006648c0  85ff                 test edi, edi
// 006648c2  7406                 je 0x6648ca
// 006648c4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006648c8  7406                 je 0x6648d0
// 006648ca  ffd5                 call ebp
// 006648cc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006648d0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006648d4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 006648d8  741d                 je 0x6648f7
// 006648da  8d4c2420             lea ecx, [esp + 0x20]
// 006648de  e8cdabffff           call 0x65f4b0
// 006648e3  53                   push ebx
// 006648e4  57                   push edi
// 006648e5  8d442418             lea eax, [esp + 0x18]
// 006648e9  50                   push eax
// 006648ea  8bce                 mov ecx, esi
// 006648ec  e8dff4ffff           call 0x663dd0
// 006648f1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006648f5  ebc9                 jmp 0x6648c0
// 006648f7  8b36                 mov esi, dword ptr [esi]
// 006648f9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006648fd  5f                   pop edi
// 006648fe  8930                 mov dword ptr [eax], esi
// 00664900  5e                   pop esi
// 00664901  5d                   pop ebp
// 00664902  895804               mov dword ptr [eax + 4], ebx
// 00664905  5b                   pop ebx
// 00664906  83c408               add esp, 8
// 00664909  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
