// from server: 100% by auto
// roc 2010-06 007df8c0  unit: CXTPReportRecordItemVariant  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007df8c0
//
// 007df8c0  8b4108               mov eax, dword ptr [ecx + 8]
// 007df8c3  8b542404             mov edx, dword ptr [esp + 4]
// 007df8c7  3b4208               cmp eax, dword ptr [edx + 8]
// 007df8ca  7529                 jne 0x7df8f5
// 007df8cc  85c0                 test eax, eax
// 007df8ce  7518                 jne 0x7df8e8
// 007df8d0  dd02                 fld qword ptr [edx]
// 007df8d2  dc19                 fcomp qword ptr [ecx]
// 007df8d4  dfe0                 fnstsw ax
// 007df8d6  f6c444               test ah, 0x44
// 007df8d9  7a08                 jp 0x7df8e3
// 007df8db  b801000000           mov eax, 1
// 007df8e0  c20400               ret 4
// 007df8e3  33c0                 xor eax, eax
// 007df8e5  c20400               ret 4
// 007df8e8  33c9                 xor ecx, ecx
// 007df8ea  83f802               cmp eax, 2
// 007df8ed  0f94c1               sete cl
// 007df8f0  8ac1                 mov al, cl
// 007df8f2  c20400               ret 4
// 007df8f5  32c0                 xor al, al
// 007df8f7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\daodfx.cpp (function ??8COleDateTime@ATL@@QBE_NABV01@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/daodfx.cpp
