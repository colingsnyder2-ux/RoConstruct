// from server: 100% by auto
// roc 2011-06 00898650  unit: XTPPaintThemes::CXTPOfficeTheme  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00898650
//
// 00898650  837c242000           cmp dword ptr [esp + 0x20], 0
// 00898655  56                   push esi
// 00898656  7553                 jne 0x8986ab
// 00898658  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0089865c  83f802               cmp eax, 2
// 0089865f  7405                 je 0x898666
// 00898661  83f803               cmp eax, 3
// 00898664  7526                 jne 0x89868c
// 00898666  837c243405           cmp dword ptr [esp + 0x34], 5
// 0089866b  7415                 je 0x898682
// 0089866d  33c0                 xor eax, eax
// 0089866f  39442428             cmp dword ptr [esp + 0x28], eax
// 00898673  0f95c0               setne al
// 00898676  8d44001f             lea eax, [eax + eax + 0x1f]
// 0089867a  50                   push eax
// 0089867b  6a20                 push 0x20
// 0089867d  e981000000           jmp 0x898703
// 00898682  b829000000           mov eax, 0x29
// 00898687  50                   push eax
// 00898688  6a20                 push 0x20
// 0089868a  eb77                 jmp 0x898703
// 0089868c  837c242800           cmp dword ptr [esp + 0x28], 0
// 00898691  0f8496000000         je 0x89872d
// 00898697  8b542434             mov edx, dword ptr [esp + 0x34]
// 0089869b  83ea05               sub edx, 5
// 0089869e  f7da                 neg edx
// 008986a0  1bd2                 sbb edx, edx
// 008986a2  83e225               and edx, 0x25
// 008986a5  4a                   dec edx
// 008986a6  52                   push edx
// 008986a7  6a3a                 push 0x3a
// 008986a9  eb58                 jmp 0x898703
// 008986ab  837c242c00           cmp dword ptr [esp + 0x2c], 0
// 008986b0  7406                 je 0x8986b8
// 008986b2  6a1e                 push 0x1e
// 008986b4  6a2b                 push 0x2b
// 008986b6  eb4b                 jmp 0x898703
// 008986b8  8b542428             mov edx, dword ptr [esp + 0x28]
// 008986bc  8b442420             mov eax, dword ptr [esp + 0x20]
// 008986c0  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 008986c4  83fa02               cmp edx, 2
// 008986c7  750e                 jne 0x8986d7
// 008986c9  85f6                 test esi, esi
// 008986cb  751c                 jne 0x8986e9
// 008986cd  85c0                 test eax, eax
// 008986cf  751c                 jne 0x8986ed
// 008986d1  6a33                 push 0x33
// 008986d3  6a25                 push 0x25
// 008986d5  eb2c                 jmp 0x898703
// 008986d7  85d2                 test edx, edx
// 008986d9  7412                 je 0x8986ed
// 008986db  85f6                 test esi, esi
// 008986dd  750a                 jne 0x8986e9
// 008986df  85c0                 test eax, eax
// 008986e1  750a                 jne 0x8986ed
// 008986e3  6a24                 push 0x24
// 008986e5  6a25                 push 0x25
// 008986e7  eb1a                 jmp 0x898703
// 008986e9  85c0                 test eax, eax
// 008986eb  7412                 je 0x8986ff
// 008986ed  83f802               cmp eax, 2
// 008986f0  740d                 je 0x8986ff
// 008986f2  83f803               cmp eax, 3
// 008986f5  7408                 je 0x8986ff
// 008986f7  85f6                 test esi, esi
// 008986f9  7436                 je 0x898731
// 008986fb  85c0                 test eax, eax
// 008986fd  7436                 je 0x898735
// 008986ff  6a21                 push 0x21
// 00898701  6a32                 push 0x32
// 00898703  8b542414             mov edx, dword ptr [esp + 0x14]
// 00898707  83ec10               sub esp, 0x10
// 0089870a  8bc4                 mov eax, esp
// 0089870c  8910                 mov dword ptr [eax], edx
// 0089870e  8b542428             mov edx, dword ptr [esp + 0x28]
// 00898712  895004               mov dword ptr [eax + 4], edx
// 00898715  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00898719  895008               mov dword ptr [eax + 8], edx
// 0089871c  8b542430             mov edx, dword ptr [esp + 0x30]
// 00898720  89500c               mov dword ptr [eax + 0xc], edx
// 00898723  8b442420             mov eax, dword ptr [esp + 0x20]
// 00898727  50                   push eax
// 00898728  e8537ff7ff           call 0x810680
// 0089872d  5e                   pop esi
// 0089872e  c23000               ret 0x30
// 00898731  85c0                 test eax, eax
// 00898733  74f8                 je 0x89872d
// 00898735  6a1f                 push 0x1f
// 00898737  6a20                 push 0x20
// 00898739  ebc8                 jmp 0x898703
// library xtp-13.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawRectangle@CXTPOfficeTheme@@MAEXPAVCDC@@VCRect@@HHHHHW4XTPBarType@@W4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOfficeTheme.cpp
