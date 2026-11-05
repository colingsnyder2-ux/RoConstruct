// from server: 100% by auto
// roc 2008-06 006d8a50  unit: CXTPReportRecordItemVariant  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006d8a50
//
// 006d8a50  8b4108               mov eax, dword ptr [ecx + 8]
// 006d8a53  8b542404             mov edx, dword ptr [esp + 4]
// 006d8a57  3b4208               cmp eax, dword ptr [edx + 8]
// 006d8a5a  7529                 jne 0x6d8a85
// 006d8a5c  85c0                 test eax, eax
// 006d8a5e  7518                 jne 0x6d8a78
// 006d8a60  dd02                 fld qword ptr [edx]
// 006d8a62  dc19                 fcomp qword ptr [ecx]
// 006d8a64  dfe0                 fnstsw ax
// 006d8a66  f6c444               test ah, 0x44
// 006d8a69  7a08                 jp 0x6d8a73
// 006d8a6b  b801000000           mov eax, 1
// 006d8a70  c20400               ret 4
// 006d8a73  33c0                 xor eax, eax
// 006d8a75  c20400               ret 4
// 006d8a78  33c9                 xor ecx, ecx
// 006d8a7a  83f802               cmp eax, 2
// 006d8a7d  0f94c1               sete cl
// 006d8a80  8ac1                 mov al, cl
// 006d8a82  c20400               ret 4
// 006d8a85  32c0                 xor al, al
// 006d8a87  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\daodfx.cpp (function ??8COleDateTime@ATL@@QBE_NABV01@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/daodfx.cpp
