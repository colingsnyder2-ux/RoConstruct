// from server: 100% by auto
// roc 2007-08 0060f010  unit: RBX::Ball  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0060f010
//
// 0060f010  56                   push esi
// 0060f011  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0060f015  0fb64604             movzx eax, byte ptr [esi + 4]
// 0060f019  806605fc             and byte ptr [esi + 5], 0xfc
// 0060f01d  83e804               sub eax, 4
// 0060f020  83f806               cmp eax, 6
// 0060f023  0f879d000000         ja 0x60f0c6
// 0060f029  57                   push edi
// 0060f02a  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0060f02e  8bff                 mov edi, edi
// 0060f030  ff2485c8f06000       jmp dword ptr [eax*4 + 0x60f0c8]
// 0060f037  8b4608               mov eax, dword ptr [esi + 8]
// 0060f03a  804e0504             or byte ptr [esi + 5], 4
// 0060f03e  85c0                 test eax, eax
// 0060f040  7410                 je 0x60f052
// 0060f042  f6400503             test byte ptr [eax + 5], 3
// 0060f046  740a                 je 0x60f052
// 0060f048  50                   push eax
// 0060f049  57                   push edi
// 0060f04a  e8c1ffffff           call 0x60f010
// 0060f04f  83c408               add esp, 8
// 0060f052  8b760c               mov esi, dword ptr [esi + 0xc]
// 0060f055  f6460503             test byte ptr [esi + 5], 3
// 0060f059  746a                 je 0x60f0c5
// 0060f05b  806605fc             and byte ptr [esi + 5], 0xfc
// 0060f05f  0fb64604             movzx eax, byte ptr [esi + 4]
// 0060f063  83e804               sub eax, 4
// 0060f066  83f806               cmp eax, 6
// 0060f069  76c5                 jbe 0x60f030
// 0060f06b  5f                   pop edi
// 0060f06c  5e                   pop esi
// 0060f06d  c3                   ret 
// 0060f06e  8b4608               mov eax, dword ptr [esi + 8]
// 0060f071  83780804             cmp dword ptr [eax + 8], 4
// 0060f075  7c12                 jl 0x60f089
// 0060f077  8b00                 mov eax, dword ptr [eax]
// 0060f079  f6400503             test byte ptr [eax + 5], 3
// 0060f07d  740a                 je 0x60f089
// 0060f07f  50                   push eax
// 0060f080  57                   push edi
// 0060f081  e88affffff           call 0x60f010
// 0060f086  83c408               add esp, 8
// 0060f089  8d4610               lea eax, [esi + 0x10]
// 0060f08c  394608               cmp dword ptr [esi + 8], eax
// 0060f08f  7534                 jne 0x60f0c5
// 0060f091  804e0504             or byte ptr [esi + 5], 4
// 0060f095  5f                   pop edi
// 0060f096  5e                   pop esi
// 0060f097  c3                   ret 
// 0060f098  8b4f24               mov ecx, dword ptr [edi + 0x24]
// 0060f09b  894e08               mov dword ptr [esi + 8], ecx
// 0060f09e  897724               mov dword ptr [edi + 0x24], esi
// 0060f0a1  5f                   pop edi
// 0060f0a2  5e                   pop esi
// 0060f0a3  c3                   ret 
// 0060f0a4  8b5724               mov edx, dword ptr [edi + 0x24]
// 0060f0a7  895618               mov dword ptr [esi + 0x18], edx
// 0060f0aa  897724               mov dword ptr [edi + 0x24], esi
// 0060f0ad  5f                   pop edi
// 0060f0ae  5e                   pop esi
// 0060f0af  c3                   ret 
// 0060f0b0  8b4724               mov eax, dword ptr [edi + 0x24]
// 0060f0b3  89466c               mov dword ptr [esi + 0x6c], eax
// 0060f0b6  897724               mov dword ptr [edi + 0x24], esi
// 0060f0b9  5f                   pop edi
// 0060f0ba  5e                   pop esi
// 0060f0bb  c3                   ret 
// 0060f0bc  8b4f24               mov ecx, dword ptr [edi + 0x24]
// 0060f0bf  894e44               mov dword ptr [esi + 0x44], ecx
// 0060f0c2  897724               mov dword ptr [edi + 0x24], esi
// 0060f0c5  5f                   pop edi
// 0060f0c6  5e                   pop esi
// 0060f0c7  c3                   ret 
// library lua-5.1/lgc.c (function _reallymarkobject)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
