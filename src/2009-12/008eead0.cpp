// from server: 100% by auto
// roc 2009-12 008eead0  unit: CXTPRibbonTabPopupToolBar  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008eead0
//
// 008eead0  8b442404             mov eax, dword ptr [esp + 4]
// 008eead4  8b5120               mov edx, dword ptr [ecx + 0x20]
// 008eead7  8910                 mov dword ptr [eax], edx
// 008eead9  8b5124               mov edx, dword ptr [ecx + 0x24]
// 008eeadc  895004               mov dword ptr [eax + 4], edx
// 008eeadf  8b5128               mov edx, dword ptr [ecx + 0x28]
// 008eeae2  8b492c               mov ecx, dword ptr [ecx + 0x2c]
// 008eeae5  895008               mov dword ptr [eax + 8], edx
// 008eeae8  89480c               mov dword ptr [eax + 0xc], ecx
// 008eeaeb  c20400               ret 4
// library raknet-4.081/ReplicaManager3.cpp (function ?GetRakNetGUID@Connection_RM3@RakNet@@QBE?AURakNetGUID@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 ReplicaManager3.cpp
