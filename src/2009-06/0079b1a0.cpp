// from server: 100% by auto
// roc 2009-06 0079b1a0  unit: CXTPResourceManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079b1a0
//
// 0079b1a0  51                   push ecx
// 0079b1a1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0079b1a5  8d0424               lea eax, [esp]
// 0079b1a8  50                   push eax
// 0079b1a9  68f0b07900           push 0x79b0f0
// 0079b1ae  51                   push ecx
// 0079b1af  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0079b1b7  ff1580e38900         call dword ptr [0x89e380]
// 0079b1bd  668b0424             mov ax, word ptr [esp]
// 0079b1c1  59                   pop ecx
// 0079b1c2  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?GetResourceLanguage@CXTPResourceManager@@SAGPAUHINSTANCE__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
