// from server: 100% by auto
// roc 2008-06 004bb990  unit: ProfiledRakPeer  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bb990
//
// 004bb990  56                   push esi
// 004bb991  8bf1                 mov esi, ecx
// 004bb993  57                   push edi
// 004bb994  8dbe3c020000         lea edi, [esi + 0x23c]
// 004bb99a  8bcf                 mov ecx, edi
// 004bb99c  e8ef850100           call 0x4d3f90
// 004bb9a1  83c60c               add esi, 0xc
// 004bb9a4  8bce                 mov ecx, esi
// 004bb9a6  e81598feff           call 0x4a51c0
// 004bb9ab  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004bb9af  85c0                 test eax, eax
// 004bb9b1  7411                 je 0x4bb9c4
// 004bb9b3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004bb9b7  85c9                 test ecx, ecx
// 004bb9b9  7609                 jbe 0x4bb9c4
// 004bb9bb  51                   push ecx
// 004bb9bc  50                   push eax
// 004bb9bd  8bce                 mov ecx, esi
// 004bb9bf  e83c9dfeff           call 0x4a5700
// 004bb9c4  8bcf                 mov ecx, edi
// 004bb9c6  e8d5850100           call 0x4d3fa0
// 004bb9cb  5f                   pop edi
// 004bb9cc  5e                   pop esi
// 004bb9cd  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?SetOfflinePingResponse@RakPeer@@UAEXPBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
