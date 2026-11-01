// from server: 100% by auto
// roc 2009-06 00787c50  unit: CXTPToolTipContext  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00787c50
//
// 00787c50  8b442404             mov eax, dword ptr [esp + 4]
// 00787c54  83ec24               sub esp, 0x24
// 00787c57  85c0                 test eax, eax
// 00787c59  757c                 jne 0x787cd7
// 00787c5b  8b0d2422a500         mov ecx, dword ptr [0xa52224]
// 00787c61  85c9                 test ecx, ecx
// 00787c63  7472                 je 0x787cd7
// 00787c65  398190000000         cmp dword ptr [ecx + 0x90], eax
// 00787c6b  746a                 je 0x787cd7
// 00787c6d  56                   push esi
// 00787c6e  8b742434             mov esi, dword ptr [esp + 0x34]
// 00787c72  8b06                 mov eax, dword ptr [esi]
// 00787c74  8b5604               mov edx, dword ptr [esi + 4]
// 00787c77  89442404             mov dword ptr [esp + 4], eax
// 00787c7b  8d442404             lea eax, [esp + 4]
// 00787c7f  50                   push eax
// 00787c80  6a00                 push 0
// 00787c82  89542410             mov dword ptr [esp + 0x10], edx
// 00787c86  e815d0ffff           call 0x784ca0
// 00787c8b  8b0d2422a500         mov ecx, dword ptr [0xa52224]
// 00787c91  3b8190000000         cmp eax, dword ptr [ecx + 0x90]
// 00787c97  7422                 je 0x787cbb
// 00787c99  8b542404             mov edx, dword ptr [esp + 4]
// 00787c9d  8b442408             mov eax, dword ptr [esp + 8]
// 00787ca1  89542420             mov dword ptr [esp + 0x20], edx
// 00787ca5  8d54240c             lea edx, [esp + 0xc]
// 00787ca9  52                   push edx
// 00787caa  89442428             mov dword ptr [esp + 0x28], eax
// 00787cae  c744241400020000     mov dword ptr [esp + 0x14], 0x200
// 00787cb6  e835f6ffff           call 0x7872f0
// 00787cbb  8b442430             mov eax, dword ptr [esp + 0x30]
// 00787cbf  8b0d2022a500         mov ecx, dword ptr [0xa52220]
// 00787cc5  56                   push esi
// 00787cc6  50                   push eax
// 00787cc7  6a00                 push 0
// 00787cc9  51                   push ecx
// 00787cca  ff15b8ee8900         call dword ptr [0x89eeb8]
// 00787cd0  5e                   pop esi
// 00787cd1  83c424               add esp, 0x24
// 00787cd4  c20c00               ret 0xc
// 00787cd7  8b542430             mov edx, dword ptr [esp + 0x30]
// 00787cdb  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00787cdf  52                   push edx
// 00787ce0  8b152022a500         mov edx, dword ptr [0xa52220]
// 00787ce6  51                   push ecx
// 00787ce7  50                   push eax
// 00787ce8  52                   push edx
// 00787ce9  ff15b8ee8900         call dword ptr [0x89eeb8]
// 00787cef  83c424               add esp, 0x24
// 00787cf2  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?MouseProc@CXTPToolTipContextToolTip@@KGJHIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
