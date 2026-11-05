// from server: 100% by auto
// roc 2010-06 005d00e0  unit: RBX::VInstance::?$NonFactoryProduct  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005d00e0
//
// 005d00e0  83ec14               sub esp, 0x14
// 005d00e3  56                   push esi
// 005d00e4  8bf1                 mov esi, ecx
// 005d00e6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 005d00ea  57                   push edi
// 005d00eb  7521                 jne 0x5d010e
// 005d00ed  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005d00f1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005d00f4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005d00f8  50                   push eax
// 005d00f9  51                   push ecx
// 005d00fa  6a01                 push 1
// 005d00fc  57                   push edi
// 005d00fd  8bce                 mov ecx, esi
// 005d00ff  e80ce9ffff           call 0x5cea10
// 005d0104  8bc7                 mov eax, edi
// 005d0106  5f                   pop edi
// 005d0107  5e                   pop esi
// 005d0108  83c414               add esp, 0x14
// 005d010b  c21000               ret 0x10
// 005d010e  8b442424             mov eax, dword ptr [esp + 0x24]
// 005d0112  8b5618               mov edx, dword ptr [esi + 0x18]
// 005d0115  8b3a                 mov edi, dword ptr [edx]
// 005d0117  8b0e                 mov ecx, dword ptr [esi]
// 005d0119  53                   push ebx
// 005d011a  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 005d0120  85c0                 test eax, eax
// 005d0122  7404                 je 0x5d0128
// 005d0124  3bc1                 cmp eax, ecx
// 005d0126  7406                 je 0x5d012e
// 005d0128  ffd3                 call ebx
// 005d012a  8b442428             mov eax, dword ptr [esp + 0x28]
// 005d012e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 005d0132  55                   push ebp
// 005d0133  3bd7                 cmp edx, edi
// 005d0135  753a                 jne 0x5d0171
// 005d0137  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 005d013b  83c20c               add edx, 0xc
// 005d013e  52                   push edx
// 005d013f  57                   push edi
// 005d0140  ff151ca59e00         call dword ptr [0x9ea51c]
// 005d0146  83c408               add esp, 8
// 005d0149  84c0                 test al, al
// 005d014b  0f849a010000         je 0x5d02eb
// 005d0151  8b442430             mov eax, dword ptr [esp + 0x30]
// 005d0155  57                   push edi
// 005d0156  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005d015a  50                   push eax
// 005d015b  6a01                 push 1
// 005d015d  57                   push edi
// 005d015e  8bce                 mov ecx, esi
// 005d0160  e8abe8ffff           call 0x5cea10
// 005d0165  5d                   pop ebp
// 005d0166  5b                   pop ebx
// 005d0167  8bc7                 mov eax, edi
// 005d0169  5f                   pop edi
// 005d016a  5e                   pop esi
// 005d016b  83c414               add esp, 0x14
// 005d016e  c21000               ret 0x10
// 005d0171  8b7e18               mov edi, dword ptr [esi + 0x18]
// 005d0174  8b0e                 mov ecx, dword ptr [esi]
// 005d0176  85c0                 test eax, eax
// 005d0178  7404                 je 0x5d017e
// 005d017a  3bc1                 cmp eax, ecx
// 005d017c  7406                 je 0x5d0184
// 005d017e  ffd3                 call ebx
// 005d0180  8b542430             mov edx, dword ptr [esp + 0x30]
// 005d0184  3bd7                 cmp edx, edi
// 005d0186  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 005d018a  753e                 jne 0x5d01ca
// 005d018c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005d018f  8b4108               mov eax, dword ptr [ecx + 8]
// 005d0192  83c00c               add eax, 0xc
// 005d0195  57                   push edi
// 005d0196  50                   push eax
// 005d0197  ff151ca59e00         call dword ptr [0x9ea51c]
// 005d019d  83c408               add esp, 8
// 005d01a0  84c0                 test al, al
// 005d01a2  0f8443010000         je 0x5d02eb
// 005d01a8  8b5618               mov edx, dword ptr [esi + 0x18]
// 005d01ab  8b4208               mov eax, dword ptr [edx + 8]
// 005d01ae  57                   push edi
// 005d01af  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005d01b3  50                   push eax
// 005d01b4  6a00                 push 0
// 005d01b6  57                   push edi
// 005d01b7  8bce                 mov ecx, esi
// 005d01b9  e852e8ffff           call 0x5cea10
// 005d01be  5d                   pop ebp
// 005d01bf  5b                   pop ebx
// 005d01c0  8bc7                 mov eax, edi
// 005d01c2  5f                   pop edi
// 005d01c3  5e                   pop esi
// 005d01c4  83c414               add esp, 0x14
// 005d01c7  c21000               ret 0x10
// 005d01ca  8b2d1ca59e00         mov ebp, dword ptr [0x9ea51c]
// 005d01d0  83c20c               add edx, 0xc
// 005d01d3  52                   push edx
// 005d01d4  57                   push edi
// 005d01d5  ffd5                 call ebp
// 005d01d7  83c408               add esp, 8
// 005d01da  84c0                 test al, al
// 005d01dc  746c                 je 0x5d024a
// 005d01de  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005d01e2  8b542430             mov edx, dword ptr [esp + 0x30]
// 005d01e6  894c2410             mov dword ptr [esp + 0x10], ecx
// 005d01ea  8d4c2410             lea ecx, [esp + 0x10]
// 005d01ee  89542414             mov dword ptr [esp + 0x14], edx
// 005d01f2  e829961600           call 0x739820
// 005d01f7  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005d01fb  57                   push edi
// 005d01fc  8d430c               lea eax, [ebx + 0xc]
// 005d01ff  50                   push eax
// 005d0200  8d4e08               lea ecx, [esi + 8]
// 005d0203  e84830eaff           call 0x473250
// 005d0208  84c0                 test al, al
// 005d020a  743e                 je 0x5d024a
// 005d020c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 005d020f  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 005d0213  57                   push edi
// 005d0214  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005d0218  8bce                 mov ecx, esi
// 005d021a  7415                 je 0x5d0231
// 005d021c  53                   push ebx
// 005d021d  6a00                 push 0
// 005d021f  57                   push edi
// 005d0220  e8ebe7ffff           call 0x5cea10
// 005d0225  5d                   pop ebp
// 005d0226  5b                   pop ebx
// 005d0227  8bc7                 mov eax, edi
// 005d0229  5f                   pop edi
// 005d022a  5e                   pop esi
// 005d022b  83c414               add esp, 0x14
// 005d022e  c21000               ret 0x10
// 005d0231  8b542434             mov edx, dword ptr [esp + 0x34]
// 005d0235  52                   push edx
// 005d0236  6a01                 push 1
// 005d0238  57                   push edi
// 005d0239  e8d2e7ffff           call 0x5cea10
// 005d023e  5d                   pop ebp
// 005d023f  5b                   pop ebx
// 005d0240  8bc7                 mov eax, edi
// 005d0242  5f                   pop edi
// 005d0243  5e                   pop esi
// 005d0244  83c414               add esp, 0x14
// 005d0247  c21000               ret 0x10
// 005d024a  8b442430             mov eax, dword ptr [esp + 0x30]
// 005d024e  83c00c               add eax, 0xc
// 005d0251  57                   push edi
// 005d0252  50                   push eax
// 005d0253  ffd5                 call ebp
// 005d0255  83c408               add esp, 8
// 005d0258  84c0                 test al, al
// 005d025a  0f848b000000         je 0x5d02eb
// 005d0260  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005d0264  8b542430             mov edx, dword ptr [esp + 0x30]
// 005d0268  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d026b  894c2410             mov dword ptr [esp + 0x10], ecx
// 005d026f  8b0e                 mov ecx, dword ptr [esi]
// 005d0271  894c2418             mov dword ptr [esp + 0x18], ecx
// 005d0275  8d4c2410             lea ecx, [esp + 0x10]
// 005d0279  89542414             mov dword ptr [esp + 0x14], edx
// 005d027d  8944241c             mov dword ptr [esp + 0x1c], eax
// 005d0281  e8ba01edff           call 0x4a0440
// 005d0286  8d542418             lea edx, [esp + 0x18]
// 005d028a  52                   push edx
// 005d028b  8d4c2414             lea ecx, [esp + 0x14]
// 005d028f  e8ec6ce9ff           call 0x466f80
// 005d0294  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005d0298  84c0                 test al, al
// 005d029a  7511                 jne 0x5d02ad
// 005d029c  8d430c               lea eax, [ebx + 0xc]
// 005d029f  50                   push eax
// 005d02a0  57                   push edi
// 005d02a1  8d4e08               lea ecx, [esi + 8]
// 005d02a4  e8a72feaff           call 0x473250
// 005d02a9  84c0                 test al, al
// 005d02ab  743e                 je 0x5d02eb
// 005d02ad  8b442430             mov eax, dword ptr [esp + 0x30]
// 005d02b1  8b4808               mov ecx, dword ptr [eax + 8]
// 005d02b4  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 005d02b8  57                   push edi
// 005d02b9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005d02bd  8bce                 mov ecx, esi
// 005d02bf  7415                 je 0x5d02d6
// 005d02c1  50                   push eax
// 005d02c2  6a00                 push 0
// 005d02c4  57                   push edi
// 005d02c5  e846e7ffff           call 0x5cea10
// 005d02ca  5d                   pop ebp
// 005d02cb  5b                   pop ebx
// 005d02cc  8bc7                 mov eax, edi
// 005d02ce  5f                   pop edi
// 005d02cf  5e                   pop esi
// 005d02d0  83c414               add esp, 0x14
// 005d02d3  c21000               ret 0x10
// 005d02d6  53                   push ebx
// 005d02d7  6a01                 push 1
// 005d02d9  57                   push edi
// 005d02da  e831e7ffff           call 0x5cea10
// 005d02df  5d                   pop ebp
// 005d02e0  5b                   pop ebx
// 005d02e1  8bc7                 mov eax, edi
// 005d02e3  5f                   pop edi
// 005d02e4  5e                   pop esi
// 005d02e5  83c414               add esp, 0x14
// 005d02e8  c21000               ret 0x10
// 005d02eb  57                   push edi
// 005d02ec  8d54241c             lea edx, [esp + 0x1c]
// 005d02f0  52                   push edx
// 005d02f1  8bce                 mov ecx, esi
// 005d02f3  e8c8f5ffff           call 0x5cf8c0
// 005d02f8  8b10                 mov edx, dword ptr [eax]
// 005d02fa  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005d02fe  5d                   pop ebp
// 005d02ff  5b                   pop ebx
// 005d0300  8911                 mov dword ptr [ecx], edx
// 005d0302  8b4004               mov eax, dword ptr [eax + 4]
// 005d0305  5f                   pop edi
// 005d0306  894104               mov dword ptr [ecx + 4], eax
// 005d0309  8bc1                 mov eax, ecx
// 005d030b  5e                   pop esi
// 005d030c  83c414               add esp, 0x14
// 005d030f  c21000               ret 0x10
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
