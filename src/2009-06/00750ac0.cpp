// from server: 100% by auto
// roc 2009-06 00750ac0  unit: CXTPReportRecordItemVariant  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00750ac0
//
// 00750ac0  8b4108               mov eax, dword ptr [ecx + 8]
// 00750ac3  8b542404             mov edx, dword ptr [esp + 4]
// 00750ac7  3b4208               cmp eax, dword ptr [edx + 8]
// 00750aca  7529                 jne 0x750af5
// 00750acc  85c0                 test eax, eax
// 00750ace  7518                 jne 0x750ae8
// 00750ad0  dd02                 fld qword ptr [edx]
// 00750ad2  dc19                 fcomp qword ptr [ecx]
// 00750ad4  dfe0                 fnstsw ax
// 00750ad6  f6c444               test ah, 0x44
// 00750ad9  7a08                 jp 0x750ae3
// 00750adb  b801000000           mov eax, 1
// 00750ae0  c20400               ret 4
// 00750ae3  33c0                 xor eax, eax
// 00750ae5  c20400               ret 4
// 00750ae8  33c9                 xor ecx, ecx
// 00750aea  83f802               cmp eax, 2
// 00750aed  0f94c1               sete cl
// 00750af0  8ac1                 mov al, cl
// 00750af2  c20400               ret 4
// 00750af5  32c0                 xor al, al
// 00750af7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\daodfx.cpp (function ??8COleDateTime@ATL@@QBE_NABV01@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/daodfx.cpp
