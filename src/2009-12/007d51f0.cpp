// from server: 100% by auto
// roc 2009-12 007d51f0  unit: seg_007d0000  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d51f0
//
// 007d51f0  53                   push ebx
// 007d51f1  56                   push esi
// 007d51f2  57                   push edi
// 007d51f3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007d51f7  33db                 xor ebx, ebx
// 007d51f9  8da42400000000       lea esp, [esp]
// 007d5200  8b349d38f39e00       mov esi, dword ptr [ebx*4 + 0x9ef338]
// 007d5207  8bc6                 mov eax, esi
// 007d5209  8d5001               lea edx, [eax + 1]
// 007d520c  8d642400             lea esp, [esp]
// 007d5210  8a08                 mov cl, byte ptr [eax]
// 007d5212  40                   inc eax
// 007d5213  84c9                 test cl, cl
// 007d5215  75f9                 jne 0x7d5210
// 007d5217  2bc2                 sub eax, edx
// 007d5219  50                   push eax
// 007d521a  56                   push esi
// 007d521b  57                   push edi
// 007d521c  e86fb9ffff           call 0x7d0b90
// 007d5221  80480520             or byte ptr [eax + 5], 0x20
// 007d5225  8acb                 mov cl, bl
// 007d5227  fec1                 inc cl
// 007d5229  43                   inc ebx
// 007d522a  83c40c               add esp, 0xc
// 007d522d  83fb15               cmp ebx, 0x15
// 007d5230  884806               mov byte ptr [eax + 6], cl
// 007d5233  7ccb                 jl 0x7d5200
// 007d5235  5f                   pop edi
// 007d5236  5e                   pop esi
// 007d5237  5b                   pop ebx
// 007d5238  c3                   ret 
// library lua-5.1/llex.c (function _luaX_init)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 llex.c
