// from server: 100% by auto
// roc 2010-06 0083b620  unit: XTPPaintThemes::CXTPOfficeTheme  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0083b620
//
// 0083b620  837c242000           cmp dword ptr [esp + 0x20], 0
// 0083b625  56                   push esi
// 0083b626  7553                 jne 0x83b67b
// 0083b628  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0083b62c  83f802               cmp eax, 2
// 0083b62f  7405                 je 0x83b636
// 0083b631  83f803               cmp eax, 3
// 0083b634  7526                 jne 0x83b65c
// 0083b636  837c243405           cmp dword ptr [esp + 0x34], 5
// 0083b63b  7415                 je 0x83b652
// 0083b63d  33c0                 xor eax, eax
// 0083b63f  39442428             cmp dword ptr [esp + 0x28], eax
// 0083b643  0f95c0               setne al
// 0083b646  8d44001f             lea eax, [eax + eax + 0x1f]
// 0083b64a  50                   push eax
// 0083b64b  6a20                 push 0x20
// 0083b64d  e981000000           jmp 0x83b6d3
// 0083b652  b829000000           mov eax, 0x29
// 0083b657  50                   push eax
// 0083b658  6a20                 push 0x20
// 0083b65a  eb77                 jmp 0x83b6d3
// 0083b65c  837c242800           cmp dword ptr [esp + 0x28], 0
// 0083b661  0f8496000000         je 0x83b6fd
// 0083b667  8b542434             mov edx, dword ptr [esp + 0x34]
// 0083b66b  83ea05               sub edx, 5
// 0083b66e  f7da                 neg edx
// 0083b670  1bd2                 sbb edx, edx
// 0083b672  83e225               and edx, 0x25
// 0083b675  4a                   dec edx
// 0083b676  52                   push edx
// 0083b677  6a3a                 push 0x3a
// 0083b679  eb58                 jmp 0x83b6d3
// 0083b67b  837c242c00           cmp dword ptr [esp + 0x2c], 0
// 0083b680  7406                 je 0x83b688
// 0083b682  6a1e                 push 0x1e
// 0083b684  6a2b                 push 0x2b
// 0083b686  eb4b                 jmp 0x83b6d3
// 0083b688  8b542428             mov edx, dword ptr [esp + 0x28]
// 0083b68c  8b442420             mov eax, dword ptr [esp + 0x20]
// 0083b690  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0083b694  83fa02               cmp edx, 2
// 0083b697  750e                 jne 0x83b6a7
// 0083b699  85f6                 test esi, esi
// 0083b69b  751c                 jne 0x83b6b9
// 0083b69d  85c0                 test eax, eax
// 0083b69f  751c                 jne 0x83b6bd
// 0083b6a1  6a33                 push 0x33
// 0083b6a3  6a25                 push 0x25
// 0083b6a5  eb2c                 jmp 0x83b6d3
// 0083b6a7  85d2                 test edx, edx
// 0083b6a9  7412                 je 0x83b6bd
// 0083b6ab  85f6                 test esi, esi
// 0083b6ad  750a                 jne 0x83b6b9
// 0083b6af  85c0                 test eax, eax
// 0083b6b1  750a                 jne 0x83b6bd
// 0083b6b3  6a24                 push 0x24
// 0083b6b5  6a25                 push 0x25
// 0083b6b7  eb1a                 jmp 0x83b6d3
// 0083b6b9  85c0                 test eax, eax
// 0083b6bb  7412                 je 0x83b6cf
// 0083b6bd  83f802               cmp eax, 2
// 0083b6c0  740d                 je 0x83b6cf
// 0083b6c2  83f803               cmp eax, 3
// 0083b6c5  7408                 je 0x83b6cf
// 0083b6c7  85f6                 test esi, esi
// 0083b6c9  7436                 je 0x83b701
// 0083b6cb  85c0                 test eax, eax
// 0083b6cd  7436                 je 0x83b705
// 0083b6cf  6a21                 push 0x21
// 0083b6d1  6a32                 push 0x32
// 0083b6d3  8b542414             mov edx, dword ptr [esp + 0x14]
// 0083b6d7  83ec10               sub esp, 0x10
// 0083b6da  8bc4                 mov eax, esp
// 0083b6dc  8910                 mov dword ptr [eax], edx
// 0083b6de  8b542428             mov edx, dword ptr [esp + 0x28]
// 0083b6e2  895004               mov dword ptr [eax + 4], edx
// 0083b6e5  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0083b6e9  895008               mov dword ptr [eax + 8], edx
// 0083b6ec  8b542430             mov edx, dword ptr [esp + 0x30]
// 0083b6f0  89500c               mov dword ptr [eax + 0xc], edx
// 0083b6f3  8b442420             mov eax, dword ptr [esp + 0x20]
// 0083b6f7  50                   push eax
// 0083b6f8  e8732bf7ff           call 0x7ae270
// 0083b6fd  5e                   pop esi
// 0083b6fe  c23000               ret 0x30
// 0083b701  85c0                 test eax, eax
// 0083b703  74f8                 je 0x83b6fd
// 0083b705  6a1f                 push 0x1f
// 0083b707  6a20                 push 0x20
// 0083b709  ebc8                 jmp 0x83b6d3
// library xtp-13.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawRectangle@CXTPOfficeTheme@@MAEXPAVCDC@@VCRect@@HHHHHW4XTPBarType@@W4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOfficeTheme.cpp
