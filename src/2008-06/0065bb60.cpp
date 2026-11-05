// from server: 100% by auto
// roc 2008-06 0065bb60  unit: RBX::BallBallContact  size: 248 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065bb60
//
// 0065bb60  53                   push ebx
// 0065bb61  8bd8                 mov ebx, eax
// 0065bb63  56                   push esi
// 0065bb64  8b7324               mov esi, dword ptr [ebx + 0x24]
// 0065bb67  0fb64604             movzx eax, byte ptr [esi + 4]
// 0065bb6b  804e0504             or byte ptr [esi + 5], 4
// 0065bb6f  83c0fb               add eax, -5
// 0065bb72  83f804               cmp eax, 4
// 0065bb75  0f87c4000000         ja 0x65bc3f
// 0065bb7b  ff248544bc6500       jmp dword ptr [eax*4 + 0x65bc44]
// 0065bb82  8b4618               mov eax, dword ptr [esi + 0x18]
// 0065bb85  56                   push esi
// 0065bb86  53                   push ebx
// 0065bb87  894324               mov dword ptr [ebx + 0x24], eax
// 0065bb8a  e8c1fbffff           call 0x65b750
// 0065bb8f  83c408               add esp, 8
// 0065bb92  85c0                 test eax, eax
// 0065bb94  7404                 je 0x65bb9a
// 0065bb96  806605fb             and byte ptr [esi + 5], 0xfb
// 0065bb9a  8a4e07               mov cl, byte ptr [esi + 7]
// 0065bb9d  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0065bba0  ba01000000           mov edx, 1
// 0065bba5  d3e2                 shl edx, cl
// 0065bba7  5e                   pop esi
// 0065bba8  5b                   pop ebx
// 0065bba9  8d445002             lea eax, [eax + edx*2 + 2]
// 0065bbad  c1e004               shl eax, 4
// 0065bbb0  c3                   ret 
// 0065bbb1  8b4e08               mov ecx, dword ptr [esi + 8]
// 0065bbb4  894b24               mov dword ptr [ebx + 0x24], ecx
// 0065bbb7  e814feffff           call 0x65b9d0
// 0065bbbc  807e0600             cmp byte ptr [esi + 6], 0
// 0065bbc0  0fb64607             movzx eax, byte ptr [esi + 7]
// 0065bbc4  7409                 je 0x65bbcf
// 0065bbc6  c1e004               shl eax, 4
// 0065bbc9  5e                   pop esi
// 0065bbca  83c018               add eax, 0x18
// 0065bbcd  5b                   pop ebx
// 0065bbce  c3                   ret 
// 0065bbcf  5e                   pop esi
// 0065bbd0  8d048514000000       lea eax, [eax*4 + 0x14]
// 0065bbd7  5b                   pop ebx
// 0065bbd8  c3                   ret 
// 0065bbd9  8b566c               mov edx, dword ptr [esi + 0x6c]
// 0065bbdc  8b4328               mov eax, dword ptr [ebx + 0x28]
// 0065bbdf  895324               mov dword ptr [ebx + 0x24], edx
// 0065bbe2  57                   push edi
// 0065bbe3  89466c               mov dword ptr [esi + 0x6c], eax
// 0065bbe6  897328               mov dword ptr [ebx + 0x28], esi
// 0065bbe9  806605fb             and byte ptr [esi + 5], 0xfb
// 0065bbed  53                   push ebx
// 0065bbee  8bfe                 mov edi, esi
// 0065bbf0  e87bfeffff           call 0x65ba70
// 0065bbf5  8b4630               mov eax, dword ptr [esi + 0x30]
// 0065bbf8  8b562c               mov edx, dword ptr [esi + 0x2c]
// 0065bbfb  83c404               add esp, 4
// 0065bbfe  83c005               add eax, 5
// 0065bc01  5f                   pop edi
// 0065bc02  8d0c40               lea ecx, [eax + eax*2]
// 0065bc05  c1e204               shl edx, 4
// 0065bc08  5e                   pop esi
// 0065bc09  8d04ca               lea eax, [edx + ecx*8]
// 0065bc0c  5b                   pop ebx
// 0065bc0d  c3                   ret 
// 0065bc0e  8b4644               mov eax, dword ptr [esi + 0x44]
// 0065bc11  53                   push ebx
// 0065bc12  894324               mov dword ptr [ebx + 0x24], eax
// 0065bc15  e8e6fcffff           call 0x65b900
// 0065bc1a  8b4638               mov eax, dword ptr [esi + 0x38]
// 0065bc1d  8b5628               mov edx, dword ptr [esi + 0x28]
// 0065bc20  8d0c40               lea ecx, [eax + eax*2]
// 0065bc23  8d0491               lea eax, [ecx + edx*4]
// 0065bc26  034634               add eax, dword ptr [esi + 0x34]
// 0065bc29  83c404               add esp, 4
// 0065bc2c  034630               add eax, dword ptr [esi + 0x30]
// 0065bc2f  03462c               add eax, dword ptr [esi + 0x2c]
// 0065bc32  034624               add eax, dword ptr [esi + 0x24]
// 0065bc35  5e                   pop esi
// 0065bc36  8d04854c000000       lea eax, [eax*4 + 0x4c]
// 0065bc3d  5b                   pop ebx
// 0065bc3e  c3                   ret 
// 0065bc3f  5e                   pop esi
// 0065bc40  33c0                 xor eax, eax
// 0065bc42  5b                   pop ebx
// 0065bc43  c3                   ret 
// 0065bc44  82bb6500b1bb65       cmp byte ptr [ebx - 0x444eff9b], 0x65
// 0065bc4b  003f                 add byte ptr [edi], bh
// 0065bc4d  bc6500d9bb           mov esp, 0xbbd90065
// 0065bc52  65000e               add byte ptr gs:[esi], cl
// library lua-5.1/lgc.c (function _propagatemark)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
