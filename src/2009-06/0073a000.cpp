// from server: 100% by auto
// roc 2009-06 0073a000  unit: CXTPImageManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073a000
//
// 0073a000  56                   push esi
// 0073a001  8bf1                 mov esi, ecx
// 0073a003  e8761f1100           call 0x84bf7e
// 0073a008  8b542408             mov edx, dword ptr [esp + 8]
// 0073a00c  894604               mov dword ptr [esi + 4], eax
// 0073a00f  8b88ec000000         mov ecx, dword ptr [eax + 0xec]
// 0073a015  890e                 mov dword ptr [esi], ecx
// 0073a017  8990ec000000         mov dword ptr [eax + 0xec], edx
// 0073a01d  8bc6                 mov eax, esi
// 0073a01f  5e                   pop esi
// 0073a020  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ??0CXTPPushRoutingFrame@CXTPToolBar@@QAE@PAVCFrameWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
