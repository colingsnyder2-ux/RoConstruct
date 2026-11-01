// from server: 100% by auto
// roc 2009-12 0082b880  unit: CXTPReportRecordItemVariant  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082b880
//
// 0082b880  8b4108               mov eax, dword ptr [ecx + 8]
// 0082b883  8b542404             mov edx, dword ptr [esp + 4]
// 0082b887  3b4208               cmp eax, dword ptr [edx + 8]
// 0082b88a  7529                 jne 0x82b8b5
// 0082b88c  85c0                 test eax, eax
// 0082b88e  7518                 jne 0x82b8a8
// 0082b890  dd02                 fld qword ptr [edx]
// 0082b892  dc19                 fcomp qword ptr [ecx]
// 0082b894  dfe0                 fnstsw ax
// 0082b896  f6c444               test ah, 0x44
// 0082b899  7a08                 jp 0x82b8a3
// 0082b89b  b801000000           mov eax, 1
// 0082b8a0  c20400               ret 4
// 0082b8a3  33c0                 xor eax, eax
// 0082b8a5  c20400               ret 4
// 0082b8a8  33c9                 xor ecx, ecx
// 0082b8aa  83f802               cmp eax, 2
// 0082b8ad  0f94c1               sete cl
// 0082b8b0  8ac1                 mov al, cl
// 0082b8b2  c20400               ret 4
// 0082b8b5  32c0                 xor al, al
// 0082b8b7  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\daodfx.cpp (function ??8COleDateTime@ATL@@QBE_NABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/daodfx.cpp
