// from server: 100% by auto
// roc 2009-06 00809f50  unit: CXTCaptionThemeOffice2003  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00809f50
//
// 00809f50  56                   push esi
// 00809f51  8b742408             mov esi, dword ptr [esp + 8]
// 00809f55  57                   push edi
// 00809f56  6a01                 push 1
// 00809f58  8bce                 mov ecx, esi
// 00809f5a  e8a71f0400           call 0x84bf06
// 00809f5f  8b442410             mov eax, dword ptr [esp + 0x10]
// 00809f63  80b88100000000       cmp byte ptr [eax + 0x81], 0
// 00809f6a  744e                 je 0x809fba
// 00809f6c  53                   push ebx
// 00809f6d  e8aeabf4ff           call 0x754b20
// 00809f72  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00809f76  6a00                 push 0
// 00809f78  6a00                 push 0
// 00809f7a  83c020               add eax, 0x20
// 00809f7d  50                   push eax
// 00809f7e  57                   push edi
// 00809f7f  56                   push esi
// 00809f80  e8eb85f6ff           call 0x772570
// 00809f85  8bc8                 mov ecx, eax
// 00809f87  e80489f6ff           call 0x772890
// 00809f8c  e88fabf4ff           call 0x754b20
// 00809f91  6a36                 push 0x36
// 00809f93  8bc8                 mov ecx, eax
// 00809f95  e806a3f4ff           call 0x7542a0
// 00809f9a  8bd8                 mov ebx, eax
// 00809f9c  e87fabf4ff           call 0x754b20
// 00809fa1  6a36                 push 0x36
// 00809fa3  8bc8                 mov ecx, eax
// 00809fa5  e8f6a2f4ff           call 0x7542a0
// 00809faa  53                   push ebx
// 00809fab  50                   push eax
// 00809fac  57                   push edi
// 00809fad  8bce                 mov ecx, esi
// 00809faf  e816f8f0ff           call 0x7197ca
// 00809fb4  5b                   pop ebx
// 00809fb5  5f                   pop edi
// 00809fb6  5e                   pop esi
// 00809fb7  c20c00               ret 0xc
// 00809fba  e861abf4ff           call 0x754b20
// 00809fbf  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00809fc3  6a00                 push 0
// 00809fc5  6a00                 push 0
// 00809fc7  83e880               sub eax, -0x80
// 00809fca  50                   push eax
// 00809fcb  57                   push edi
// 00809fcc  56                   push esi
// 00809fcd  e89e85f6ff           call 0x772570
// 00809fd2  8bc8                 mov ecx, eax
// 00809fd4  e8b788f6ff           call 0x772890
// 00809fd9  e842abf4ff           call 0x754b20
// 00809fde  6a36                 push 0x36
// 00809fe0  8bc8                 mov ecx, eax
// 00809fe2  e8b9a2f4ff           call 0x7542a0
// 00809fe7  8b0f                 mov ecx, dword ptr [edi]
// 00809fe9  8b5708               mov edx, dword ptr [edi + 8]
// 00809fec  50                   push eax
// 00809fed  8b470c               mov eax, dword ptr [edi + 0xc]
// 00809ff0  6a01                 push 1
// 00809ff2  2bd1                 sub edx, ecx
// 00809ff4  52                   push edx
// 00809ff5  48                   dec eax
// 00809ff6  50                   push eax
// 00809ff7  51                   push ecx
// 00809ff8  8bce                 mov ecx, esi
// 00809ffa  e8311f0400           call 0x84bf30
// 00809fff  5f                   pop edi
// 0080a000  5e                   pop esi
// 0080a001  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawCaptionBack@CXTCaptionThemeOffice2003@@MAEXPAVCDC@@PAVCXTCaption@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
