// from server: 100% by auto
// roc 2010-06 007e62b0  unit: CRobloxTreeCtrl  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e62b0
//
// 007e62b0  56                   push esi
// 007e62b1  8bf1                 mov esi, ecx
// 007e62b3  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e62b6  e8276d1900           call 0x97cfe2
// 007e62bb  85c0                 test eax, eax
// 007e62bd  7510                 jne 0x7e62cf
// 007e62bf  e85cd8ffff           call 0x7e3b20
// 007e62c4  6a11                 push 0x11
// 007e62c6  8bc8                 mov ecx, eax
// 007e62c8  e8e3cfffff           call 0x7e32b0
// 007e62cd  5e                   pop esi
// 007e62ce  c3                   ret 
// 007e62cf  e89c950000           call 0x7ef870
// 007e62d4  8bc8                 mov ecx, eax
// 007e62d6  e875a50000           call 0x7f0850
// 007e62db  3d47000400           cmp eax, 0x40047
// 007e62e0  721b                 jb 0x7e62fd
// 007e62e2  8b4634               mov eax, dword ptr [esi + 0x34]
// 007e62e5  8b4020               mov eax, dword ptr [eax + 0x20]
// 007e62e8  6a00                 push 0
// 007e62ea  6a00                 push 0
// 007e62ec  6820110000           push 0x1120
// 007e62f1  50                   push eax
// 007e62f2  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e62f8  83f8ff               cmp eax, -1
// 007e62fb  750e                 jne 0x7e630b
// 007e62fd  e81ed8ffff           call 0x7e3b20
// 007e6302  6a08                 push 8
// 007e6304  8bc8                 mov ecx, eax
// 007e6306  e8a5cfffff           call 0x7e32b0
// 007e630b  5e                   pop esi
// 007e630c  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?GetTreeTextColor@CXTTreeBase@@MBEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
