// roc 2012-06 00a57bd0  unit: CXTPPropertyGridInplaceEdit  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a57bd0
//
// 00a57bd0  8b442404             mov eax, dword ptr [esp + 4]
// 00a57bd4  85c0                 test eax, eax
// 00a57bd6  7c0e                 jl 0xa57be6
// 00a57bd8  3b4108               cmp eax, dword ptr [ecx + 8]
// 00a57bdb  7d09                 jge 0xa57be6
// 00a57bdd  8b4904               mov ecx, dword ptr [ecx + 4]
// 00a57be0  8b0481               mov eax, dword ptr [ecx + eax*4]
// 00a57be3  c20400               ret 4
// 00a57be6  e8d5a7f2ff           call 0x9823c0
// copied from an identical function in another client (function ?GetAt@CPtrArray@@QBEPAXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp