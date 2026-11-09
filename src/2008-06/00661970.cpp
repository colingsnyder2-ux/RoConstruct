// from server: 100% by auto
// roc 2008-06 00661970  unit: RBX::FilterStairs  size: 739 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00661970
//
// 00661970  83ec1c               sub esp, 0x1c
// 00661973  53                   push ebx
// 00661974  8b5e30               mov ebx, dword ptr [esi + 0x30]
// 00661977  8bc7                 mov eax, edi
// 00661979  8bce                 mov ecx, esi
// 0066197b  895c2404             mov dword ptr [esp + 4], ebx
// 0066197f  e87cffffff           call 0x661900
// 00661984  8b4610               mov eax, dword ptr [esi + 0x10]
// 00661987  83e828               sub eax, 0x28
// 0066198a  3df6000000           cmp eax, 0xf6
// 0066198f  0f87ac010000         ja 0x661b41
// 00661995  55                   push ebp
// 00661996  eb08                 jmp 0x6619a0
// 00661998  8da42400000000       lea esp, [esp]
// 0066199f  90                   nop 
// 006619a0  0fb6805c1b6600       movzx eax, byte ptr [eax + 0x661b5c]
// 006619a7  ff2485481b6600       jmp dword ptr [eax*4 + 0x661b48]
// 006619ae  8b6e30               mov ebp, dword ptr [esi + 0x30]
// 006619b1  57                   push edi
// 006619b2  55                   push ebp
// 006619b3  e8f89e0000           call 0x66b8b0
// 006619b8  56                   push esi
// 006619b9  e8423c0000           call 0x665600
// 006619be  83c40c               add esp, 0xc
// 006619c1  817e101d010000       cmp dword ptr [esi + 0x10], 0x11d
// 006619c8  7424                 je 0x6619ee
// 006619ca  681d010000           push 0x11d
// 006619cf  56                   push esi
// 006619d0  e83b270000           call 0x664110
// 006619d5  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 006619d8  50                   push eax
// 006619d9  68c0c48400           push 0x84c4c0
// 006619de  51                   push ecx
// 006619df  e8dc10fcff           call 0x622ac0
// 006619e4  50                   push eax
// 006619e5  56                   push esi
// 006619e6  e825280000           call 0x664210
// 006619eb  83c41c               add esp, 0x1c
// 006619ee  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006619f1  56                   push esi
// 006619f2  e8093c0000           call 0x665600
// 006619f7  8b5630               mov edx, dword ptr [esi + 0x30]
// 006619fa  53                   push ebx
// 006619fb  52                   push edx
// 006619fc  e8df940000           call 0x66aee0
// 00661a01  89442420             mov dword ptr [esp + 0x20], eax
// 00661a05  8d442418             lea eax, [esp + 0x18]
// 00661a09  50                   push eax
// 00661a0a  83c9ff               or ecx, 0xffffffff
// 00661a0d  57                   push edi
// 00661a0e  55                   push ebp
// 00661a0f  894c2434             mov dword ptr [esp + 0x34], ecx
// 00661a13  894c2438             mov dword ptr [esp + 0x38], ecx
// 00661a17  c744242404000000     mov dword ptr [esp + 0x24], 4
// 00661a1f  e81ca40000           call 0x66be40
// 00661a24  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00661a28  83c418               add esp, 0x18
// 00661a2b  e9ff000000           jmp 0x661b2f
// 00661a30  57                   push edi
// 00661a31  53                   push ebx
// 00661a32  e8799e0000           call 0x66b8b0
// 00661a37  56                   push esi
// 00661a38  e8c33b0000           call 0x665600
// 00661a3d  6a00                 push 0
// 00661a3f  8d4c241c             lea ecx, [esp + 0x1c]
// 00661a43  51                   push ecx
// 00661a44  56                   push esi
// 00661a45  e8a6050000           call 0x661ff0
// 00661a4a  8b4630               mov eax, dword ptr [esi + 0x30]
// 00661a4d  8d542424             lea edx, [esp + 0x24]
// 00661a51  52                   push edx
// 00661a52  50                   push eax
// 00661a53  e8a89e0000           call 0x66b900
// 00661a58  83c420               add esp, 0x20
// 00661a5b  837e105d             cmp dword ptr [esi + 0x10], 0x5d
// 00661a5f  7421                 je 0x661a82
// 00661a61  6a5d                 push 0x5d
// 00661a63  56                   push esi
// 00661a64  e8a7260000           call 0x664110
// 00661a69  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00661a6c  50                   push eax
// 00661a6d  68c0c48400           push 0x84c4c0
// 00661a72  51                   push ecx
// 00661a73  e84810fcff           call 0x622ac0
// 00661a78  50                   push eax
// 00661a79  56                   push esi
// 00661a7a  e891270000           call 0x664210
// 00661a7f  83c41c               add esp, 0x1c
// 00661a82  56                   push esi
// 00661a83  e8783b0000           call 0x665600
// 00661a88  8d542410             lea edx, [esp + 0x10]
// 00661a8c  52                   push edx
// 00661a8d  57                   push edi
// 00661a8e  53                   push ebx
// 00661a8f  e8aca30000           call 0x66be40
// 00661a94  83c410               add esp, 0x10
// 00661a97  e993000000           jmp 0x661b2f
// 00661a9c  56                   push esi
// 00661a9d  e85e3b0000           call 0x665600
// 00661aa2  83c404               add esp, 4
// 00661aa5  817e101d010000       cmp dword ptr [esi + 0x10], 0x11d
// 00661aac  7424                 je 0x661ad2
// 00661aae  681d010000           push 0x11d
// 00661ab3  56                   push esi
// 00661ab4  e857260000           call 0x664110
// 00661ab9  50                   push eax
// 00661aba  8b4634               mov eax, dword ptr [esi + 0x34]
// 00661abd  68c0c48400           push 0x84c4c0
// 00661ac2  50                   push eax
// 00661ac3  e8f80ffcff           call 0x622ac0
// 00661ac8  50                   push eax
// 00661ac9  56                   push esi
// 00661aca  e841270000           call 0x664210
// 00661acf  83c41c               add esp, 0x1c
// 00661ad2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00661ad5  56                   push esi
// 00661ad6  e8253b0000           call 0x665600
// 00661adb  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 00661ade  53                   push ebx
// 00661adf  51                   push ecx
// 00661ae0  e8fb930000           call 0x66aee0
// 00661ae5  8d542418             lea edx, [esp + 0x18]
// 00661ae9  52                   push edx
// 00661aea  89442424             mov dword ptr [esp + 0x24], eax
// 00661aee  8b442418             mov eax, dword ptr [esp + 0x18]
// 00661af2  83c9ff               or ecx, 0xffffffff
// 00661af5  57                   push edi
// 00661af6  50                   push eax
// 00661af7  894c2434             mov dword ptr [esp + 0x34], ecx
// 00661afb  894c2438             mov dword ptr [esp + 0x38], ecx
// 00661aff  c744242404000000     mov dword ptr [esp + 0x24], 4
// 00661b07  e804a00000           call 0x66bb10
// 00661b0c  57                   push edi
// 00661b0d  8bc6                 mov eax, esi
// 00661b0f  e8acfcffff           call 0x6617c0
// 00661b14  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00661b18  83c41c               add esp, 0x1c
// 00661b1b  eb12                 jmp 0x661b2f
// 00661b1d  57                   push edi
// 00661b1e  53                   push ebx
// 00661b1f  e80c9d0000           call 0x66b830
// 00661b24  57                   push edi
// 00661b25  8bc6                 mov eax, esi
// 00661b27  e894fcffff           call 0x6617c0
// 00661b2c  83c40c               add esp, 0xc
// 00661b2f  8b4610               mov eax, dword ptr [esi + 0x10]
// 00661b32  83e828               sub eax, 0x28
// 00661b35  3df6000000           cmp eax, 0xf6
// 00661b3a  0f8660feffff         jbe 0x6619a0
// 00661b40  5d                   pop ebp
// 00661b41  5b                   pop ebx
// 00661b42  83c41c               add esp, 0x1c
// 00661b45  c3                   ret 
// 00661b46  8bff                 mov edi, edi
// 00661b48  1d1b6600ae           sbb eax, 0xae00661b
// 00661b4d  196600               sbb dword ptr [esi], esp
// 00661b50  9c                   pushfd 
// 00661b51  1a6600               sbb ah, byte ptr [esi]
// 00661b54  301a                 xor byte ptr [edx], bl
// 00661b56  6600401b             add byte ptr [eax + 0x1b], al
// 00661b5a  660000               add byte ptr [eax], al
// 00661b5d  0404                 add al, 4
// 00661b5f  0404                 add al, 4
// 00661b61  0401                 add al, 1
// 00661b63  0404                 add al, 4
// 00661b65  0404                 add al, 4
// 00661b67  0404                 add al, 4
// 00661b69  0404                 add al, 4
// 00661b6b  0404                 add al, 4
// 00661b6d  0402                 add al, 2
// 00661b6f  0404                 add al, 4
// 00661b71  0404                 add al, 4
// 00661b73  0404                 add al, 4
// 00661b75  0404                 add al, 4
// 00661b77  0404                 add al, 4
// 00661b79  0404                 add al, 4
// 00661b7b  0404                 add al, 4
// 00661b7d  0404                 add al, 4
// 00661b7f  0404                 add al, 4
// 00661b81  0404                 add al, 4
// 00661b83  0404                 add al, 4
// 00661b85  0404                 add al, 4
// 00661b87  0404                 add al, 4
// 00661b89  0404                 add al, 4
// 00661b8b  0404                 add al, 4
// 00661b8d  0404                 add al, 4
// 00661b8f  030404               add eax, dword ptr [esp + eax]
// 00661b92  0404                 add al, 4
// 00661b94  0404                 add al, 4
// 00661b96  0404                 add al, 4
// 00661b98  0404                 add al, 4
// 00661b9a  0404                 add al, 4
// 00661b9c  0404                 add al, 4
// 00661b9e  0404                 add al, 4
// 00661ba0  0404                 add al, 4
// 00661ba2  0404                 add al, 4
// 00661ba4  0404                 add al, 4
// 00661ba6  0404                 add al, 4
// 00661ba8  0404                 add al, 4
// 00661baa  0404                 add al, 4
// 00661bac  0404                 add al, 4
// 00661bae  0400                 add al, 0
// 00661bb0  0404                 add al, 4
// 00661bb2  0404                 add al, 4
// 00661bb4  0404                 add al, 4
// 00661bb6  0404                 add al, 4
// 00661bb8  0404                 add al, 4
// 00661bba  0404                 add al, 4
// 00661bbc  0404                 add al, 4
// 00661bbe  0404                 add al, 4
// 00661bc0  0404                 add al, 4
// 00661bc2  0404                 add al, 4
// 00661bc4  0404                 add al, 4
// 00661bc6  0404                 add al, 4
// 00661bc8  0404                 add al, 4
// 00661bca  0404                 add al, 4
// 00661bcc  0404                 add al, 4
// 00661bce  0404                 add al, 4
// 00661bd0  0404                 add al, 4
// 00661bd2  0404                 add al, 4
// 00661bd4  0404                 add al, 4
// 00661bd6  0404                 add al, 4
// 00661bd8  0404                 add al, 4
// 00661bda  0404                 add al, 4
// 00661bdc  0404                 add al, 4
// 00661bde  0404                 add al, 4
// 00661be0  0404                 add al, 4
// 00661be2  0404                 add al, 4
// 00661be4  0404                 add al, 4
// 00661be6  0404                 add al, 4
// 00661be8  0404                 add al, 4
// 00661bea  0404                 add al, 4
// 00661bec  0404                 add al, 4
// 00661bee  0404                 add al, 4
// 00661bf0  0404                 add al, 4
// 00661bf2  0404                 add al, 4
// 00661bf4  0404                 add al, 4
// 00661bf6  0404                 add al, 4
// 00661bf8  0404                 add al, 4
// 00661bfa  0404                 add al, 4
// 00661bfc  0404                 add al, 4
// 00661bfe  0404                 add al, 4
// 00661c00  0404                 add al, 4
// 00661c02  0404                 add al, 4
// 00661c04  0404                 add al, 4
// 00661c06  0404                 add al, 4
// 00661c08  0404                 add al, 4
// 00661c0a  0404                 add al, 4
// 00661c0c  0404                 add al, 4
// 00661c0e  0404                 add al, 4
// 00661c10  0404                 add al, 4
// 00661c12  0404                 add al, 4
// 00661c14  0404                 add al, 4
// 00661c16  0404                 add al, 4
// 00661c18  0404                 add al, 4
// 00661c1a  0404                 add al, 4
// 00661c1c  0404                 add al, 4
// 00661c1e  0404                 add al, 4
// 00661c20  0404                 add al, 4
// 00661c22  0404                 add al, 4
// 00661c24  0404                 add al, 4
// 00661c26  0404                 add al, 4
// 00661c28  0404                 add al, 4
// 00661c2a  0404                 add al, 4
// 00661c2c  0404                 add al, 4
// 00661c2e  0404                 add al, 4
// 00661c30  0404                 add al, 4
// 00661c32  0404                 add al, 4
// 00661c34  0404                 add al, 4
// 00661c36  0404                 add al, 4
// 00661c38  0404                 add al, 4
// 00661c3a  0404                 add al, 4
// 00661c3c  0404                 add al, 4
// 00661c3e  0404                 add al, 4
// 00661c40  0404                 add al, 4
// 00661c42  0404                 add al, 4
// 00661c44  0404                 add al, 4
// 00661c46  0404                 add al, 4
// 00661c48  0404                 add al, 4
// 00661c4a  0404                 add al, 4
// 00661c4c  0404                 add al, 4
// 00661c4e  0404                 add al, 4
// 00661c50  0404                 add al, 4
// library lua-5.1/lparser.c (function _primaryexp)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
