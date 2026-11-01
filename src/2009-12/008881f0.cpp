// from server: 100% by auto
// roc 2009-12 008881f0  unit: XTPPaintThemes::CXTPOfficeTheme  size: 189 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008881f0
//
// 008881f0  33c0                 xor eax, eax
// 008881f2  837c241c05           cmp dword ptr [esp + 0x1c], 5
// 008881f7  0f95c0               setne al
// 008881fa  837c241802           cmp dword ptr [esp + 0x18], 2
// 008881ff  8d44002c             lea eax, [eax + eax + 0x2c]
// 00888203  752a                 jne 0x88822f
// 00888205  837c240c00           cmp dword ptr [esp + 0xc], 0
// 0088820a  750e                 jne 0x88821a
// 0088820c  b823000000           mov eax, 0x23
// 00888211  50                   push eax
// 00888212  e82954f7ff           call 0x7fd640
// 00888217  c21c00               ret 0x1c
// 0088821a  33c0                 xor eax, eax
// 0088821c  39442404             cmp dword ptr [esp + 4], eax
// 00888220  0f95c0               setne al
// 00888223  83c02c               add eax, 0x2c
// 00888226  50                   push eax
// 00888227  e81454f7ff           call 0x7fd640
// 0088822c  c21c00               ret 0x1c
// 0088822f  837c240c00           cmp dword ptr [esp + 0xc], 0
// 00888234  750e                 jne 0x888244
// 00888236  b83c000000           mov eax, 0x3c
// 0088823b  50                   push eax
// 0088823c  e8ff53f7ff           call 0x7fd640
// 00888241  c21c00               ret 0x1c
// 00888244  837c241400           cmp dword ptr [esp + 0x14], 0
// 00888249  740e                 je 0x888259
// 0088824b  b82e000000           mov eax, 0x2e
// 00888250  50                   push eax
// 00888251  e8ea53f7ff           call 0x7fd640
// 00888256  c21c00               ret 0x1c
// 00888259  8b542408             mov edx, dword ptr [esp + 8]
// 0088825d  56                   push esi
// 0088825e  8b742408             mov esi, dword ptr [esp + 8]
// 00888262  57                   push edi
// 00888263  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00888267  85ff                 test edi, edi
// 00888269  7408                 je 0x888273
// 0088826b  85f6                 test esi, esi
// 0088826d  7504                 jne 0x888273
// 0088826f  85d2                 test edx, edx
// 00888271  742a                 je 0x88829d
// 00888273  83fa02               cmp edx, 2
// 00888276  7411                 je 0x888289
// 00888278  83fa03               cmp edx, 3
// 0088827b  740c                 je 0x888289
// 0088827d  85f6                 test esi, esi
// 0088827f  7418                 je 0x888299
// 00888281  85d2                 test edx, edx
// 00888283  7504                 jne 0x888289
// 00888285  85ff                 test edi, edi
// 00888287  7414                 je 0x88829d
// 00888289  b82f000000           mov eax, 0x2f
// 0088828e  5f                   pop edi
// 0088828f  5e                   pop esi
// 00888290  50                   push eax
// 00888291  e8aa53f7ff           call 0x7fd640
// 00888296  c21c00               ret 0x1c
// 00888299  85d2                 test edx, edx
// 0088829b  74f1                 je 0x88828e
// 0088829d  5f                   pop edi
// 0088829e  b82d000000           mov eax, 0x2d
// 008882a3  5e                   pop esi
// 008882a4  50                   push eax
// 008882a5  e89653f7ff           call 0x7fd640
// 008882aa  c21c00               ret 0x1c
// library xtp-15.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?GetRectangleTextColor@CXTPOfficeTheme@@UAEKHHHHHW4XTPBarType@@W4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPOfficeTheme.cpp
