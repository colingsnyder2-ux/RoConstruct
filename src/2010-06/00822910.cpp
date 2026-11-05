// from server: 100% by auto
// roc 2010-06 00822910  unit: CXTPResourceManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00822910
//
// 00822910  51                   push ecx
// 00822911  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00822915  8d0424               lea eax, [esp]
// 00822918  50                   push eax
// 00822919  6860288200           push 0x822860
// 0082291e  51                   push ecx
// 0082291f  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00822927  ff1550a29e00         call dword ptr [0x9ea250]
// 0082292d  668b0424             mov ax, word ptr [esp]
// 00822931  59                   pop ecx
// 00822932  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPResourceManager.cpp (function ?GetResourceLanguage@CXTPResourceManager@@SAGPAUHINSTANCE__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPResourceManager.cpp
