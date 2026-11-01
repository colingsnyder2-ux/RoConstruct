// from server: 100% by auto
// roc 2007-03 00651ca0  unit: seg_00650000  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00651ca0
//
// 00651ca0  56                   push esi
// 00651ca1  8bf1                 mov esi, ecx
// 00651ca3  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00651ca6  e80f900e00           call 0x73acba
// 00651cab  85c0                 test eax, eax
// 00651cad  7510                 jne 0x651cbf
// 00651caf  e8ec320000           call 0x654fa0
// 00651cb4  6a11                 push 0x11
// 00651cb6  8bc8                 mov ecx, eax
// 00651cb8  e8f32a0000           call 0x6547b0
// 00651cbd  5e                   pop esi
// 00651cbe  c3                   ret 
// 00651cbf  e84c400300           call 0x685d10
// 00651cc4  8bc8                 mov ecx, eax
// 00651cc6  e8a54f0300           call 0x686c70
// 00651ccb  3d47000400           cmp eax, 0x40047
// 00651cd0  721b                 jb 0x651ced
// 00651cd2  8b4634               mov eax, dword ptr [esi + 0x34]
// 00651cd5  8b4020               mov eax, dword ptr [eax + 0x20]
// 00651cd8  6a00                 push 0
// 00651cda  6a00                 push 0
// 00651cdc  6820110000           push 0x1120
// 00651ce1  50                   push eax
// 00651ce2  ff1550ee7700         call dword ptr [0x77ee50]
// 00651ce8  83f8ff               cmp eax, -1
// 00651ceb  750e                 jne 0x651cfb
// 00651ced  e8ae320000           call 0x654fa0
// 00651cf2  6a08                 push 8
// 00651cf4  8bc8                 mov ecx, eax
// 00651cf6  e8b52a0000           call 0x6547b0
// 00651cfb  5e                   pop esi
// 00651cfc  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetTreeTextColor@CXTPTreeBase@@MBEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
