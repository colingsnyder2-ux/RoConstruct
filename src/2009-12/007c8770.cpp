// from server: 100% by auto
// roc 2009-12 007c8770  unit: RBX::ScoreHud  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c8770
//
// 007c8770  83ec14               sub esp, 0x14
// 007c8773  53                   push ebx
// 007c8774  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 007c8778  55                   push ebp
// 007c8779  56                   push esi
// 007c877a  8be9                 mov ebp, ecx
// 007c877c  57                   push edi
// 007c877d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 007c8780  8b7704               mov esi, dword ptr [edi + 4]
// 007c8783  807e4900             cmp byte ptr [esi + 0x49], 0
// 007c8787  b001                 mov al, 1
// 007c8789  88442410             mov byte ptr [esp + 0x10], al
// 007c878d  7526                 jne 0x7c87b5
// 007c878f  90                   nop 
// 007c8790  8d460c               lea eax, [esi + 0xc]
// 007c8793  50                   push eax
// 007c8794  53                   push ebx
// 007c8795  8bfe                 mov edi, esi
// 007c8797  ff15d8b59800         call dword ptr [0x98b5d8]
// 007c879d  83c408               add esp, 8
// 007c87a0  88442410             mov byte ptr [esp + 0x10], al
// 007c87a4  84c0                 test al, al
// 007c87a6  7404                 je 0x7c87ac
// 007c87a8  8b36                 mov esi, dword ptr [esi]
// 007c87aa  eb03                 jmp 0x7c87af
// 007c87ac  8b7608               mov esi, dword ptr [esi + 8]
// 007c87af  807e4900             cmp byte ptr [esi + 0x49], 0
// 007c87b3  74db                 je 0x7c8790
// 007c87b5  8b7500               mov esi, dword ptr [ebp]
// 007c87b8  897c2418             mov dword ptr [esp + 0x18], edi
// 007c87bc  89742414             mov dword ptr [esp + 0x14], esi
// 007c87c0  84c0                 test al, al
// 007c87c2  7458                 je 0x7c881c
// 007c87c4  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 007c87c7  8b11                 mov edx, dword ptr [ecx]
// 007c87c9  89542420             mov dword ptr [esp + 0x20], edx
// 007c87cd  85f6                 test esi, esi
// 007c87cf  7404                 je 0x7c87d5
// 007c87d1  3bf6                 cmp esi, esi
// 007c87d3  7406                 je 0x7c87db
// 007c87d5  ff1560b79800         call dword ptr [0x98b760]
// 007c87db  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 007c87df  752e                 jne 0x7c880f
// 007c87e1  53                   push ebx
// 007c87e2  57                   push edi
// 007c87e3  6a01                 push 1
// 007c87e5  8d442428             lea eax, [esp + 0x28]
// 007c87e9  50                   push eax
// 007c87ea  8bcd                 mov ecx, ebp
// 007c87ec  e86ff3ffff           call 0x7c7b60
// 007c87f1  5f                   pop edi
// 007c87f2  8bc8                 mov ecx, eax
// 007c87f4  8b11                 mov edx, dword ptr [ecx]
// 007c87f6  8b442424             mov eax, dword ptr [esp + 0x24]
// 007c87fa  8b4904               mov ecx, dword ptr [ecx + 4]
// 007c87fd  5e                   pop esi
// 007c87fe  5d                   pop ebp
// 007c87ff  8910                 mov dword ptr [eax], edx
// 007c8801  894804               mov dword ptr [eax + 4], ecx
// 007c8804  c6400801             mov byte ptr [eax + 8], 1
// 007c8808  5b                   pop ebx
// 007c8809  83c414               add esp, 0x14
// 007c880c  c20800               ret 8
// 007c880f  8d4c2414             lea ecx, [esp + 0x14]
// 007c8813  e868a0ebff           call 0x682880
// 007c8818  8b742414             mov esi, dword ptr [esp + 0x14]
// 007c881c  8b542418             mov edx, dword ptr [esp + 0x18]
// 007c8820  83c20c               add edx, 0xc
// 007c8823  53                   push ebx
// 007c8824  52                   push edx
// 007c8825  ff15d8b59800         call dword ptr [0x98b5d8]
// 007c882b  83c408               add esp, 8
// 007c882e  84c0                 test al, al
// 007c8830  740e                 je 0x7c8840
// 007c8832  8b442410             mov eax, dword ptr [esp + 0x10]
// 007c8836  53                   push ebx
// 007c8837  57                   push edi
// 007c8838  50                   push eax
// 007c8839  8d4c2428             lea ecx, [esp + 0x28]
// 007c883d  51                   push ecx
// 007c883e  ebaa                 jmp 0x7c87ea
// 007c8840  8b442428             mov eax, dword ptr [esp + 0x28]
// 007c8844  8b542418             mov edx, dword ptr [esp + 0x18]
// 007c8848  5f                   pop edi
// 007c8849  8930                 mov dword ptr [eax], esi
// 007c884b  5e                   pop esi
// 007c884c  5d                   pop ebp
// 007c884d  895004               mov dword ptr [eax + 4], edx
// 007c8850  c6400800             mov byte ptr [eax + 8], 0
// 007c8854  5b                   pop ebx
// 007c8855  83c414               add esp, 0x14
// 007c8858  c20800               ret 8
// standard library map_str<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
