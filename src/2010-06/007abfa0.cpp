// from server: 100% by auto
// roc 2010-06 007abfa0  unit: PAVCXTPControlAction::?$CArray  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007abfa0
//
// 007abfa0  56                   push esi
// 007abfa1  8bf1                 mov esi, ecx
// 007abfa3  e8d60d1d00           call 0x97cd7e
// 007abfa8  8d4e20               lea ecx, [esi + 0x20]
// 007abfab  c706645ba500         mov dword ptr [esi], 0xa55b64
// 007abfb1  e8eaf9ffff           call 0x7ab9a0
// 007abfb6  8b442408             mov eax, dword ptr [esp + 8]
// 007abfba  894634               mov dword ptr [esi + 0x34], eax
// 007abfbd  8bc6                 mov eax, esi
// 007abfbf  5e                   pop esi
// 007abfc0  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPControl.cpp (function ??0CXTPControlActions@@IAE@PAVCXTPCommandBars@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControl.cpp
