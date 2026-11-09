// from server: 100% by auto
// roc 2008-06 004a3390  unit: RBX::Network::Server::ClientProxy  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a3390
//
// 004a3390  83ec08               sub esp, 8
// 004a3393  53                   push ebx
// 004a3394  55                   push ebp
// 004a3395  8b2d90288000         mov ebp, dword ptr [0x802890]
// 004a339b  56                   push esi
// 004a339c  8bf1                 mov esi, ecx
// 004a339e  8b4618               mov eax, dword ptr [esi + 0x18]
// 004a33a1  8b18                 mov ebx, dword ptr [eax]
// 004a33a3  8b06                 mov eax, dword ptr [esi]
// 004a33a5  57                   push edi
// 004a33a6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004a33aa  85ff                 test edi, edi
// 004a33ac  7404                 je 0x4a33b2
// 004a33ae  3bf8                 cmp edi, eax
// 004a33b0  7406                 je 0x4a33b8
// 004a33b2  ffd5                 call ebp
// 004a33b4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004a33b8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004a33bc  7562                 jne 0x4a3420
// 004a33be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004a33c2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004a33c5  8b06                 mov eax, dword ptr [esi]
// 004a33c7  85c9                 test ecx, ecx
// 004a33c9  7404                 je 0x4a33cf
// 004a33cb  3bc8                 cmp ecx, eax
// 004a33cd  7406                 je 0x4a33d5
// 004a33cf  ffd5                 call ebp
// 004a33d1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004a33d5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004a33d9  7545                 jne 0x4a3420
// 004a33db  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004a33de  8b5104               mov edx, dword ptr [ecx + 4]
// 004a33e1  52                   push edx
// 004a33e2  8bce                 mov ecx, esi
// 004a33e4  e8b7f3ffff           call 0x4a27a0
// 004a33e9  8b4618               mov eax, dword ptr [esi + 0x18]
// 004a33ec  894004               mov dword ptr [eax + 4], eax
// 004a33ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 004a33f2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004a33f9  8900                 mov dword ptr [eax], eax
// 004a33fb  8b4618               mov eax, dword ptr [esi + 0x18]
// 004a33fe  894008               mov dword ptr [eax + 8], eax
// 004a3401  8b4618               mov eax, dword ptr [esi + 0x18]
// 004a3404  8b16                 mov edx, dword ptr [esi]
// 004a3406  8b08                 mov ecx, dword ptr [eax]
// 004a3408  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a340c  5f                   pop edi
// 004a340d  5e                   pop esi
// 004a340e  5d                   pop ebp
// 004a340f  894804               mov dword ptr [eax + 4], ecx
// 004a3412  8910                 mov dword ptr [eax], edx
// 004a3414  5b                   pop ebx
// 004a3415  83c408               add esp, 8
// 004a3418  c21400               ret 0x14
// 004a341b  eb03                 jmp 0x4a3420
// 004a341d  8d4900               lea ecx, [ecx]
// 004a3420  85ff                 test edi, edi
// 004a3422  7406                 je 0x4a342a
// 004a3424  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004a3428  7406                 je 0x4a3430
// 004a342a  ffd5                 call ebp
// 004a342c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004a3430  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004a3434  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004a3438  741d                 je 0x4a3457
// 004a343a  8d4c2420             lea ecx, [esp + 0x20]
// 004a343e  e82d53f9ff           call 0x438770
// 004a3443  53                   push ebx
// 004a3444  57                   push edi
// 004a3445  8d442418             lea eax, [esp + 0x18]
// 004a3449  50                   push eax
// 004a344a  8bce                 mov ecx, esi
// 004a344c  e86ff0ffff           call 0x4a24c0
// 004a3451  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004a3455  ebc9                 jmp 0x4a3420
// 004a3457  8b36                 mov esi, dword ptr [esi]
// 004a3459  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a345d  5f                   pop edi
// 004a345e  8930                 mov dword ptr [eax], esi
// 004a3460  5e                   pop esi
// 004a3461  5d                   pop ebp
// 004a3462  895804               mov dword ptr [eax + 4], ebx
// 004a3465  5b                   pop ebx
// 004a3466  83c408               add esp, 8
// 004a3469  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
