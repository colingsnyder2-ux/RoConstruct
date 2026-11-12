// from server: 100% by auto
// roc 2008-06 004d66f0  unit: CSHA1  size: 284 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d66f0
//
// 004d66f0  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004d66f4  83ec20               sub esp, 0x20
// 004d66f7  55                   push ebp
// 004d66f8  56                   push esi
// 004d66f9  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 004d66fd  8d2ccd00000000       lea ebp, [ecx*8]
// 004d6704  85f6                 test esi, esi
// 004d6706  7509                 jne 0x4d6711
// 004d6708  8d46fd               lea eax, [esi - 3]
// 004d670b  5e                   pop esi
// 004d670c  5d                   pop ebp
// 004d670d  83c420               add esp, 0x20
// 004d6710  c3                   ret 
// 004d6711  53                   push ebx
// 004d6712  8a5c2434             mov bl, byte ptr [esp + 0x34]
// 004d6716  84db                 test bl, bl
// 004d6718  740f                 je 0x4d6729
// 004d671a  80fb01               cmp bl, 1
// 004d671d  740a                 je 0x4d6729
// 004d671f  5b                   pop ebx
// 004d6720  5e                   pop esi
// 004d6721  83c8ff               or eax, 0xffffffff
// 004d6724  5d                   pop ebp
// 004d6725  83c420               add esp, 0x20
// 004d6728  c3                   ret 
// 004d6729  881e                 mov byte ptr [esi], bl
// 004d672b  81fd80000000         cmp ebp, 0x80
// 004d6731  7414                 je 0x4d6747
// 004d6733  81fdc0000000         cmp ebp, 0xc0
// 004d6739  740c                 je 0x4d6747
// 004d673b  81fd00010000         cmp ebp, 0x100
// 004d6741  0f85b9000000         jne 0x4d6800
// 004d6747  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 004d674b  896e04               mov dword ptr [esi + 4], ebp
// 004d674e  85c0                 test eax, eax
// 004d6750  0f84aa000000         je 0x4d6800
// 004d6756  57                   push edi
// 004d6757  51                   push ecx
// 004d6758  50                   push eax
// 004d6759  8d7e08               lea edi, [esi + 8]
// 004d675c  57                   push edi
// 004d675d  ff1548288000         call dword ptr [0x802848]
// 004d6763  8bc5                 mov eax, ebp
// 004d6765  99                   cdq 
// 004d6766  83e21f               and edx, 0x1f
// 004d6769  03c2                 add eax, edx
// 004d676b  c1f805               sar eax, 5
// 004d676e  83c006               add eax, 6
// 004d6771  a308279700           mov dword ptr [0x972708], eax
// 004d6776  8b6e04               mov ebp, dword ptr [esi + 4]
// 004d6779  8bc5                 mov eax, ebp
// 004d677b  99                   cdq 
// 004d677c  83e207               and edx, 7
// 004d677f  03c2                 add eax, edx
// 004d6781  c1f803               sar eax, 3
// 004d6784  83c40c               add esp, 0xc
// 004d6787  33c9                 xor ecx, ecx
// 004d6789  85c0                 test eax, eax
// 004d678b  7e42                 jle 0x4d67cf
// 004d678d  8bc5                 mov eax, ebp
// 004d678f  99                   cdq 
// 004d6790  83e207               and edx, 7
// 004d6793  03c2                 add eax, edx
// 004d6795  c1f803               sar eax, 3
// 004d6798  8944243c             mov dword ptr [esp + 0x3c], eax
// 004d679c  8d642400             lea esp, [esp]
// 004d67a0  8bc1                 mov eax, ecx
// 004d67a2  99                   cdq 
// 004d67a3  83e203               and edx, 3
// 004d67a6  03c2                 add eax, edx
// 004d67a8  8bd1                 mov edx, ecx
// 004d67aa  c1f802               sar eax, 2
// 004d67ad  81e203000080         and edx, 0x80000003
// 004d67b3  7905                 jns 0x4d67ba
// 004d67b5  4a                   dec edx
// 004d67b6  83cafc               or edx, 0xfffffffc
// 004d67b9  42                   inc edx
// 004d67ba  8a1c0f               mov bl, byte ptr [edi + ecx]
// 004d67bd  41                   inc ecx
// 004d67be  3b4c243c             cmp ecx, dword ptr [esp + 0x3c]
// 004d67c2  8d541410             lea edx, [esp + edx + 0x10]
// 004d67c6  881c82               mov byte ptr [edx + eax*4], bl
// 004d67c9  7cd5                 jl 0x4d67a0
// 004d67cb  8a5c2438             mov bl, byte ptr [esp + 0x38]
// 004d67cf  8d7e30               lea edi, [esi + 0x30]
// 004d67d2  57                   push edi
// 004d67d3  8d442414             lea eax, [esp + 0x14]
// 004d67d7  55                   push ebp
// 004d67d8  50                   push eax
// 004d67d9  e8a2f5ffff           call 0x4d5d80
// 004d67de  83c40c               add esp, 0xc
// 004d67e1  80fb01               cmp bl, 1
// 004d67e4  750d                 jne 0x4d67f3
// 004d67e6  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d67e9  57                   push edi
// 004d67ea  51                   push ecx
// 004d67eb  e840f7ffff           call 0x4d5f30
// 004d67f0  83c408               add esp, 8
// 004d67f3  5f                   pop edi
// 004d67f4  5b                   pop ebx
// 004d67f5  5e                   pop esi
// 004d67f6  b801000000           mov eax, 1
// 004d67fb  5d                   pop ebp
// 004d67fc  83c420               add esp, 0x20
// 004d67ff  c3                   ret 
// 004d6800  5b                   pop ebx
// 004d6801  5e                   pop esi
// 004d6802  b8feffffff           mov eax, 0xfffffffe
// 004d6807  5d                   pop ebp
// 004d6808  83c420               add esp, 0x20
// 004d680b  c3                   ret 
// library openrbx-raknet/rijndael.cpp (function ?makeKey@@YAHPAUkeyInstance@@EHPAD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet rijndael.cpp
