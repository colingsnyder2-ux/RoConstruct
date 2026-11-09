// from server: 100% by auto
// roc 2010-06 0081f660  unit: CXTPPropertyGridItemEnum  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081f660
//
// 0081f660  56                   push esi
// 0081f661  8bf1                 mov esi, ecx
// 0081f663  e80802fdff           call 0x7ef870
// 0081f668  8bc8                 mov ecx, eax
// 0081f66a  e8e111fdff           call 0x7f0850
// 0081f66f  68d0000000           push 0xd0
// 0081f674  6a00                 push 0
// 0081f676  56                   push esi
// 0081f677  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 0081f67d  e86295f8ff           call 0x7a8be4
// 0081f682  83c40c               add esp, 0xc
// 0081f685  68d442a600           push 0xa642d4
// 0081f68a  ff1548a39e00         call dword ptr [0x9ea348]
// 0081f690  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 0081f696  8bc6                 mov eax, esi
// 0081f698  5e                   pop esi
// 0081f699  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPWinThemeWrapper.cpp (function ??0CSharedData@CXTPWinThemeWrapper@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPWinThemeWrapper.cpp
