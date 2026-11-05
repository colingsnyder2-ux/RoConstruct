// from server: 100% by auto
// roc 2007-08 005cc530  unit: seg_005c0000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005cc530
//
// 005cc530  56                   push esi
// 005cc531  57                   push edi
// 005cc532  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005cc536  68edd8ffff           push 0xffffd8ed
// 005cc53b  57                   push edi
// 005cc53c  e87f15ffff           call 0x5bdac0
// 005cc541  57                   push edi
// 005cc542  8bf0                 mov esi, eax
// 005cc544  e83710ffff           call 0x5bd580
// 005cc549  83c40c               add esp, 0xc
// 005cc54c  e8affeffff           call 0x5cc400
// 005cc551  8bf0                 mov esi, eax
// 005cc553  85f6                 test esi, esi
// 005cc555  7d35                 jge 0x5cc58c
// 005cc557  6aff                 push -1
// 005cc559  57                   push edi
// 005cc55a  e8c112ffff           call 0x5bd820
// 005cc55f  83c408               add esp, 8
// 005cc562  85c0                 test eax, eax
// 005cc564  741b                 je 0x5cc581
// 005cc566  6a01                 push 1
// 005cc568  57                   push edi
// 005cc569  e80223ffff           call 0x5be870
// 005cc56e  6afe                 push -2
// 005cc570  57                   push edi
// 005cc571  e8ba10ffff           call 0x5bd630
// 005cc576  6a02                 push 2
// 005cc578  57                   push edi
// 005cc579  e8b21fffff           call 0x5be530
// 005cc57e  83c418               add esp, 0x18
// 005cc581  57                   push edi
// 005cc582  e8591fffff           call 0x5be4e0
// 005cc587  83c404               add esp, 4
// 005cc58a  8bc6                 mov eax, esi
// 005cc58c  5f                   pop edi
// 005cc58d  5e                   pop esi
// 005cc58e  c3                   ret 
// library lua-5.1.2/lbaselib.c (function _luaB_auxwrap)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lbaselib.c
