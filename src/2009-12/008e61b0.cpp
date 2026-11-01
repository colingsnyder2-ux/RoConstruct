// from server: 100% by auto
// roc 2009-12 008e61b0  unit: CXTCaptionButton  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e61b0
//
// 008e61b0  8b442404             mov eax, dword ptr [esp + 4]
// 008e61b4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008e61b8  56                   push esi
// 008e61b9  8bf1                 mov esi, ecx
// 008e61bb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008e61bf  898e90000000         mov dword ptr [esi + 0x90], ecx
// 008e61c5  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008e61c8  89868c000000         mov dword ptr [esi + 0x8c], eax
// 008e61ce  8b442414             mov eax, dword ptr [esp + 0x14]
// 008e61d2  51                   push ecx
// 008e61d3  899694000000         mov dword ptr [esi + 0x94], edx
// 008e61d9  898698000000         mov dword ptr [esi + 0x98], eax
// 008e61df  ff1584cc9800         call dword ptr [0x98cc84]
// 008e61e5  85c0                 test eax, eax
// 008e61e7  7415                 je 0x8e61fe
// 008e61e9  837c241800           cmp dword ptr [esp + 0x18], 0
// 008e61ee  740e                 je 0x8e61fe
// 008e61f0  8b5620               mov edx, dword ptr [esi + 0x20]
// 008e61f3  6a01                 push 1
// 008e61f5  6a00                 push 0
// 008e61f7  52                   push edx
// 008e61f8  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008e61fe  c7467801000000       mov dword ptr [esi + 0x78], 1
// 008e6205  b801000000           mov eax, 1
// 008e620a  5e                   pop esi
// 008e620b  c21400               ret 0x14
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?SetTextAndImagePos@CXTButton@@UAEHVCPoint@@0H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
