// from server: 100% by auto
// roc 2007-08 00662780  unit: PluginInterface  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00662780
//
// 00662780  8b4108               mov eax, dword ptr [ecx + 8]
// 00662783  8b542404             mov edx, dword ptr [esp + 4]
// 00662787  3b4208               cmp eax, dword ptr [edx + 8]
// 0066278a  7529                 jne 0x6627b5
// 0066278c  85c0                 test eax, eax
// 0066278e  7518                 jne 0x6627a8
// 00662790  dd02                 fld qword ptr [edx]
// 00662792  dc19                 fcomp qword ptr [ecx]
// 00662794  dfe0                 fnstsw ax
// 00662796  f6c444               test ah, 0x44
// 00662799  7a08                 jp 0x6627a3
// 0066279b  b801000000           mov eax, 1
// 006627a0  c20400               ret 4
// 006627a3  33c0                 xor eax, eax
// 006627a5  c20400               ret 4
// 006627a8  33c9                 xor ecx, ecx
// 006627aa  83f802               cmp eax, 2
// 006627ad  0f94c1               sete cl
// 006627b0  8ac1                 mov al, cl
// 006627b2  c20400               ret 4
// 006627b5  32c0                 xor al, al
// 006627b7  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\daodfx.cpp (function ??8COleDateTime@ATL@@QBE_NABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/daodfx.cpp
