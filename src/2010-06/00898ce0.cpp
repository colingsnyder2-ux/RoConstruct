// from server: 100% by auto
// roc 2010-06 00898ce0  unit: CXTCaptionThemeOffice2003  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00898ce0
//
// 00898ce0  56                   push esi
// 00898ce1  8b742408             mov esi, dword ptr [esp + 8]
// 00898ce5  57                   push edi
// 00898ce6  6a01                 push 1
// 00898ce8  8bce                 mov ecx, esi
// 00898cea  e8c5400e00           call 0x97cdb4
// 00898cef  8b442410             mov eax, dword ptr [esp + 0x10]
// 00898cf3  80b88100000000       cmp byte ptr [eax + 0x81], 0
// 00898cfa  744e                 je 0x898d4a
// 00898cfc  53                   push ebx
// 00898cfd  e81eaef4ff           call 0x7e3b20
// 00898d02  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00898d06  6a00                 push 0
// 00898d08  6a00                 push 0
// 00898d0a  83c020               add eax, 0x20
// 00898d0d  50                   push eax
// 00898d0e  57                   push edi
// 00898d0f  56                   push esi
// 00898d10  e8eb85f6ff           call 0x801300
// 00898d15  8bc8                 mov ecx, eax
// 00898d17  e80489f6ff           call 0x801620
// 00898d1c  e8ffadf4ff           call 0x7e3b20
// 00898d21  6a36                 push 0x36
// 00898d23  8bc8                 mov ecx, eax
// 00898d25  e886a5f4ff           call 0x7e32b0
// 00898d2a  8bd8                 mov ebx, eax
// 00898d2c  e8efadf4ff           call 0x7e3b20
// 00898d31  6a36                 push 0x36
// 00898d33  8bc8                 mov ecx, eax
// 00898d35  e876a5f4ff           call 0x7e32b0
// 00898d3a  53                   push ebx
// 00898d3b  50                   push eax
// 00898d3c  57                   push edi
// 00898d3d  8bce                 mov ecx, esi
// 00898d3f  e8f4f9f0ff           call 0x7a8738
// 00898d44  5b                   pop ebx
// 00898d45  5f                   pop edi
// 00898d46  5e                   pop esi
// 00898d47  c20c00               ret 0xc
// 00898d4a  e8d1adf4ff           call 0x7e3b20
// 00898d4f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00898d53  6a00                 push 0
// 00898d55  6a00                 push 0
// 00898d57  83e880               sub eax, -0x80
// 00898d5a  50                   push eax
// 00898d5b  57                   push edi
// 00898d5c  56                   push esi
// 00898d5d  e89e85f6ff           call 0x801300
// 00898d62  8bc8                 mov ecx, eax
// 00898d64  e8b788f6ff           call 0x801620
// 00898d69  e8b2adf4ff           call 0x7e3b20
// 00898d6e  6a36                 push 0x36
// 00898d70  8bc8                 mov ecx, eax
// 00898d72  e839a5f4ff           call 0x7e32b0
// 00898d77  8b0f                 mov ecx, dword ptr [edi]
// 00898d79  8b5708               mov edx, dword ptr [edi + 8]
// 00898d7c  50                   push eax
// 00898d7d  8b470c               mov eax, dword ptr [edi + 0xc]
// 00898d80  6a01                 push 1
// 00898d82  2bd1                 sub edx, ecx
// 00898d84  52                   push edx
// 00898d85  48                   dec eax
// 00898d86  50                   push eax
// 00898d87  51                   push ecx
// 00898d88  8bce                 mov ecx, esi
// 00898d8a  e8fb3f0e00           call 0x97cd8a
// 00898d8f  5f                   pop edi
// 00898d90  5e                   pop esi
// 00898d91  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawCaptionBack@CXTCaptionThemeOffice2003@@MAEXPAVCDC@@PAVCXTCaption@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
