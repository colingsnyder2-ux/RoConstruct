// from server: 100% by auto
// roc 2011-06 004036a0  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004036a0
//
// 004036a0  8b442404             mov eax, dword ptr [esp + 4]
// 004036a4  85c0                 test eax, eax
// 004036a6  7e0a                 jle 0x4036b2
// 004036a8  25ffff0000           and eax, 0xffff
// 004036ad  0d00000780           or eax, 0x80070000
// 004036b2  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function _HRESULT_FROM_WIN32)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
