// roc 2012-06 00a7b9c7  unit: CXTIconHandle  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7b9c7
//
// 00a7b9c7  8bff                 mov edi, edi
// 00a7b9c9  55                   push ebp
// 00a7b9ca  8bec                 mov ebp, esp
// 00a7b9cc  56                   push esi
// 00a7b9cd  57                   push edi
// 00a7b9ce  8bf1                 mov esi, ecx
// 00a7b9d0  8d7e14               lea edi, [esi + 0x14]
// 00a7b9d3  57                   push edi
// 00a7b9d4  ff15b821b200         call dword ptr [0xb221b8]
// 00a7b9da  8b4630               mov eax, dword ptr [esi + 0x30]
// 00a7b9dd  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00a7b9e0  3bc8                 cmp ecx, eax
// 00a7b9e2  7f23                 jg 0xa7ba07
// 00a7b9e4  85c9                 test ecx, ecx
// 00a7b9e6  7c1f                 jl 0xa7ba07
// 00a7b9e8  3bc8                 cmp ecx, eax
// 00a7b9ea  750e                 jne 0xa7b9fa
// 00a7b9ec  8b7608               mov esi, dword ptr [esi + 8]
// 00a7b9ef  57                   push edi
// 00a7b9f0  ff15b421b200         call dword ptr [0xb221b4]
// 00a7b9f6  8bc6                 mov eax, esi
// 00a7b9f8  eb16                 jmp 0xa7ba10
// 00a7b9fa  51                   push ecx
// 00a7b9fb  8d4e2c               lea ecx, [esi + 0x2c]
// 00a7b9fe  e864ffffff           call 0xa7b967
// 00a7ba03  8b30                 mov esi, dword ptr [eax]
// 00a7ba05  ebe8                 jmp 0xa7b9ef
// 00a7ba07  57                   push edi
// 00a7ba08  ff15b421b200         call dword ptr [0xb221b4]
// 00a7ba0e  33c0                 xor eax, eax
// 00a7ba10  5f                   pop edi
// 00a7ba11  5e                   pop esi
// 00a7ba12  5d                   pop ebp
// 00a7ba13  c20400               ret 4
// copied from an identical function in another client (function ?GetHInstanceAt@CAtlBaseModule@ATL@@QAEPAUHINSTANCE__@@H@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlbase.obj