// from server: 100% by auto
// roc 2010-06 00403020  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00403020
//
// 00403020  56                   push esi
// 00403021  8bf1                 mov esi, ecx
// 00403023  8b06                 mov eax, dword ptr [esi]
// 00403025  57                   push edi
// 00403026  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0040302a  8d4c3801             lea ecx, [eax + edi + 1]
// 0040302e  3bc8                 cmp ecx, eax
// 00403030  7e7d                 jle 0x4030af
// 00403032  3bcf                 cmp ecx, edi
// 00403034  7e79                 jle 0x4030af
// 00403036  3b4e04               cmp ecx, dword ptr [esi + 4]
// 00403039  7c35                 jl 0x403070
// 0040303b  eb03                 jmp 0x403040
// 0040303d  8d4900               lea ecx, [ecx]
// 00403040  8b4604               mov eax, dword ptr [esi + 4]
// 00403043  3dffffff3f           cmp eax, 0x3fffffff
// 00403048  7f65                 jg 0x4030af
// 0040304a  03c0                 add eax, eax
// 0040304c  3bc8                 cmp ecx, eax
// 0040304e  894604               mov dword ptr [esi + 4], eax
// 00403051  7ded                 jge 0x403040
// 00403053  33c9                 xor ecx, ecx
// 00403055  8b5608               mov edx, dword ptr [esi + 8]
// 00403058  7755                 ja 0x4030af
// 0040305a  7205                 jb 0x403061
// 0040305c  83f8ff               cmp eax, -1
// 0040305f  774e                 ja 0x4030af
// 00403061  50                   push eax
// 00403062  52                   push edx
// 00403063  ff15d4d09e00         call dword ptr [0x9ed0d4]
// 00403069  85c0                 test eax, eax
// 0040306b  7442                 je 0x4030af
// 0040306d  894608               mov dword ptr [esi + 8], eax
// 00403070  8b06                 mov eax, dword ptr [esi]
// 00403072  85c0                 test eax, eax
// 00403074  7c39                 jl 0x4030af
// 00403076  8b5604               mov edx, dword ptr [esi + 4]
// 00403079  3bc2                 cmp eax, edx
// 0040307b  7d32                 jge 0x4030af
// 0040307d  8bca                 mov ecx, edx
// 0040307f  2bc8                 sub ecx, eax
// 00403081  3bca                 cmp ecx, edx
// 00403083  7f2a                 jg 0x4030af
// 00403085  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00403089  57                   push edi
// 0040308a  52                   push edx
// 0040308b  51                   push ecx
// 0040308c  8b4e08               mov ecx, dword ptr [esi + 8]
// 0040308f  03c8                 add ecx, eax
// 00403091  51                   push ecx
// 00403092  e859fbffff           call 0x402bf0
// 00403097  8b5608               mov edx, dword ptr [esi + 8]
// 0040309a  83c410               add esp, 0x10
// 0040309d  013e                 add dword ptr [esi], edi
// 0040309f  8b06                 mov eax, dword ptr [esi]
// 004030a1  5f                   pop edi
// 004030a2  c6041000             mov byte ptr [eax + edx], 0
// 004030a6  b801000000           mov eax, 1
// 004030ab  5e                   pop esi
// 004030ac  c20800               ret 8
// 004030af  5f                   pop edi
// 004030b0  33c0                 xor eax, eax
// 004030b2  5e                   pop esi
// 004030b3  c20800               ret 8
// library atl-8.0/atl.cpp (function ?Append@CParseBuffer@CRegParser@ATL@@QAEHPBDH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
