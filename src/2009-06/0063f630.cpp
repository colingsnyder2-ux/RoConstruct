// from server: 100% by auto
// roc 2009-06 0063f630  unit: RBX::Accoutrement  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063f630
//
// 0063f630  83ec0c               sub esp, 0xc
// 0063f633  53                   push ebx
// 0063f634  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0063f638  55                   push ebp
// 0063f639  56                   push esi
// 0063f63a  57                   push edi
// 0063f63b  8bf9                 mov edi, ecx
// 0063f63d  8b7718               mov esi, dword ptr [edi + 0x18]
// 0063f640  8b4604               mov eax, dword ptr [esi + 4]
// 0063f643  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0063f647  b101                 mov cl, 1
// 0063f649  884c2410             mov byte ptr [esp + 0x10], cl
// 0063f64d  751f                 jne 0x63f66e
// 0063f64f  8b13                 mov edx, dword ptr [ebx]
// 0063f651  3b500c               cmp edx, dword ptr [eax + 0xc]
// 0063f654  8bf0                 mov esi, eax
// 0063f656  0f9cc1               setl cl
// 0063f659  884c2410             mov byte ptr [esp + 0x10], cl
// 0063f65d  84c9                 test cl, cl
// 0063f65f  7404                 je 0x63f665
// 0063f661  8b00                 mov eax, dword ptr [eax]
// 0063f663  eb03                 jmp 0x63f668
// 0063f665  8b4008               mov eax, dword ptr [eax + 8]
// 0063f668  80782d00             cmp byte ptr [eax + 0x2d], 0
// 0063f66c  74e3                 je 0x63f651
// 0063f66e  8b17                 mov edx, dword ptr [edi]
// 0063f670  8bee                 mov ebp, esi
// 0063f672  896c2418             mov dword ptr [esp + 0x18], ebp
// 0063f676  89542414             mov dword ptr [esp + 0x14], edx
// 0063f67a  84c9                 test cl, cl
// 0063f67c  7452                 je 0x63f6d0
// 0063f67e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0063f681  8b28                 mov ebp, dword ptr [eax]
// 0063f683  85d2                 test edx, edx
// 0063f685  7404                 je 0x63f68b
// 0063f687  3bd2                 cmp edx, edx
// 0063f689  7406                 je 0x63f691
// 0063f68b  ff15ace98900         call dword ptr [0x89e9ac]
// 0063f691  8d4c2414             lea ecx, [esp + 0x14]
// 0063f695  3bf5                 cmp esi, ebp
// 0063f697  752a                 jne 0x63f6c3
// 0063f699  53                   push ebx
// 0063f69a  56                   push esi
// 0063f69b  6a01                 push 1
// 0063f69d  51                   push ecx
// 0063f69e  8bcf                 mov ecx, edi
// 0063f6a0  e86bf7ffff           call 0x63ee10
// 0063f6a5  5f                   pop edi
// 0063f6a6  8bc8                 mov ecx, eax
// 0063f6a8  8b11                 mov edx, dword ptr [ecx]
// 0063f6aa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0063f6ae  8b4904               mov ecx, dword ptr [ecx + 4]
// 0063f6b1  5e                   pop esi
// 0063f6b2  5d                   pop ebp
// 0063f6b3  894804               mov dword ptr [eax + 4], ecx
// 0063f6b6  c6400801             mov byte ptr [eax + 8], 1
// 0063f6ba  8910                 mov dword ptr [eax], edx
// 0063f6bc  5b                   pop ebx
// 0063f6bd  83c40c               add esp, 0xc
// 0063f6c0  c20800               ret 8
// 0063f6c3  e888befbff           call 0x5fb550
// 0063f6c8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0063f6cc  8b542414             mov edx, dword ptr [esp + 0x14]
// 0063f6d0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0063f6d3  3b03                 cmp eax, dword ptr [ebx]
// 0063f6d5  7d31                 jge 0x63f708
// 0063f6d7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0063f6db  53                   push ebx
// 0063f6dc  56                   push esi
// 0063f6dd  51                   push ecx
// 0063f6de  8d542420             lea edx, [esp + 0x20]
// 0063f6e2  52                   push edx
// 0063f6e3  8bcf                 mov ecx, edi
// 0063f6e5  e826f7ffff           call 0x63ee10
// 0063f6ea  5f                   pop edi
// 0063f6eb  8bc8                 mov ecx, eax
// 0063f6ed  8b11                 mov edx, dword ptr [ecx]
// 0063f6ef  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0063f6f3  8b4904               mov ecx, dword ptr [ecx + 4]
// 0063f6f6  5e                   pop esi
// 0063f6f7  5d                   pop ebp
// 0063f6f8  894804               mov dword ptr [eax + 4], ecx
// 0063f6fb  c6400801             mov byte ptr [eax + 8], 1
// 0063f6ff  8910                 mov dword ptr [eax], edx
// 0063f701  5b                   pop ebx
// 0063f702  83c40c               add esp, 0xc
// 0063f705  c20800               ret 8
// 0063f708  8b442420             mov eax, dword ptr [esp + 0x20]
// 0063f70c  5f                   pop edi
// 0063f70d  5e                   pop esi
// 0063f70e  896804               mov dword ptr [eax + 4], ebp
// 0063f711  5d                   pop ebp
// 0063f712  c6400800             mov byte ptr [eax + 8], 0
// 0063f716  8910                 mov dword ptr [eax], edx
// 0063f718  5b                   pop ebx
// 0063f719  83c40c               add esp, 0xc
// 0063f71c  c20800               ret 8
// standard library map_int<string> (function ?insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
