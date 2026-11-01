// from server: 100% by auto
// roc 2007-03 0068b1c0  unit: seg_00680000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068b1c0
//
// 0068b1c0  56                   push esi
// 0068b1c1  8bf1                 mov esi, ecx
// 0068b1c3  33c0                 xor eax, eax
// 0068b1c5  8906                 mov dword ptr [esi], eax
// 0068b1c7  894604               mov dword ptr [esi + 4], eax
// 0068b1ca  6894fb7c00           push 0x7cfb94
// 0068b1cf  894608               mov dword ptr [esi + 8], eax
// 0068b1d2  ff1548d27700         call dword ptr [0x77d248]
// 0068b1d8  89460c               mov dword ptr [esi + 0xc], eax
// 0068b1db  8bc6                 mov eax, esi
// 0068b1dd  5e                   pop esi
// 0068b1de  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPWinThemeWrapper.cpp (function ??0CSharedData@CXTPWinDwmWrapper@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPWinThemeWrapper.cpp
