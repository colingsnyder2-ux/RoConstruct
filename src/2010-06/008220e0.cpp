// from server: 100% by auto
// roc 2010-06 008220e0  unit: CXTPResourceManager  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008220e0
//
// 008220e0  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008220e4  85c9                 test ecx, ecx
// 008220e6  7505                 jne 0x8220ed
// 008220e8  33c0                 xor eax, eax
// 008220ea  c21400               ret 0x14
// 008220ed  668b442410           mov ax, word ptr [esp + 0x10]
// 008220f2  6685c0               test ax, ax
// 008220f5  7508                 jne 0x8220ff
// 008220f7  b801000000           mov eax, 1
// 008220fc  c21400               ret 0x14
// 008220ff  668901               mov word ptr [ecx], ax
// 00822102  33d2                 xor edx, edx
// 00822104  b909040000           mov ecx, 0x409
// 00822109  663bc1               cmp ax, cx
// 0082210c  0f94c2               sete dl
// 0082210f  8bc2                 mov eax, edx
// 00822111  c21400               ret 0x14
// library xtp-13.2.1/Source\Common\XTPResourceManager.cpp (function ?EnumResLangProc@CXTPResourceManager@@KGHPAUHINSTANCE__@@PBD1GJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPResourceManager.cpp
