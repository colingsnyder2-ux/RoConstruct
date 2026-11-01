// from server: 100% by auto
// roc 2011-06 008f1830  unit: CXTCaptionThemeOffice2003  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f1830
//
// 008f1830  56                   push esi
// 008f1831  8b742408             mov esi, dword ptr [esp + 8]
// 008f1835  57                   push edi
// 008f1836  6a01                 push 1
// 008f1838  8bce                 mov ecx, esi
// 008f183a  e8afad0d00           call 0x9cc5ee
// 008f183f  8b442410             mov eax, dword ptr [esp + 0x10]
// 008f1843  80b88100000000       cmp byte ptr [eax + 0x81], 0
// 008f184a  744e                 je 0x8f189a
// 008f184c  53                   push ebx
// 008f184d  e88e3bf5ff           call 0x8453e0
// 008f1852  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 008f1856  6a00                 push 0
// 008f1858  6a00                 push 0
// 008f185a  83c020               add eax, 0x20
// 008f185d  50                   push eax
// 008f185e  57                   push edi
// 008f185f  56                   push esi
// 008f1860  e81bd5f6ff           call 0x85ed80
// 008f1865  8bc8                 mov ecx, eax
// 008f1867  e834d8f6ff           call 0x85f0a0
// 008f186c  e86f3bf5ff           call 0x8453e0
// 008f1871  6a36                 push 0x36
// 008f1873  8bc8                 mov ecx, eax
// 008f1875  e83633f5ff           call 0x844bb0
// 008f187a  8bd8                 mov ebx, eax
// 008f187c  e85f3bf5ff           call 0x8453e0
// 008f1881  6a36                 push 0x36
// 008f1883  8bc8                 mov ecx, eax
// 008f1885  e82633f5ff           call 0x844bb0
// 008f188a  53                   push ebx
// 008f188b  50                   push eax
// 008f188c  57                   push edi
// 008f188d  8bce                 mov ecx, esi
// 008f188f  e88695f1ff           call 0x80ae1a
// 008f1894  5b                   pop ebx
// 008f1895  5f                   pop edi
// 008f1896  5e                   pop esi
// 008f1897  c20c00               ret 0xc
// 008f189a  e8413bf5ff           call 0x8453e0
// 008f189f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 008f18a3  6a00                 push 0
// 008f18a5  6a00                 push 0
// 008f18a7  83e880               sub eax, -0x80
// 008f18aa  50                   push eax
// 008f18ab  57                   push edi
// 008f18ac  56                   push esi
// 008f18ad  e8ced4f6ff           call 0x85ed80
// 008f18b2  8bc8                 mov ecx, eax
// 008f18b4  e8e7d7f6ff           call 0x85f0a0
// 008f18b9  e8223bf5ff           call 0x8453e0
// 008f18be  6a36                 push 0x36
// 008f18c0  8bc8                 mov ecx, eax
// 008f18c2  e8e932f5ff           call 0x844bb0
// 008f18c7  8b0f                 mov ecx, dword ptr [edi]
// 008f18c9  8b5708               mov edx, dword ptr [edi + 8]
// 008f18cc  50                   push eax
// 008f18cd  8b470c               mov eax, dword ptr [edi + 0xc]
// 008f18d0  6a01                 push 1
// 008f18d2  2bd1                 sub edx, ecx
// 008f18d4  52                   push edx
// 008f18d5  48                   dec eax
// 008f18d6  50                   push eax
// 008f18d7  51                   push ecx
// 008f18d8  8bce                 mov ecx, esi
// 008f18da  e8f7ac0d00           call 0x9cc5d6
// 008f18df  5f                   pop edi
// 008f18e0  5e                   pop esi
// 008f18e1  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawCaptionBack@CXTCaptionThemeOffice2003@@MAEXPAVCDC@@PAVCXTCaption@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
