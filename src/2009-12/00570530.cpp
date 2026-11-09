// from server: 100% by auto
// roc 2009-12 00570530  unit: CSHA1  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00570530
//
// 00570530  8b442404             mov eax, dword ptr [esp + 4]
// 00570534  50                   push eax
// 00570535  ff15ecb29800         call dword ptr [0x98b2ec]
// 0057053b  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dbrfx.cpp (function ?RFX_Text_strlen@nsRFX_Text@@YAHPAD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dbrfx.cpp
