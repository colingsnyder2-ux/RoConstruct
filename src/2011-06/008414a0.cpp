// from server: 100% by auto
// roc 2011-06 008414a0  unit: CXTPReportRecordItemVariant  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008414a0
//
// 008414a0  8b4108               mov eax, dword ptr [ecx + 8]
// 008414a3  8b542404             mov edx, dword ptr [esp + 4]
// 008414a7  3b4208               cmp eax, dword ptr [edx + 8]
// 008414aa  7529                 jne 0x8414d5
// 008414ac  85c0                 test eax, eax
// 008414ae  7518                 jne 0x8414c8
// 008414b0  dd02                 fld qword ptr [edx]
// 008414b2  dc19                 fcomp qword ptr [ecx]
// 008414b4  dfe0                 fnstsw ax
// 008414b6  f6c444               test ah, 0x44
// 008414b9  7a08                 jp 0x8414c3
// 008414bb  b801000000           mov eax, 1
// 008414c0  c20400               ret 4
// 008414c3  33c0                 xor eax, eax
// 008414c5  c20400               ret 4
// 008414c8  33c9                 xor ecx, ecx
// 008414ca  83f802               cmp eax, 2
// 008414cd  0f94c1               sete cl
// 008414d0  8ac1                 mov al, cl
// 008414d2  c20400               ret 4
// 008414d5  32c0                 xor al, al
// 008414d7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\daodfx.cpp (function ??8COleDateTime@ATL@@QBE_NABV01@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/daodfx.cpp
