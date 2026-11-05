// from server: 100% by auto
// roc 2008-06 00671830  unit: RBX::AdornRbxGfx  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00671830
//
// 00671830  83ec08               sub esp, 8
// 00671833  53                   push ebx
// 00671834  55                   push ebp
// 00671835  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0067183b  56                   push esi
// 0067183c  8bf1                 mov esi, ecx
// 0067183e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00671841  8b18                 mov ebx, dword ptr [eax]
// 00671843  8b06                 mov eax, dword ptr [esi]
// 00671845  57                   push edi
// 00671846  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0067184a  85ff                 test edi, edi
// 0067184c  7404                 je 0x671852
// 0067184e  3bf8                 cmp edi, eax
// 00671850  7406                 je 0x671858
// 00671852  ffd5                 call ebp
// 00671854  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00671858  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0067185c  7562                 jne 0x6718c0
// 0067185e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00671862  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00671865  8b06                 mov eax, dword ptr [esi]
// 00671867  85c9                 test ecx, ecx
// 00671869  7404                 je 0x67186f
// 0067186b  3bc8                 cmp ecx, eax
// 0067186d  7406                 je 0x671875
// 0067186f  ffd5                 call ebp
// 00671871  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00671875  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00671879  7545                 jne 0x6718c0
// 0067187b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0067187e  8b5104               mov edx, dword ptr [ecx + 4]
// 00671881  52                   push edx
// 00671882  8bce                 mov ecx, esi
// 00671884  e8d7f8ffff           call 0x671160
// 00671889  8b4618               mov eax, dword ptr [esi + 0x18]
// 0067188c  894004               mov dword ptr [eax + 4], eax
// 0067188f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00671892  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00671899  8900                 mov dword ptr [eax], eax
// 0067189b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0067189e  894008               mov dword ptr [eax + 8], eax
// 006718a1  8b4618               mov eax, dword ptr [esi + 0x18]
// 006718a4  8b16                 mov edx, dword ptr [esi]
// 006718a6  8b08                 mov ecx, dword ptr [eax]
// 006718a8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006718ac  5f                   pop edi
// 006718ad  5e                   pop esi
// 006718ae  5d                   pop ebp
// 006718af  894804               mov dword ptr [eax + 4], ecx
// 006718b2  8910                 mov dword ptr [eax], edx
// 006718b4  5b                   pop ebx
// 006718b5  83c408               add esp, 8
// 006718b8  c21400               ret 0x14
// 006718bb  eb03                 jmp 0x6718c0
// 006718bd  8d4900               lea ecx, [ecx]
// 006718c0  85ff                 test edi, edi
// 006718c2  7406                 je 0x6718ca
// 006718c4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006718c8  7406                 je 0x6718d0
// 006718ca  ffd5                 call ebp
// 006718cc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006718d0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006718d4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 006718d8  741d                 je 0x6718f7
// 006718da  8d4c2420             lea ecx, [esp + 0x20]
// 006718de  e87d86d9ff           call 0x409f60
// 006718e3  53                   push ebx
// 006718e4  57                   push edi
// 006718e5  8d442418             lea eax, [esp + 0x18]
// 006718e9  50                   push eax
// 006718ea  8bce                 mov ecx, esi
// 006718ec  e85ff1ffff           call 0x670a50
// 006718f1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006718f5  ebc9                 jmp 0x6718c0
// 006718f7  8b36                 mov esi, dword ptr [esi]
// 006718f9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006718fd  5f                   pop edi
// 006718fe  8930                 mov dword ptr [eax], esi
// 00671900  5e                   pop esi
// 00671901  5d                   pop ebp
// 00671902  895804               mov dword ptr [eax + 4], ebx
// 00671905  5b                   pop ebx
// 00671906  83c408               add esp, 8
// 00671909  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
