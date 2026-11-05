// from server: 100% by auto
// roc 2007-08 00583ef0  unit: RBX::VHat::?$FactoryProduct  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00583ef0
//
// 00583ef0  83ec0c               sub esp, 0xc
// 00583ef3  55                   push ebp
// 00583ef4  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00583ef8  56                   push esi
// 00583ef9  57                   push edi
// 00583efa  8bf9                 mov edi, ecx
// 00583efc  8b7704               mov esi, dword ptr [edi + 4]
// 00583eff  8b4604               mov eax, dword ptr [esi + 4]
// 00583f02  80782100             cmp byte ptr [eax + 0x21], 0
// 00583f06  b101                 mov cl, 1
// 00583f08  884c240c             mov byte ptr [esp + 0xc], cl
// 00583f0c  7520                 jne 0x583f2e
// 00583f0e  8b5500               mov edx, dword ptr [ebp]
// 00583f11  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00583f14  8bf0                 mov esi, eax
// 00583f16  0f9cc1               setl cl
// 00583f19  84c9                 test cl, cl
// 00583f1b  884c240c             mov byte ptr [esp + 0xc], cl
// 00583f1f  7404                 je 0x583f25
// 00583f21  8b00                 mov eax, dword ptr [eax]
// 00583f23  eb03                 jmp 0x583f28
// 00583f25  8b4008               mov eax, dword ptr [eax + 8]
// 00583f28  80782100             cmp byte ptr [eax + 0x21], 0
// 00583f2c  74e3                 je 0x583f11
// 00583f2e  84c9                 test cl, cl
// 00583f30  8bd6                 mov edx, esi
// 00583f32  89542414             mov dword ptr [esp + 0x14], edx
// 00583f36  897c2410             mov dword ptr [esp + 0x10], edi
// 00583f3a  743d                 je 0x583f79
// 00583f3c  8b4704               mov eax, dword ptr [edi + 4]
// 00583f3f  3b30                 cmp esi, dword ptr [eax]
// 00583f41  8d4c2410             lea ecx, [esp + 0x10]
// 00583f45  7529                 jne 0x583f70
// 00583f47  55                   push ebp
// 00583f48  56                   push esi
// 00583f49  6a01                 push 1
// 00583f4b  51                   push ecx
// 00583f4c  8bcf                 mov ecx, edi
// 00583f4e  e8ddf6ffff           call 0x583630
// 00583f53  8bc8                 mov ecx, eax
// 00583f55  8b11                 mov edx, dword ptr [ecx]
// 00583f57  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00583f5b  8b4904               mov ecx, dword ptr [ecx + 4]
// 00583f5e  5f                   pop edi
// 00583f5f  5e                   pop esi
// 00583f60  8910                 mov dword ptr [eax], edx
// 00583f62  894804               mov dword ptr [eax + 4], ecx
// 00583f65  c6400801             mov byte ptr [eax + 8], 1
// 00583f69  5d                   pop ebp
// 00583f6a  83c40c               add esp, 0xc
// 00583f6d  c20800               ret 8
// 00583f70  e83bc4f1ff           call 0x4a03b0
// 00583f75  8b542414             mov edx, dword ptr [esp + 0x14]
// 00583f79  8b420c               mov eax, dword ptr [edx + 0xc]
// 00583f7c  3b4500               cmp eax, dword ptr [ebp]
// 00583f7f  7d0e                 jge 0x583f8f
// 00583f81  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00583f85  55                   push ebp
// 00583f86  56                   push esi
// 00583f87  51                   push ecx
// 00583f88  8d54241c             lea edx, [esp + 0x1c]
// 00583f8c  52                   push edx
// 00583f8d  ebbd                 jmp 0x583f4c
// 00583f8f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00583f93  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00583f97  5f                   pop edi
// 00583f98  5e                   pop esi
// 00583f99  8908                 mov dword ptr [eax], ecx
// 00583f9b  895004               mov dword ptr [eax + 4], edx
// 00583f9e  c6400800             mov byte ptr [eax + 8], 0
// 00583fa2  5d                   pop ebp
// 00583fa3  83c40c               add esp, 0xc
// 00583fa6  c20800               ret 8
// standard library map_int<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
