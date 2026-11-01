// from server: 100% by auto
// roc 2009-06 00498250  unit: VThreadLogManager::?$thread_specific_ptr::delete_data  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00498250
//
// 00498250  8b0dc0c7a300         mov ecx, dword ptr [0xa3c7c0]
// 00498256  85c9                 test ecx, ecx
// 00498258  7408                 je 0x498262
// 0049825a  8b01                 mov eax, dword ptr [ecx]
// 0049825c  8b10                 mov edx, dword ptr [eax]
// 0049825e  6a01                 push 1
// 00498260  ffd2                 call edx
// 00498262  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManager.cpp (function ??1CDestructor@CXTPSkinManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManager.cpp
