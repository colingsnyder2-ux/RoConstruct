// from server: 100% by auto
// roc 2007-03 00682210  unit: seg_00680000  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00682210
//
// 00682210  56                   push esi
// 00682211  57                   push edi
// 00682212  8b3dbced7700         mov edi, dword ptr [0x77edbc]
// 00682218  6a31                 push 0x31
// 0068221a  8bf1                 mov esi, ecx
// 0068221c  ffd7                 call edi
// 0068221e  6a32                 push 0x32
// 00682220  8986c0000000         mov dword ptr [esi + 0xc0], eax
// 00682226  ffd7                 call edi
// 00682228  6a0a                 push 0xa
// 0068222a  8986c4000000         mov dword ptr [esi + 0xc4], eax
// 00682230  ffd7                 call edi
// 00682232  6a09                 push 9
// 00682234  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 0068223a  ffd7                 call edi
// 0068223c  6a0f                 push 0xf
// 0068223e  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 00682244  ffd7                 call edi
// 00682246  8986d8000000         mov dword ptr [esi + 0xd8], eax
// 0068224c  b812000000           mov eax, 0x12
// 00682251  5f                   pop edi
// 00682252  8986c8000000         mov dword ptr [esi + 0xc8], eax
// 00682258  8986cc000000         mov dword ptr [esi + 0xcc], eax
// 0068225e  5e                   pop esi
// 0068225f  c3                   ret 
// library xtp-15.2.1/Source\Controls\Util\XTPGlobal.cpp (function ?UpdateSysMetrics@CXTPAuxData@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPGlobal.cpp
