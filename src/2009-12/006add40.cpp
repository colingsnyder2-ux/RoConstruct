// from server: 100% by auto
// roc 2009-12 006add40  unit: RBX::Accoutrement  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006add40
//
// 006add40  83ec0c               sub esp, 0xc
// 006add43  53                   push ebx
// 006add44  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006add48  55                   push ebp
// 006add49  56                   push esi
// 006add4a  57                   push edi
// 006add4b  8bf9                 mov edi, ecx
// 006add4d  8b7718               mov esi, dword ptr [edi + 0x18]
// 006add50  8b4604               mov eax, dword ptr [esi + 4]
// 006add53  80782d00             cmp byte ptr [eax + 0x2d], 0
// 006add57  b101                 mov cl, 1
// 006add59  884c2410             mov byte ptr [esp + 0x10], cl
// 006add5d  751f                 jne 0x6add7e
// 006add5f  8b13                 mov edx, dword ptr [ebx]
// 006add61  3b500c               cmp edx, dword ptr [eax + 0xc]
// 006add64  8bf0                 mov esi, eax
// 006add66  0f9cc1               setl cl
// 006add69  884c2410             mov byte ptr [esp + 0x10], cl
// 006add6d  84c9                 test cl, cl
// 006add6f  7404                 je 0x6add75
// 006add71  8b00                 mov eax, dword ptr [eax]
// 006add73  eb03                 jmp 0x6add78
// 006add75  8b4008               mov eax, dword ptr [eax + 8]
// 006add78  80782d00             cmp byte ptr [eax + 0x2d], 0
// 006add7c  74e3                 je 0x6add61
// 006add7e  8b17                 mov edx, dword ptr [edi]
// 006add80  8bee                 mov ebp, esi
// 006add82  896c2418             mov dword ptr [esp + 0x18], ebp
// 006add86  89542414             mov dword ptr [esp + 0x14], edx
// 006add8a  84c9                 test cl, cl
// 006add8c  7452                 je 0x6adde0
// 006add8e  8b4718               mov eax, dword ptr [edi + 0x18]
// 006add91  8b28                 mov ebp, dword ptr [eax]
// 006add93  85d2                 test edx, edx
// 006add95  7404                 je 0x6add9b
// 006add97  3bd2                 cmp edx, edx
// 006add99  7406                 je 0x6adda1
// 006add9b  ff1560b79800         call dword ptr [0x98b760]
// 006adda1  8d4c2414             lea ecx, [esp + 0x14]
// 006adda5  3bf5                 cmp esi, ebp
// 006adda7  752a                 jne 0x6addd3
// 006adda9  53                   push ebx
// 006addaa  56                   push esi
// 006addab  6a01                 push 1
// 006addad  51                   push ecx
// 006addae  8bcf                 mov ecx, edi
// 006addb0  e87be4ecff           call 0x57c230
// 006addb5  5f                   pop edi
// 006addb6  8bc8                 mov ecx, eax
// 006addb8  8b11                 mov edx, dword ptr [ecx]
// 006addba  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006addbe  8b4904               mov ecx, dword ptr [ecx + 4]
// 006addc1  5e                   pop esi
// 006addc2  5d                   pop ebp
// 006addc3  894804               mov dword ptr [eax + 4], ecx
// 006addc6  c6400801             mov byte ptr [eax + 8], 1
// 006addca  8910                 mov dword ptr [eax], edx
// 006addcc  5b                   pop ebx
// 006addcd  83c40c               add esp, 0xc
// 006addd0  c20800               ret 8
// 006addd3  e828abfdff           call 0x688900
// 006addd8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 006adddc  8b542414             mov edx, dword ptr [esp + 0x14]
// 006adde0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006adde3  3b03                 cmp eax, dword ptr [ebx]
// 006adde5  7d31                 jge 0x6ade18
// 006adde7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006addeb  53                   push ebx
// 006addec  56                   push esi
// 006added  51                   push ecx
// 006addee  8d542420             lea edx, [esp + 0x20]
// 006addf2  52                   push edx
// 006addf3  8bcf                 mov ecx, edi
// 006addf5  e836e4ecff           call 0x57c230
// 006addfa  5f                   pop edi
// 006addfb  8bc8                 mov ecx, eax
// 006addfd  8b11                 mov edx, dword ptr [ecx]
// 006addff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006ade03  8b4904               mov ecx, dword ptr [ecx + 4]
// 006ade06  5e                   pop esi
// 006ade07  5d                   pop ebp
// 006ade08  894804               mov dword ptr [eax + 4], ecx
// 006ade0b  c6400801             mov byte ptr [eax + 8], 1
// 006ade0f  8910                 mov dword ptr [eax], edx
// 006ade11  5b                   pop ebx
// 006ade12  83c40c               add esp, 0xc
// 006ade15  c20800               ret 8
// 006ade18  8b442420             mov eax, dword ptr [esp + 0x20]
// 006ade1c  5f                   pop edi
// 006ade1d  5e                   pop esi
// 006ade1e  896804               mov dword ptr [eax + 4], ebp
// 006ade21  5d                   pop ebp
// 006ade22  c6400800             mov byte ptr [eax + 8], 0
// 006ade26  8910                 mov dword ptr [eax], edx
// 006ade28  5b                   pop ebx
// 006ade29  83c40c               add esp, 0xc
// 006ade2c  c20800               ret 8
// standard library map_int<string> (function ?insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
