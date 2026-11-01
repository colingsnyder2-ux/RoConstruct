// from server: 100% by auto
// roc 2007-03 005184a0  unit: seg_00510000  size: 306 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005184a0
//
// 005184a0  53                   push ebx
// 005184a1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005184a5  807b0908             cmp byte ptr [ebx + 9], 8
// 005184a9  0f8521010000         jne 0x5185d0
// 005184af  807b0a01             cmp byte ptr [ebx + 0xa], 1
// 005184b3  0f8517010000         jne 0x5185d0
// 005184b9  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005184bd  83e901               sub ecx, 1
// 005184c0  55                   push ebp
// 005184c1  56                   push esi
// 005184c2  57                   push edi
// 005184c3  0f8497000000         je 0x518560
// 005184c9  83e901               sub ecx, 1
// 005184cc  7452                 je 0x518520
// 005184ce  83e902               sub ecx, 2
// 005184d1  0f85cb000000         jne 0x5185a2
// 005184d7  8b3b                 mov edi, dword ptr [ebx]
// 005184d9  8b742418             mov esi, dword ptr [esp + 0x18]
// 005184dd  33d2                 xor edx, edx
// 005184df  85ff                 test edi, edi
// 005184e1  8bee                 mov ebp, esi
// 005184e3  b904000000           mov ecx, 4
// 005184e8  0f86b4000000         jbe 0x5185a2
// 005184ee  8bff                 mov edi, edi
// 005184f0  0fb64500             movzx eax, byte ptr [ebp]
// 005184f4  83e00f               and eax, 0xf
// 005184f7  d3e0                 shl eax, cl
// 005184f9  0bd0                 or edx, eax
// 005184fb  85c9                 test ecx, ecx
// 005184fd  750e                 jne 0x51850d
// 005184ff  8816                 mov byte ptr [esi], dl
// 00518501  83c601               add esi, 1
// 00518504  b904000000           mov ecx, 4
// 00518509  33d2                 xor edx, edx
// 0051850b  eb03                 jmp 0x518510
// 0051850d  83e904               sub ecx, 4
// 00518510  83c501               add ebp, 1
// 00518513  83ef01               sub edi, 1
// 00518516  75d8                 jne 0x5184f0
// 00518518  83f904               cmp ecx, 4
// 0051851b  e97e000000           jmp 0x51859e
// 00518520  8b3b                 mov edi, dword ptr [ebx]
// 00518522  8b742418             mov esi, dword ptr [esp + 0x18]
// 00518526  33d2                 xor edx, edx
// 00518528  85ff                 test edi, edi
// 0051852a  8bee                 mov ebp, esi
// 0051852c  b906000000           mov ecx, 6
// 00518531  766f                 jbe 0x5185a2
// 00518533  0fb64500             movzx eax, byte ptr [ebp]
// 00518537  83e003               and eax, 3
// 0051853a  d3e0                 shl eax, cl
// 0051853c  0bd0                 or edx, eax
// 0051853e  85c9                 test ecx, ecx
// 00518540  750e                 jne 0x518550
// 00518542  8816                 mov byte ptr [esi], dl
// 00518544  83c601               add esi, 1
// 00518547  b906000000           mov ecx, 6
// 0051854c  33d2                 xor edx, edx
// 0051854e  eb03                 jmp 0x518553
// 00518550  83e902               sub ecx, 2
// 00518553  83c501               add ebp, 1
// 00518556  83ef01               sub edi, 1
// 00518559  75d8                 jne 0x518533
// 0051855b  83f906               cmp ecx, 6
// 0051855e  eb3e                 jmp 0x51859e
// 00518560  8b3b                 mov edi, dword ptr [ebx]
// 00518562  8b742418             mov esi, dword ptr [esp + 0x18]
// 00518566  33d2                 xor edx, edx
// 00518568  85ff                 test edi, edi
// 0051856a  8bee                 mov ebp, esi
// 0051856c  b980000000           mov ecx, 0x80
// 00518571  762f                 jbe 0x5185a2
// 00518573  807d0000             cmp byte ptr [ebp], 0
// 00518577  7402                 je 0x51857b
// 00518579  0bd1                 or edx, ecx
// 0051857b  83c501               add ebp, 1
// 0051857e  83f901               cmp ecx, 1
// 00518581  7e04                 jle 0x518587
// 00518583  d1f9                 sar ecx, 1
// 00518585  eb0c                 jmp 0x518593
// 00518587  8816                 mov byte ptr [esi], dl
// 00518589  83c601               add esi, 1
// 0051858c  b980000000           mov ecx, 0x80
// 00518591  33d2                 xor edx, edx
// 00518593  83ef01               sub edi, 1
// 00518596  75db                 jne 0x518573
// 00518598  81f980000000         cmp ecx, 0x80
// 0051859e  7402                 je 0x5185a2
// 005185a0  8816                 mov byte ptr [esi], dl
// 005185a2  8a44241c             mov al, byte ptr [esp + 0x1c]
// 005185a6  884309               mov byte ptr [ebx + 9], al
// 005185a9  f66b0a               imul byte ptr [ebx + 0xa]
// 005185ac  5f                   pop edi
// 005185ad  5e                   pop esi
// 005185ae  88430b               mov byte ptr [ebx + 0xb], al
// 005185b1  3c08                 cmp al, 8
// 005185b3  5d                   pop ebp
// 005185b4  0fb6c0               movzx eax, al
// 005185b7  720b                 jb 0x5185c4
// 005185b9  c1e803               shr eax, 3
// 005185bc  0faf03               imul eax, dword ptr [ebx]
// 005185bf  894304               mov dword ptr [ebx + 4], eax
// 005185c2  5b                   pop ebx
// 005185c3  c3                   ret 
// 005185c4  0faf03               imul eax, dword ptr [ebx]
// 005185c7  83c007               add eax, 7
// 005185ca  c1e803               shr eax, 3
// 005185cd  894304               mov dword ptr [ebx + 4], eax
// 005185d0  5b                   pop ebx
// 005185d1  c3                   ret 
// library libpng-1.2.7/pngwtran.c (function _png_do_pack)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwtran.c
