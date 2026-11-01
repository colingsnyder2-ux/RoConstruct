// from server: 100% by auto
// roc 2009-06 00788a60  unit: CXTPToolTipContextToolTip  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00788a60
//
// 00788a60  56                   push esi
// 00788a61  57                   push edi
// 00788a62  8b3ddced8900         mov edi, dword ptr [0x89eddc]
// 00788a68  6a31                 push 0x31
// 00788a6a  8bf1                 mov esi, ecx
// 00788a6c  ffd7                 call edi
// 00788a6e  6a32                 push 0x32
// 00788a70  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 00788a76  ffd7                 call edi
// 00788a78  6a0a                 push 0xa
// 00788a7a  8986c4000000         mov dword ptr [esi + 0xc4], eax
// 00788a80  ffd7                 call edi
// 00788a82  6a09                 push 9
// 00788a84  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 00788a8a  ffd7                 call edi
// 00788a8c  6a0f                 push 0xf
// 00788a8e  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 00788a94  ffd7                 call edi
// 00788a96  8986d8000000         mov dword ptr [esi + 0xd8], eax
// 00788a9c  b812000000           mov eax, 0x12
// 00788aa1  5f                   pop edi
// 00788aa2  8986c8000000         mov dword ptr [esi + 0xc8], eax
// 00788aa8  8986cc000000         mov dword ptr [esi + 0xcc], eax
// 00788aae  5e                   pop esi
// 00788aaf  c3                   ret 
// library xtp-15.2.1/Source\Controls\Util\XTPGlobal.cpp (function ?UpdateSysMetrics@CXTPAuxData@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPGlobal.cpp
