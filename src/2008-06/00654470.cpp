// from server: 100% by auto
// roc 2008-06 00654470  unit: RBX::ScoreHud  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00654470
//
// 00654470  83ec08               sub esp, 8
// 00654473  53                   push ebx
// 00654474  55                   push ebp
// 00654475  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0065447b  56                   push esi
// 0065447c  8bf1                 mov esi, ecx
// 0065447e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00654481  8b18                 mov ebx, dword ptr [eax]
// 00654483  8b06                 mov eax, dword ptr [esi]
// 00654485  57                   push edi
// 00654486  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0065448a  85ff                 test edi, edi
// 0065448c  7404                 je 0x654492
// 0065448e  3bf8                 cmp edi, eax
// 00654490  7406                 je 0x654498
// 00654492  ffd5                 call ebp
// 00654494  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00654498  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0065449c  7562                 jne 0x654500
// 0065449e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006544a2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006544a5  8b06                 mov eax, dword ptr [esi]
// 006544a7  85c9                 test ecx, ecx
// 006544a9  7404                 je 0x6544af
// 006544ab  3bc8                 cmp ecx, eax
// 006544ad  7406                 je 0x6544b5
// 006544af  ffd5                 call ebp
// 006544b1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006544b5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006544b9  7545                 jne 0x654500
// 006544bb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006544be  8b5104               mov edx, dword ptr [ecx + 4]
// 006544c1  52                   push edx
// 006544c2  8bce                 mov ecx, esi
// 006544c4  e847f5ffff           call 0x653a10
// 006544c9  8b4618               mov eax, dword ptr [esi + 0x18]
// 006544cc  894004               mov dword ptr [eax + 4], eax
// 006544cf  8b4618               mov eax, dword ptr [esi + 0x18]
// 006544d2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006544d9  8900                 mov dword ptr [eax], eax
// 006544db  8b4618               mov eax, dword ptr [esi + 0x18]
// 006544de  894008               mov dword ptr [eax + 8], eax
// 006544e1  8b4618               mov eax, dword ptr [esi + 0x18]
// 006544e4  8b16                 mov edx, dword ptr [esi]
// 006544e6  8b08                 mov ecx, dword ptr [eax]
// 006544e8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006544ec  5f                   pop edi
// 006544ed  5e                   pop esi
// 006544ee  5d                   pop ebp
// 006544ef  894804               mov dword ptr [eax + 4], ecx
// 006544f2  8910                 mov dword ptr [eax], edx
// 006544f4  5b                   pop ebx
// 006544f5  83c408               add esp, 8
// 006544f8  c21400               ret 0x14
// 006544fb  eb03                 jmp 0x654500
// 006544fd  8d4900               lea ecx, [ecx]
// 00654500  85ff                 test edi, edi
// 00654502  7406                 je 0x65450a
// 00654504  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00654508  7406                 je 0x654510
// 0065450a  ffd5                 call ebp
// 0065450c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00654510  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00654514  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00654518  741d                 je 0x654537
// 0065451a  8d4c2420             lea ecx, [esp + 0x20]
// 0065451e  e8cdcbffff           call 0x6510f0
// 00654523  53                   push ebx
// 00654524  57                   push edi
// 00654525  8d442418             lea eax, [esp + 0x18]
// 00654529  50                   push eax
// 0065452a  8bce                 mov ecx, esi
// 0065452c  e8ffeeffff           call 0x653430
// 00654531  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00654535  ebc9                 jmp 0x654500
// 00654537  8b36                 mov esi, dword ptr [esi]
// 00654539  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065453d  5f                   pop edi
// 0065453e  8930                 mov dword ptr [eax], esi
// 00654540  5e                   pop esi
// 00654541  5d                   pop ebp
// 00654542  895804               mov dword ptr [eax + 4], ebx
// 00654545  5b                   pop ebx
// 00654546  83c408               add esp, 8
// 00654549  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
