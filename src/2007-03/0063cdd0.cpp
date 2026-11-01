// from server: 100% by auto
// roc 2007-03 0063cdd0  unit: seg_00630000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0063cdd0
//
// 0063cdd0  56                   push esi
// 0063cdd1  8bf1                 mov esi, ecx
// 0063cdd3  e8a4dd0f00           call 0x73ab7c
// 0063cdd8  8b542408             mov edx, dword ptr [esp + 8]
// 0063cddc  894604               mov dword ptr [esi + 4], eax
// 0063cddf  8b88ec000000         mov ecx, dword ptr [eax + 0xec]
// 0063cde5  890e                 mov dword ptr [esi], ecx
// 0063cde7  8990ec000000         mov dword ptr [eax + 0xec], edx
// 0063cded  8bc6                 mov eax, esi
// 0063cdef  5e                   pop esi
// 0063cdf0  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ??0CXTPPushRoutingFrame@CXTPToolBar@@QAE@PAVCFrameWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
