// from server: 100% by auto
// roc 2011-06 008ecd40  unit: CXTPRichRender::XTextHost  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ecd40
//
// 008ecd40  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008ecd44  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008ecd48  50                   push eax
// 008ecd49  ff15a42da400         call dword ptr [0xa42da4]
// 008ecd4f  33c0                 xor eax, eax
// 008ecd51  c21000               ret 0x10
// library xtp-15.2.1-shared-mfc/Source\Common\XTPResourceImage.cpp (function ?EnumResNameProc@CXTPResourceImages@@CGHPAUHINSTANCE__@@PBDPADJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPResourceImage.cpp
