// from server: 100% by auto
// roc 2007-03 00720770  unit: seg_00720000  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00720770
//
// 00720770  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00720774  53                   push ebx
// 00720775  56                   push esi
// 00720776  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0072077a  57                   push edi
// 0072077b  8b3df8d07700         mov edi, dword ptr [0x77d0f8]
// 00720781  50                   push eax
// 00720782  56                   push esi
// 00720783  ffd7                 call edi
// 00720785  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00720789  6a00                 push 0
// 0072078b  6a00                 push 0
// 0072078d  6a00                 push 0
// 0072078f  51                   push ecx
// 00720790  6a02                 push 2
// 00720792  6a00                 push 0
// 00720794  6a00                 push 0
// 00720796  56                   push esi
// 00720797  8bd8                 mov ebx, eax
// 00720799  ff15c0d07700         call dword ptr [0x77d0c0]
// 0072079f  53                   push ebx
// 007207a0  56                   push esi
// 007207a1  ffd7                 call edi
// 007207a3  5f                   pop edi
// 007207a4  5e                   pop esi
// 007207a5  b801000000           mov eax, 1
// 007207aa  5b                   pop ebx
// 007207ab  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinDrawTools.cpp (function ?XTPFillSolidRect@@YAHPAUHDC__@@PAUtagRECT@@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinDrawTools.cpp
