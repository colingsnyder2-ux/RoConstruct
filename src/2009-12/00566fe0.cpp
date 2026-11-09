// from server: 100% by auto
// roc 2009-12 00566fe0  unit: RakPeer  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00566fe0
//
// 00566fe0  83790800             cmp dword ptr [ecx + 8], 0
// 00566fe4  7609                 jbe 0x566fef
// 00566fe6  8b01                 mov eax, dword ptr [ecx]
// 00566fe8  50                   push eax
// 00566fe9  e818cb2800           call 0x7f3b06
// 00566fee  59                   pop ecx
// 00566fef  c3                   ret 
// library raknet-4.081/CloudClient.cpp (function ??1?$List@PAUCloudQueryRow@RakNet@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 CloudClient.cpp
