// from server: 100% by auto
// roc 2008-06 00628bd0  unit: seg_00620000  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00628bd0
//
// 00628bd0  56                   push esi
// 00628bd1  57                   push edi
// 00628bd2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00628bd6  6a01                 push 1
// 00628bd8  57                   push edi
// 00628bd9  e87295feff           call 0x612150
// 00628bde  8bf0                 mov esi, eax
// 00628be0  83c408               add esp, 8
// 00628be3  85f6                 test esi, esi
// 00628be5  7510                 jne 0x628bf7
// 00628be7  6860578400           push 0x845760
// 00628bec  6a01                 push 1
// 00628bee  57                   push edi
// 00628bef  e8dc88feff           call 0x6114d0
// 00628bf4  83c40c               add esp, 0xc
// 00628bf7  57                   push edi
// 00628bf8  e81390feff           call 0x611c10
// 00628bfd  83c404               add esp, 4
// 00628c00  48                   dec eax
// 00628c01  e81affffff           call 0x628b20
// 00628c06  8bf0                 mov esi, eax
// 00628c08  85f6                 test esi, esi
// 00628c0a  7d1b                 jge 0x628c27
// 00628c0c  6a00                 push 0
// 00628c0e  57                   push edi
// 00628c0f  e8dc97feff           call 0x6123f0
// 00628c14  6afe                 push -2
// 00628c16  57                   push edi
// 00628c17  e8a490feff           call 0x611cc0
// 00628c1c  83c410               add esp, 0x10
// 00628c1f  5f                   pop edi
// 00628c20  b802000000           mov eax, 2
// 00628c25  5e                   pop esi
// 00628c26  c3                   ret 
// 00628c27  6a01                 push 1
// 00628c29  57                   push edi
// 00628c2a  e8c197feff           call 0x6123f0
// 00628c2f  83c8ff               or eax, 0xffffffff
// 00628c32  2bc6                 sub eax, esi
// 00628c34  50                   push eax
// 00628c35  57                   push edi
// 00628c36  e88590feff           call 0x611cc0
// 00628c3b  83c410               add esp, 0x10
// 00628c3e  5f                   pop edi
// 00628c3f  8d4601               lea eax, [esi + 1]
// 00628c42  5e                   pop esi
// 00628c43  c3                   ret 
// library lua-5.1.2/lbaselib.c (function _luaB_coresume)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lbaselib.c
