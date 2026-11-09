// from server: 100% by auto
// roc 2009-06 006fdef0  unit: RBX::AdornRbxGfx  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fdef0
//
// 006fdef0  83ec14               sub esp, 0x14
// 006fdef3  53                   push ebx
// 006fdef4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 006fdef8  55                   push ebp
// 006fdef9  56                   push esi
// 006fdefa  8be9                 mov ebp, ecx
// 006fdefc  57                   push edi
// 006fdefd  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 006fdf00  8b7704               mov esi, dword ptr [edi + 4]
// 006fdf03  807e3500             cmp byte ptr [esi + 0x35], 0
// 006fdf07  b001                 mov al, 1
// 006fdf09  88442410             mov byte ptr [esp + 0x10], al
// 006fdf0d  7526                 jne 0x6fdf35
// 006fdf0f  90                   nop 
// 006fdf10  8d460c               lea eax, [esi + 0xc]
// 006fdf13  50                   push eax
// 006fdf14  53                   push ebx
// 006fdf15  8bfe                 mov edi, esi
// 006fdf17  ff15e0e48900         call dword ptr [0x89e4e0]
// 006fdf1d  83c408               add esp, 8
// 006fdf20  88442410             mov byte ptr [esp + 0x10], al
// 006fdf24  84c0                 test al, al
// 006fdf26  7404                 je 0x6fdf2c
// 006fdf28  8b36                 mov esi, dword ptr [esi]
// 006fdf2a  eb03                 jmp 0x6fdf2f
// 006fdf2c  8b7608               mov esi, dword ptr [esi + 8]
// 006fdf2f  807e3500             cmp byte ptr [esi + 0x35], 0
// 006fdf33  74db                 je 0x6fdf10
// 006fdf35  8b7500               mov esi, dword ptr [ebp]
// 006fdf38  897c2418             mov dword ptr [esp + 0x18], edi
// 006fdf3c  89742414             mov dword ptr [esp + 0x14], esi
// 006fdf40  84c0                 test al, al
// 006fdf42  7458                 je 0x6fdf9c
// 006fdf44  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 006fdf47  8b11                 mov edx, dword ptr [ecx]
// 006fdf49  89542420             mov dword ptr [esp + 0x20], edx
// 006fdf4d  85f6                 test esi, esi
// 006fdf4f  7404                 je 0x6fdf55
// 006fdf51  3bf6                 cmp esi, esi
// 006fdf53  7406                 je 0x6fdf5b
// 006fdf55  ff15ace98900         call dword ptr [0x89e9ac]
// 006fdf5b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 006fdf5f  752e                 jne 0x6fdf8f
// 006fdf61  53                   push ebx
// 006fdf62  57                   push edi
// 006fdf63  6a01                 push 1
// 006fdf65  8d442428             lea eax, [esp + 0x28]
// 006fdf69  50                   push eax
// 006fdf6a  8bcd                 mov ecx, ebp
// 006fdf6c  e8dff5ffff           call 0x6fd550
// 006fdf71  5f                   pop edi
// 006fdf72  8bc8                 mov ecx, eax
// 006fdf74  8b11                 mov edx, dword ptr [ecx]
// 006fdf76  8b442424             mov eax, dword ptr [esp + 0x24]
// 006fdf7a  8b4904               mov ecx, dword ptr [ecx + 4]
// 006fdf7d  5e                   pop esi
// 006fdf7e  5d                   pop ebp
// 006fdf7f  8910                 mov dword ptr [eax], edx
// 006fdf81  894804               mov dword ptr [eax + 4], ecx
// 006fdf84  c6400801             mov byte ptr [eax + 8], 1
// 006fdf88  5b                   pop ebx
// 006fdf89  83c414               add esp, 0x14
// 006fdf8c  c20800               ret 8
// 006fdf8f  8d4c2414             lea ecx, [esp + 0x14]
// 006fdf93  e8f8ebffff           call 0x6fcb90
// 006fdf98  8b742414             mov esi, dword ptr [esp + 0x14]
// 006fdf9c  8b542418             mov edx, dword ptr [esp + 0x18]
// 006fdfa0  83c20c               add edx, 0xc
// 006fdfa3  53                   push ebx
// 006fdfa4  52                   push edx
// 006fdfa5  ff15e0e48900         call dword ptr [0x89e4e0]
// 006fdfab  83c408               add esp, 8
// 006fdfae  84c0                 test al, al
// 006fdfb0  740e                 je 0x6fdfc0
// 006fdfb2  8b442410             mov eax, dword ptr [esp + 0x10]
// 006fdfb6  53                   push ebx
// 006fdfb7  57                   push edi
// 006fdfb8  50                   push eax
// 006fdfb9  8d4c2428             lea ecx, [esp + 0x28]
// 006fdfbd  51                   push ecx
// 006fdfbe  ebaa                 jmp 0x6fdf6a
// 006fdfc0  8b442428             mov eax, dword ptr [esp + 0x28]
// 006fdfc4  8b542418             mov edx, dword ptr [esp + 0x18]
// 006fdfc8  5f                   pop edi
// 006fdfc9  8930                 mov dword ptr [eax], esi
// 006fdfcb  5e                   pop esi
// 006fdfcc  5d                   pop ebp
// 006fdfcd  895004               mov dword ptr [eax + 4], edx
// 006fdfd0  c6400800             mov byte ptr [eax + 8], 0
// 006fdfd4  5b                   pop ebx
// 006fdfd5  83c414               add esp, 0x14
// 006fdfd8  c20800               ret 8
// standard library map_str<pod12> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
