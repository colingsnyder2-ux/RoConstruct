// from server: 100% by auto
// roc 2010-06 00901bd0  unit: VThreadLogManager::?$thread_specific_ptr::delete_data  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00901bd0
//
// 00901bd0  8b0d98cbc200         mov ecx, dword ptr [0xc2cb98]
// 00901bd6  85c9                 test ecx, ecx
// 00901bd8  7408                 je 0x901be2
// 00901bda  8b01                 mov eax, dword ptr [ecx]
// 00901bdc  8b10                 mov edx, dword ptr [eax]
// 00901bde  6a01                 push 1
// 00901be0  ffd2                 call edx
// 00901be2  c3                   ret 
// library xtp-13.2.1/Source\SkinFramework\XTPSkinManager.cpp (function ??1CDestructor@CXTPSkinManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SkinFramework/XTPSkinManager.cpp
