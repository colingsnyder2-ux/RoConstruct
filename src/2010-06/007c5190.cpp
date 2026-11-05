// from server: 100% by auto
// roc 2010-06 007c5190  unit: CXTPImageManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c5190
//
// 007c5190  56                   push esi
// 007c5191  8bf1                 mov esi, ecx
// 007c5193  e8487d1b00           call 0x97cee0
// 007c5198  8b542408             mov edx, dword ptr [esp + 8]
// 007c519c  894604               mov dword ptr [esi + 4], eax
// 007c519f  8b88ec000000         mov ecx, dword ptr [eax + 0xec]
// 007c51a5  890e                 mov dword ptr [esi], ecx
// 007c51a7  8990ec000000         mov dword ptr [eax + 0xec], edx
// 007c51ad  8bc6                 mov eax, esi
// 007c51af  5e                   pop esi
// 007c51b0  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPMenuBar.cpp (function ??0CXTPPushRoutingFrame@@QAE@PAVCFrameWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPMenuBar.cpp
