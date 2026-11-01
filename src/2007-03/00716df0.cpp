// from server: 100% by auto
// roc 2007-03 00716df0  unit: seg_00710000  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00716df0
//
// 00716df0  8b442408             mov eax, dword ptr [esp + 8]
// 00716df4  56                   push esi
// 00716df5  57                   push edi
// 00716df6  8bf1                 mov esi, ecx
// 00716df8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00716dfc  8b5620               mov edx, dword ptr [esi + 0x20]
// 00716dff  50                   push eax
// 00716e00  51                   push ecx
// 00716e01  6828010000           push 0x128
// 00716e06  52                   push edx
// 00716e07  ff15fcec7700         call dword ptr [0x77ecfc]
// 00716e0d  6a00                 push 0
// 00716e0f  8bf8                 mov edi, eax
// 00716e11  8b4620               mov eax, dword ptr [esi + 0x20]
// 00716e14  6a00                 push 0
// 00716e16  50                   push eax
// 00716e17  ff1554ee7700         call dword ptr [0x77ee54]
// 00716e1d  8bc7                 mov eax, edi
// 00716e1f  5f                   pop edi
// 00716e20  5e                   pop esi
// 00716e21  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnUpdateUIState@CXTButton@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
