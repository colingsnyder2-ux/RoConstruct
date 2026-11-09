// from server: 100% by auto
// roc 2009-06 006b15e0  unit: RBX::BlockBlockContact  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b15e0
//
// 006b15e0  8b4134               mov eax, dword ptr [ecx + 0x34]
// 006b15e3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006b15e7  8b0488               mov eax, dword ptr [eax + ecx*4]
// 006b15ea  c20400               ret 4
// library raknet-4.081/TeamManager.cpp (function ?GetTeamMemberByIndex@TM_World@RakNet@@QBEPAVTM_TeamMember@2@I@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 TeamManager.cpp
