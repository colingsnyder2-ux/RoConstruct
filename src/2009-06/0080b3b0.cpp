// from server: 100% by auto
// roc 2009-06 0080b3b0  unit: CXTCaptionButton  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080b3b0
//
// 0080b3b0  8b442404             mov eax, dword ptr [esp + 4]
// 0080b3b4  56                   push esi
// 0080b3b5  8bf1                 mov esi, ecx
// 0080b3b7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0080b3bb  898e88000000         mov dword ptr [esi + 0x88], ecx
// 0080b3c1  8b8e9c000000         mov ecx, dword ptr [esi + 0x9c]
// 0080b3c7  898684000000         mov dword ptr [esi + 0x84], eax
// 0080b3cd  85c9                 test ecx, ecx
// 0080b3cf  740f                 je 0x80b3e0
// 0080b3d1  e8d2dbf0ff           call 0x718fa8
// 0080b3d6  c7869c00000000000000 mov dword ptr [esi + 0x9c], 0
// 0080b3e0  8b4620               mov eax, dword ptr [esi + 0x20]
// 0080b3e3  8b542410             mov edx, dword ptr [esp + 0x10]
// 0080b3e7  50                   push eax
// 0080b3e8  89969c000000         mov dword ptr [esi + 0x9c], edx
// 0080b3ee  ff15e0ed8900         call dword ptr [0x89ede0]
// 0080b3f4  85c0                 test eax, eax
// 0080b3f6  7415                 je 0x80b40d
// 0080b3f8  837c241400           cmp dword ptr [esp + 0x14], 0
// 0080b3fd  740e                 je 0x80b40d
// 0080b3ff  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0080b402  6a01                 push 1
// 0080b404  6a00                 push 0
// 0080b406  51                   push ecx
// 0080b407  ff157cee8900         call dword ptr [0x89ee7c]
// 0080b40d  b801000000           mov eax, 1
// 0080b412  5e                   pop esi
// 0080b413  c21000               ret 0x10
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?SetIcon@CXTButton@@QAEHVCSize@@PAVCXTPImageManagerIcon@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
