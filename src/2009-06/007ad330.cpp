// from server: 100% by auto
// roc 2009-06 007ad330  unit: XTPPaintThemes::CXTPOfficeTheme  size: 189 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ad330
//
// 007ad330  33c0                 xor eax, eax
// 007ad332  837c241c05           cmp dword ptr [esp + 0x1c], 5
// 007ad337  0f95c0               setne al
// 007ad33a  837c241802           cmp dword ptr [esp + 0x18], 2
// 007ad33f  8d44002c             lea eax, [eax + eax + 0x2c]
// 007ad343  752a                 jne 0x7ad36f
// 007ad345  837c240c00           cmp dword ptr [esp + 0xc], 0
// 007ad34a  750e                 jne 0x7ad35a
// 007ad34c  b823000000           mov eax, 0x23
// 007ad351  50                   push eax
// 007ad352  e82954f7ff           call 0x722780
// 007ad357  c21c00               ret 0x1c
// 007ad35a  33c0                 xor eax, eax
// 007ad35c  39442404             cmp dword ptr [esp + 4], eax
// 007ad360  0f95c0               setne al
// 007ad363  83c02c               add eax, 0x2c
// 007ad366  50                   push eax
// 007ad367  e81454f7ff           call 0x722780
// 007ad36c  c21c00               ret 0x1c
// 007ad36f  837c240c00           cmp dword ptr [esp + 0xc], 0
// 007ad374  750e                 jne 0x7ad384
// 007ad376  b83c000000           mov eax, 0x3c
// 007ad37b  50                   push eax
// 007ad37c  e8ff53f7ff           call 0x722780
// 007ad381  c21c00               ret 0x1c
// 007ad384  837c241400           cmp dword ptr [esp + 0x14], 0
// 007ad389  740e                 je 0x7ad399
// 007ad38b  b82e000000           mov eax, 0x2e
// 007ad390  50                   push eax
// 007ad391  e8ea53f7ff           call 0x722780
// 007ad396  c21c00               ret 0x1c
// 007ad399  8b542408             mov edx, dword ptr [esp + 8]
// 007ad39d  56                   push esi
// 007ad39e  8b742408             mov esi, dword ptr [esp + 8]
// 007ad3a2  57                   push edi
// 007ad3a3  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 007ad3a7  85ff                 test edi, edi
// 007ad3a9  7408                 je 0x7ad3b3
// 007ad3ab  85f6                 test esi, esi
// 007ad3ad  7504                 jne 0x7ad3b3
// 007ad3af  85d2                 test edx, edx
// 007ad3b1  742a                 je 0x7ad3dd
// 007ad3b3  83fa02               cmp edx, 2
// 007ad3b6  7411                 je 0x7ad3c9
// 007ad3b8  83fa03               cmp edx, 3
// 007ad3bb  740c                 je 0x7ad3c9
// 007ad3bd  85f6                 test esi, esi
// 007ad3bf  7418                 je 0x7ad3d9
// 007ad3c1  85d2                 test edx, edx
// 007ad3c3  7504                 jne 0x7ad3c9
// 007ad3c5  85ff                 test edi, edi
// 007ad3c7  7414                 je 0x7ad3dd
// 007ad3c9  b82f000000           mov eax, 0x2f
// 007ad3ce  5f                   pop edi
// 007ad3cf  5e                   pop esi
// 007ad3d0  50                   push eax
// 007ad3d1  e8aa53f7ff           call 0x722780
// 007ad3d6  c21c00               ret 0x1c
// 007ad3d9  85d2                 test edx, edx
// 007ad3db  74f1                 je 0x7ad3ce
// 007ad3dd  5f                   pop edi
// 007ad3de  b82d000000           mov eax, 0x2d
// 007ad3e3  5e                   pop esi
// 007ad3e4  50                   push eax
// 007ad3e5  e89653f7ff           call 0x722780
// 007ad3ea  c21c00               ret 0x1c
// library xtp-15.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?GetRectangleTextColor@CXTPOfficeTheme@@UAEKHHHHHW4XTPBarType@@W4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPOfficeTheme.cpp
