// from server: 100% by Xemicl
// roc 2012-06 00a7bc16  unit: CXTIconHandle  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7bc16
//
// 00a7bc16  8bff                 mov edi, edi
// 00a7bc18  55                   push ebp
// 00a7bc19  8bec                 mov ebp, esp
// 00a7bc1b  8b4508               mov eax, dword ptr [ebp + 8]
// 00a7bc1e  85c0                 test eax, eax
// 00a7bc20  7c0e                 jl 0xa7bc30
// 00a7bc22  3b4104               cmp eax, dword ptr [ecx + 4]
// 00a7bc25  7d09                 jge 0xa7bc30
// 00a7bc27  8b09                 mov ecx, dword ptr [ecx]
// 00a7bc29  8d0441               lea eax, [ecx + eax*2]
// 00a7bc2c  5d                   pop ebp
// 00a7bc2d  c20400               ret 4
// 00a7bc30  6a00                 push 0
// 00a7bc32  6a00                 push 0
// 00a7bc34  6a01                 push 1
// 00a7bc36  688c0000c0           push 0xc000008c
// 00a7bc3b  ff15c021b200         call dword ptr [0xb221c0]
// copied from an identical function in another client (function ??A?$CSimpleArray@GV?$CSimpleArrayEqualHelper@G@ATL@@@ATL@@QAEAAGH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlwinmodule.obj