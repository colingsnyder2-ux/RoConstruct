// from server: 100% by auto
// roc 2009-12 0079f780  unit: seg_00790000  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079f780
//
// 0079f780  56                   push esi
// 0079f781  57                   push edi
// 0079f782  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0079f786  68edd8ffff           push 0xffffd8ed
// 0079f78b  57                   push edi
// 0079f78c  e81f95feff           call 0x788cb0
// 0079f791  57                   push edi
// 0079f792  8bf0                 mov esi, eax
// 0079f794  e80790feff           call 0x7887a0
// 0079f799  83c40c               add esp, 0xc
// 0079f79c  8bce                 mov ecx, esi
// 0079f79e  e89dfeffff           call 0x79f640
// 0079f7a3  8bf0                 mov esi, eax
// 0079f7a5  85f6                 test esi, esi
// 0079f7a7  7d35                 jge 0x79f7de
// 0079f7a9  6aff                 push -1
// 0079f7ab  57                   push edi
// 0079f7ac  e88f92feff           call 0x788a40
// 0079f7b1  83c408               add esp, 8
// 0079f7b4  85c0                 test eax, eax
// 0079f7b6  741b                 je 0x79f7d3
// 0079f7b8  6a01                 push 1
// 0079f7ba  57                   push edi
// 0079f7bb  e8c0a4feff           call 0x789c80
// 0079f7c0  6afe                 push -2
// 0079f7c2  57                   push edi
// 0079f7c3  e88890feff           call 0x788850
// 0079f7c8  6a02                 push 2
// 0079f7ca  57                   push edi
// 0079f7cb  e8a09ffeff           call 0x789770
// 0079f7d0  83c418               add esp, 0x18
// 0079f7d3  57                   push edi
// 0079f7d4  e8479ffeff           call 0x789720
// 0079f7d9  83c404               add esp, 4
// 0079f7dc  8bc6                 mov eax, esi
// 0079f7de  5f                   pop edi
// 0079f7df  5e                   pop esi
// 0079f7e0  c3                   ret 
// library lua-5.1.3/lbaselib.c (function _luaB_auxwrap)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 lbaselib.c
