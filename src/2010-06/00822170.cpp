// from server: 100% by auto
// roc 2010-06 00822170  unit: CXTPResourceManager  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00822170
//
// 00822170  0fb7542404           movzx edx, word ptr [esp + 4]
// 00822175  8b01                 mov eax, dword ptr [ecx]
// 00822177  8b4020               mov eax, dword ptr [eax + 0x20]
// 0082217a  52                   push edx
// 0082217b  ffd0                 call eax
// 0082217d  89442404             mov dword ptr [esp + 4], eax
// 00822181  ff25eca29e00         jmp dword ptr [0x9ea2ec]
// library xtp-13.2.1/Source\Common\XTPResourceManager.cpp (function ?LoadDialogTemplate@CXTPResourceManager@@UAEPBUDLGTEMPLATE@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPResourceManager.cpp
