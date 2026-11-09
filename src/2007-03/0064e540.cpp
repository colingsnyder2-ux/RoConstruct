// from server: 100% by auto
// roc 2007-03 0064e540  unit: seg_00640000  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0064e540
//
// 0064e540  8b4108               mov eax, dword ptr [ecx + 8]
// 0064e543  8b542404             mov edx, dword ptr [esp + 4]
// 0064e547  3b4208               cmp eax, dword ptr [edx + 8]
// 0064e54a  7529                 jne 0x64e575
// 0064e54c  85c0                 test eax, eax
// 0064e54e  7518                 jne 0x64e568
// 0064e550  dd02                 fld qword ptr [edx]
// 0064e552  dc19                 fcomp qword ptr [ecx]
// 0064e554  dfe0                 fnstsw ax
// 0064e556  f6c444               test ah, 0x44
// 0064e559  7a08                 jp 0x64e563
// 0064e55b  b801000000           mov eax, 1
// 0064e560  c20400               ret 4
// 0064e563  33c0                 xor eax, eax
// 0064e565  c20400               ret 4
// 0064e568  33c9                 xor ecx, ecx
// 0064e56a  83f802               cmp eax, 2
// 0064e56d  0f94c1               sete cl
// 0064e570  8ac1                 mov al, cl
// 0064e572  c20400               ret 4
// 0064e575  32c0                 xor al, al
// 0064e577  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\daodfx.cpp (function ??8COleDateTime@ATL@@QBE_NABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/daodfx.cpp
