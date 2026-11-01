// from server: 100% by auto
// roc 2009-06 0079a970  unit: CXTPResourceManager  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079a970
//
// 0079a970  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0079a974  85c9                 test ecx, ecx
// 0079a976  7505                 jne 0x79a97d
// 0079a978  33c0                 xor eax, eax
// 0079a97a  c21400               ret 0x14
// 0079a97d  668b442410           mov ax, word ptr [esp + 0x10]
// 0079a982  6685c0               test ax, ax
// 0079a985  7508                 jne 0x79a98f
// 0079a987  b801000000           mov eax, 1
// 0079a98c  c21400               ret 0x14
// 0079a98f  668901               mov word ptr [ecx], ax
// 0079a992  33d2                 xor edx, edx
// 0079a994  b909040000           mov ecx, 0x409
// 0079a999  663bc1               cmp ax, cx
// 0079a99c  0f94c2               sete dl
// 0079a99f  8bc2                 mov eax, edx
// 0079a9a1  c21400               ret 0x14
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?EnumResLangProc@CXTPResourceManager@@KGHPAUHINSTANCE__@@PBD1GJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
