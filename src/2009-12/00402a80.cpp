// from server: 100% by auto
// roc 2009-12 00402a80  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402a80
//
// 00402a80  8b442408             mov eax, dword ptr [esp + 8]
// 00402a84  f76c240c             imul dword ptr [esp + 0xc]
// 00402a88  8bc8                 mov ecx, eax
// 00402a8a  81c100000080         add ecx, 0x80000000
// 00402a90  83d200               adc edx, 0
// 00402a93  85d2                 test edx, edx
// 00402a95  7710                 ja 0x402aa7
// 00402a97  7205                 jb 0x402a9e
// 00402a99  83f9ff               cmp ecx, -1
// 00402a9c  7709                 ja 0x402aa7
// 00402a9e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00402aa2  8901                 mov dword ptr [ecx], eax
// 00402aa4  33c0                 xor eax, eax
// 00402aa6  c3                   ret 
// 00402aa7  b857000780           mov eax, 0x80070057
// 00402aac  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??$AtlMultiply@H@ATL@@YAJPAHHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
