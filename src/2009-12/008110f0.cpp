// from server: 100% by auto
// roc 2009-12 008110f0  unit: CXTPImageManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008110f0
//
// 008110f0  56                   push esi
// 008110f1  8bf1                 mov esi, ecx
// 008110f3  e8ac541100           call 0x9265a4
// 008110f8  8b542408             mov edx, dword ptr [esp + 8]
// 008110fc  894604               mov dword ptr [esi + 4], eax
// 008110ff  8b88ec000000         mov ecx, dword ptr [eax + 0xec]
// 00811105  890e                 mov dword ptr [esi], ecx
// 00811107  8990ec000000         mov dword ptr [eax + 0xec], edx
// 0081110d  8bc6                 mov eax, esi
// 0081110f  5e                   pop esi
// 00811110  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ??0CXTPPushRoutingFrame@CXTPToolBar@@QAE@PAVCFrameWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
