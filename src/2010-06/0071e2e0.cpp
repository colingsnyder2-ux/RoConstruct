// from server: 100% by auto
// roc 2010-06 0071e2e0  unit: RBX::Unlocked  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0071e2e0
//
// 0071e2e0  51                   push ecx
// 0071e2e1  8d442408             lea eax, [esp + 8]
// 0071e2e5  50                   push eax
// 0071e2e6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0071e2ea  8d542404             lea edx, [esp + 4]
// 0071e2ee  52                   push edx
// 0071e2ef  50                   push eax
// 0071e2f0  e86bffffff           call 0x71e260
// 0071e2f5  59                   pop ecx
// 0071e2f6  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\map_ss.cpp (function ?PLookup@CMapStringToString@@QBEPBUCPair@1@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/map_ss.cpp
