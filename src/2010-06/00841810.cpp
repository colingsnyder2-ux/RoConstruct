// from server: 100% by auto
// roc 2010-06 00841810  unit: CXTPCommandBarAnimation::PAUCAnimateInfo::?$CArray  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00841810
//
// 00841810  56                   push esi
// 00841811  8bf1                 mov esi, ecx
// 00841813  57                   push edi
// 00841814  8d4e24               lea ecx, [esi + 0x24]
// 00841817  e834ffffff           call 0x841750
// 0084181c  33ff                 xor edi, edi
// 0084181e  8d4610               lea eax, [esi + 0x10]
// 00841821  50                   push eax
// 00841822  893e                 mov dword ptr [esi], edi
// 00841824  897e04               mov dword ptr [esi + 4], edi
// 00841827  897e08               mov dword ptr [esi + 8], edi
// 0084182a  897e0c               mov dword ptr [esi + 0xc], edi
// 0084182d  ff15e4ba9e00         call dword ptr [0x9ebae4]
// 00841833  897e20               mov dword ptr [esi + 0x20], edi
// 00841836  5f                   pop edi
// 00841837  8bc6                 mov eax, esi
// 00841839  5e                   pop esi
// 0084183a  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ??0CAnimateInfo@CXTPCommandBarAnimation@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
