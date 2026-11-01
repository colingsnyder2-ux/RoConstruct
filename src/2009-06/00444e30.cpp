// from server: 100% by auto
// roc 2009-06 00444e30  unit: G3D::_WeakPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00444e30
//
// 00444e30  85c0                 test eax, eax
// 00444e32  7501                 jne 0x444e35
// 00444e34  c3                   ret 
// 00444e35  8a08                 mov cl, byte ptr [eax]
// 00444e37  56                   push esi
// 00444e38  33f6                 xor esi, esi
// 00444e3a  84c9                 test cl, cl
// 00444e3c  7427                 je 0x444e65
// 00444e3e  57                   push edi
// 00444e3f  8b3d80ee8900         mov edi, dword ptr [0x89ee80]
// 00444e45  80f92e               cmp cl, 0x2e
// 00444e48  7409                 je 0x444e53
// 00444e4a  80f95c               cmp cl, 0x5c
// 00444e4d  7506                 jne 0x444e55
// 00444e4f  33f6                 xor esi, esi
// 00444e51  eb02                 jmp 0x444e55
// 00444e53  8bf0                 mov esi, eax
// 00444e55  50                   push eax
// 00444e56  ffd7                 call edi
// 00444e58  8a08                 mov cl, byte ptr [eax]
// 00444e5a  84c9                 test cl, cl
// 00444e5c  75e7                 jne 0x444e45
// 00444e5e  5f                   pop edi
// 00444e5f  85f6                 test esi, esi
// 00444e61  7402                 je 0x444e65
// 00444e63  8bc6                 mov eax, esi
// 00444e65  5e                   pop esi
// 00444e66  c3                   ret 
// library atl-9.0/atl.cpp (function ?AtlFindExtension@ATL@@YAPADPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
