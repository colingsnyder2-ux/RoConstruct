// from server: 100% by auto
// roc 2009-12 0047ace0  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047ace0
//
// 0047ace0  83ec14               sub esp, 0x14
// 0047ace3  53                   push ebx
// 0047ace4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0047ace8  55                   push ebp
// 0047ace9  56                   push esi
// 0047acea  8be9                 mov ebp, ecx
// 0047acec  57                   push edi
// 0047aced  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 0047acf0  8b7704               mov esi, dword ptr [edi + 4]
// 0047acf3  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 0047acf7  b001                 mov al, 1
// 0047acf9  88442410             mov byte ptr [esp + 0x10], al
// 0047acfd  7526                 jne 0x47ad25
// 0047acff  90                   nop 
// 0047ad00  8d460c               lea eax, [esi + 0xc]
// 0047ad03  50                   push eax
// 0047ad04  53                   push ebx
// 0047ad05  8bfe                 mov edi, esi
// 0047ad07  ff15d8b59800         call dword ptr [0x98b5d8]
// 0047ad0d  83c408               add esp, 8
// 0047ad10  88442410             mov byte ptr [esp + 0x10], al
// 0047ad14  84c0                 test al, al
// 0047ad16  7404                 je 0x47ad1c
// 0047ad18  8b36                 mov esi, dword ptr [esi]
// 0047ad1a  eb03                 jmp 0x47ad1f
// 0047ad1c  8b7608               mov esi, dword ptr [esi + 8]
// 0047ad1f  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 0047ad23  74db                 je 0x47ad00
// 0047ad25  8b7500               mov esi, dword ptr [ebp]
// 0047ad28  897c2418             mov dword ptr [esp + 0x18], edi
// 0047ad2c  89742414             mov dword ptr [esp + 0x14], esi
// 0047ad30  84c0                 test al, al
// 0047ad32  7458                 je 0x47ad8c
// 0047ad34  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0047ad37  8b11                 mov edx, dword ptr [ecx]
// 0047ad39  89542420             mov dword ptr [esp + 0x20], edx
// 0047ad3d  85f6                 test esi, esi
// 0047ad3f  7404                 je 0x47ad45
// 0047ad41  3bf6                 cmp esi, esi
// 0047ad43  7406                 je 0x47ad4b
// 0047ad45  ff1560b79800         call dword ptr [0x98b760]
// 0047ad4b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 0047ad4f  752e                 jne 0x47ad7f
// 0047ad51  53                   push ebx
// 0047ad52  57                   push edi
// 0047ad53  6a01                 push 1
// 0047ad55  8d442428             lea eax, [esp + 0x28]
// 0047ad59  50                   push eax
// 0047ad5a  8bcd                 mov ecx, ebp
// 0047ad5c  e87ffdffff           call 0x47aae0
// 0047ad61  5f                   pop edi
// 0047ad62  8bc8                 mov ecx, eax
// 0047ad64  8b11                 mov edx, dword ptr [ecx]
// 0047ad66  8b442424             mov eax, dword ptr [esp + 0x24]
// 0047ad6a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0047ad6d  5e                   pop esi
// 0047ad6e  5d                   pop ebp
// 0047ad6f  8910                 mov dword ptr [eax], edx
// 0047ad71  894804               mov dword ptr [eax + 4], ecx
// 0047ad74  c6400801             mov byte ptr [eax + 8], 1
// 0047ad78  5b                   pop ebx
// 0047ad79  83c414               add esp, 0x14
// 0047ad7c  c20800               ret 8
// 0047ad7f  8d4c2414             lea ecx, [esp + 0x14]
// 0047ad83  e878db2000           call 0x688900
// 0047ad88  8b742414             mov esi, dword ptr [esp + 0x14]
// 0047ad8c  8b542418             mov edx, dword ptr [esp + 0x18]
// 0047ad90  83c20c               add edx, 0xc
// 0047ad93  53                   push ebx
// 0047ad94  52                   push edx
// 0047ad95  ff15d8b59800         call dword ptr [0x98b5d8]
// 0047ad9b  83c408               add esp, 8
// 0047ad9e  84c0                 test al, al
// 0047ada0  740e                 je 0x47adb0
// 0047ada2  8b442410             mov eax, dword ptr [esp + 0x10]
// 0047ada6  53                   push ebx
// 0047ada7  57                   push edi
// 0047ada8  50                   push eax
// 0047ada9  8d4c2428             lea ecx, [esp + 0x28]
// 0047adad  51                   push ecx
// 0047adae  ebaa                 jmp 0x47ad5a
// 0047adb0  8b442428             mov eax, dword ptr [esp + 0x28]
// 0047adb4  8b542418             mov edx, dword ptr [esp + 0x18]
// 0047adb8  5f                   pop edi
// 0047adb9  8930                 mov dword ptr [eax], esi
// 0047adbb  5e                   pop esi
// 0047adbc  5d                   pop ebp
// 0047adbd  895004               mov dword ptr [eax + 4], edx
// 0047adc0  c6400800             mov byte ptr [eax + 8], 0
// 0047adc4  5b                   pop ebx
// 0047adc5  83c414               add esp, 0x14
// 0047adc8  c20800               ret 8
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
