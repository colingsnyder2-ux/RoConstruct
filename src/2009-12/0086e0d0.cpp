// from server: 100% by auto
// roc 2009-12 0086e0d0  unit: CXTPResourceManager  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086e0d0
//
// 0086e0d0  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0086e0d4  85c9                 test ecx, ecx
// 0086e0d6  7505                 jne 0x86e0dd
// 0086e0d8  33c0                 xor eax, eax
// 0086e0da  c21400               ret 0x14
// 0086e0dd  668b442410           mov ax, word ptr [esp + 0x10]
// 0086e0e2  6685c0               test ax, ax
// 0086e0e5  7508                 jne 0x86e0ef
// 0086e0e7  b801000000           mov eax, 1
// 0086e0ec  c21400               ret 0x14
// 0086e0ef  668901               mov word ptr [ecx], ax
// 0086e0f2  33d2                 xor edx, edx
// 0086e0f4  b909040000           mov ecx, 0x409
// 0086e0f9  663bc1               cmp ax, cx
// 0086e0fc  0f94c2               sete dl
// 0086e0ff  8bc2                 mov eax, edx
// 0086e101  c21400               ret 0x14
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?EnumResLangProc@CXTPResourceManager@@KGHPAUHINSTANCE__@@PBD1GJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
