// from server: 100% by auto
// roc 2009-12 0086e160  unit: CXTPResourceManager  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086e160
//
// 0086e160  0fb7542404           movzx edx, word ptr [esp + 4]
// 0086e165  8b01                 mov eax, dword ptr [ecx]
// 0086e167  8b4020               mov eax, dword ptr [eax + 0x20]
// 0086e16a  52                   push edx
// 0086e16b  ffd0                 call eax
// 0086e16d  89442404             mov dword ptr [esp + 4], eax
// 0086e171  ff257cb29800         jmp dword ptr [0x98b27c]
// library xtp-13.2.1/Source\Common\XTPResourceManager.cpp (function ?LoadDialogTemplate@CXTPResourceManager@@UAEPBUDLGTEMPLATE@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPResourceManager.cpp
