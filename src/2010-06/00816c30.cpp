// from server: 100% by auto
// roc 2010-06 00816c30  unit: CXTPToolTipContext  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00816c30
//
// 00816c30  8b442404             mov eax, dword ptr [esp + 4]
// 00816c34  83ec24               sub esp, 0x24
// 00816c37  85c0                 test eax, eax
// 00816c39  757c                 jne 0x816cb7
// 00816c3b  8b0dac5dc200         mov ecx, dword ptr [0xc25dac]
// 00816c41  85c9                 test ecx, ecx
// 00816c43  7472                 je 0x816cb7
// 00816c45  398190000000         cmp dword ptr [ecx + 0x90], eax
// 00816c4b  746a                 je 0x816cb7
// 00816c4d  56                   push esi
// 00816c4e  8b742434             mov esi, dword ptr [esp + 0x34]
// 00816c52  8b06                 mov eax, dword ptr [esi]
// 00816c54  8b5604               mov edx, dword ptr [esi + 4]
// 00816c57  89442404             mov dword ptr [esp + 4], eax
// 00816c5b  8d442404             lea eax, [esp + 4]
// 00816c5f  50                   push eax
// 00816c60  6a00                 push 0
// 00816c62  89542410             mov dword ptr [esp + 0x10], edx
// 00816c66  e845d0ffff           call 0x813cb0
// 00816c6b  8b0dac5dc200         mov ecx, dword ptr [0xc25dac]
// 00816c71  3b8190000000         cmp eax, dword ptr [ecx + 0x90]
// 00816c77  7422                 je 0x816c9b
// 00816c79  8b542404             mov edx, dword ptr [esp + 4]
// 00816c7d  8b442408             mov eax, dword ptr [esp + 8]
// 00816c81  89542420             mov dword ptr [esp + 0x20], edx
// 00816c85  8d54240c             lea edx, [esp + 0xc]
// 00816c89  52                   push edx
// 00816c8a  89442428             mov dword ptr [esp + 0x28], eax
// 00816c8e  c744241400020000     mov dword ptr [esp + 0x14], 0x200
// 00816c96  e845f6ffff           call 0x8162e0
// 00816c9b  8b442430             mov eax, dword ptr [esp + 0x30]
// 00816c9f  8b0da85dc200         mov ecx, dword ptr [0xc25da8]
// 00816ca5  56                   push esi
// 00816ca6  50                   push eax
// 00816ca7  6a00                 push 0
// 00816ca9  51                   push ecx
// 00816caa  ff1524ba9e00         call dword ptr [0x9eba24]
// 00816cb0  5e                   pop esi
// 00816cb1  83c424               add esp, 0x24
// 00816cb4  c20c00               ret 0xc
// 00816cb7  8b542430             mov edx, dword ptr [esp + 0x30]
// 00816cbb  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00816cbf  52                   push edx
// 00816cc0  8b15a85dc200         mov edx, dword ptr [0xc25da8]
// 00816cc6  51                   push ecx
// 00816cc7  50                   push eax
// 00816cc8  52                   push edx
// 00816cc9  ff1524ba9e00         call dword ptr [0x9eba24]
// 00816ccf  83c424               add esp, 0x24
// 00816cd2  c20c00               ret 0xc
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?MouseProc@CXTPToolTipContextToolTip@@KGJHIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
