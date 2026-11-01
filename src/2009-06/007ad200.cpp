// from server: 100% by auto
// roc 2009-06 007ad200  unit: XTPPaintThemes::CXTPOfficeTheme  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ad200
//
// 007ad200  837c242000           cmp dword ptr [esp + 0x20], 0
// 007ad205  56                   push esi
// 007ad206  7553                 jne 0x7ad25b
// 007ad208  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007ad20c  83f802               cmp eax, 2
// 007ad20f  7405                 je 0x7ad216
// 007ad211  83f803               cmp eax, 3
// 007ad214  7526                 jne 0x7ad23c
// 007ad216  837c243405           cmp dword ptr [esp + 0x34], 5
// 007ad21b  7415                 je 0x7ad232
// 007ad21d  33c0                 xor eax, eax
// 007ad21f  39442428             cmp dword ptr [esp + 0x28], eax
// 007ad223  0f95c0               setne al
// 007ad226  8d44001f             lea eax, [eax + eax + 0x1f]
// 007ad22a  50                   push eax
// 007ad22b  6a20                 push 0x20
// 007ad22d  e981000000           jmp 0x7ad2b3
// 007ad232  b829000000           mov eax, 0x29
// 007ad237  50                   push eax
// 007ad238  6a20                 push 0x20
// 007ad23a  eb77                 jmp 0x7ad2b3
// 007ad23c  837c242800           cmp dword ptr [esp + 0x28], 0
// 007ad241  0f8496000000         je 0x7ad2dd
// 007ad247  8b542434             mov edx, dword ptr [esp + 0x34]
// 007ad24b  83ea05               sub edx, 5
// 007ad24e  f7da                 neg edx
// 007ad250  1bd2                 sbb edx, edx
// 007ad252  83e225               and edx, 0x25
// 007ad255  4a                   dec edx
// 007ad256  52                   push edx
// 007ad257  6a3a                 push 0x3a
// 007ad259  eb58                 jmp 0x7ad2b3
// 007ad25b  837c242c00           cmp dword ptr [esp + 0x2c], 0
// 007ad260  7406                 je 0x7ad268
// 007ad262  6a1e                 push 0x1e
// 007ad264  6a2b                 push 0x2b
// 007ad266  eb4b                 jmp 0x7ad2b3
// 007ad268  8b542428             mov edx, dword ptr [esp + 0x28]
// 007ad26c  8b442420             mov eax, dword ptr [esp + 0x20]
// 007ad270  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 007ad274  83fa02               cmp edx, 2
// 007ad277  750e                 jne 0x7ad287
// 007ad279  85f6                 test esi, esi
// 007ad27b  751c                 jne 0x7ad299
// 007ad27d  85c0                 test eax, eax
// 007ad27f  751c                 jne 0x7ad29d
// 007ad281  6a33                 push 0x33
// 007ad283  6a25                 push 0x25
// 007ad285  eb2c                 jmp 0x7ad2b3
// 007ad287  85d2                 test edx, edx
// 007ad289  7412                 je 0x7ad29d
// 007ad28b  85f6                 test esi, esi
// 007ad28d  750a                 jne 0x7ad299
// 007ad28f  85c0                 test eax, eax
// 007ad291  750a                 jne 0x7ad29d
// 007ad293  6a24                 push 0x24
// 007ad295  6a25                 push 0x25
// 007ad297  eb1a                 jmp 0x7ad2b3
// 007ad299  85c0                 test eax, eax
// 007ad29b  7412                 je 0x7ad2af
// 007ad29d  83f802               cmp eax, 2
// 007ad2a0  740d                 je 0x7ad2af
// 007ad2a2  83f803               cmp eax, 3
// 007ad2a5  7408                 je 0x7ad2af
// 007ad2a7  85f6                 test esi, esi
// 007ad2a9  7436                 je 0x7ad2e1
// 007ad2ab  85c0                 test eax, eax
// 007ad2ad  7436                 je 0x7ad2e5
// 007ad2af  6a21                 push 0x21
// 007ad2b1  6a32                 push 0x32
// 007ad2b3  8b542414             mov edx, dword ptr [esp + 0x14]
// 007ad2b7  83ec10               sub esp, 0x10
// 007ad2ba  8bc4                 mov eax, esp
// 007ad2bc  8910                 mov dword ptr [eax], edx
// 007ad2be  8b542428             mov edx, dword ptr [esp + 0x28]
// 007ad2c2  895004               mov dword ptr [eax + 4], edx
// 007ad2c5  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007ad2c9  895008               mov dword ptr [eax + 8], edx
// 007ad2cc  8b542430             mov edx, dword ptr [esp + 0x30]
// 007ad2d0  89500c               mov dword ptr [eax + 0xc], edx
// 007ad2d3  8b442420             mov eax, dword ptr [esp + 0x20]
// 007ad2d7  50                   push eax
// 007ad2d8  e81365f7ff           call 0x7237f0
// 007ad2dd  5e                   pop esi
// 007ad2de  c23000               ret 0x30
// 007ad2e1  85c0                 test eax, eax
// 007ad2e3  74f8                 je 0x7ad2dd
// 007ad2e5  6a1f                 push 0x1f
// 007ad2e7  6a20                 push 0x20
// 007ad2e9  ebc8                 jmp 0x7ad2b3
// library xtp-13.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawRectangle@CXTPOfficeTheme@@MAEXPAVCDC@@VCRect@@HHHHHW4XTPBarType@@W4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOfficeTheme.cpp
