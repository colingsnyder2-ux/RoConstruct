// from server: 100% by auto
// roc 2011-06 008f4960  unit: CXTPTabPaintManager::CColorSetWinXP  size: 362 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f4960
//
// 008f4960  56                   push esi
// 008f4961  8bf1                 mov esi, ecx
// 008f4963  57                   push edi
// 008f4964  8d4e04               lea ecx, [esi + 4]
// 008f4967  c70600aaad00         mov dword ptr [esi], 0xadaa00
// 008f496d  e86efff4ff           call 0x8448e0
// 008f4972  8d4e24               lea ecx, [esi + 0x24]
// 008f4975  e866fff4ff           call 0x8448e0
// 008f497a  8d4e44               lea ecx, [esi + 0x44]
// 008f497d  e83efff4ff           call 0x8448c0
// 008f4982  8d4e50               lea ecx, [esi + 0x50]
// 008f4985  e836fff4ff           call 0x8448c0
// 008f498a  8d4e5c               lea ecx, [esi + 0x5c]
// 008f498d  e82efff4ff           call 0x8448c0
// 008f4992  8d4e68               lea ecx, [esi + 0x68]
// 008f4995  e826fff4ff           call 0x8448c0
// 008f499a  8d4e74               lea ecx, [esi + 0x74]
// 008f499d  e81efff4ff           call 0x8448c0
// 008f49a2  8d8e80000000         lea ecx, [esi + 0x80]
// 008f49a8  e813fff4ff           call 0x8448c0
// 008f49ad  8d8e8c000000         lea ecx, [esi + 0x8c]
// 008f49b3  e808fff4ff           call 0x8448c0
// 008f49b8  8d8e98000000         lea ecx, [esi + 0x98]
// 008f49be  e8fdfef4ff           call 0x8448c0
// 008f49c3  8d8ea4000000         lea ecx, [esi + 0xa4]
// 008f49c9  e8f2fef4ff           call 0x8448c0
// 008f49ce  8d8eb0000000         lea ecx, [esi + 0xb0]
// 008f49d4  e8e7fef4ff           call 0x8448c0
// 008f49d9  8d8ebc000000         lea ecx, [esi + 0xbc]
// 008f49df  e8dcfef4ff           call 0x8448c0
// 008f49e4  8d8ec8000000         lea ecx, [esi + 0xc8]
// 008f49ea  e8d1fef4ff           call 0x8448c0
// 008f49ef  8d8ed4000000         lea ecx, [esi + 0xd4]
// 008f49f5  e8c6fef4ff           call 0x8448c0
// 008f49fa  8dbee0000000         lea edi, [esi + 0xe0]
// 008f4a00  8bcf                 mov ecx, edi
// 008f4a02  e8d9fef4ff           call 0x8448e0
// 008f4a07  8d4f20               lea ecx, [edi + 0x20]
// 008f4a0a  e8d1fef4ff           call 0x8448e0
// 008f4a0f  8dbe20010000         lea edi, [esi + 0x120]
// 008f4a15  8bcf                 mov ecx, edi
// 008f4a17  e8a4fef4ff           call 0x8448c0
// 008f4a1c  8d4f0c               lea ecx, [edi + 0xc]
// 008f4a1f  e89cfef4ff           call 0x8448c0
// 008f4a24  8d4f18               lea ecx, [edi + 0x18]
// 008f4a27  e894fef4ff           call 0x8448c0
// 008f4a2c  8dbe44010000         lea edi, [esi + 0x144]
// 008f4a32  8bcf                 mov ecx, edi
// 008f4a34  e887fef4ff           call 0x8448c0
// 008f4a39  8d4f0c               lea ecx, [edi + 0xc]
// 008f4a3c  e87ffef4ff           call 0x8448c0
// 008f4a41  8d4f18               lea ecx, [edi + 0x18]
// 008f4a44  e877fef4ff           call 0x8448c0
// 008f4a49  8d4f24               lea ecx, [edi + 0x24]
// 008f4a4c  e86ffef4ff           call 0x8448c0
// 008f4a51  8dbe74010000         lea edi, [esi + 0x174]
// 008f4a57  8bcf                 mov ecx, edi
// 008f4a59  e862fef4ff           call 0x8448c0
// 008f4a5e  8d4f0c               lea ecx, [edi + 0xc]
// 008f4a61  e85afef4ff           call 0x8448c0
// 008f4a66  8d4f18               lea ecx, [edi + 0x18]
// 008f4a69  e852fef4ff           call 0x8448c0
// 008f4a6e  8d4f24               lea ecx, [edi + 0x24]
// 008f4a71  e84afef4ff           call 0x8448c0
// 008f4a76  8d4f30               lea ecx, [edi + 0x30]
// 008f4a79  e842fef4ff           call 0x8448c0
// 008f4a7e  8d4f3c               lea ecx, [edi + 0x3c]
// 008f4a81  e83afef4ff           call 0x8448c0
// 008f4a86  8dbebc010000         lea edi, [esi + 0x1bc]
// 008f4a8c  8bcf                 mov ecx, edi
// 008f4a8e  e82dfef4ff           call 0x8448c0
// 008f4a93  8d4f0c               lea ecx, [edi + 0xc]
// 008f4a96  e825fef4ff           call 0x8448c0
// 008f4a9b  8d4f18               lea ecx, [edi + 0x18]
// 008f4a9e  e81dfef4ff           call 0x8448c0
// 008f4aa3  8d4f24               lea ecx, [edi + 0x24]
// 008f4aa6  e815fef4ff           call 0x8448c0
// 008f4aab  8d4f30               lea ecx, [edi + 0x30]
// 008f4aae  e80dfef4ff           call 0x8448c0
// 008f4ab3  8d4f3c               lea ecx, [edi + 0x3c]
// 008f4ab6  e805fef4ff           call 0x8448c0
// 008f4abb  5f                   pop edi
// 008f4abc  c7860402000000000000 mov dword ptr [esi + 0x204], 0
// 008f4ac6  8bc6                 mov eax, esi
// 008f4ac8  5e                   pop esi
// 008f4ac9  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ??0CColorSet@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
