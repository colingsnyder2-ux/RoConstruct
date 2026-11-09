// from server: 100% by auto
// roc 2010-06 0089be00  unit: CXTPTabPaintManager::CColorSetWinXP  size: 362 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089be00
//
// 0089be00  56                   push esi
// 0089be01  8bf1                 mov esi, ecx
// 0089be03  57                   push edi
// 0089be04  8d4e04               lea ecx, [esi + 4]
// 0089be07  c706d80ea700         mov dword ptr [esi], 0xa70ed8
// 0089be0d  e8ce71f4ff           call 0x7e2fe0
// 0089be12  8d4e24               lea ecx, [esi + 0x24]
// 0089be15  e8c671f4ff           call 0x7e2fe0
// 0089be1a  8d4e44               lea ecx, [esi + 0x44]
// 0089be1d  e89e71f4ff           call 0x7e2fc0
// 0089be22  8d4e50               lea ecx, [esi + 0x50]
// 0089be25  e89671f4ff           call 0x7e2fc0
// 0089be2a  8d4e5c               lea ecx, [esi + 0x5c]
// 0089be2d  e88e71f4ff           call 0x7e2fc0
// 0089be32  8d4e68               lea ecx, [esi + 0x68]
// 0089be35  e88671f4ff           call 0x7e2fc0
// 0089be3a  8d4e74               lea ecx, [esi + 0x74]
// 0089be3d  e87e71f4ff           call 0x7e2fc0
// 0089be42  8d8e80000000         lea ecx, [esi + 0x80]
// 0089be48  e87371f4ff           call 0x7e2fc0
// 0089be4d  8d8e8c000000         lea ecx, [esi + 0x8c]
// 0089be53  e86871f4ff           call 0x7e2fc0
// 0089be58  8d8e98000000         lea ecx, [esi + 0x98]
// 0089be5e  e85d71f4ff           call 0x7e2fc0
// 0089be63  8d8ea4000000         lea ecx, [esi + 0xa4]
// 0089be69  e85271f4ff           call 0x7e2fc0
// 0089be6e  8d8eb0000000         lea ecx, [esi + 0xb0]
// 0089be74  e84771f4ff           call 0x7e2fc0
// 0089be79  8d8ebc000000         lea ecx, [esi + 0xbc]
// 0089be7f  e83c71f4ff           call 0x7e2fc0
// 0089be84  8d8ec8000000         lea ecx, [esi + 0xc8]
// 0089be8a  e83171f4ff           call 0x7e2fc0
// 0089be8f  8d8ed4000000         lea ecx, [esi + 0xd4]
// 0089be95  e82671f4ff           call 0x7e2fc0
// 0089be9a  8dbee0000000         lea edi, [esi + 0xe0]
// 0089bea0  8bcf                 mov ecx, edi
// 0089bea2  e83971f4ff           call 0x7e2fe0
// 0089bea7  8d4f20               lea ecx, [edi + 0x20]
// 0089beaa  e83171f4ff           call 0x7e2fe0
// 0089beaf  8dbe20010000         lea edi, [esi + 0x120]
// 0089beb5  8bcf                 mov ecx, edi
// 0089beb7  e80471f4ff           call 0x7e2fc0
// 0089bebc  8d4f0c               lea ecx, [edi + 0xc]
// 0089bebf  e8fc70f4ff           call 0x7e2fc0
// 0089bec4  8d4f18               lea ecx, [edi + 0x18]
// 0089bec7  e8f470f4ff           call 0x7e2fc0
// 0089becc  8dbe44010000         lea edi, [esi + 0x144]
// 0089bed2  8bcf                 mov ecx, edi
// 0089bed4  e8e770f4ff           call 0x7e2fc0
// 0089bed9  8d4f0c               lea ecx, [edi + 0xc]
// 0089bedc  e8df70f4ff           call 0x7e2fc0
// 0089bee1  8d4f18               lea ecx, [edi + 0x18]
// 0089bee4  e8d770f4ff           call 0x7e2fc0
// 0089bee9  8d4f24               lea ecx, [edi + 0x24]
// 0089beec  e8cf70f4ff           call 0x7e2fc0
// 0089bef1  8dbe74010000         lea edi, [esi + 0x174]
// 0089bef7  8bcf                 mov ecx, edi
// 0089bef9  e8c270f4ff           call 0x7e2fc0
// 0089befe  8d4f0c               lea ecx, [edi + 0xc]
// 0089bf01  e8ba70f4ff           call 0x7e2fc0
// 0089bf06  8d4f18               lea ecx, [edi + 0x18]
// 0089bf09  e8b270f4ff           call 0x7e2fc0
// 0089bf0e  8d4f24               lea ecx, [edi + 0x24]
// 0089bf11  e8aa70f4ff           call 0x7e2fc0
// 0089bf16  8d4f30               lea ecx, [edi + 0x30]
// 0089bf19  e8a270f4ff           call 0x7e2fc0
// 0089bf1e  8d4f3c               lea ecx, [edi + 0x3c]
// 0089bf21  e89a70f4ff           call 0x7e2fc0
// 0089bf26  8dbebc010000         lea edi, [esi + 0x1bc]
// 0089bf2c  8bcf                 mov ecx, edi
// 0089bf2e  e88d70f4ff           call 0x7e2fc0
// 0089bf33  8d4f0c               lea ecx, [edi + 0xc]
// 0089bf36  e88570f4ff           call 0x7e2fc0
// 0089bf3b  8d4f18               lea ecx, [edi + 0x18]
// 0089bf3e  e87d70f4ff           call 0x7e2fc0
// 0089bf43  8d4f24               lea ecx, [edi + 0x24]
// 0089bf46  e87570f4ff           call 0x7e2fc0
// 0089bf4b  8d4f30               lea ecx, [edi + 0x30]
// 0089bf4e  e86d70f4ff           call 0x7e2fc0
// 0089bf53  8d4f3c               lea ecx, [edi + 0x3c]
// 0089bf56  e86570f4ff           call 0x7e2fc0
// 0089bf5b  5f                   pop edi
// 0089bf5c  c7860402000000000000 mov dword ptr [esi + 0x204], 0
// 0089bf66  8bc6                 mov eax, esi
// 0089bf68  5e                   pop esi
// 0089bf69  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ??0CColorSet@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
