// from server: 100% by auto
// roc 2009-12 0086e850  unit: CXTPResourceManager  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086e850
//
// 0086e850  56                   push esi
// 0086e851  8b742410             mov esi, dword ptr [esp + 0x10]
// 0086e855  85f6                 test esi, esi
// 0086e857  7506                 jne 0x86e85f
// 0086e859  33c0                 xor eax, eax
// 0086e85b  5e                   pop esi
// 0086e85c  c20c00               ret 0xc
// 0086e85f  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0086e863  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0086e867  56                   push esi
// 0086e868  6860e78600           push 0x86e760
// 0086e86d  50                   push eax
// 0086e86e  51                   push ecx
// 0086e86f  ff1538b39800         call dword ptr [0x98b338]
// 0086e875  0fb706               movzx eax, word ptr [esi]
// 0086e878  6685c0               test ax, ax
// 0086e87b  7509                 jne 0x86e886
// 0086e87d  b801000000           mov eax, 1
// 0086e882  5e                   pop esi
// 0086e883  c20c00               ret 0xc
// 0086e886  33c9                 xor ecx, ecx
// 0086e888  ba09040000           mov edx, 0x409
// 0086e88d  663bc2               cmp ax, dx
// 0086e890  0f94c1               sete cl
// 0086e893  5e                   pop esi
// 0086e894  8bc1                 mov eax, ecx
// 0086e896  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?EnumResTypeProc@CXTPResourceManager@@KGHPAUHINSTANCE__@@PADJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
