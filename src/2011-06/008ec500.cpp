// from server: 100% by auto
// roc 2011-06 008ec500  unit: CXTColorPageCustom  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ec500
//
// 008ec500  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008ec504  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008ec508  8b01                 mov eax, dword ptr [ecx]
// 008ec50a  8b403c               mov eax, dword ptr [eax + 0x3c]
// 008ec50d  52                   push edx
// 008ec50e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008ec512  52                   push edx
// 008ec513  ffd0                 call eax
// 008ec515  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008ec519  8901                 mov dword ptr [ecx], eax
// 008ec51b  33c0                 xor eax, eax
// 008ec51d  c21000               ret 0x10
// library xtp-15.2.1-shared-mfc/Source\Common\XTPRichRender.cpp (function ?RichTextCtrlCallbackIn@CXTPRichRender@@KGKKPAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPRichRender.cpp
