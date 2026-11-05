// from server: 100% by auto
// roc 2011-06 0087f890  unit: CXTPResourceManager  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0087f890
//
// 0087f890  0fb7542404           movzx edx, word ptr [esp + 4]
// 0087f895  8b01                 mov eax, dword ptr [ecx]
// 0087f897  8b4020               mov eax, dword ptr [eax + 0x20]
// 0087f89a  52                   push edx
// 0087f89b  ffd0                 call eax
// 0087f89d  89442404             mov dword ptr [esp + 4], eax
// 0087f8a1  ff25d001a400         jmp dword ptr [0xa401d0]
// library xtp-13.2.1/Source\Common\XTPResourceManager.cpp (function ?LoadDialogTemplate@CXTPResourceManager@@UAEPBUDLGTEMPLATE@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPResourceManager.cpp
