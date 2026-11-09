// from server: 100% by auto
// roc 2010-06 0061bb40  unit: RBX::Accoutrement  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0061bb40
//
// 0061bb40  83ec0c               sub esp, 0xc
// 0061bb43  53                   push ebx
// 0061bb44  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0061bb48  55                   push ebp
// 0061bb49  56                   push esi
// 0061bb4a  57                   push edi
// 0061bb4b  8bf9                 mov edi, ecx
// 0061bb4d  8b7718               mov esi, dword ptr [edi + 0x18]
// 0061bb50  8b4604               mov eax, dword ptr [esi + 4]
// 0061bb53  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0061bb57  b101                 mov cl, 1
// 0061bb59  884c2410             mov byte ptr [esp + 0x10], cl
// 0061bb5d  751f                 jne 0x61bb7e
// 0061bb5f  8b13                 mov edx, dword ptr [ebx]
// 0061bb61  3b500c               cmp edx, dword ptr [eax + 0xc]
// 0061bb64  8bf0                 mov esi, eax
// 0061bb66  0f9cc1               setl cl
// 0061bb69  884c2410             mov byte ptr [esp + 0x10], cl
// 0061bb6d  84c9                 test cl, cl
// 0061bb6f  7404                 je 0x61bb75
// 0061bb71  8b00                 mov eax, dword ptr [eax]
// 0061bb73  eb03                 jmp 0x61bb78
// 0061bb75  8b4008               mov eax, dword ptr [eax + 8]
// 0061bb78  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0061bb7c  74e3                 je 0x61bb61
// 0061bb7e  8b17                 mov edx, dword ptr [edi]
// 0061bb80  8bee                 mov ebp, esi
// 0061bb82  896c2418             mov dword ptr [esp + 0x18], ebp
// 0061bb86  89542414             mov dword ptr [esp + 0x14], edx
// 0061bb8a  84c9                 test cl, cl
// 0061bb8c  7452                 je 0x61bbe0
// 0061bb8e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061bb91  8b28                 mov ebp, dword ptr [eax]
// 0061bb93  85d2                 test edx, edx
// 0061bb95  7404                 je 0x61bb9b
// 0061bb97  3bd2                 cmp edx, edx
// 0061bb99  7406                 je 0x61bba1
// 0061bb9b  ff150ca99e00         call dword ptr [0x9ea90c]
// 0061bba1  8d4c2414             lea ecx, [esp + 0x14]
// 0061bba5  3bf5                 cmp esi, ebp
// 0061bba7  752a                 jne 0x61bbd3
// 0061bba9  53                   push ebx
// 0061bbaa  56                   push esi
// 0061bbab  6a01                 push 1
// 0061bbad  51                   push ecx
// 0061bbae  8bcf                 mov ecx, edi
// 0061bbb0  e85bf8ffff           call 0x61b410
// 0061bbb5  5f                   pop edi
// 0061bbb6  8bc8                 mov ecx, eax
// 0061bbb8  8b11                 mov edx, dword ptr [ecx]
// 0061bbba  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061bbbe  8b4904               mov ecx, dword ptr [ecx + 4]
// 0061bbc1  5e                   pop esi
// 0061bbc2  5d                   pop ebp
// 0061bbc3  894804               mov dword ptr [eax + 4], ecx
// 0061bbc6  c6400801             mov byte ptr [eax + 8], 1
// 0061bbca  8910                 mov dword ptr [eax], edx
// 0061bbcc  5b                   pop ebx
// 0061bbcd  83c40c               add esp, 0xc
// 0061bbd0  c20800               ret 8
// 0061bbd3  e848dc1100           call 0x739820
// 0061bbd8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0061bbdc  8b542414             mov edx, dword ptr [esp + 0x14]
// 0061bbe0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0061bbe3  3b03                 cmp eax, dword ptr [ebx]
// 0061bbe5  7d31                 jge 0x61bc18
// 0061bbe7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0061bbeb  53                   push ebx
// 0061bbec  56                   push esi
// 0061bbed  51                   push ecx
// 0061bbee  8d542420             lea edx, [esp + 0x20]
// 0061bbf2  52                   push edx
// 0061bbf3  8bcf                 mov ecx, edi
// 0061bbf5  e816f8ffff           call 0x61b410
// 0061bbfa  5f                   pop edi
// 0061bbfb  8bc8                 mov ecx, eax
// 0061bbfd  8b11                 mov edx, dword ptr [ecx]
// 0061bbff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061bc03  8b4904               mov ecx, dword ptr [ecx + 4]
// 0061bc06  5e                   pop esi
// 0061bc07  5d                   pop ebp
// 0061bc08  894804               mov dword ptr [eax + 4], ecx
// 0061bc0b  c6400801             mov byte ptr [eax + 8], 1
// 0061bc0f  8910                 mov dword ptr [eax], edx
// 0061bc11  5b                   pop ebx
// 0061bc12  83c40c               add esp, 0xc
// 0061bc15  c20800               ret 8
// 0061bc18  8b442420             mov eax, dword ptr [esp + 0x20]
// 0061bc1c  5f                   pop edi
// 0061bc1d  5e                   pop esi
// 0061bc1e  896804               mov dword ptr [eax + 4], ebp
// 0061bc21  5d                   pop ebp
// 0061bc22  c6400800             mov byte ptr [eax + 8], 0
// 0061bc26  8910                 mov dword ptr [eax], edx
// 0061bc28  5b                   pop ebx
// 0061bc29  83c40c               add esp, 0xc
// 0061bc2c  c20800               ret 8
// standard library map_int<string> (function ?insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
