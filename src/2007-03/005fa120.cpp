// from server: 100% by auto
// roc 2007-03 005fa120  unit: seg_005f0000  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fa120
//
// 005fa120  8b4708               mov eax, dword ptr [edi + 8]
// 005fa123  3b4608               cmp eax, dword ptr [esi + 8]
// 005fa126  55                   push ebp
// 005fa127  8b6c2408             mov ebp, dword ptr [esp + 8]
// 005fa12b  740d                 je 0x5fa13a
// 005fa12d  56                   push esi
// 005fa12e  57                   push edi
// 005fa12f  55                   push ebp
// 005fa130  e89b92fcff           call 0x5c33d0
// 005fa135  83c40c               add esp, 0xc
// 005fa138  5d                   pop ebp
// 005fa139  c3                   ret 
// 005fa13a  83f803               cmp eax, 3
// 005fa13d  7516                 jne 0x5fa155
// 005fa13f  dd06                 fld qword ptr [esi]
// 005fa141  dc1f                 fcomp qword ptr [edi]
// 005fa143  dfe0                 fnstsw ax
// 005fa145  f6c401               test ah, 1
// 005fa148  7507                 jne 0x5fa151
// 005fa14a  b801000000           mov eax, 1
// 005fa14f  5d                   pop ebp
// 005fa150  c3                   ret 
// 005fa151  33c0                 xor eax, eax
// 005fa153  5d                   pop ebp
// 005fa154  c3                   ret 
// 005fa155  83f804               cmp eax, 4
// 005fa158  7514                 jne 0x5fa16e
// 005fa15a  8b06                 mov eax, dword ptr [esi]
// 005fa15c  8b0f                 mov ecx, dword ptr [edi]
// 005fa15e  e8bdfeffff           call 0x5fa020
// 005fa163  33c9                 xor ecx, ecx
// 005fa165  85c0                 test eax, eax
// 005fa167  0f9ec1               setle cl
// 005fa16a  5d                   pop ebp
// 005fa16b  8bc1                 mov eax, ecx
// 005fa16d  c3                   ret 
// 005fa16e  53                   push ebx
// 005fa16f  6a0e                 push 0xe
// 005fa171  57                   push edi
// 005fa172  8bde                 mov ebx, esi
// 005fa174  8bc5                 mov eax, ebp
// 005fa176  e825feffff           call 0x5f9fa0
// 005fa17b  83c408               add esp, 8
// 005fa17e  83f8ff               cmp eax, -1
// 005fa181  752b                 jne 0x5fa1ae
// 005fa183  6a0d                 push 0xd
// 005fa185  56                   push esi
// 005fa186  8bdf                 mov ebx, edi
// 005fa188  8bc5                 mov eax, ebp
// 005fa18a  e811feffff           call 0x5f9fa0
// 005fa18f  83c408               add esp, 8
// 005fa192  83f8ff               cmp eax, -1
// 005fa195  740c                 je 0x5fa1a3
// 005fa197  33d2                 xor edx, edx
// 005fa199  85c0                 test eax, eax
// 005fa19b  0f94c2               sete dl
// 005fa19e  5b                   pop ebx
// 005fa19f  5d                   pop ebp
// 005fa1a0  8bc2                 mov eax, edx
// 005fa1a2  c3                   ret 
// 005fa1a3  56                   push esi
// 005fa1a4  57                   push edi
// 005fa1a5  55                   push ebp
// 005fa1a6  e82592fcff           call 0x5c33d0
// 005fa1ab  83c40c               add esp, 0xc
// 005fa1ae  5b                   pop ebx
// 005fa1af  5d                   pop ebp
// 005fa1b0  c3                   ret 
// library lua-5.1.1/lvm.c (function _lessequal)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lvm.c
