// from server: 100% by auto
// roc 2009-12 00480670  unit: RBX::AdornRbxGfx  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00480670
//
// 00480670  83ec14               sub esp, 0x14
// 00480673  53                   push ebx
// 00480674  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00480678  55                   push ebp
// 00480679  56                   push esi
// 0048067a  8be9                 mov ebp, ecx
// 0048067c  57                   push edi
// 0048067d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 00480680  8b7704               mov esi, dword ptr [edi + 4]
// 00480683  807e3900             cmp byte ptr [esi + 0x39], 0
// 00480687  b001                 mov al, 1
// 00480689  88442410             mov byte ptr [esp + 0x10], al
// 0048068d  7526                 jne 0x4806b5
// 0048068f  90                   nop 
// 00480690  8d460c               lea eax, [esi + 0xc]
// 00480693  50                   push eax
// 00480694  53                   push ebx
// 00480695  8bfe                 mov edi, esi
// 00480697  ff15d8b59800         call dword ptr [0x98b5d8]
// 0048069d  83c408               add esp, 8
// 004806a0  88442410             mov byte ptr [esp + 0x10], al
// 004806a4  84c0                 test al, al
// 004806a6  7404                 je 0x4806ac
// 004806a8  8b36                 mov esi, dword ptr [esi]
// 004806aa  eb03                 jmp 0x4806af
// 004806ac  8b7608               mov esi, dword ptr [esi + 8]
// 004806af  807e3900             cmp byte ptr [esi + 0x39], 0
// 004806b3  74db                 je 0x480690
// 004806b5  8b7500               mov esi, dword ptr [ebp]
// 004806b8  897c2418             mov dword ptr [esp + 0x18], edi
// 004806bc  89742414             mov dword ptr [esp + 0x14], esi
// 004806c0  84c0                 test al, al
// 004806c2  7458                 je 0x48071c
// 004806c4  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 004806c7  8b11                 mov edx, dword ptr [ecx]
// 004806c9  89542420             mov dword ptr [esp + 0x20], edx
// 004806cd  85f6                 test esi, esi
// 004806cf  7404                 je 0x4806d5
// 004806d1  3bf6                 cmp esi, esi
// 004806d3  7406                 je 0x4806db
// 004806d5  ff1560b79800         call dword ptr [0x98b760]
// 004806db  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 004806df  752e                 jne 0x48070f
// 004806e1  53                   push ebx
// 004806e2  57                   push edi
// 004806e3  6a01                 push 1
// 004806e5  8d442428             lea eax, [esp + 0x28]
// 004806e9  50                   push eax
// 004806ea  8bcd                 mov ecx, ebp
// 004806ec  e86ff2ffff           call 0x47f960
// 004806f1  5f                   pop edi
// 004806f2  8bc8                 mov ecx, eax
// 004806f4  8b11                 mov edx, dword ptr [ecx]
// 004806f6  8b442424             mov eax, dword ptr [esp + 0x24]
// 004806fa  8b4904               mov ecx, dword ptr [ecx + 4]
// 004806fd  5e                   pop esi
// 004806fe  5d                   pop ebp
// 004806ff  8910                 mov dword ptr [eax], edx
// 00480701  894804               mov dword ptr [eax + 4], ecx
// 00480704  c6400801             mov byte ptr [eax + 8], 1
// 00480708  5b                   pop ebx
// 00480709  83c414               add esp, 0x14
// 0048070c  c20800               ret 8
// 0048070f  8d4c2414             lea ecx, [esp + 0x14]
// 00480713  e8d8e8ffff           call 0x47eff0
// 00480718  8b742414             mov esi, dword ptr [esp + 0x14]
// 0048071c  8b542418             mov edx, dword ptr [esp + 0x18]
// 00480720  83c20c               add edx, 0xc
// 00480723  53                   push ebx
// 00480724  52                   push edx
// 00480725  ff15d8b59800         call dword ptr [0x98b5d8]
// 0048072b  83c408               add esp, 8
// 0048072e  84c0                 test al, al
// 00480730  740e                 je 0x480740
// 00480732  8b442410             mov eax, dword ptr [esp + 0x10]
// 00480736  53                   push ebx
// 00480737  57                   push edi
// 00480738  50                   push eax
// 00480739  8d4c2428             lea ecx, [esp + 0x28]
// 0048073d  51                   push ecx
// 0048073e  ebaa                 jmp 0x4806ea
// 00480740  8b442428             mov eax, dword ptr [esp + 0x28]
// 00480744  8b542418             mov edx, dword ptr [esp + 0x18]
// 00480748  5f                   pop edi
// 00480749  8930                 mov dword ptr [eax], esi
// 0048074b  5e                   pop esi
// 0048074c  5d                   pop ebp
// 0048074d  895004               mov dword ptr [eax + 4], edx
// 00480750  c6400800             mov byte ptr [eax + 8], 0
// 00480754  5b                   pop ebx
// 00480755  83c414               add esp, 0x14
// 00480758  c20800               ret 8
// standard library map_str<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod16>
struct E { int v[4]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
