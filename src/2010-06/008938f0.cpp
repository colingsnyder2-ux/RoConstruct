// from server: 100% by auto
// roc 2010-06 008938f0  unit: CXTColorPageCustom  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008938f0
//
// 008938f0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008938f4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008938f8  8b01                 mov eax, dword ptr [ecx]
// 008938fa  8b403c               mov eax, dword ptr [eax + 0x3c]
// 008938fd  52                   push edx
// 008938fe  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00893902  52                   push edx
// 00893903  ffd0                 call eax
// 00893905  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00893909  8901                 mov dword ptr [ecx], eax
// 0089390b  33c0                 xor eax, eax
// 0089390d  c21000               ret 0x10
// library xtp-13.2.1-shared-mfc/Source\Common\XTPRichRender.cpp (function ?RichTextCtrlCallbackIn@CXTPRichRender@@KGKKPAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPRichRender.cpp
