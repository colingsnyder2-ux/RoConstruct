// from server: 100% by auto
// roc 2010-06 0089a4d0  unit: CXTCaptionButton  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089a4d0
//
// 0089a4d0  8b442404             mov eax, dword ptr [esp + 4]
// 0089a4d4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0089a4d8  56                   push esi
// 0089a4d9  8bf1                 mov esi, ecx
// 0089a4db  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0089a4df  898e90000000         mov dword ptr [esi + 0x90], ecx
// 0089a4e5  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0089a4e8  89868c000000         mov dword ptr [esi + 0x8c], eax
// 0089a4ee  8b442414             mov eax, dword ptr [esp + 0x14]
// 0089a4f2  51                   push ecx
// 0089a4f3  899694000000         mov dword ptr [esi + 0x94], edx
// 0089a4f9  898698000000         mov dword ptr [esi + 0x98], eax
// 0089a4ff  ff1528bc9e00         call dword ptr [0x9ebc28]
// 0089a505  85c0                 test eax, eax
// 0089a507  7415                 je 0x89a51e
// 0089a509  837c241800           cmp dword ptr [esp + 0x18], 0
// 0089a50e  740e                 je 0x89a51e
// 0089a510  8b5620               mov edx, dword ptr [esi + 0x20]
// 0089a513  6a01                 push 1
// 0089a515  6a00                 push 0
// 0089a517  52                   push edx
// 0089a518  ff1578ba9e00         call dword ptr [0x9eba78]
// 0089a51e  c7467801000000       mov dword ptr [esi + 0x78], 1
// 0089a525  b801000000           mov eax, 1
// 0089a52a  5e                   pop esi
// 0089a52b  c21400               ret 0x14
// library xtp-13.2.1/Source\Controls\XTButton.cpp (function ?SetTextAndImagePos@CXTButton@@UAEHVCPoint@@0H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButton.cpp
