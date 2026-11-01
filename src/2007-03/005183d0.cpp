// from server: 100% by auto
// roc 2007-03 005183d0  unit: seg_00510000  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005183d0
//
// 005183d0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005183d4  56                   push esi
// 005183d5  8b742408             mov esi, dword ptr [esp + 8]
// 005183d9  33c0                 xor eax, eax
// 005183db  f7466c00000c00       test dword ptr [esi + 0x6c], 0xc0000
// 005183e2  7424                 je 0x518408
// 005183e4  803923               cmp byte ptr [ecx], 0x23
// 005183e7  751f                 jne 0x518408
// 005183e9  b801000000           mov eax, 1
// 005183ee  b220                 mov dl, 0x20
// 005183f0  381408               cmp byte ptr [eax + ecx], dl
// 005183f3  7413                 je 0x518408
// 005183f5  38540801             cmp byte ptr [eax + ecx + 1], dl
// 005183f9  740a                 je 0x518405
// 005183fb  83c002               add eax, 2
// 005183fe  83f80f               cmp eax, 0xf
// 00518401  7ced                 jl 0x5183f0
// 00518403  eb03                 jmp 0x518408
// 00518405  83c001               add eax, 1
// 00518408  8b5644               mov edx, dword ptr [esi + 0x44]
// 0051840b  03c1                 add eax, ecx
// 0051840d  85d2                 test edx, edx
// 0051840f  50                   push eax
// 00518410  7408                 je 0x51841a
// 00518412  56                   push esi
// 00518413  ffd2                 call edx
// 00518415  83c408               add esp, 8
// 00518418  5e                   pop esi
// 00518419  c3                   ret 
// 0051841a  e881fdffff           call 0x5181a0
// 0051841f  83c404               add esp, 4
// 00518422  5e                   pop esi
// 00518423  c3                   ret 
// library libpng-1.2.7/pngerror.c (function _png_warning)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS /MD
// roc-lib: libpng-1.2.7 pngerror.c
