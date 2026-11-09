// from server: 100% by auto
// roc 2008-06 0058ea20  unit: TextXmlWriter  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0058ea20
//
// 0058ea20  83ec14               sub esp, 0x14
// 0058ea23  53                   push ebx
// 0058ea24  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0058ea28  55                   push ebp
// 0058ea29  56                   push esi
// 0058ea2a  8be9                 mov ebp, ecx
// 0058ea2c  57                   push edi
// 0058ea2d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 0058ea30  8b7704               mov esi, dword ptr [edi + 4]
// 0058ea33  807e4500             cmp byte ptr [esi + 0x45], 0
// 0058ea37  b001                 mov al, 1
// 0058ea39  88442410             mov byte ptr [esp + 0x10], al
// 0058ea3d  7526                 jne 0x58ea65
// 0058ea3f  90                   nop 
// 0058ea40  8d460c               lea eax, [esi + 0xc]
// 0058ea43  50                   push eax
// 0058ea44  53                   push ebx
// 0058ea45  8bfe                 mov edi, esi
// 0058ea47  ff155c238000         call dword ptr [0x80235c]
// 0058ea4d  83c408               add esp, 8
// 0058ea50  88442410             mov byte ptr [esp + 0x10], al
// 0058ea54  84c0                 test al, al
// 0058ea56  7404                 je 0x58ea5c
// 0058ea58  8b36                 mov esi, dword ptr [esi]
// 0058ea5a  eb03                 jmp 0x58ea5f
// 0058ea5c  8b7608               mov esi, dword ptr [esi + 8]
// 0058ea5f  807e4500             cmp byte ptr [esi + 0x45], 0
// 0058ea63  74db                 je 0x58ea40
// 0058ea65  8b7500               mov esi, dword ptr [ebp]
// 0058ea68  897c2418             mov dword ptr [esp + 0x18], edi
// 0058ea6c  89742414             mov dword ptr [esp + 0x14], esi
// 0058ea70  84c0                 test al, al
// 0058ea72  7458                 je 0x58eacc
// 0058ea74  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0058ea77  8b11                 mov edx, dword ptr [ecx]
// 0058ea79  89542420             mov dword ptr [esp + 0x20], edx
// 0058ea7d  85f6                 test esi, esi
// 0058ea7f  7404                 je 0x58ea85
// 0058ea81  3bf6                 cmp esi, esi
// 0058ea83  7406                 je 0x58ea8b
// 0058ea85  ff1590288000         call dword ptr [0x802890]
// 0058ea8b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 0058ea8f  752e                 jne 0x58eabf
// 0058ea91  53                   push ebx
// 0058ea92  57                   push edi
// 0058ea93  6a01                 push 1
// 0058ea95  8d442428             lea eax, [esp + 0x28]
// 0058ea99  50                   push eax
// 0058ea9a  8bcd                 mov ecx, ebp
// 0058ea9c  e87ffdffff           call 0x58e820
// 0058eaa1  5f                   pop edi
// 0058eaa2  8bc8                 mov ecx, eax
// 0058eaa4  8b11                 mov edx, dword ptr [ecx]
// 0058eaa6  8b442424             mov eax, dword ptr [esp + 0x24]
// 0058eaaa  8b4904               mov ecx, dword ptr [ecx + 4]
// 0058eaad  5e                   pop esi
// 0058eaae  5d                   pop ebp
// 0058eaaf  8910                 mov dword ptr [eax], edx
// 0058eab1  894804               mov dword ptr [eax + 4], ecx
// 0058eab4  c6400801             mov byte ptr [eax + 8], 1
// 0058eab8  5b                   pop ebx
// 0058eab9  83c414               add esp, 0x14
// 0058eabc  c20800               ret 8
// 0058eabf  8d4c2414             lea ecx, [esp + 0x14]
// 0058eac3  e828ecffff           call 0x58d6f0
// 0058eac8  8b742414             mov esi, dword ptr [esp + 0x14]
// 0058eacc  8b542418             mov edx, dword ptr [esp + 0x18]
// 0058ead0  83c20c               add edx, 0xc
// 0058ead3  53                   push ebx
// 0058ead4  52                   push edx
// 0058ead5  ff155c238000         call dword ptr [0x80235c]
// 0058eadb  83c408               add esp, 8
// 0058eade  84c0                 test al, al
// 0058eae0  740e                 je 0x58eaf0
// 0058eae2  8b442410             mov eax, dword ptr [esp + 0x10]
// 0058eae6  53                   push ebx
// 0058eae7  57                   push edi
// 0058eae8  50                   push eax
// 0058eae9  8d4c2428             lea ecx, [esp + 0x28]
// 0058eaed  51                   push ecx
// 0058eaee  ebaa                 jmp 0x58ea9a
// 0058eaf0  8b442428             mov eax, dword ptr [esp + 0x28]
// 0058eaf4  8b542418             mov edx, dword ptr [esp + 0x18]
// 0058eaf8  5f                   pop edi
// 0058eaf9  8930                 mov dword ptr [eax], esi
// 0058eafb  5e                   pop esi
// 0058eafc  5d                   pop ebp
// 0058eafd  895004               mov dword ptr [eax + 4], edx
// 0058eb00  c6400800             mov byte ptr [eax + 8], 0
// 0058eb04  5b                   pop ebx
// 0058eb05  83c414               add esp, 0x14
// 0058eb08  c20800               ret 8
// standard library map_str<string> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
