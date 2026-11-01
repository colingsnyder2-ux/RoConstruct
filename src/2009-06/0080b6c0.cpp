// from server: 100% by auto
// roc 2009-06 0080b6c0  unit: CXTCaptionButton  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080b6c0
//
// 0080b6c0  8b442404             mov eax, dword ptr [esp + 4]
// 0080b6c4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0080b6c8  56                   push esi
// 0080b6c9  8bf1                 mov esi, ecx
// 0080b6cb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0080b6cf  898e90000000         mov dword ptr [esi + 0x90], ecx
// 0080b6d5  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0080b6d8  89868c000000         mov dword ptr [esi + 0x8c], eax
// 0080b6de  8b442414             mov eax, dword ptr [esp + 0x14]
// 0080b6e2  51                   push ecx
// 0080b6e3  899694000000         mov dword ptr [esi + 0x94], edx
// 0080b6e9  898698000000         mov dword ptr [esi + 0x98], eax
// 0080b6ef  ff15e0ed8900         call dword ptr [0x89ede0]
// 0080b6f5  85c0                 test eax, eax
// 0080b6f7  7415                 je 0x80b70e
// 0080b6f9  837c241800           cmp dword ptr [esp + 0x18], 0
// 0080b6fe  740e                 je 0x80b70e
// 0080b700  8b5620               mov edx, dword ptr [esi + 0x20]
// 0080b703  6a01                 push 1
// 0080b705  6a00                 push 0
// 0080b707  52                   push edx
// 0080b708  ff157cee8900         call dword ptr [0x89ee7c]
// 0080b70e  c7467801000000       mov dword ptr [esi + 0x78], 1
// 0080b715  b801000000           mov eax, 1
// 0080b71a  5e                   pop esi
// 0080b71b  c21400               ret 0x14
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?SetTextAndImagePos@CXTButton@@UAEHVCPoint@@0H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
