// from server: 100% by auto
// roc 2011-06 0085f900  unit: CXTPPropExchange  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0085f900
//
// 0085f900  837c240800           cmp dword ptr [esp + 8], 0
// 0085f905  56                   push esi
// 0085f906  8b742408             mov esi, dword ptr [esp + 8]
// 0085f90a  8bce                 mov ecx, esi
// 0085f90c  746f                 je 0x85f97d
// 0085f90e  6a00                 push 0
// 0085f910  6a5c                 push 0x5c
// 0085f912  ff154c27a400         call dword ptr [0xa4274c]
// 0085f918  83f8ff               cmp eax, -1
// 0085f91b  0f84a2000000         je 0x85f9c3
// 0085f921  6888a9ac00           push 0xaca988
// 0085f926  68bcffa700           push 0xa7ffbc
// 0085f92b  8bce                 mov ecx, esi
// 0085f92d  ff15b828a400         call dword ptr [0xa428b8]
// 0085f933  687442a600           push 0xa64274
// 0085f938  68c4ffa700           push 0xa7ffc4
// 0085f93d  8bce                 mov ecx, esi
// 0085f93f  ff15b828a400         call dword ptr [0xa428b8]
// 0085f945  6884a9ac00           push 0xaca984
// 0085f94a  68c8ffa700           push 0xa7ffc8
// 0085f94f  8bce                 mov ecx, esi
// 0085f951  ff15b828a400         call dword ptr [0xa428b8]
// 0085f957  68f8eba600           push 0xa6ebf8
// 0085f95c  68c0ffa700           push 0xa7ffc0
// 0085f961  8bce                 mov ecx, esi
// 0085f963  ff15b828a400         call dword ptr [0xa428b8]
// 0085f969  684858a600           push 0xa65848
// 0085f96e  6888a9ac00           push 0xaca988
// 0085f973  8bce                 mov ecx, esi
// 0085f975  ff15b828a400         call dword ptr [0xa428b8]
// 0085f97b  5e                   pop esi
// 0085f97c  c3                   ret 
// 0085f97d  68bcffa700           push 0xa7ffbc
// 0085f982  684858a600           push 0xa65848
// 0085f987  ff15b828a400         call dword ptr [0xa428b8]
// 0085f98d  68c4ffa700           push 0xa7ffc4
// 0085f992  687442a600           push 0xa64274
// 0085f997  8bce                 mov ecx, esi
// 0085f999  ff15b828a400         call dword ptr [0xa428b8]
// 0085f99f  68c8ffa700           push 0xa7ffc8
// 0085f9a4  6884a9ac00           push 0xaca984
// 0085f9a9  8bce                 mov ecx, esi
// 0085f9ab  ff15b828a400         call dword ptr [0xa428b8]
// 0085f9b1  68c0ffa700           push 0xa7ffc0
// 0085f9b6  68f8eba600           push 0xa6ebf8
// 0085f9bb  8bce                 mov ecx, esi
// 0085f9bd  ff15b828a400         call dword ptr [0xa428b8]
// 0085f9c3  5e                   pop esi
// 0085f9c4  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?PreformatString@CXTPPropExchange@@SAXAAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
