// from server: 100% by auto
// roc 2009-06 0079aa00  unit: CXTPResourceManager  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079aa00
//
// 0079aa00  0fb7542404           movzx edx, word ptr [esp + 4]
// 0079aa05  8b01                 mov eax, dword ptr [ecx]
// 0079aa07  8b4020               mov eax, dword ptr [eax + 0x20]
// 0079aa0a  52                   push edx
// 0079aa0b  ffd0                 call eax
// 0079aa0d  89442404             mov dword ptr [esp + 4], eax
// 0079aa11  ff2550e28900         jmp dword ptr [0x89e250]
// library xtp-13.2.1/Source\Common\XTPResourceManager.cpp (function ?LoadDialogTemplate@CXTPResourceManager@@UAEPBUDLGTEMPLATE@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPResourceManager.cpp
