// from server: 100% by auto
// roc 2010-06 00822860  unit: CXTPResourceManager  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00822860
//
// 00822860  56                   push esi
// 00822861  8b742410             mov esi, dword ptr [esp + 0x10]
// 00822865  85f6                 test esi, esi
// 00822867  7506                 jne 0x82286f
// 00822869  33c0                 xor eax, eax
// 0082286b  5e                   pop esi
// 0082286c  c20c00               ret 0xc
// 0082286f  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00822873  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00822877  56                   push esi
// 00822878  6870278200           push 0x822770
// 0082287d  50                   push eax
// 0082287e  51                   push ecx
// 0082287f  ff1554a29e00         call dword ptr [0x9ea254]
// 00822885  0fb706               movzx eax, word ptr [esi]
// 00822888  6685c0               test ax, ax
// 0082288b  7509                 jne 0x822896
// 0082288d  b801000000           mov eax, 1
// 00822892  5e                   pop esi
// 00822893  c20c00               ret 0xc
// 00822896  33c9                 xor ecx, ecx
// 00822898  ba09040000           mov edx, 0x409
// 0082289d  663bc2               cmp ax, dx
// 008228a0  0f94c1               sete cl
// 008228a3  5e                   pop esi
// 008228a4  8bc1                 mov eax, ecx
// 008228a6  c20c00               ret 0xc
// library xtp-13.2.1/Source\Common\XTPResourceManager.cpp (function ?EnumResTypeProc@CXTPResourceManager@@KGHPAUHINSTANCE__@@PADJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPResourceManager.cpp
