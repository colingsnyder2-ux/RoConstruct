// from server: 100% by auto
// roc 2009-06 0048e770  unit: Ogre::RbxTextureCompositorSceneManager  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048e770
//
// 0048e770  83ec14               sub esp, 0x14
// 0048e773  53                   push ebx
// 0048e774  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0048e778  55                   push ebp
// 0048e779  56                   push esi
// 0048e77a  8be9                 mov ebp, ecx
// 0048e77c  57                   push edi
// 0048e77d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 0048e780  8b7704               mov esi, dword ptr [edi + 4]
// 0048e783  807e6900             cmp byte ptr [esi + 0x69], 0
// 0048e787  b001                 mov al, 1
// 0048e789  88442410             mov byte ptr [esp + 0x10], al
// 0048e78d  7526                 jne 0x48e7b5
// 0048e78f  90                   nop 
// 0048e790  8d460c               lea eax, [esi + 0xc]
// 0048e793  50                   push eax
// 0048e794  53                   push ebx
// 0048e795  8bfe                 mov edi, esi
// 0048e797  ff15e0e48900         call dword ptr [0x89e4e0]
// 0048e79d  83c408               add esp, 8
// 0048e7a0  88442410             mov byte ptr [esp + 0x10], al
// 0048e7a4  84c0                 test al, al
// 0048e7a6  7404                 je 0x48e7ac
// 0048e7a8  8b36                 mov esi, dword ptr [esi]
// 0048e7aa  eb03                 jmp 0x48e7af
// 0048e7ac  8b7608               mov esi, dword ptr [esi + 8]
// 0048e7af  807e6900             cmp byte ptr [esi + 0x69], 0
// 0048e7b3  74db                 je 0x48e790
// 0048e7b5  8b7500               mov esi, dword ptr [ebp]
// 0048e7b8  897c2418             mov dword ptr [esp + 0x18], edi
// 0048e7bc  89742414             mov dword ptr [esp + 0x14], esi
// 0048e7c0  84c0                 test al, al
// 0048e7c2  7458                 je 0x48e81c
// 0048e7c4  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0048e7c7  8b11                 mov edx, dword ptr [ecx]
// 0048e7c9  89542420             mov dword ptr [esp + 0x20], edx
// 0048e7cd  85f6                 test esi, esi
// 0048e7cf  7404                 je 0x48e7d5
// 0048e7d1  3bf6                 cmp esi, esi
// 0048e7d3  7406                 je 0x48e7db
// 0048e7d5  ff15ace98900         call dword ptr [0x89e9ac]
// 0048e7db  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 0048e7df  752e                 jne 0x48e80f
// 0048e7e1  53                   push ebx
// 0048e7e2  57                   push edi
// 0048e7e3  6a01                 push 1
// 0048e7e5  8d442428             lea eax, [esp + 0x28]
// 0048e7e9  50                   push eax
// 0048e7ea  8bcd                 mov ecx, ebp
// 0048e7ec  e8dffcffff           call 0x48e4d0
// 0048e7f1  5f                   pop edi
// 0048e7f2  8bc8                 mov ecx, eax
// 0048e7f4  8b11                 mov edx, dword ptr [ecx]
// 0048e7f6  8b442424             mov eax, dword ptr [esp + 0x24]
// 0048e7fa  8b4904               mov ecx, dword ptr [ecx + 4]
// 0048e7fd  5e                   pop esi
// 0048e7fe  5d                   pop ebp
// 0048e7ff  8910                 mov dword ptr [eax], edx
// 0048e801  894804               mov dword ptr [eax + 4], ecx
// 0048e804  c6400801             mov byte ptr [eax + 8], 1
// 0048e808  5b                   pop ebx
// 0048e809  83c414               add esp, 0x14
// 0048e80c  c20800               ret 8
// 0048e80f  8d4c2414             lea ecx, [esp + 0x14]
// 0048e813  e8f8cfffff           call 0x48b810
// 0048e818  8b742414             mov esi, dword ptr [esp + 0x14]
// 0048e81c  8b542418             mov edx, dword ptr [esp + 0x18]
// 0048e820  83c20c               add edx, 0xc
// 0048e823  53                   push ebx
// 0048e824  52                   push edx
// 0048e825  ff15e0e48900         call dword ptr [0x89e4e0]
// 0048e82b  83c408               add esp, 8
// 0048e82e  84c0                 test al, al
// 0048e830  740e                 je 0x48e840
// 0048e832  8b442410             mov eax, dword ptr [esp + 0x10]
// 0048e836  53                   push ebx
// 0048e837  57                   push edi
// 0048e838  50                   push eax
// 0048e839  8d4c2428             lea ecx, [esp + 0x28]
// 0048e83d  51                   push ecx
// 0048e83e  ebaa                 jmp 0x48e7ea
// 0048e840  8b442428             mov eax, dword ptr [esp + 0x28]
// 0048e844  8b542418             mov edx, dword ptr [esp + 0x18]
// 0048e848  5f                   pop edi
// 0048e849  8930                 mov dword ptr [eax], esi
// 0048e84b  5e                   pop esi
// 0048e84c  5d                   pop ebp
// 0048e84d  895004               mov dword ptr [eax + 4], edx
// 0048e850  c6400800             mov byte ptr [eax + 8], 0
// 0048e854  5b                   pop ebx
// 0048e855  83c414               add esp, 0x14
// 0048e858  c20800               ret 8
// standard library map_str<pod64> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
