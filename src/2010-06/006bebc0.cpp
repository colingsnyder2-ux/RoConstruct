// from server: 100% by auto
// roc 2010-06 006bebc0  unit: RBX::VInstance::V?$shared_ptr::V?$vector::V?$copy_on_write_ptr::?$sp_counted_impl_p  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006bebc0
//
// 006bebc0  83ec14               sub esp, 0x14
// 006bebc3  53                   push ebx
// 006bebc4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 006bebc8  55                   push ebp
// 006bebc9  56                   push esi
// 006bebca  8be9                 mov ebp, ecx
// 006bebcc  57                   push edi
// 006bebcd  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 006bebd0  8b7704               mov esi, dword ptr [edi + 4]
// 006bebd3  807e3100             cmp byte ptr [esi + 0x31], 0
// 006bebd7  b001                 mov al, 1
// 006bebd9  88442410             mov byte ptr [esp + 0x10], al
// 006bebdd  7526                 jne 0x6bec05
// 006bebdf  90                   nop 
// 006bebe0  8d460c               lea eax, [esi + 0xc]
// 006bebe3  50                   push eax
// 006bebe4  53                   push ebx
// 006bebe5  8bfe                 mov edi, esi
// 006bebe7  ff151ca59e00         call dword ptr [0x9ea51c]
// 006bebed  83c408               add esp, 8
// 006bebf0  88442410             mov byte ptr [esp + 0x10], al
// 006bebf4  84c0                 test al, al
// 006bebf6  7404                 je 0x6bebfc
// 006bebf8  8b36                 mov esi, dword ptr [esi]
// 006bebfa  eb03                 jmp 0x6bebff
// 006bebfc  8b7608               mov esi, dword ptr [esi + 8]
// 006bebff  807e3100             cmp byte ptr [esi + 0x31], 0
// 006bec03  74db                 je 0x6bebe0
// 006bec05  8b7500               mov esi, dword ptr [ebp]
// 006bec08  897c2418             mov dword ptr [esp + 0x18], edi
// 006bec0c  89742414             mov dword ptr [esp + 0x14], esi
// 006bec10  84c0                 test al, al
// 006bec12  7458                 je 0x6bec6c
// 006bec14  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 006bec17  8b11                 mov edx, dword ptr [ecx]
// 006bec19  89542420             mov dword ptr [esp + 0x20], edx
// 006bec1d  85f6                 test esi, esi
// 006bec1f  7404                 je 0x6bec25
// 006bec21  3bf6                 cmp esi, esi
// 006bec23  7406                 je 0x6bec2b
// 006bec25  ff150ca99e00         call dword ptr [0x9ea90c]
// 006bec2b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 006bec2f  752e                 jne 0x6bec5f
// 006bec31  53                   push ebx
// 006bec32  57                   push edi
// 006bec33  6a01                 push 1
// 006bec35  8d442428             lea eax, [esp + 0x28]
// 006bec39  50                   push eax
// 006bec3a  8bcd                 mov ecx, ebp
// 006bec3c  e89ffcffff           call 0x6be8e0
// 006bec41  5f                   pop edi
// 006bec42  8bc8                 mov ecx, eax
// 006bec44  8b11                 mov edx, dword ptr [ecx]
// 006bec46  8b442424             mov eax, dword ptr [esp + 0x24]
// 006bec4a  8b4904               mov ecx, dword ptr [ecx + 4]
// 006bec4d  5e                   pop esi
// 006bec4e  5d                   pop ebp
// 006bec4f  8910                 mov dword ptr [eax], edx
// 006bec51  894804               mov dword ptr [eax + 4], ecx
// 006bec54  c6400801             mov byte ptr [eax + 8], 1
// 006bec58  5b                   pop ebx
// 006bec59  83c414               add esp, 0x14
// 006bec5c  c20800               ret 8
// 006bec5f  8d4c2414             lea ecx, [esp + 0x14]
// 006bec63  e87848dbff           call 0x4734e0
// 006bec68  8b742414             mov esi, dword ptr [esp + 0x14]
// 006bec6c  8b542418             mov edx, dword ptr [esp + 0x18]
// 006bec70  83c20c               add edx, 0xc
// 006bec73  53                   push ebx
// 006bec74  52                   push edx
// 006bec75  ff151ca59e00         call dword ptr [0x9ea51c]
// 006bec7b  83c408               add esp, 8
// 006bec7e  84c0                 test al, al
// 006bec80  740e                 je 0x6bec90
// 006bec82  8b442410             mov eax, dword ptr [esp + 0x10]
// 006bec86  53                   push ebx
// 006bec87  57                   push edi
// 006bec88  50                   push eax
// 006bec89  8d4c2428             lea ecx, [esp + 0x28]
// 006bec8d  51                   push ecx
// 006bec8e  ebaa                 jmp 0x6bec3a
// 006bec90  8b442428             mov eax, dword ptr [esp + 0x28]
// 006bec94  8b542418             mov edx, dword ptr [esp + 0x18]
// 006bec98  5f                   pop edi
// 006bec99  8930                 mov dword ptr [eax], esi
// 006bec9b  5e                   pop esi
// 006bec9c  5d                   pop ebp
// 006bec9d  895004               mov dword ptr [eax + 4], edx
// 006beca0  c6400800             mov byte ptr [eax + 8], 0
// 006beca4  5b                   pop ebx
// 006beca5  83c414               add esp, 0x14
// 006beca8  c20800               ret 8
// standard library map_str<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
