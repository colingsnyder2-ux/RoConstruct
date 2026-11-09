// from server: 100% by auto
// roc 2008-06 004a7a30  unit: RBX::VHint::?$FactoryProduct::Creator  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a7a30
//
// 004a7a30  83ec14               sub esp, 0x14
// 004a7a33  53                   push ebx
// 004a7a34  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 004a7a38  55                   push ebp
// 004a7a39  56                   push esi
// 004a7a3a  8be9                 mov ebp, ecx
// 004a7a3c  57                   push edi
// 004a7a3d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 004a7a40  8b7704               mov esi, dword ptr [edi + 4]
// 004a7a43  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 004a7a47  b001                 mov al, 1
// 004a7a49  88442410             mov byte ptr [esp + 0x10], al
// 004a7a4d  7526                 jne 0x4a7a75
// 004a7a4f  90                   nop 
// 004a7a50  8d460c               lea eax, [esi + 0xc]
// 004a7a53  50                   push eax
// 004a7a54  53                   push ebx
// 004a7a55  8bfe                 mov edi, esi
// 004a7a57  ff155c238000         call dword ptr [0x80235c]
// 004a7a5d  83c408               add esp, 8
// 004a7a60  88442410             mov byte ptr [esp + 0x10], al
// 004a7a64  84c0                 test al, al
// 004a7a66  7404                 je 0x4a7a6c
// 004a7a68  8b36                 mov esi, dword ptr [esi]
// 004a7a6a  eb03                 jmp 0x4a7a6f
// 004a7a6c  8b7608               mov esi, dword ptr [esi + 8]
// 004a7a6f  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 004a7a73  74db                 je 0x4a7a50
// 004a7a75  8b7500               mov esi, dword ptr [ebp]
// 004a7a78  897c2418             mov dword ptr [esp + 0x18], edi
// 004a7a7c  89742414             mov dword ptr [esp + 0x14], esi
// 004a7a80  84c0                 test al, al
// 004a7a82  7458                 je 0x4a7adc
// 004a7a84  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 004a7a87  8b11                 mov edx, dword ptr [ecx]
// 004a7a89  89542420             mov dword ptr [esp + 0x20], edx
// 004a7a8d  85f6                 test esi, esi
// 004a7a8f  7404                 je 0x4a7a95
// 004a7a91  3bf6                 cmp esi, esi
// 004a7a93  7406                 je 0x4a7a9b
// 004a7a95  ff1590288000         call dword ptr [0x802890]
// 004a7a9b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 004a7a9f  752e                 jne 0x4a7acf
// 004a7aa1  53                   push ebx
// 004a7aa2  57                   push edi
// 004a7aa3  6a01                 push 1
// 004a7aa5  8d442428             lea eax, [esp + 0x28]
// 004a7aa9  50                   push eax
// 004a7aaa  8bcd                 mov ecx, ebp
// 004a7aac  e86ffcffff           call 0x4a7720
// 004a7ab1  5f                   pop edi
// 004a7ab2  8bc8                 mov ecx, eax
// 004a7ab4  8b11                 mov edx, dword ptr [ecx]
// 004a7ab6  8b442424             mov eax, dword ptr [esp + 0x24]
// 004a7aba  8b4904               mov ecx, dword ptr [ecx + 4]
// 004a7abd  5e                   pop esi
// 004a7abe  5d                   pop ebp
// 004a7abf  8910                 mov dword ptr [eax], edx
// 004a7ac1  894804               mov dword ptr [eax + 4], ecx
// 004a7ac4  c6400801             mov byte ptr [eax + 8], 1
// 004a7ac8  5b                   pop ebx
// 004a7ac9  83c414               add esp, 0x14
// 004a7acc  c20800               ret 8
// 004a7acf  8d4c2414             lea ecx, [esp + 0x14]
// 004a7ad3  e878581e00           call 0x68d350
// 004a7ad8  8b742414             mov esi, dword ptr [esp + 0x14]
// 004a7adc  8b542418             mov edx, dword ptr [esp + 0x18]
// 004a7ae0  83c20c               add edx, 0xc
// 004a7ae3  53                   push ebx
// 004a7ae4  52                   push edx
// 004a7ae5  ff155c238000         call dword ptr [0x80235c]
// 004a7aeb  83c408               add esp, 8
// 004a7aee  84c0                 test al, al
// 004a7af0  740e                 je 0x4a7b00
// 004a7af2  8b442410             mov eax, dword ptr [esp + 0x10]
// 004a7af6  53                   push ebx
// 004a7af7  57                   push edi
// 004a7af8  50                   push eax
// 004a7af9  8d4c2428             lea ecx, [esp + 0x28]
// 004a7afd  51                   push ecx
// 004a7afe  ebaa                 jmp 0x4a7aaa
// 004a7b00  8b442428             mov eax, dword ptr [esp + 0x28]
// 004a7b04  8b542418             mov edx, dword ptr [esp + 0x18]
// 004a7b08  5f                   pop edi
// 004a7b09  8930                 mov dword ptr [eax], esi
// 004a7b0b  5e                   pop esi
// 004a7b0c  5d                   pop ebp
// 004a7b0d  895004               mov dword ptr [eax + 4], edx
// 004a7b10  c6400800             mov byte ptr [eax + 8], 0
// 004a7b14  5b                   pop ebx
// 004a7b15  83c414               add esp, 0x14
// 004a7b18  c20800               ret 8
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
