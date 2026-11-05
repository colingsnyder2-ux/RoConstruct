// from server: 100% by auto
// roc 2007-08 00583fb0  unit: RBX::VHat::?$FactoryProduct  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00583fb0
//
// 00583fb0  83ec0c               sub esp, 0xc
// 00583fb3  55                   push ebp
// 00583fb4  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00583fb8  56                   push esi
// 00583fb9  57                   push edi
// 00583fba  8bf9                 mov edi, ecx
// 00583fbc  8b7704               mov esi, dword ptr [edi + 4]
// 00583fbf  8b4604               mov eax, dword ptr [esi + 4]
// 00583fc2  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00583fc6  b101                 mov cl, 1
// 00583fc8  884c240c             mov byte ptr [esp + 0xc], cl
// 00583fcc  7520                 jne 0x583fee
// 00583fce  8b5500               mov edx, dword ptr [ebp]
// 00583fd1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00583fd4  8bf0                 mov esi, eax
// 00583fd6  0f9cc1               setl cl
// 00583fd9  84c9                 test cl, cl
// 00583fdb  884c240c             mov byte ptr [esp + 0xc], cl
// 00583fdf  7404                 je 0x583fe5
// 00583fe1  8b00                 mov eax, dword ptr [eax]
// 00583fe3  eb03                 jmp 0x583fe8
// 00583fe5  8b4008               mov eax, dword ptr [eax + 8]
// 00583fe8  80782d00             cmp byte ptr [eax + 0x2d], 0
// 00583fec  74e3                 je 0x583fd1
// 00583fee  84c9                 test cl, cl
// 00583ff0  8bd6                 mov edx, esi
// 00583ff2  89542414             mov dword ptr [esp + 0x14], edx
// 00583ff6  897c2410             mov dword ptr [esp + 0x10], edi
// 00583ffa  743d                 je 0x584039
// 00583ffc  8b4704               mov eax, dword ptr [edi + 4]
// 00583fff  3b30                 cmp esi, dword ptr [eax]
// 00584001  8d4c2410             lea ecx, [esp + 0x10]
// 00584005  7529                 jne 0x584030
// 00584007  55                   push ebp
// 00584008  56                   push esi
// 00584009  6a01                 push 1
// 0058400b  51                   push ecx
// 0058400c  8bcf                 mov ecx, edi
// 0058400e  e81df8ffff           call 0x583830
// 00584013  8bc8                 mov ecx, eax
// 00584015  8b11                 mov edx, dword ptr [ecx]
// 00584017  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0058401b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0058401e  5f                   pop edi
// 0058401f  5e                   pop esi
// 00584020  8910                 mov dword ptr [eax], edx
// 00584022  894804               mov dword ptr [eax + 4], ecx
// 00584025  c6400801             mov byte ptr [eax + 8], 1
// 00584029  5d                   pop ebp
// 0058402a  83c40c               add esp, 0xc
// 0058402d  c20800               ret 8
// 00584030  e8ebf3ffff           call 0x583420
// 00584035  8b542414             mov edx, dword ptr [esp + 0x14]
// 00584039  8b420c               mov eax, dword ptr [edx + 0xc]
// 0058403c  3b4500               cmp eax, dword ptr [ebp]
// 0058403f  7d0e                 jge 0x58404f
// 00584041  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00584045  55                   push ebp
// 00584046  56                   push esi
// 00584047  51                   push ecx
// 00584048  8d54241c             lea edx, [esp + 0x1c]
// 0058404c  52                   push edx
// 0058404d  ebbd                 jmp 0x58400c
// 0058404f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00584053  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00584057  5f                   pop edi
// 00584058  5e                   pop esi
// 00584059  8908                 mov dword ptr [eax], ecx
// 0058405b  895004               mov dword ptr [eax + 4], edx
// 0058405e  c6400800             mov byte ptr [eax + 8], 0
// 00584062  5d                   pop ebp
// 00584063  83c40c               add esp, 0xc
// 00584066  c20800               ret 8
// standard library map_int<string> (function ?insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
