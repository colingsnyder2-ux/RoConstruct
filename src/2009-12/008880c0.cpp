// from server: 100% by auto
// roc 2009-12 008880c0  unit: XTPPaintThemes::CXTPOfficeTheme  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008880c0
//
// 008880c0  837c242000           cmp dword ptr [esp + 0x20], 0
// 008880c5  56                   push esi
// 008880c6  7553                 jne 0x88811b
// 008880c8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008880cc  83f802               cmp eax, 2
// 008880cf  7405                 je 0x8880d6
// 008880d1  83f803               cmp eax, 3
// 008880d4  7526                 jne 0x8880fc
// 008880d6  837c243405           cmp dword ptr [esp + 0x34], 5
// 008880db  7415                 je 0x8880f2
// 008880dd  33c0                 xor eax, eax
// 008880df  39442428             cmp dword ptr [esp + 0x28], eax
// 008880e3  0f95c0               setne al
// 008880e6  8d44001f             lea eax, [eax + eax + 0x1f]
// 008880ea  50                   push eax
// 008880eb  6a20                 push 0x20
// 008880ed  e981000000           jmp 0x888173
// 008880f2  b829000000           mov eax, 0x29
// 008880f7  50                   push eax
// 008880f8  6a20                 push 0x20
// 008880fa  eb77                 jmp 0x888173
// 008880fc  837c242800           cmp dword ptr [esp + 0x28], 0
// 00888101  0f8496000000         je 0x88819d
// 00888107  8b542434             mov edx, dword ptr [esp + 0x34]
// 0088810b  83ea05               sub edx, 5
// 0088810e  f7da                 neg edx
// 00888110  1bd2                 sbb edx, edx
// 00888112  83e225               and edx, 0x25
// 00888115  4a                   dec edx
// 00888116  52                   push edx
// 00888117  6a3a                 push 0x3a
// 00888119  eb58                 jmp 0x888173
// 0088811b  837c242c00           cmp dword ptr [esp + 0x2c], 0
// 00888120  7406                 je 0x888128
// 00888122  6a1e                 push 0x1e
// 00888124  6a2b                 push 0x2b
// 00888126  eb4b                 jmp 0x888173
// 00888128  8b542428             mov edx, dword ptr [esp + 0x28]
// 0088812c  8b442420             mov eax, dword ptr [esp + 0x20]
// 00888130  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00888134  83fa02               cmp edx, 2
// 00888137  750e                 jne 0x888147
// 00888139  85f6                 test esi, esi
// 0088813b  751c                 jne 0x888159
// 0088813d  85c0                 test eax, eax
// 0088813f  751c                 jne 0x88815d
// 00888141  6a33                 push 0x33
// 00888143  6a25                 push 0x25
// 00888145  eb2c                 jmp 0x888173
// 00888147  85d2                 test edx, edx
// 00888149  7412                 je 0x88815d
// 0088814b  85f6                 test esi, esi
// 0088814d  750a                 jne 0x888159
// 0088814f  85c0                 test eax, eax
// 00888151  750a                 jne 0x88815d
// 00888153  6a24                 push 0x24
// 00888155  6a25                 push 0x25
// 00888157  eb1a                 jmp 0x888173
// 00888159  85c0                 test eax, eax
// 0088815b  7412                 je 0x88816f
// 0088815d  83f802               cmp eax, 2
// 00888160  740d                 je 0x88816f
// 00888162  83f803               cmp eax, 3
// 00888165  7408                 je 0x88816f
// 00888167  85f6                 test esi, esi
// 00888169  7436                 je 0x8881a1
// 0088816b  85c0                 test eax, eax
// 0088816d  7436                 je 0x8881a5
// 0088816f  6a21                 push 0x21
// 00888171  6a32                 push 0x32
// 00888173  8b542414             mov edx, dword ptr [esp + 0x14]
// 00888177  83ec10               sub esp, 0x10
// 0088817a  8bc4                 mov eax, esp
// 0088817c  8910                 mov dword ptr [eax], edx
// 0088817e  8b542428             mov edx, dword ptr [esp + 0x28]
// 00888182  895004               mov dword ptr [eax + 4], edx
// 00888185  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00888189  895008               mov dword ptr [eax + 8], edx
// 0088818c  8b542430             mov edx, dword ptr [esp + 0x30]
// 00888190  89500c               mov dword ptr [eax + 0xc], edx
// 00888193  8b442420             mov eax, dword ptr [esp + 0x20]
// 00888197  50                   push eax
// 00888198  e8c365f7ff           call 0x7fe760
// 0088819d  5e                   pop esi
// 0088819e  c23000               ret 0x30
// 008881a1  85c0                 test eax, eax
// 008881a3  74f8                 je 0x88819d
// 008881a5  6a1f                 push 0x1f
// 008881a7  6a20                 push 0x20
// 008881a9  ebc8                 jmp 0x888173
// library xtp-13.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawRectangle@CXTPOfficeTheme@@MAEXPAVCDC@@VCRect@@HHHHHW4XTPBarType@@W4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOfficeTheme.cpp
