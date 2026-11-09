// from server: 100% by auto
// roc 2011-06 004e7060  unit: RBX::VHint::?$FactoryProduct  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004e7060
//
// 004e7060  8b442404             mov eax, dword ptr [esp + 4]
// 004e7064  51                   push ecx
// 004e7065  50                   push eax
// 004e7066  e895fcffff           call 0x4e6d00
// 004e706b  83c408               add esp, 8
// 004e706e  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxshelllistctrl.cpp (function ?ConvertSystemTimeToVariantTime@COleDateTime@ATL@@IAEHABU_SYSTEMTIME@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelllistctrl.cpp
