// from server: 100% by auto
// roc 2007-03 00659e40  unit: seg_00650000  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00659e40
//
// 00659e40  56                   push esi
// 00659e41  57                   push edi
// 00659e42  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00659e46  8b4720               mov eax, dword ptr [edi + 0x20]
// 00659e49  50                   push eax
// 00659e4a  8bf1                 mov esi, ecx
// 00659e4c  ff1574ed7700         call dword ptr [0x77ed74]
// 00659e52  85c0                 test eax, eax
// 00659e54  7427                 je 0x659e7d
// 00659e56  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00659e5a  8b542410             mov edx, dword ptr [esp + 0x10]
// 00659e5e  51                   push ecx
// 00659e5f  52                   push edx
// 00659e60  8bce                 mov ecx, esi
// 00659e62  e879feffff           call 0x659ce0
// 00659e67  85c0                 test eax, eax
// 00659e69  7412                 je 0x659e7d
// 00659e6b  56                   push esi
// 00659e6c  8bcf                 mov ecx, edi
// 00659e6e  e8a90f0e00           call 0x73ae1c
// 00659e73  5f                   pop edi
// 00659e74  b801000000           mov eax, 1
// 00659e79  5e                   pop esi
// 00659e7a  c20c00               ret 0xc
// 00659e7d  5f                   pop edi
// 00659e7e  33c0                 xor eax, eax
// 00659e80  5e                   pop esi
// 00659e81  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Util\XTPWindowPos.cpp (function ?LoadWindowPos@CXTPWindowPos@@QAEHPAVCWnd@@PBD1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPWindowPos.cpp
