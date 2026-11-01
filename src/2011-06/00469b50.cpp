// from server: 100% by auto
// roc 2011-06 00469b50  unit: VCRoblox3D::?$CComObject  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00469b50
//
// 00469b50  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00469b54  e837fdffff           call 0x469890
// 00469b59  33c0                 xor eax, eax
// 00469b5b  c20400               ret 4
// library raknet-4.081/RakNetSocket2.cpp (function ?RecvFromLoop@RNS2_Berkley@RakNet@@KGIPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 RakNetSocket2.cpp
