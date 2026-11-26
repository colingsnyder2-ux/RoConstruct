// from server: 100% by Xemicl
// roc 2012-06 00a7b967  unit: CXTIconHandle  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7b967
//
// 00a7b967  8bff                 mov edi, edi
// 00a7b969  55                   push ebp
// 00a7b96a  8bec                 mov ebp, esp
// 00a7b96c  8b4508               mov eax, dword ptr [ebp + 8]
// 00a7b96f  85c0                 test eax, eax
// 00a7b971  7c0e                 jl 0xa7b981
// 00a7b973  3b4104               cmp eax, dword ptr [ecx + 4]
// 00a7b976  7d09                 jge 0xa7b981
// 00a7b978  8b09                 mov ecx, dword ptr [ecx]
// 00a7b97a  8d0481               lea eax, [ecx + eax*4]
// 00a7b97d  5d                   pop ebp
// 00a7b97e  c20400               ret 4
// 00a7b981  6a00                 push 0
// 00a7b983  6a00                 push 0
// 00a7b985  6a01                 push 1
// 00a7b987  688c0000c0           push 0xc000008c
// 00a7b98c  ff15c021b200         call dword ptr [0xb221c0]
// copied from an identical function in another client (function ??A?$CSimpleArray@PAUHINSTANCE__@@V?$CSimpleArrayEqualHelper@PAUHINSTANCE__@@@ATL@@@ATL@@QAEAAPAUHINSTANCE__@@H@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlbase.obj