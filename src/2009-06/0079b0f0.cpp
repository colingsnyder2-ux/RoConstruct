// from server: 100% by auto
// roc 2009-06 0079b0f0  unit: CXTPResourceManager  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079b0f0
//
// 0079b0f0  56                   push esi
// 0079b0f1  8b742410             mov esi, dword ptr [esp + 0x10]
// 0079b0f5  85f6                 test esi, esi
// 0079b0f7  7506                 jne 0x79b0ff
// 0079b0f9  33c0                 xor eax, eax
// 0079b0fb  5e                   pop esi
// 0079b0fc  c20c00               ret 0xc
// 0079b0ff  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0079b103  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0079b107  56                   push esi
// 0079b108  6800b07900           push 0x79b000
// 0079b10d  50                   push eax
// 0079b10e  51                   push ecx
// 0079b10f  ff157ce38900         call dword ptr [0x89e37c]
// 0079b115  0fb706               movzx eax, word ptr [esi]
// 0079b118  6685c0               test ax, ax
// 0079b11b  7509                 jne 0x79b126
// 0079b11d  b801000000           mov eax, 1
// 0079b122  5e                   pop esi
// 0079b123  c20c00               ret 0xc
// 0079b126  33c9                 xor ecx, ecx
// 0079b128  ba09040000           mov edx, 0x409
// 0079b12d  663bc2               cmp ax, dx
// 0079b130  0f94c1               sete cl
// 0079b133  5e                   pop esi
// 0079b134  8bc1                 mov eax, ecx
// 0079b136  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?EnumResTypeProc@CXTPResourceManager@@KGHPAUHINSTANCE__@@PADJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
