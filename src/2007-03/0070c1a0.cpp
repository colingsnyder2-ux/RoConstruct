// from server: 100% by auto
// roc 2007-03 0070c1a0  unit: seg_00700000  size: 362 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0070c1a0
//
// 0070c1a0  56                   push esi
// 0070c1a1  8bf1                 mov esi, ecx
// 0070c1a3  57                   push edi
// 0070c1a4  8d4e04               lea ecx, [esi + 4]
// 0070c1a7  c706c4de7d00         mov dword ptr [esi], 0x7ddec4
// 0070c1ad  e84e83f4ff           call 0x654500
// 0070c1b2  8d4e24               lea ecx, [esi + 0x24]
// 0070c1b5  e84683f4ff           call 0x654500
// 0070c1ba  8d4e44               lea ecx, [esi + 0x44]
// 0070c1bd  e81e83f4ff           call 0x6544e0
// 0070c1c2  8d4e50               lea ecx, [esi + 0x50]
// 0070c1c5  e81683f4ff           call 0x6544e0
// 0070c1ca  8d4e5c               lea ecx, [esi + 0x5c]
// 0070c1cd  e80e83f4ff           call 0x6544e0
// 0070c1d2  8d4e68               lea ecx, [esi + 0x68]
// 0070c1d5  e80683f4ff           call 0x6544e0
// 0070c1da  8d4e74               lea ecx, [esi + 0x74]
// 0070c1dd  e8fe82f4ff           call 0x6544e0
// 0070c1e2  8d8e80000000         lea ecx, [esi + 0x80]
// 0070c1e8  e8f382f4ff           call 0x6544e0
// 0070c1ed  8d8e8c000000         lea ecx, [esi + 0x8c]
// 0070c1f3  e8e882f4ff           call 0x6544e0
// 0070c1f8  8d8e98000000         lea ecx, [esi + 0x98]
// 0070c1fe  e8dd82f4ff           call 0x6544e0
// 0070c203  8d8ea4000000         lea ecx, [esi + 0xa4]
// 0070c209  e8d282f4ff           call 0x6544e0
// 0070c20e  8d8eb0000000         lea ecx, [esi + 0xb0]
// 0070c214  e8c782f4ff           call 0x6544e0
// 0070c219  8d8ebc000000         lea ecx, [esi + 0xbc]
// 0070c21f  e8bc82f4ff           call 0x6544e0
// 0070c224  8d8ec8000000         lea ecx, [esi + 0xc8]
// 0070c22a  e8b182f4ff           call 0x6544e0
// 0070c22f  8d8ed4000000         lea ecx, [esi + 0xd4]
// 0070c235  e8a682f4ff           call 0x6544e0
// 0070c23a  8dbee0000000         lea edi, [esi + 0xe0]
// 0070c240  8bcf                 mov ecx, edi
// 0070c242  e8b982f4ff           call 0x654500
// 0070c247  8d4f20               lea ecx, [edi + 0x20]
// 0070c24a  e8b182f4ff           call 0x654500
// 0070c24f  8dbe20010000         lea edi, [esi + 0x120]
// 0070c255  8bcf                 mov ecx, edi
// 0070c257  e88482f4ff           call 0x6544e0
// 0070c25c  8d4f0c               lea ecx, [edi + 0xc]
// 0070c25f  e87c82f4ff           call 0x6544e0
// 0070c264  8d4f18               lea ecx, [edi + 0x18]
// 0070c267  e87482f4ff           call 0x6544e0
// 0070c26c  8dbe44010000         lea edi, [esi + 0x144]
// 0070c272  8bcf                 mov ecx, edi
// 0070c274  e86782f4ff           call 0x6544e0
// 0070c279  8d4f0c               lea ecx, [edi + 0xc]
// 0070c27c  e85f82f4ff           call 0x6544e0
// 0070c281  8d4f18               lea ecx, [edi + 0x18]
// 0070c284  e85782f4ff           call 0x6544e0
// 0070c289  8d4f24               lea ecx, [edi + 0x24]
// 0070c28c  e84f82f4ff           call 0x6544e0
// 0070c291  8dbe74010000         lea edi, [esi + 0x174]
// 0070c297  8bcf                 mov ecx, edi
// 0070c299  e84282f4ff           call 0x6544e0
// 0070c29e  8d4f0c               lea ecx, [edi + 0xc]
// 0070c2a1  e83a82f4ff           call 0x6544e0
// 0070c2a6  8d4f18               lea ecx, [edi + 0x18]
// 0070c2a9  e83282f4ff           call 0x6544e0
// 0070c2ae  8d4f24               lea ecx, [edi + 0x24]
// 0070c2b1  e82a82f4ff           call 0x6544e0
// 0070c2b6  8d4f30               lea ecx, [edi + 0x30]
// 0070c2b9  e82282f4ff           call 0x6544e0
// 0070c2be  8d4f3c               lea ecx, [edi + 0x3c]
// 0070c2c1  e81a82f4ff           call 0x6544e0
// 0070c2c6  8dbebc010000         lea edi, [esi + 0x1bc]
// 0070c2cc  8bcf                 mov ecx, edi
// 0070c2ce  e80d82f4ff           call 0x6544e0
// 0070c2d3  8d4f0c               lea ecx, [edi + 0xc]
// 0070c2d6  e80582f4ff           call 0x6544e0
// 0070c2db  8d4f18               lea ecx, [edi + 0x18]
// 0070c2de  e8fd81f4ff           call 0x6544e0
// 0070c2e3  8d4f24               lea ecx, [edi + 0x24]
// 0070c2e6  e8f581f4ff           call 0x6544e0
// 0070c2eb  8d4f30               lea ecx, [edi + 0x30]
// 0070c2ee  e8ed81f4ff           call 0x6544e0
// 0070c2f3  8d4f3c               lea ecx, [edi + 0x3c]
// 0070c2f6  e8e581f4ff           call 0x6544e0
// 0070c2fb  5f                   pop edi
// 0070c2fc  c7860402000000000000 mov dword ptr [esi + 0x204], 0
// 0070c306  8bc6                 mov eax, esi
// 0070c308  5e                   pop esi
// 0070c309  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ??0CColorSet@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
