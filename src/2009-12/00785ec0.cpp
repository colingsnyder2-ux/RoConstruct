// from server: 100% by auto
// roc 2009-12 00785ec0  unit: RBX::Unlocked  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00785ec0
//
// 00785ec0  51                   push ecx
// 00785ec1  8d442408             lea eax, [esp + 8]
// 00785ec5  50                   push eax
// 00785ec6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00785eca  8d542404             lea edx, [esp + 4]
// 00785ece  52                   push edx
// 00785ecf  50                   push eax
// 00785ed0  e86bffffff           call 0x785e40
// 00785ed5  59                   pop ecx
// 00785ed6  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\map_ss.cpp (function ?PLookup@CMapStringToString@@QBEPBUCPair@1@PBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/map_ss.cpp
