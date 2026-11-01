// from server: 100% by auto
// roc 2009-12 004b79a0  unit: VThreadLogManager::?$thread_specific_ptr::delete_data  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b79a0
//
// 004b79a0  8b0de0ceb700         mov ecx, dword ptr [0xb7cee0]
// 004b79a6  85c9                 test ecx, ecx
// 004b79a8  7408                 je 0x4b79b2
// 004b79aa  8b01                 mov eax, dword ptr [ecx]
// 004b79ac  8b10                 mov edx, dword ptr [eax]
// 004b79ae  6a01                 push 1
// 004b79b0  ffd2                 call edx
// 004b79b2  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManager.cpp (function ??1CDestructor@CXTPSkinManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManager.cpp
