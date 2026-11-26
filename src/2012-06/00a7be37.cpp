// from server: 100% by Xemicl
// roc 2012-06 00a7be37  unit: CXTIconHandle  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7be37
//
// 00a7be37  8bff                 mov edi, edi
// 00a7be39  55                   push ebp
// 00a7be3a  8bec                 mov ebp, esp
// 00a7be3c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00a7be3f  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00a7be42  83caff               or edx, 0xffffffff
// 00a7be45  2bd0                 sub edx, eax
// 00a7be47  3bd1                 cmp edx, ecx
// 00a7be49  7307                 jae 0xa7be52
// 00a7be4b  b857000780           mov eax, 0x80070057
// 00a7be50  5d                   pop ebp
// 00a7be51  c3                   ret 
// 00a7be52  03c1                 add eax, ecx
// 00a7be54  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00a7be57  8901                 mov dword ptr [ecx], eax
// 00a7be59  33c0                 xor eax, eax
// 00a7be5b  5d                   pop ebp
// 00a7be5c  c3                   ret 
// copied from an identical function in another client (function ??$AtlAdd@K@ATL@@YAJPAKKK@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlstr.obj