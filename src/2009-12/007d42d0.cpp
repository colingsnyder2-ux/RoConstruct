// from server: 100% by auto
// roc 2009-12 007d42d0  unit: seg_007d0000  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d42d0
//
// 007d42d0  83ec20               sub esp, 0x20
// 007d42d3  53                   push ebx
// 007d42d4  56                   push esi
// 007d42d5  57                   push edi
// 007d42d6  8bf0                 mov esi, eax
// 007d42d8  8b5e30               mov ebx, dword ptr [esi + 0x30]
// 007d42db  8d7c2414             lea edi, [esp + 0x14]
// 007d42df  e84ce7ffff           call 0x7d2a30
// 007d42e4  837c24140d           cmp dword ptr [esp + 0x14], 0xd
// 007d42e9  7523                 jne 0x7d430e
// 007d42eb  8b03                 mov eax, dword ptr [ebx]
// 007d42ed  8b480c               mov ecx, dword ptr [eax + 0xc]
// 007d42f0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007d42f4  8d0491               lea eax, [ecx + edx*4]
// 007d42f7  8b08                 mov ecx, dword ptr [eax]
// 007d42f9  5f                   pop edi
// 007d42fa  81e1ff7f80ff         and ecx, 0xff807fff
// 007d4300  81c900400000         or ecx, 0x4000
// 007d4306  5e                   pop esi
// 007d4307  8908                 mov dword ptr [eax], ecx
// 007d4309  5b                   pop ebx
// 007d430a  83c420               add esp, 0x20
// 007d430d  c3                   ret 
// 007d430e  6a01                 push 1
// 007d4310  8d542410             lea edx, [esp + 0x10]
// 007d4314  52                   push edx
// 007d4315  56                   push esi
// 007d4316  c744241800000000     mov dword ptr [esp + 0x18], 0
// 007d431e  e87defffff           call 0x7d32a0
// 007d4323  83c40c               add esp, 0xc
// 007d4326  5f                   pop edi
// 007d4327  5e                   pop esi
// 007d4328  5b                   pop ebx
// 007d4329  83c420               add esp, 0x20
// 007d432c  c3                   ret 
// library lua-5.1/lparser.c (function _exprstat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
