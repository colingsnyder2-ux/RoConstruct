// from server: 100% by auto
// roc 2007-08 00589890  unit: VStockSound::?$FactoryProduct  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00589890
//
// 00589890  83ec0c               sub esp, 0xc
// 00589893  55                   push ebp
// 00589894  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00589898  56                   push esi
// 00589899  57                   push edi
// 0058989a  8bf9                 mov edi, ecx
// 0058989c  8b7704               mov esi, dword ptr [edi + 4]
// 0058989f  8b4604               mov eax, dword ptr [esi + 4]
// 005898a2  80781900             cmp byte ptr [eax + 0x19], 0
// 005898a6  b101                 mov cl, 1
// 005898a8  884c240c             mov byte ptr [esp + 0xc], cl
// 005898ac  7520                 jne 0x5898ce
// 005898ae  8b5500               mov edx, dword ptr [ebp]
// 005898b1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 005898b4  8bf0                 mov esi, eax
// 005898b6  0f9cc1               setl cl
// 005898b9  84c9                 test cl, cl
// 005898bb  884c240c             mov byte ptr [esp + 0xc], cl
// 005898bf  7404                 je 0x5898c5
// 005898c1  8b00                 mov eax, dword ptr [eax]
// 005898c3  eb03                 jmp 0x5898c8
// 005898c5  8b4008               mov eax, dword ptr [eax + 8]
// 005898c8  80781900             cmp byte ptr [eax + 0x19], 0
// 005898cc  74e3                 je 0x5898b1
// 005898ce  84c9                 test cl, cl
// 005898d0  8bd6                 mov edx, esi
// 005898d2  89542414             mov dword ptr [esp + 0x14], edx
// 005898d6  897c2410             mov dword ptr [esp + 0x10], edi
// 005898da  743d                 je 0x589919
// 005898dc  8b4704               mov eax, dword ptr [edi + 4]
// 005898df  3b30                 cmp esi, dword ptr [eax]
// 005898e1  8d4c2410             lea ecx, [esp + 0x10]
// 005898e5  7529                 jne 0x589910
// 005898e7  55                   push ebp
// 005898e8  56                   push esi
// 005898e9  6a01                 push 1
// 005898eb  51                   push ecx
// 005898ec  8bcf                 mov ecx, edi
// 005898ee  e8edf6ffff           call 0x588fe0
// 005898f3  8bc8                 mov ecx, eax
// 005898f5  8b11                 mov edx, dword ptr [ecx]
// 005898f7  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005898fb  8b4904               mov ecx, dword ptr [ecx + 4]
// 005898fe  5f                   pop edi
// 005898ff  5e                   pop esi
// 00589900  8910                 mov dword ptr [eax], edx
// 00589902  894804               mov dword ptr [eax + 4], ecx
// 00589905  c6400801             mov byte ptr [eax + 8], 1
// 00589909  5d                   pop ebp
// 0058990a  83c40c               add esp, 0xc
// 0058990d  c20800               ret 8
// 00589910  e81be3ffff           call 0x587c30
// 00589915  8b542414             mov edx, dword ptr [esp + 0x14]
// 00589919  8b420c               mov eax, dword ptr [edx + 0xc]
// 0058991c  3b4500               cmp eax, dword ptr [ebp]
// 0058991f  7d0e                 jge 0x58992f
// 00589921  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00589925  55                   push ebp
// 00589926  56                   push esi
// 00589927  51                   push ecx
// 00589928  8d54241c             lea edx, [esp + 0x1c]
// 0058992c  52                   push edx
// 0058992d  ebbd                 jmp 0x5898ec
// 0058992f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00589933  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00589937  5f                   pop edi
// 00589938  5e                   pop esi
// 00589939  8908                 mov dword ptr [eax], ecx
// 0058993b  895004               mov dword ptr [eax + 4], edx
// 0058993e  c6400800             mov byte ptr [eax + 8], 0
// 00589942  5d                   pop ebp
// 00589943  83c40c               add esp, 0xc
// 00589946  c20800               ret 8
// standard library map_int<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
