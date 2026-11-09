// from server: 100% by auto
// roc 2009-12 008e49f0  unit: CXTCaptionThemeOffice2003  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e49f0
//
// 008e49f0  56                   push esi
// 008e49f1  8b742408             mov esi, dword ptr [esp + 8]
// 008e49f5  57                   push edi
// 008e49f6  6a01                 push 1
// 008e49f8  8bce                 mov ecx, esi
// 008e49fa  e8911a0400           call 0x926490
// 008e49ff  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e4a03  80b88100000000       cmp byte ptr [eax + 0x81], 0
// 008e4a0a  744e                 je 0x8e4a5a
// 008e4a0c  53                   push ebx
// 008e4a0d  e8beaff4ff           call 0x82f9d0
// 008e4a12  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 008e4a16  6a00                 push 0
// 008e4a18  6a00                 push 0
// 008e4a1a  83c020               add eax, 0x20
// 008e4a1d  50                   push eax
// 008e4a1e  57                   push edi
// 008e4a1f  56                   push esi
// 008e4a20  e87b88f6ff           call 0x84d2a0
// 008e4a25  8bc8                 mov ecx, eax
// 008e4a27  e8948bf6ff           call 0x84d5c0
// 008e4a2c  e89faff4ff           call 0x82f9d0
// 008e4a31  6a36                 push 0x36
// 008e4a33  8bc8                 mov ecx, eax
// 008e4a35  e8c6a6f4ff           call 0x82f100
// 008e4a3a  8bd8                 mov ebx, eax
// 008e4a3c  e88faff4ff           call 0x82f9d0
// 008e4a41  6a36                 push 0x36
// 008e4a43  8bc8                 mov ecx, eax
// 008e4a45  e8b6a6f4ff           call 0x82f100
// 008e4a4a  53                   push ebx
// 008e4a4b  50                   push eax
// 008e4a4c  57                   push edi
// 008e4a4d  8bce                 mov ecx, esi
// 008e4a4f  e8a4fbf0ff           call 0x7f45f8
// 008e4a54  5b                   pop ebx
// 008e4a55  5f                   pop edi
// 008e4a56  5e                   pop esi
// 008e4a57  c20c00               ret 0xc
// 008e4a5a  e871aff4ff           call 0x82f9d0
// 008e4a5f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 008e4a63  6a00                 push 0
// 008e4a65  6a00                 push 0
// 008e4a67  83e880               sub eax, -0x80
// 008e4a6a  50                   push eax
// 008e4a6b  57                   push edi
// 008e4a6c  56                   push esi
// 008e4a6d  e82e88f6ff           call 0x84d2a0
// 008e4a72  8bc8                 mov ecx, eax
// 008e4a74  e8478bf6ff           call 0x84d5c0
// 008e4a79  e852aff4ff           call 0x82f9d0
// 008e4a7e  6a36                 push 0x36
// 008e4a80  8bc8                 mov ecx, eax
// 008e4a82  e879a6f4ff           call 0x82f100
// 008e4a87  8b0f                 mov ecx, dword ptr [edi]
// 008e4a89  8b5708               mov edx, dword ptr [edi + 8]
// 008e4a8c  50                   push eax
// 008e4a8d  8b470c               mov eax, dword ptr [edi + 0xc]
// 008e4a90  6a01                 push 1
// 008e4a92  2bd1                 sub edx, ecx
// 008e4a94  52                   push edx
// 008e4a95  48                   dec eax
// 008e4a96  50                   push eax
// 008e4a97  51                   push ecx
// 008e4a98  8bce                 mov ecx, esi
// 008e4a9a  e8f7190400           call 0x926496
// 008e4a9f  5f                   pop edi
// 008e4aa0  5e                   pop esi
// 008e4aa1  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawCaptionBack@CXTCaptionThemeOffice2003@@MAEXPAVCDC@@PAVCXTCaption@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
