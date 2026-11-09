// from server: 100% by auto
// roc 2010-06 007ec5c0  unit: CXTPControls  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ec5c0
//
// 007ec5c0  56                   push esi
// 007ec5c1  57                   push edi
// 007ec5c2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007ec5c6  8b4720               mov eax, dword ptr [edi + 0x20]
// 007ec5c9  50                   push eax
// 007ec5ca  8bf1                 mov esi, ecx
// 007ec5cc  ff1528bc9e00         call dword ptr [0x9ebc28]
// 007ec5d2  85c0                 test eax, eax
// 007ec5d4  7427                 je 0x7ec5fd
// 007ec5d6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007ec5da  8b542410             mov edx, dword ptr [esp + 0x10]
// 007ec5de  51                   push ecx
// 007ec5df  52                   push edx
// 007ec5e0  8bce                 mov ecx, esi
// 007ec5e2  e879feffff           call 0x7ec460
// 007ec5e7  85c0                 test eax, eax
// 007ec5e9  7412                 je 0x7ec5fd
// 007ec5eb  56                   push esi
// 007ec5ec  8bcf                 mov ecx, edi
// 007ec5ee  e8090b1900           call 0x97d0fc
// 007ec5f3  5f                   pop edi
// 007ec5f4  b801000000           mov eax, 1
// 007ec5f9  5e                   pop esi
// 007ec5fa  c20c00               ret 0xc
// 007ec5fd  5f                   pop edi
// 007ec5fe  33c0                 xor eax, eax
// 007ec600  5e                   pop esi
// 007ec601  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTWindowPos.cpp (function ?LoadWindowPos@CXTWindowPos@@QAEHPAVCWnd@@PBD1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTWindowPos.cpp
