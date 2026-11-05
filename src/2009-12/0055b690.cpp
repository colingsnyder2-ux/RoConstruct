// from server: 100% by auto
// roc 2009-12 0055b690  unit: RBX::Network::ServerReplicator  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0055b690
//
// 0055b690  83ec08               sub esp, 8
// 0055b693  53                   push ebx
// 0055b694  55                   push ebp
// 0055b695  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0055b69b  56                   push esi
// 0055b69c  8bf1                 mov esi, ecx
// 0055b69e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0055b6a1  8b18                 mov ebx, dword ptr [eax]
// 0055b6a3  8b06                 mov eax, dword ptr [esi]
// 0055b6a5  57                   push edi
// 0055b6a6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0055b6aa  85ff                 test edi, edi
// 0055b6ac  7404                 je 0x55b6b2
// 0055b6ae  3bf8                 cmp edi, eax
// 0055b6b0  7406                 je 0x55b6b8
// 0055b6b2  ffd5                 call ebp
// 0055b6b4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0055b6b8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0055b6bc  7562                 jne 0x55b720
// 0055b6be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0055b6c2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0055b6c5  8b06                 mov eax, dword ptr [esi]
// 0055b6c7  85c9                 test ecx, ecx
// 0055b6c9  7404                 je 0x55b6cf
// 0055b6cb  3bc8                 cmp ecx, eax
// 0055b6cd  7406                 je 0x55b6d5
// 0055b6cf  ffd5                 call ebp
// 0055b6d1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0055b6d5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0055b6d9  7545                 jne 0x55b720
// 0055b6db  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0055b6de  8b5104               mov edx, dword ptr [ecx + 4]
// 0055b6e1  52                   push edx
// 0055b6e2  8bce                 mov ecx, esi
// 0055b6e4  e8e7f8ffff           call 0x55afd0
// 0055b6e9  8b4618               mov eax, dword ptr [esi + 0x18]
// 0055b6ec  894004               mov dword ptr [eax + 4], eax
// 0055b6ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 0055b6f2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0055b6f9  8900                 mov dword ptr [eax], eax
// 0055b6fb  8b4618               mov eax, dword ptr [esi + 0x18]
// 0055b6fe  894008               mov dword ptr [eax + 8], eax
// 0055b701  8b4618               mov eax, dword ptr [esi + 0x18]
// 0055b704  8b16                 mov edx, dword ptr [esi]
// 0055b706  8b08                 mov ecx, dword ptr [eax]
// 0055b708  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0055b70c  5f                   pop edi
// 0055b70d  5e                   pop esi
// 0055b70e  5d                   pop ebp
// 0055b70f  894804               mov dword ptr [eax + 4], ecx
// 0055b712  8910                 mov dword ptr [eax], edx
// 0055b714  5b                   pop ebx
// 0055b715  83c408               add esp, 8
// 0055b718  c21400               ret 0x14
// 0055b71b  eb03                 jmp 0x55b720
// 0055b71d  8d4900               lea ecx, [ecx]
// 0055b720  85ff                 test edi, edi
// 0055b722  7406                 je 0x55b72a
// 0055b724  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0055b728  7406                 je 0x55b730
// 0055b72a  ffd5                 call ebp
// 0055b72c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0055b730  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0055b734  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0055b738  741d                 je 0x55b757
// 0055b73a  8d4c2420             lea ecx, [esp + 0x20]
// 0055b73e  e8edf6ffff           call 0x55ae30
// 0055b743  53                   push ebx
// 0055b744  57                   push edi
// 0055b745  8d442418             lea eax, [esp + 0x18]
// 0055b749  50                   push eax
// 0055b74a  8bce                 mov ecx, esi
// 0055b74c  e86ffaffff           call 0x55b1c0
// 0055b751  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0055b755  ebc9                 jmp 0x55b720
// 0055b757  8b36                 mov esi, dword ptr [esi]
// 0055b759  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0055b75d  5f                   pop edi
// 0055b75e  8930                 mov dword ptr [eax], esi
// 0055b760  5e                   pop esi
// 0055b761  5d                   pop ebp
// 0055b762  895804               mov dword ptr [eax + 4], ebx
// 0055b765  5b                   pop ebx
// 0055b766  83c408               add esp, 8
// 0055b769  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
