// from server: 100% by auto
// roc 2010-06 00817a40  unit: CXTPToolTipContextToolTip  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00817a40
//
// 00817a40  56                   push esi
// 00817a41  57                   push edi
// 00817a42  8b3d6cba9e00         mov edi, dword ptr [0x9eba6c]
// 00817a48  6a31                 push 0x31
// 00817a4a  8bf1                 mov esi, ecx
// 00817a4c  ffd7                 call edi
// 00817a4e  6a32                 push 0x32
// 00817a50  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 00817a56  ffd7                 call edi
// 00817a58  6a0a                 push 0xa
// 00817a5a  8986c4000000         mov dword ptr [esi + 0xc4], eax
// 00817a60  ffd7                 call edi
// 00817a62  6a09                 push 9
// 00817a64  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 00817a6a  ffd7                 call edi
// 00817a6c  6a0f                 push 0xf
// 00817a6e  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 00817a74  ffd7                 call edi
// 00817a76  8986d8000000         mov dword ptr [esi + 0xd8], eax
// 00817a7c  b812000000           mov eax, 0x12
// 00817a81  5f                   pop edi
// 00817a82  8986c8000000         mov dword ptr [esi + 0xc8], eax
// 00817a88  8986cc000000         mov dword ptr [esi + 0xcc], eax
// 00817a8e  5e                   pop esi
// 00817a8f  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTGlobal.cpp (function ?UpdateSysMetrics@CXTAuxData@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTGlobal.cpp
