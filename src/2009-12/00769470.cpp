// from server: 100% by auto
// roc 2009-12 00769470  unit: RBX::VInstance::?$NonFactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00769470
//
// 00769470  83ec08               sub esp, 8
// 00769473  53                   push ebx
// 00769474  55                   push ebp
// 00769475  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0076947b  56                   push esi
// 0076947c  8bf1                 mov esi, ecx
// 0076947e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00769481  8b18                 mov ebx, dword ptr [eax]
// 00769483  8b06                 mov eax, dword ptr [esi]
// 00769485  57                   push edi
// 00769486  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0076948a  85ff                 test edi, edi
// 0076948c  7404                 je 0x769492
// 0076948e  3bf8                 cmp edi, eax
// 00769490  7406                 je 0x769498
// 00769492  ffd5                 call ebp
// 00769494  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00769498  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0076949c  7562                 jne 0x769500
// 0076949e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007694a2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 007694a5  8b06                 mov eax, dword ptr [esi]
// 007694a7  85c9                 test ecx, ecx
// 007694a9  7404                 je 0x7694af
// 007694ab  3bc8                 cmp ecx, eax
// 007694ad  7406                 je 0x7694b5
// 007694af  ffd5                 call ebp
// 007694b1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007694b5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 007694b9  7545                 jne 0x769500
// 007694bb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007694be  8b5104               mov edx, dword ptr [ecx + 4]
// 007694c1  52                   push edx
// 007694c2  8bce                 mov ecx, esi
// 007694c4  e887f5ffff           call 0x768a50
// 007694c9  8b4618               mov eax, dword ptr [esi + 0x18]
// 007694cc  894004               mov dword ptr [eax + 4], eax
// 007694cf  8b4618               mov eax, dword ptr [esi + 0x18]
// 007694d2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007694d9  8900                 mov dword ptr [eax], eax
// 007694db  8b4618               mov eax, dword ptr [esi + 0x18]
// 007694de  894008               mov dword ptr [eax + 8], eax
// 007694e1  8b4618               mov eax, dword ptr [esi + 0x18]
// 007694e4  8b16                 mov edx, dword ptr [esi]
// 007694e6  8b08                 mov ecx, dword ptr [eax]
// 007694e8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007694ec  5f                   pop edi
// 007694ed  5e                   pop esi
// 007694ee  5d                   pop ebp
// 007694ef  894804               mov dword ptr [eax + 4], ecx
// 007694f2  8910                 mov dword ptr [eax], edx
// 007694f4  5b                   pop ebx
// 007694f5  83c408               add esp, 8
// 007694f8  c21400               ret 0x14
// 007694fb  eb03                 jmp 0x769500
// 007694fd  8d4900               lea ecx, [ecx]
// 00769500  85ff                 test edi, edi
// 00769502  7406                 je 0x76950a
// 00769504  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00769508  7406                 je 0x769510
// 0076950a  ffd5                 call ebp
// 0076950c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00769510  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00769514  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00769518  741d                 je 0x769537
// 0076951a  8d4c2420             lea ecx, [esp + 0x20]
// 0076951e  e8cda3daff           call 0x5138f0
// 00769523  53                   push ebx
// 00769524  57                   push edi
// 00769525  8d442418             lea eax, [esp + 0x18]
// 00769529  50                   push eax
// 0076952a  8bce                 mov ecx, esi
// 0076952c  e89ff9ffff           call 0x768ed0
// 00769531  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00769535  ebc9                 jmp 0x769500
// 00769537  8b36                 mov esi, dword ptr [esi]
// 00769539  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0076953d  5f                   pop edi
// 0076953e  8930                 mov dword ptr [eax], esi
// 00769540  5e                   pop esi
// 00769541  5d                   pop ebp
// 00769542  895804               mov dword ptr [eax + 4], ebx
// 00769545  5b                   pop ebx
// 00769546  83c408               add esp, 8
// 00769549  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
