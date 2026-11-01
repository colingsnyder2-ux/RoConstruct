// from server: 100% by auto
// roc 2009-12 00863a60  unit: CXTPToolTipContextToolTip  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00863a60
//
// 00863a60  56                   push esi
// 00863a61  57                   push edi
// 00863a62  8b3ddccb9800         mov edi, dword ptr [0x98cbdc]
// 00863a68  6a31                 push 0x31
// 00863a6a  8bf1                 mov esi, ecx
// 00863a6c  ffd7                 call edi
// 00863a6e  6a32                 push 0x32
// 00863a70  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 00863a76  ffd7                 call edi
// 00863a78  6a0a                 push 0xa
// 00863a7a  8986c4000000         mov dword ptr [esi + 0xc4], eax
// 00863a80  ffd7                 call edi
// 00863a82  6a09                 push 9
// 00863a84  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 00863a8a  ffd7                 call edi
// 00863a8c  6a0f                 push 0xf
// 00863a8e  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 00863a94  ffd7                 call edi
// 00863a96  8986d8000000         mov dword ptr [esi + 0xd8], eax
// 00863a9c  b812000000           mov eax, 0x12
// 00863aa1  5f                   pop edi
// 00863aa2  8986c8000000         mov dword ptr [esi + 0xc8], eax
// 00863aa8  8986cc000000         mov dword ptr [esi + 0xcc], eax
// 00863aae  5e                   pop esi
// 00863aaf  c3                   ret 
// library xtp-15.2.1/Source\Controls\Util\XTPGlobal.cpp (function ?UpdateSysMetrics@CXTPAuxData@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPGlobal.cpp
