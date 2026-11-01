// from server: 100% by auto
// roc 2009-06 007bd640  unit: CXTPCommandBarAnimation::PAUCAnimateInfo::?$CArray  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bd640
//
// 007bd640  56                   push esi
// 007bd641  8bf1                 mov esi, ecx
// 007bd643  57                   push edi
// 007bd644  8d4e24               lea ecx, [esi + 0x24]
// 007bd647  e834ffffff           call 0x7bd580
// 007bd64c  33ff                 xor edi, edi
// 007bd64e  8d4610               lea eax, [esi + 0x10]
// 007bd651  50                   push eax
// 007bd652  893e                 mov dword ptr [esi], edi
// 007bd654  897e04               mov dword ptr [esi + 4], edi
// 007bd657  897e08               mov dword ptr [esi + 8], edi
// 007bd65a  897e0c               mov dword ptr [esi + 0xc], edi
// 007bd65d  ff15c8ee8900         call dword ptr [0x89eec8]
// 007bd663  897e20               mov dword ptr [esi + 0x20], edi
// 007bd666  5f                   pop edi
// 007bd667  8bc6                 mov eax, esi
// 007bd669  5e                   pop esi
// 007bd66a  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ??0CAnimateInfo@CXTPCommandBarAnimation@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
