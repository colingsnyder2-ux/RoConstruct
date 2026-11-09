// from server: 100% by auto
// roc 2008-06 00592ca0  unit: ArchiveBinder  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00592ca0
//
// 00592ca0  83ec14               sub esp, 0x14
// 00592ca3  53                   push ebx
// 00592ca4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00592ca8  55                   push ebp
// 00592ca9  56                   push esi
// 00592caa  8be9                 mov ebp, ecx
// 00592cac  57                   push edi
// 00592cad  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 00592cb0  8b7704               mov esi, dword ptr [edi + 4]
// 00592cb3  807e3100             cmp byte ptr [esi + 0x31], 0
// 00592cb7  b001                 mov al, 1
// 00592cb9  88442410             mov byte ptr [esp + 0x10], al
// 00592cbd  7526                 jne 0x592ce5
// 00592cbf  90                   nop 
// 00592cc0  8d460c               lea eax, [esi + 0xc]
// 00592cc3  50                   push eax
// 00592cc4  53                   push ebx
// 00592cc5  8bfe                 mov edi, esi
// 00592cc7  ff155c238000         call dword ptr [0x80235c]
// 00592ccd  83c408               add esp, 8
// 00592cd0  88442410             mov byte ptr [esp + 0x10], al
// 00592cd4  84c0                 test al, al
// 00592cd6  7404                 je 0x592cdc
// 00592cd8  8b36                 mov esi, dword ptr [esi]
// 00592cda  eb03                 jmp 0x592cdf
// 00592cdc  8b7608               mov esi, dword ptr [esi + 8]
// 00592cdf  807e3100             cmp byte ptr [esi + 0x31], 0
// 00592ce3  74db                 je 0x592cc0
// 00592ce5  8b7500               mov esi, dword ptr [ebp]
// 00592ce8  897c2418             mov dword ptr [esp + 0x18], edi
// 00592cec  89742414             mov dword ptr [esp + 0x14], esi
// 00592cf0  84c0                 test al, al
// 00592cf2  7458                 je 0x592d4c
// 00592cf4  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00592cf7  8b11                 mov edx, dword ptr [ecx]
// 00592cf9  89542420             mov dword ptr [esp + 0x20], edx
// 00592cfd  85f6                 test esi, esi
// 00592cff  7404                 je 0x592d05
// 00592d01  3bf6                 cmp esi, esi
// 00592d03  7406                 je 0x592d0b
// 00592d05  ff1590288000         call dword ptr [0x802890]
// 00592d0b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 00592d0f  752e                 jne 0x592d3f
// 00592d11  53                   push ebx
// 00592d12  57                   push edi
// 00592d13  6a01                 push 1
// 00592d15  8d442428             lea eax, [esp + 0x28]
// 00592d19  50                   push eax
// 00592d1a  8bcd                 mov ecx, ebp
// 00592d1c  e87ffdffff           call 0x592aa0
// 00592d21  5f                   pop edi
// 00592d22  8bc8                 mov ecx, eax
// 00592d24  8b11                 mov edx, dword ptr [ecx]
// 00592d26  8b442424             mov eax, dword ptr [esp + 0x24]
// 00592d2a  8b4904               mov ecx, dword ptr [ecx + 4]
// 00592d2d  5e                   pop esi
// 00592d2e  5d                   pop ebp
// 00592d2f  8910                 mov dword ptr [eax], edx
// 00592d31  894804               mov dword ptr [eax + 4], ecx
// 00592d34  c6400801             mov byte ptr [eax + 8], 1
// 00592d38  5b                   pop ebx
// 00592d39  83c414               add esp, 0x14
// 00592d3c  c20800               ret 8
// 00592d3f  8d4c2414             lea ecx, [esp + 0x14]
// 00592d43  e818e40b00           call 0x651160
// 00592d48  8b742414             mov esi, dword ptr [esp + 0x14]
// 00592d4c  8b542418             mov edx, dword ptr [esp + 0x18]
// 00592d50  83c20c               add edx, 0xc
// 00592d53  53                   push ebx
// 00592d54  52                   push edx
// 00592d55  ff155c238000         call dword ptr [0x80235c]
// 00592d5b  83c408               add esp, 8
// 00592d5e  84c0                 test al, al
// 00592d60  740e                 je 0x592d70
// 00592d62  8b442410             mov eax, dword ptr [esp + 0x10]
// 00592d66  53                   push ebx
// 00592d67  57                   push edi
// 00592d68  50                   push eax
// 00592d69  8d4c2428             lea ecx, [esp + 0x28]
// 00592d6d  51                   push ecx
// 00592d6e  ebaa                 jmp 0x592d1a
// 00592d70  8b442428             mov eax, dword ptr [esp + 0x28]
// 00592d74  8b542418             mov edx, dword ptr [esp + 0x18]
// 00592d78  5f                   pop edi
// 00592d79  8930                 mov dword ptr [eax], esi
// 00592d7b  5e                   pop esi
// 00592d7c  5d                   pop ebp
// 00592d7d  895004               mov dword ptr [eax + 4], edx
// 00592d80  c6400800             mov byte ptr [eax + 8], 0
// 00592d84  5b                   pop ebx
// 00592d85  83c414               add esp, 0x14
// 00592d88  c20800               ret 8
// standard library map_str<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
