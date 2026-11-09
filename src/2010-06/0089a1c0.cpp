// from server: 100% by auto
// roc 2010-06 0089a1c0  unit: CXTCaptionButton  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089a1c0
//
// 0089a1c0  8b442404             mov eax, dword ptr [esp + 4]
// 0089a1c4  56                   push esi
// 0089a1c5  8bf1                 mov esi, ecx
// 0089a1c7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0089a1cb  898e88000000         mov dword ptr [esi + 0x88], ecx
// 0089a1d1  8b8e9c000000         mov ecx, dword ptr [esi + 0x9c]
// 0089a1d7  898684000000         mov dword ptr [esi + 0x84], eax
// 0089a1dd  85c9                 test ecx, ecx
// 0089a1df  740f                 je 0x89a1f0
// 0089a1e1  e836ddf0ff           call 0x7a7f1c
// 0089a1e6  c7869c00000000000000 mov dword ptr [esi + 0x9c], 0
// 0089a1f0  8b4620               mov eax, dword ptr [esi + 0x20]
// 0089a1f3  8b542410             mov edx, dword ptr [esp + 0x10]
// 0089a1f7  50                   push eax
// 0089a1f8  89969c000000         mov dword ptr [esi + 0x9c], edx
// 0089a1fe  ff1528bc9e00         call dword ptr [0x9ebc28]
// 0089a204  85c0                 test eax, eax
// 0089a206  7415                 je 0x89a21d
// 0089a208  837c241400           cmp dword ptr [esp + 0x14], 0
// 0089a20d  740e                 je 0x89a21d
// 0089a20f  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0089a212  6a01                 push 1
// 0089a214  6a00                 push 0
// 0089a216  51                   push ecx
// 0089a217  ff1578ba9e00         call dword ptr [0x9eba78]
// 0089a21d  b801000000           mov eax, 1
// 0089a222  5e                   pop esi
// 0089a223  c21000               ret 0x10
// library xtp-13.2.1/Source\Controls\XTButton.cpp (function ?SetIcon@CXTButton@@QAEHVCSize@@PAVCXTPImageManagerIcon@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButton.cpp
