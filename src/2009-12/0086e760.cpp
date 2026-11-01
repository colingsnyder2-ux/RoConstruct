// from server: 100% by auto
// roc 2009-12 0086e760  unit: CXTPResourceManager  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086e760
//
// 0086e760  56                   push esi
// 0086e761  8b742414             mov esi, dword ptr [esp + 0x14]
// 0086e765  85f6                 test esi, esi
// 0086e767  7506                 jne 0x86e76f
// 0086e769  33c0                 xor eax, eax
// 0086e76b  5e                   pop esi
// 0086e76c  c21000               ret 0x10
// 0086e76f  8b442410             mov eax, dword ptr [esp + 0x10]
// 0086e773  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0086e777  8b542408             mov edx, dword ptr [esp + 8]
// 0086e77b  56                   push esi
// 0086e77c  68d0e08600           push 0x86e0d0
// 0086e781  50                   push eax
// 0086e782  51                   push ecx
// 0086e783  52                   push edx
// 0086e784  ff1534b39800         call dword ptr [0x98b334]
// 0086e78a  0fb706               movzx eax, word ptr [esi]
// 0086e78d  6685c0               test ax, ax
// 0086e790  7509                 jne 0x86e79b
// 0086e792  b801000000           mov eax, 1
// 0086e797  5e                   pop esi
// 0086e798  c21000               ret 0x10
// 0086e79b  33d2                 xor edx, edx
// 0086e79d  b909040000           mov ecx, 0x409
// 0086e7a2  663bc1               cmp ax, cx
// 0086e7a5  0f94c2               sete dl
// 0086e7a8  5e                   pop esi
// 0086e7a9  8bc2                 mov eax, edx
// 0086e7ab  c21000               ret 0x10
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?EnumResNameProc@CXTPResourceManager@@KGHPAUHINSTANCE__@@PBDPADJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
