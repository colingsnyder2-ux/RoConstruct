// from server: 100% by auto
// roc 2009-12 00570720  unit: CSHA1  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00570720
//
// 00570720  8bc1                 mov eax, ecx
// 00570722  33c9                 xor ecx, ecx
// 00570724  894808               mov dword ptr [eax + 8], ecx
// 00570727  8908                 mov dword ptr [eax], ecx
// 00570729  894804               mov dword ptr [eax + 4], ecx
// 0057072c  c3                   ret 
// library raknet-4.081/CloudClient.cpp (function ??0?$List@UCloudKey@RakNet@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 CloudClient.cpp
