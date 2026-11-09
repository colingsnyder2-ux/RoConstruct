// from server: 100% by auto
// roc 2009-12 00480a80  unit: RBX::AdornRbxGfx  size: 424 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00480a80
//
// 00480a80  51                   push ecx
// 00480a81  56                   push esi
// 00480a82  8bf1                 mov esi, ecx
// 00480a84  8b560c               mov edx, dword ptr [esi + 0xc]
// 00480a87  57                   push edi
// 00480a88  85d2                 test edx, edx
// 00480a8a  7504                 jne 0x480a90
// 00480a8c  33c9                 xor ecx, ecx
// 00480a8e  eb0a                 jmp 0x480a9a
// 00480a90  8b4614               mov eax, dword ptr [esi + 0x14]
// 00480a93  2bc2                 sub eax, edx
// 00480a95  c1f802               sar eax, 2
// 00480a98  8bc8                 mov ecx, eax
// 00480a9a  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00480a9e  85ff                 test edi, edi
// 00480aa0  0f847c010000         je 0x480c22
// 00480aa6  53                   push ebx
// 00480aa7  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00480aaa  8bc3                 mov eax, ebx
// 00480aac  2bc2                 sub eax, edx
// 00480aae  c1f802               sar eax, 2
// 00480ab1  baffffff3f           mov edx, 0x3fffffff
// 00480ab6  2bd0                 sub edx, eax
// 00480ab8  3bd7                 cmp edx, edi
// 00480aba  7305                 jae 0x480ac1
// 00480abc  e89f16fcff           call 0x442160
// 00480ac1  8d1438               lea edx, [eax + edi]
// 00480ac4  55                   push ebp
// 00480ac5  3bca                 cmp ecx, edx
// 00480ac7  0f83b5000000         jae 0x480b82
// 00480acd  8bc1                 mov eax, ecx
// 00480acf  d1e8                 shr eax, 1
// 00480ad1  bbffffff3f           mov ebx, 0x3fffffff
// 00480ad6  2bd8                 sub ebx, eax
// 00480ad8  3bd9                 cmp ebx, ecx
// 00480ada  730e                 jae 0x480aea
// 00480adc  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00480ae4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00480ae8  eb06                 jmp 0x480af0
// 00480aea  03c8                 add ecx, eax
// 00480aec  894c2410             mov dword ptr [esp + 0x10], ecx
// 00480af0  3bca                 cmp ecx, edx
// 00480af2  7306                 jae 0x480afa
// 00480af4  89542410             mov dword ptr [esp + 0x10], edx
// 00480af8  8bca                 mov ecx, edx
// 00480afa  6a00                 push 0
// 00480afc  51                   push ecx
// 00480afd  e83efefaff           call 0x430940
// 00480b02  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00480b06  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 00480b09  83c408               add esp, 8
// 00480b0c  8be8                 mov ebp, eax
// 00480b0e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00480b12  50                   push eax
// 00480b13  c1fb02               sar ebx, 2
// 00480b16  57                   push edi
// 00480b17  8d4c9d00             lea ecx, [ebp + ebx*4]
// 00480b1b  51                   push ecx
// 00480b1c  8bce                 mov ecx, esi
// 00480b1e  e84da60200           call 0x4ab170
// 00480b23  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00480b27  8b460c               mov eax, dword ptr [esi + 0xc]
// 00480b2a  55                   push ebp
// 00480b2b  52                   push edx
// 00480b2c  50                   push eax
// 00480b2d  8bce                 mov ecx, esi
// 00480b2f  e89ce20200           call 0x4aedd0
// 00480b34  8b5610               mov edx, dword ptr [esi + 0x10]
// 00480b37  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00480b3b  03df                 add ebx, edi
// 00480b3d  8d4c9d00             lea ecx, [ebp + ebx*4]
// 00480b41  51                   push ecx
// 00480b42  52                   push edx
// 00480b43  50                   push eax
// 00480b44  8bce                 mov ecx, esi
// 00480b46  e885e20200           call 0x4aedd0
// 00480b4b  8b460c               mov eax, dword ptr [esi + 0xc]
// 00480b4e  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00480b51  2bc8                 sub ecx, eax
// 00480b53  c1f902               sar ecx, 2
// 00480b56  03f9                 add edi, ecx
// 00480b58  85c0                 test eax, eax
// 00480b5a  7409                 je 0x480b65
// 00480b5c  50                   push eax
// 00480b5d  e8f82c3700           call 0x7f385a
// 00480b62  83c404               add esp, 4
// 00480b65  8b542410             mov edx, dword ptr [esp + 0x10]
// 00480b69  8d4cbd00             lea ecx, [ebp + edi*4]
// 00480b6d  8d449500             lea eax, [ebp + edx*4]
// 00480b71  896e0c               mov dword ptr [esi + 0xc], ebp
// 00480b74  5d                   pop ebp
// 00480b75  5b                   pop ebx
// 00480b76  5f                   pop edi
// 00480b77  894614               mov dword ptr [esi + 0x14], eax
// 00480b7a  894e10               mov dword ptr [esi + 0x10], ecx
// 00480b7d  5e                   pop esi
// 00480b7e  59                   pop ecx
// 00480b7f  c21000               ret 0x10
// 00480b82  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00480b86  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00480b8a  8bd3                 mov edx, ebx
// 00480b8c  2bd0                 sub edx, eax
// 00480b8e  c1fa02               sar edx, 2
// 00480b91  3bd7                 cmp edx, edi
// 00480b93  8b11                 mov edx, dword ptr [ecx]
// 00480b95  8d2cbd00000000       lea ebp, [edi*4]
// 00480b9c  89542424             mov dword ptr [esp + 0x24], edx
// 00480ba0  734c                 jae 0x480bee
// 00480ba2  8d0c28               lea ecx, [eax + ebp]
// 00480ba5  51                   push ecx
// 00480ba6  53                   push ebx
// 00480ba7  50                   push eax
// 00480ba8  8bce                 mov ecx, esi
// 00480baa  e821e20200           call 0x4aedd0
// 00480baf  8b4610               mov eax, dword ptr [esi + 0x10]
// 00480bb2  8bc8                 mov ecx, eax
// 00480bb4  2b4c241c             sub ecx, dword ptr [esp + 0x1c]
// 00480bb8  8d542424             lea edx, [esp + 0x24]
// 00480bbc  c1f902               sar ecx, 2
// 00480bbf  52                   push edx
// 00480bc0  2bf9                 sub edi, ecx
// 00480bc2  57                   push edi
// 00480bc3  50                   push eax
// 00480bc4  8bce                 mov ecx, esi
// 00480bc6  e8a5a50200           call 0x4ab170
// 00480bcb  016e10               add dword ptr [esi + 0x10], ebp
// 00480bce  8b7610               mov esi, dword ptr [esi + 0x10]
// 00480bd1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00480bd5  8d542424             lea edx, [esp + 0x24]
// 00480bd9  52                   push edx
// 00480bda  2bf5                 sub esi, ebp
// 00480bdc  56                   push esi
// 00480bdd  50                   push eax
// 00480bde  e87db23400           call 0x7cbe60
// 00480be3  83c40c               add esp, 0xc
// 00480be6  5d                   pop ebp
// 00480be7  5b                   pop ebx
// 00480be8  5f                   pop edi
// 00480be9  5e                   pop esi
// 00480bea  59                   pop ecx
// 00480beb  c21000               ret 0x10
// 00480bee  53                   push ebx
// 00480bef  8bfb                 mov edi, ebx
// 00480bf1  53                   push ebx
// 00480bf2  2bfd                 sub edi, ebp
// 00480bf4  57                   push edi
// 00480bf5  8bce                 mov ecx, esi
// 00480bf7  e8d4e10200           call 0x4aedd0
// 00480bfc  53                   push ebx
// 00480bfd  894610               mov dword ptr [esi + 0x10], eax
// 00480c00  8b442420             mov eax, dword ptr [esp + 0x20]
// 00480c04  57                   push edi
// 00480c05  50                   push eax
// 00480c06  e865211e00           call 0x662d70
// 00480c0b  8b442428             mov eax, dword ptr [esp + 0x28]
// 00480c0f  8d4c2430             lea ecx, [esp + 0x30]
// 00480c13  51                   push ecx
// 00480c14  03e8                 add ebp, eax
// 00480c16  55                   push ebp
// 00480c17  50                   push eax
// 00480c18  e843b23400           call 0x7cbe60
// 00480c1d  83c418               add esp, 0x18
// 00480c20  5d                   pop ebp
// 00480c21  5b                   pop ebx
// 00480c22  5f                   pop edi
// 00480c23  5e                   pop esi
// 00480c24  59                   pop ecx
// 00480c25  c21000               ret 0x10
// standard library vector<ptr> (function ?_Insert_n@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXV?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@IABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
