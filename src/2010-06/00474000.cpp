// from server: 100% by auto
// roc 2010-06 00474000  unit: CRobloxScriptReviewPaneView  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00474000
//
// 00474000  83ec14               sub esp, 0x14
// 00474003  53                   push ebx
// 00474004  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00474008  55                   push ebp
// 00474009  56                   push esi
// 0047400a  8be9                 mov ebp, ecx
// 0047400c  57                   push edi
// 0047400d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 00474010  8b7704               mov esi, dword ptr [edi + 4]
// 00474013  807e3100             cmp byte ptr [esi + 0x31], 0
// 00474017  b001                 mov al, 1
// 00474019  88442410             mov byte ptr [esp + 0x10], al
// 0047401d  7526                 jne 0x474045
// 0047401f  90                   nop 
// 00474020  8d460c               lea eax, [esi + 0xc]
// 00474023  50                   push eax
// 00474024  53                   push ebx
// 00474025  8bfe                 mov edi, esi
// 00474027  ff151ca59e00         call dword ptr [0x9ea51c]
// 0047402d  83c408               add esp, 8
// 00474030  88442410             mov byte ptr [esp + 0x10], al
// 00474034  84c0                 test al, al
// 00474036  7404                 je 0x47403c
// 00474038  8b36                 mov esi, dword ptr [esi]
// 0047403a  eb03                 jmp 0x47403f
// 0047403c  8b7608               mov esi, dword ptr [esi + 8]
// 0047403f  807e3100             cmp byte ptr [esi + 0x31], 0
// 00474043  74db                 je 0x474020
// 00474045  8b7500               mov esi, dword ptr [ebp]
// 00474048  897c2418             mov dword ptr [esp + 0x18], edi
// 0047404c  89742414             mov dword ptr [esp + 0x14], esi
// 00474050  84c0                 test al, al
// 00474052  7458                 je 0x4740ac
// 00474054  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00474057  8b11                 mov edx, dword ptr [ecx]
// 00474059  89542420             mov dword ptr [esp + 0x20], edx
// 0047405d  85f6                 test esi, esi
// 0047405f  7404                 je 0x474065
// 00474061  3bf6                 cmp esi, esi
// 00474063  7406                 je 0x47406b
// 00474065  ff150ca99e00         call dword ptr [0x9ea90c]
// 0047406b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 0047406f  752e                 jne 0x47409f
// 00474071  53                   push ebx
// 00474072  57                   push edi
// 00474073  6a01                 push 1
// 00474075  8d442428             lea eax, [esp + 0x28]
// 00474079  50                   push eax
// 0047407a  8bcd                 mov ecx, ebp
// 0047407c  e85ffaffff           call 0x473ae0
// 00474081  5f                   pop edi
// 00474082  8bc8                 mov ecx, eax
// 00474084  8b11                 mov edx, dword ptr [ecx]
// 00474086  8b442424             mov eax, dword ptr [esp + 0x24]
// 0047408a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0047408d  5e                   pop esi
// 0047408e  5d                   pop ebp
// 0047408f  8910                 mov dword ptr [eax], edx
// 00474091  894804               mov dword ptr [eax + 4], ecx
// 00474094  c6400801             mov byte ptr [eax + 8], 1
// 00474098  5b                   pop ebx
// 00474099  83c414               add esp, 0x14
// 0047409c  c20800               ret 8
// 0047409f  8d4c2414             lea ecx, [esp + 0x14]
// 004740a3  e838f4ffff           call 0x4734e0
// 004740a8  8b742414             mov esi, dword ptr [esp + 0x14]
// 004740ac  8b542418             mov edx, dword ptr [esp + 0x18]
// 004740b0  83c20c               add edx, 0xc
// 004740b3  53                   push ebx
// 004740b4  52                   push edx
// 004740b5  ff151ca59e00         call dword ptr [0x9ea51c]
// 004740bb  83c408               add esp, 8
// 004740be  84c0                 test al, al
// 004740c0  740e                 je 0x4740d0
// 004740c2  8b442410             mov eax, dword ptr [esp + 0x10]
// 004740c6  53                   push ebx
// 004740c7  57                   push edi
// 004740c8  50                   push eax
// 004740c9  8d4c2428             lea ecx, [esp + 0x28]
// 004740cd  51                   push ecx
// 004740ce  ebaa                 jmp 0x47407a
// 004740d0  8b442428             mov eax, dword ptr [esp + 0x28]
// 004740d4  8b542418             mov edx, dword ptr [esp + 0x18]
// 004740d8  5f                   pop edi
// 004740d9  8930                 mov dword ptr [eax], esi
// 004740db  5e                   pop esi
// 004740dc  5d                   pop ebp
// 004740dd  895004               mov dword ptr [eax + 4], edx
// 004740e0  c6400800             mov byte ptr [eax + 8], 0
// 004740e4  5b                   pop ebx
// 004740e5  83c414               add esp, 0x14
// 004740e8  c20800               ret 8
// standard library map_str<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
