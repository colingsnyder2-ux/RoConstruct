// from server: 100% by auto
// roc 2010-06 0083b750  unit: XTPPaintThemes::CXTPOfficeTheme  size: 189 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0083b750
//
// 0083b750  33c0                 xor eax, eax
// 0083b752  837c241c05           cmp dword ptr [esp + 0x1c], 5
// 0083b757  0f95c0               setne al
// 0083b75a  837c241802           cmp dword ptr [esp + 0x18], 2
// 0083b75f  8d44002c             lea eax, [eax + eax + 0x2c]
// 0083b763  752a                 jne 0x83b78f
// 0083b765  837c240c00           cmp dword ptr [esp + 0xc], 0
// 0083b76a  750e                 jne 0x83b77a
// 0083b76c  b823000000           mov eax, 0x23
// 0083b771  50                   push eax
// 0083b772  e89919f7ff           call 0x7ad110
// 0083b777  c21c00               ret 0x1c
// 0083b77a  33c0                 xor eax, eax
// 0083b77c  39442404             cmp dword ptr [esp + 4], eax
// 0083b780  0f95c0               setne al
// 0083b783  83c02c               add eax, 0x2c
// 0083b786  50                   push eax
// 0083b787  e88419f7ff           call 0x7ad110
// 0083b78c  c21c00               ret 0x1c
// 0083b78f  837c240c00           cmp dword ptr [esp + 0xc], 0
// 0083b794  750e                 jne 0x83b7a4
// 0083b796  b83c000000           mov eax, 0x3c
// 0083b79b  50                   push eax
// 0083b79c  e86f19f7ff           call 0x7ad110
// 0083b7a1  c21c00               ret 0x1c
// 0083b7a4  837c241400           cmp dword ptr [esp + 0x14], 0
// 0083b7a9  740e                 je 0x83b7b9
// 0083b7ab  b82e000000           mov eax, 0x2e
// 0083b7b0  50                   push eax
// 0083b7b1  e85a19f7ff           call 0x7ad110
// 0083b7b6  c21c00               ret 0x1c
// 0083b7b9  8b542408             mov edx, dword ptr [esp + 8]
// 0083b7bd  56                   push esi
// 0083b7be  8b742408             mov esi, dword ptr [esp + 8]
// 0083b7c2  57                   push edi
// 0083b7c3  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0083b7c7  85ff                 test edi, edi
// 0083b7c9  7408                 je 0x83b7d3
// 0083b7cb  85f6                 test esi, esi
// 0083b7cd  7504                 jne 0x83b7d3
// 0083b7cf  85d2                 test edx, edx
// 0083b7d1  742a                 je 0x83b7fd
// 0083b7d3  83fa02               cmp edx, 2
// 0083b7d6  7411                 je 0x83b7e9
// 0083b7d8  83fa03               cmp edx, 3
// 0083b7db  740c                 je 0x83b7e9
// 0083b7dd  85f6                 test esi, esi
// 0083b7df  7418                 je 0x83b7f9
// 0083b7e1  85d2                 test edx, edx
// 0083b7e3  7504                 jne 0x83b7e9
// 0083b7e5  85ff                 test edi, edi
// 0083b7e7  7414                 je 0x83b7fd
// 0083b7e9  b82f000000           mov eax, 0x2f
// 0083b7ee  5f                   pop edi
// 0083b7ef  5e                   pop esi
// 0083b7f0  50                   push eax
// 0083b7f1  e81a19f7ff           call 0x7ad110
// 0083b7f6  c21c00               ret 0x1c
// 0083b7f9  85d2                 test edx, edx
// 0083b7fb  74f1                 je 0x83b7ee
// 0083b7fd  5f                   pop edi
// 0083b7fe  b82d000000           mov eax, 0x2d
// 0083b803  5e                   pop esi
// 0083b804  50                   push eax
// 0083b805  e80619f7ff           call 0x7ad110
// 0083b80a  c21c00               ret 0x1c
// library xtp-13.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?GetRectangleTextColor@CXTPOfficeTheme@@UAEKHHHHHW4XTPBarType@@W4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOfficeTheme.cpp
