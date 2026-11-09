// roc 2012-06 00a7bc5e  unit: CXTIconHandle  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7bc5e
//
// 00a7bc5e  8bff                 mov edi, edi
// 00a7bc60  55                   push ebp
// 00a7bc61  8bec                 mov ebp, esp
// 00a7bc63  56                   push esi
// 00a7bc64  8b7508               mov esi, dword ptr [ebp + 8]
// 00a7bc67  57                   push edi
// 00a7bc68  33ff                 xor edi, edi
// 00a7bc6a  3bf7                 cmp esi, edi
// 00a7bc6c  7507                 jne 0xa7bc75
// 00a7bc6e  b857000780           mov eax, 0x80070057
// 00a7bc73  eb47                 jmp 0xa7bcbc
// 00a7bc75  8b06                 mov eax, dword ptr [esi]
// 00a7bc77  3bc7                 cmp eax, edi
// 00a7bc79  743f                 je 0xa7bcba
// 00a7bc7b  83f82c               cmp eax, 0x2c
// 00a7bc7e  75ee                 jne 0xa7bc6e
// 00a7bc80  397e24               cmp dword ptr [esi + 0x24], edi
// 00a7bc83  7e20                 jle 0xa7bca5
// 00a7bc85  53                   push ebx
// 00a7bc86  8d5e20               lea ebx, [esi + 0x20]
// 00a7bc89  57                   push edi
// 00a7bc8a  8bcb                 mov ecx, ebx
// 00a7bc8c  e885ffffff           call 0xa7bc16
// 00a7bc91  0fb700               movzx eax, word ptr [eax]
// 00a7bc94  ff750c               push dword ptr [ebp + 0xc]
// 00a7bc97  50                   push eax
// 00a7bc98  ff15a03ab200         call dword ptr [0xb23aa0]
// 00a7bc9e  47                   inc edi
// 00a7bc9f  3b7e24               cmp edi, dword ptr [esi + 0x24]
// 00a7bca2  7ce5                 jl 0xa7bc89
// 00a7bca4  5b                   pop ebx
// 00a7bca5  8d4e20               lea ecx, [esi + 0x20]
// 00a7bca8  e89bfcffff           call 0xa7b948
// 00a7bcad  8d4604               lea eax, [esi + 4]
// 00a7bcb0  50                   push eax
// 00a7bcb1  ff15d821b200         call dword ptr [0xb221d8]
// 00a7bcb7  832600               and dword ptr [esi], 0
// 00a7bcba  33c0                 xor eax, eax
// 00a7bcbc  5f                   pop edi
// 00a7bcbd  5e                   pop esi
// 00a7bcbe  5d                   pop ebp
// 00a7bcbf  c20800               ret 8
// copied from an identical function in another client (function ?AtlWinModuleTerm@ATL@@YGJPAU_ATL_WIN_MODULE70@1@PAUHINSTANCE__@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlwinmodule.obj