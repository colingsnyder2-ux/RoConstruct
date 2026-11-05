// from server: 100% by auto
// roc 2007-08 00543090  unit: RBX::VDebugSettings::?$FactoryProduct  size: 243 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00543090
//
// 00543090  83ec0c               sub esp, 0xc
// 00543093  53                   push ebx
// 00543094  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00543098  55                   push ebp
// 00543099  56                   push esi
// 0054309a  8be9                 mov ebp, ecx
// 0054309c  57                   push edi
// 0054309d  8b7d04               mov edi, dword ptr [ebp + 4]
// 005430a0  8b7704               mov esi, dword ptr [edi + 4]
// 005430a3  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 005430a7  b001                 mov al, 1
// 005430a9  88442410             mov byte ptr [esp + 0x10], al
// 005430ad  7526                 jne 0x5430d5
// 005430af  90                   nop 
// 005430b0  8d460c               lea eax, [esi + 0xc]
// 005430b3  50                   push eax
// 005430b4  53                   push ebx
// 005430b5  8bfe                 mov edi, esi
// 005430b7  ff1520e67700         call dword ptr [0x77e620]
// 005430bd  83c408               add esp, 8
// 005430c0  84c0                 test al, al
// 005430c2  88442410             mov byte ptr [esp + 0x10], al
// 005430c6  7404                 je 0x5430cc
// 005430c8  8b36                 mov esi, dword ptr [esi]
// 005430ca  eb03                 jmp 0x5430cf
// 005430cc  8b7608               mov esi, dword ptr [esi + 8]
// 005430cf  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 005430d3  74db                 je 0x5430b0
// 005430d5  84c0                 test al, al
// 005430d7  8bf7                 mov esi, edi
// 005430d9  89742418             mov dword ptr [esp + 0x18], esi
// 005430dd  896c2414             mov dword ptr [esp + 0x14], ebp
// 005430e1  7442                 je 0x543125
// 005430e3  8b4d04               mov ecx, dword ptr [ebp + 4]
// 005430e6  3b39                 cmp edi, dword ptr [ecx]
// 005430e8  752e                 jne 0x543118
// 005430ea  53                   push ebx
// 005430eb  57                   push edi
// 005430ec  6a01                 push 1
// 005430ee  8d542420             lea edx, [esp + 0x20]
// 005430f2  52                   push edx
// 005430f3  8bcd                 mov ecx, ebp
// 005430f5  e886350200           call 0x566680
// 005430fa  5f                   pop edi
// 005430fb  8bc8                 mov ecx, eax
// 005430fd  8b11                 mov edx, dword ptr [ecx]
// 005430ff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00543103  8b4904               mov ecx, dword ptr [ecx + 4]
// 00543106  5e                   pop esi
// 00543107  5d                   pop ebp
// 00543108  894804               mov dword ptr [eax + 4], ecx
// 0054310b  c6400801             mov byte ptr [eax + 8], 1
// 0054310f  8910                 mov dword ptr [eax], edx
// 00543111  5b                   pop ebx
// 00543112  83c40c               add esp, 0xc
// 00543115  c20800               ret 8
// 00543118  8d4c2414             lea ecx, [esp + 0x14]
// 0054311c  e8ff020400           call 0x583420
// 00543121  8b742418             mov esi, dword ptr [esp + 0x18]
// 00543125  8d560c               lea edx, [esi + 0xc]
// 00543128  53                   push ebx
// 00543129  52                   push edx
// 0054312a  ff1520e67700         call dword ptr [0x77e620]
// 00543130  83c408               add esp, 8
// 00543133  84c0                 test al, al
// 00543135  7431                 je 0x543168
// 00543137  8b442410             mov eax, dword ptr [esp + 0x10]
// 0054313b  53                   push ebx
// 0054313c  57                   push edi
// 0054313d  50                   push eax
// 0054313e  8d4c2420             lea ecx, [esp + 0x20]
// 00543142  51                   push ecx
// 00543143  8bcd                 mov ecx, ebp
// 00543145  e836350200           call 0x566680
// 0054314a  5f                   pop edi
// 0054314b  8bc8                 mov ecx, eax
// 0054314d  8b11                 mov edx, dword ptr [ecx]
// 0054314f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00543153  8b4904               mov ecx, dword ptr [ecx + 4]
// 00543156  5e                   pop esi
// 00543157  5d                   pop ebp
// 00543158  894804               mov dword ptr [eax + 4], ecx
// 0054315b  c6400801             mov byte ptr [eax + 8], 1
// 0054315f  8910                 mov dword ptr [eax], edx
// 00543161  5b                   pop ebx
// 00543162  83c40c               add esp, 0xc
// 00543165  c20800               ret 8
// 00543168  8b442420             mov eax, dword ptr [esp + 0x20]
// 0054316c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00543170  5f                   pop edi
// 00543171  897004               mov dword ptr [eax + 4], esi
// 00543174  5e                   pop esi
// 00543175  5d                   pop ebp
// 00543176  c6400800             mov byte ptr [eax + 8], 0
// 0054317a  8910                 mov dword ptr [eax], edx
// 0054317c  5b                   pop ebx
// 0054317d  83c40c               add esp, 0xc
// 00543180  c20800               ret 8
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
