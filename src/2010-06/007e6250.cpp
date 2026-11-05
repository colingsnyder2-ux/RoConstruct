// from server: 100% by auto
// roc 2010-06 007e6250  unit: CRobloxTreeCtrl  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e6250
//
// 007e6250  56                   push esi
// 007e6251  8bf1                 mov esi, ecx
// 007e6253  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e6256  e8876d1900           call 0x97cfe2
// 007e625b  85c0                 test eax, eax
// 007e625d  7510                 jne 0x7e626f
// 007e625f  e8bcd8ffff           call 0x7e3b20
// 007e6264  6a0f                 push 0xf
// 007e6266  8bc8                 mov ecx, eax
// 007e6268  e843d0ffff           call 0x7e32b0
// 007e626d  5e                   pop esi
// 007e626e  c3                   ret 
// 007e626f  e8fc950000           call 0x7ef870
// 007e6274  8bc8                 mov ecx, eax
// 007e6276  e8d5a50000           call 0x7f0850
// 007e627b  3d47000400           cmp eax, 0x40047
// 007e6280  721b                 jb 0x7e629d
// 007e6282  8b4634               mov eax, dword ptr [esi + 0x34]
// 007e6285  8b4020               mov eax, dword ptr [eax + 0x20]
// 007e6288  6a00                 push 0
// 007e628a  6a00                 push 0
// 007e628c  681f110000           push 0x111f
// 007e6291  50                   push eax
// 007e6292  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e6298  83f8ff               cmp eax, -1
// 007e629b  750e                 jne 0x7e62ab
// 007e629d  e87ed8ffff           call 0x7e3b20
// 007e62a2  6a05                 push 5
// 007e62a4  8bc8                 mov ecx, eax
// 007e62a6  e805d0ffff           call 0x7e32b0
// 007e62ab  5e                   pop esi
// 007e62ac  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?GetTreeBackColor@CXTTreeBase@@MBEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
