// from server: 100% by auto
// roc 2008-06 004bb8e0  unit: ProfiledRakPeer  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bb8e0
//
// 004bb8e0  8b442404             mov eax, dword ptr [esp + 4]
// 004bb8e4  85c0                 test eax, eax
// 004bb8e6  7414                 je 0x4bb8fc
// 004bb8e8  803800               cmp byte ptr [eax], 0
// 004bb8eb  740f                 je 0x4bb8fc
// 004bb8ed  89442404             mov dword ptr [esp + 4], eax
// 004bb8f1  81c1fc060000         add ecx, 0x6fc
// 004bb8f7  e9e4850100           jmp 0x4d3ee0
// 004bb8fc  c20400               ret 4
// library openrbx-raknet/RakPeer.cpp (function ?UnregisterAsRemoteProcedureCall@RakPeer@@UAEXPBD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
