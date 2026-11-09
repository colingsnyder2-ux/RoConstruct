// from server: 100% by auto
// roc 2010-06 00739b50  unit: seg_00730000  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00739b50
//
// 00739b50  83ec14               sub esp, 0x14
// 00739b53  53                   push ebx
// 00739b54  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00739b58  55                   push ebp
// 00739b59  56                   push esi
// 00739b5a  8be9                 mov ebp, ecx
// 00739b5c  57                   push edi
// 00739b5d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 00739b60  8b7704               mov esi, dword ptr [edi + 4]
// 00739b63  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 00739b67  b001                 mov al, 1
// 00739b69  88442410             mov byte ptr [esp + 0x10], al
// 00739b6d  7526                 jne 0x739b95
// 00739b6f  90                   nop 
// 00739b70  8d460c               lea eax, [esi + 0xc]
// 00739b73  50                   push eax
// 00739b74  53                   push ebx
// 00739b75  8bfe                 mov edi, esi
// 00739b77  ff151ca59e00         call dword ptr [0x9ea51c]
// 00739b7d  83c408               add esp, 8
// 00739b80  88442410             mov byte ptr [esp + 0x10], al
// 00739b84  84c0                 test al, al
// 00739b86  7404                 je 0x739b8c
// 00739b88  8b36                 mov esi, dword ptr [esi]
// 00739b8a  eb03                 jmp 0x739b8f
// 00739b8c  8b7608               mov esi, dword ptr [esi + 8]
// 00739b8f  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 00739b93  74db                 je 0x739b70
// 00739b95  8b7500               mov esi, dword ptr [ebp]
// 00739b98  897c2418             mov dword ptr [esp + 0x18], edi
// 00739b9c  89742414             mov dword ptr [esp + 0x14], esi
// 00739ba0  84c0                 test al, al
// 00739ba2  7458                 je 0x739bfc
// 00739ba4  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00739ba7  8b11                 mov edx, dword ptr [ecx]
// 00739ba9  89542420             mov dword ptr [esp + 0x20], edx
// 00739bad  85f6                 test esi, esi
// 00739baf  7404                 je 0x739bb5
// 00739bb1  3bf6                 cmp esi, esi
// 00739bb3  7406                 je 0x739bbb
// 00739bb5  ff150ca99e00         call dword ptr [0x9ea90c]
// 00739bbb  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 00739bbf  752e                 jne 0x739bef
// 00739bc1  53                   push ebx
// 00739bc2  57                   push edi
// 00739bc3  6a01                 push 1
// 00739bc5  8d442428             lea eax, [esp + 0x28]
// 00739bc9  50                   push eax
// 00739bca  8bcd                 mov ecx, ebp
// 00739bcc  e87ffdffff           call 0x739950
// 00739bd1  5f                   pop edi
// 00739bd2  8bc8                 mov ecx, eax
// 00739bd4  8b11                 mov edx, dword ptr [ecx]
// 00739bd6  8b442424             mov eax, dword ptr [esp + 0x24]
// 00739bda  8b4904               mov ecx, dword ptr [ecx + 4]
// 00739bdd  5e                   pop esi
// 00739bde  5d                   pop ebp
// 00739bdf  8910                 mov dword ptr [eax], edx
// 00739be1  894804               mov dword ptr [eax + 4], ecx
// 00739be4  c6400801             mov byte ptr [eax + 8], 1
// 00739be8  5b                   pop ebx
// 00739be9  83c414               add esp, 0x14
// 00739bec  c20800               ret 8
// 00739bef  8d4c2414             lea ecx, [esp + 0x14]
// 00739bf3  e828fcffff           call 0x739820
// 00739bf8  8b742414             mov esi, dword ptr [esp + 0x14]
// 00739bfc  8b542418             mov edx, dword ptr [esp + 0x18]
// 00739c00  83c20c               add edx, 0xc
// 00739c03  53                   push ebx
// 00739c04  52                   push edx
// 00739c05  ff151ca59e00         call dword ptr [0x9ea51c]
// 00739c0b  83c408               add esp, 8
// 00739c0e  84c0                 test al, al
// 00739c10  740e                 je 0x739c20
// 00739c12  8b442410             mov eax, dword ptr [esp + 0x10]
// 00739c16  53                   push ebx
// 00739c17  57                   push edi
// 00739c18  50                   push eax
// 00739c19  8d4c2428             lea ecx, [esp + 0x28]
// 00739c1d  51                   push ecx
// 00739c1e  ebaa                 jmp 0x739bca
// 00739c20  8b442428             mov eax, dword ptr [esp + 0x28]
// 00739c24  8b542418             mov edx, dword ptr [esp + 0x18]
// 00739c28  5f                   pop edi
// 00739c29  8930                 mov dword ptr [eax], esi
// 00739c2b  5e                   pop esi
// 00739c2c  5d                   pop ebp
// 00739c2d  895004               mov dword ptr [eax + 4], edx
// 00739c30  c6400800             mov byte ptr [eax + 8], 0
// 00739c34  5b                   pop ebx
// 00739c35  83c414               add esp, 0x14
// 00739c38  c20800               ret 8
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
