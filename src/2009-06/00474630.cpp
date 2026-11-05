// from server: 100% by auto
// roc 2009-06 00474630  unit: Ogre::RbxSceneManager  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00474630
//
// 00474630  83ec14               sub esp, 0x14
// 00474633  53                   push ebx
// 00474634  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00474638  55                   push ebp
// 00474639  56                   push esi
// 0047463a  8be9                 mov ebp, ecx
// 0047463c  57                   push edi
// 0047463d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 00474640  8b7704               mov esi, dword ptr [edi + 4]
// 00474643  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 00474647  b001                 mov al, 1
// 00474649  88442410             mov byte ptr [esp + 0x10], al
// 0047464d  7526                 jne 0x474675
// 0047464f  90                   nop 
// 00474650  8d460c               lea eax, [esi + 0xc]
// 00474653  50                   push eax
// 00474654  53                   push ebx
// 00474655  8bfe                 mov edi, esi
// 00474657  ff15e0e48900         call dword ptr [0x89e4e0]
// 0047465d  83c408               add esp, 8
// 00474660  88442410             mov byte ptr [esp + 0x10], al
// 00474664  84c0                 test al, al
// 00474666  7404                 je 0x47466c
// 00474668  8b36                 mov esi, dword ptr [esi]
// 0047466a  eb03                 jmp 0x47466f
// 0047466c  8b7608               mov esi, dword ptr [esi + 8]
// 0047466f  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 00474673  74db                 je 0x474650
// 00474675  8b7500               mov esi, dword ptr [ebp]
// 00474678  897c2418             mov dword ptr [esp + 0x18], edi
// 0047467c  89742414             mov dword ptr [esp + 0x14], esi
// 00474680  84c0                 test al, al
// 00474682  7458                 je 0x4746dc
// 00474684  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00474687  8b11                 mov edx, dword ptr [ecx]
// 00474689  89542420             mov dword ptr [esp + 0x20], edx
// 0047468d  85f6                 test esi, esi
// 0047468f  7404                 je 0x474695
// 00474691  3bf6                 cmp esi, esi
// 00474693  7406                 je 0x47469b
// 00474695  ff15ace98900         call dword ptr [0x89e9ac]
// 0047469b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 0047469f  752e                 jne 0x4746cf
// 004746a1  53                   push ebx
// 004746a2  57                   push edi
// 004746a3  6a01                 push 1
// 004746a5  8d442428             lea eax, [esp + 0x28]
// 004746a9  50                   push eax
// 004746aa  8bcd                 mov ecx, ebp
// 004746ac  e8fff6ffff           call 0x473db0
// 004746b1  5f                   pop edi
// 004746b2  8bc8                 mov ecx, eax
// 004746b4  8b11                 mov edx, dword ptr [ecx]
// 004746b6  8b442424             mov eax, dword ptr [esp + 0x24]
// 004746ba  8b4904               mov ecx, dword ptr [ecx + 4]
// 004746bd  5e                   pop esi
// 004746be  5d                   pop ebp
// 004746bf  8910                 mov dword ptr [eax], edx
// 004746c1  894804               mov dword ptr [eax + 4], ecx
// 004746c4  c6400801             mov byte ptr [eax + 8], 1
// 004746c8  5b                   pop ebx
// 004746c9  83c414               add esp, 0x14
// 004746cc  c20800               ret 8
// 004746cf  8d4c2414             lea ecx, [esp + 0x14]
// 004746d3  e8786e1800           call 0x5fb550
// 004746d8  8b742414             mov esi, dword ptr [esp + 0x14]
// 004746dc  8b542418             mov edx, dword ptr [esp + 0x18]
// 004746e0  83c20c               add edx, 0xc
// 004746e3  53                   push ebx
// 004746e4  52                   push edx
// 004746e5  ff15e0e48900         call dword ptr [0x89e4e0]
// 004746eb  83c408               add esp, 8
// 004746ee  84c0                 test al, al
// 004746f0  740e                 je 0x474700
// 004746f2  8b442410             mov eax, dword ptr [esp + 0x10]
// 004746f6  53                   push ebx
// 004746f7  57                   push edi
// 004746f8  50                   push eax
// 004746f9  8d4c2428             lea ecx, [esp + 0x28]
// 004746fd  51                   push ecx
// 004746fe  ebaa                 jmp 0x4746aa
// 00474700  8b442428             mov eax, dword ptr [esp + 0x28]
// 00474704  8b542418             mov edx, dword ptr [esp + 0x18]
// 00474708  5f                   pop edi
// 00474709  8930                 mov dword ptr [eax], esi
// 0047470b  5e                   pop esi
// 0047470c  5d                   pop ebp
// 0047470d  895004               mov dword ptr [eax + 4], edx
// 00474710  c6400800             mov byte ptr [eax + 8], 0
// 00474714  5b                   pop ebx
// 00474715  83c414               add esp, 0x14
// 00474718  c20800               ret 8
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
