// from server: 100% by auto
// roc 2010-06 0067cb60  unit: RBX::VInstance::?$NonFactoryProduct  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0067cb60
//
// 0067cb60  83ec14               sub esp, 0x14
// 0067cb63  53                   push ebx
// 0067cb64  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0067cb68  55                   push ebp
// 0067cb69  56                   push esi
// 0067cb6a  8be9                 mov ebp, ecx
// 0067cb6c  57                   push edi
// 0067cb6d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 0067cb70  8b7704               mov esi, dword ptr [edi + 4]
// 0067cb73  807e3100             cmp byte ptr [esi + 0x31], 0
// 0067cb77  b001                 mov al, 1
// 0067cb79  88442410             mov byte ptr [esp + 0x10], al
// 0067cb7d  7526                 jne 0x67cba5
// 0067cb7f  90                   nop 
// 0067cb80  8d460c               lea eax, [esi + 0xc]
// 0067cb83  50                   push eax
// 0067cb84  53                   push ebx
// 0067cb85  8bfe                 mov edi, esi
// 0067cb87  ff151ca59e00         call dword ptr [0x9ea51c]
// 0067cb8d  83c408               add esp, 8
// 0067cb90  88442410             mov byte ptr [esp + 0x10], al
// 0067cb94  84c0                 test al, al
// 0067cb96  7404                 je 0x67cb9c
// 0067cb98  8b36                 mov esi, dword ptr [esi]
// 0067cb9a  eb03                 jmp 0x67cb9f
// 0067cb9c  8b7608               mov esi, dword ptr [esi + 8]
// 0067cb9f  807e3100             cmp byte ptr [esi + 0x31], 0
// 0067cba3  74db                 je 0x67cb80
// 0067cba5  8b7500               mov esi, dword ptr [ebp]
// 0067cba8  897c2418             mov dword ptr [esp + 0x18], edi
// 0067cbac  89742414             mov dword ptr [esp + 0x14], esi
// 0067cbb0  84c0                 test al, al
// 0067cbb2  7458                 je 0x67cc0c
// 0067cbb4  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0067cbb7  8b11                 mov edx, dword ptr [ecx]
// 0067cbb9  89542420             mov dword ptr [esp + 0x20], edx
// 0067cbbd  85f6                 test esi, esi
// 0067cbbf  7404                 je 0x67cbc5
// 0067cbc1  3bf6                 cmp esi, esi
// 0067cbc3  7406                 je 0x67cbcb
// 0067cbc5  ff150ca99e00         call dword ptr [0x9ea90c]
// 0067cbcb  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 0067cbcf  752e                 jne 0x67cbff
// 0067cbd1  53                   push ebx
// 0067cbd2  57                   push edi
// 0067cbd3  6a01                 push 1
// 0067cbd5  8d442428             lea eax, [esp + 0x28]
// 0067cbd9  50                   push eax
// 0067cbda  8bcd                 mov ecx, ebp
// 0067cbdc  e8eff1ffff           call 0x67bdd0
// 0067cbe1  5f                   pop edi
// 0067cbe2  8bc8                 mov ecx, eax
// 0067cbe4  8b11                 mov edx, dword ptr [ecx]
// 0067cbe6  8b442424             mov eax, dword ptr [esp + 0x24]
// 0067cbea  8b4904               mov ecx, dword ptr [ecx + 4]
// 0067cbed  5e                   pop esi
// 0067cbee  5d                   pop ebp
// 0067cbef  8910                 mov dword ptr [eax], edx
// 0067cbf1  894804               mov dword ptr [eax + 4], ecx
// 0067cbf4  c6400801             mov byte ptr [eax + 8], 1
// 0067cbf8  5b                   pop ebx
// 0067cbf9  83c414               add esp, 0x14
// 0067cbfc  c20800               ret 8
// 0067cbff  8d4c2414             lea ecx, [esp + 0x14]
// 0067cc03  e8d868dfff           call 0x4734e0
// 0067cc08  8b742414             mov esi, dword ptr [esp + 0x14]
// 0067cc0c  8b542418             mov edx, dword ptr [esp + 0x18]
// 0067cc10  83c20c               add edx, 0xc
// 0067cc13  53                   push ebx
// 0067cc14  52                   push edx
// 0067cc15  ff151ca59e00         call dword ptr [0x9ea51c]
// 0067cc1b  83c408               add esp, 8
// 0067cc1e  84c0                 test al, al
// 0067cc20  740e                 je 0x67cc30
// 0067cc22  8b442410             mov eax, dword ptr [esp + 0x10]
// 0067cc26  53                   push ebx
// 0067cc27  57                   push edi
// 0067cc28  50                   push eax
// 0067cc29  8d4c2428             lea ecx, [esp + 0x28]
// 0067cc2d  51                   push ecx
// 0067cc2e  ebaa                 jmp 0x67cbda
// 0067cc30  8b442428             mov eax, dword ptr [esp + 0x28]
// 0067cc34  8b542418             mov edx, dword ptr [esp + 0x18]
// 0067cc38  5f                   pop edi
// 0067cc39  8930                 mov dword ptr [eax], esi
// 0067cc3b  5e                   pop esi
// 0067cc3c  5d                   pop ebp
// 0067cc3d  895004               mov dword ptr [eax + 4], edx
// 0067cc40  c6400800             mov byte ptr [eax + 8], 0
// 0067cc44  5b                   pop ebx
// 0067cc45  83c414               add esp, 0x14
// 0067cc48  c20800               ret 8
// standard library map_str<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
