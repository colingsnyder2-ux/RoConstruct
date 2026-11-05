// from server: 100% by auto
// roc 2012-06 00404560  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404560
//
// 00404560  56                   push esi
// 00404561  8bf1                 mov esi, ecx
// 00404563  8b06                 mov eax, dword ptr [esi]
// 00404565  57                   push edi
// 00404566  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0040456a  8d4c3801             lea ecx, [eax + edi + 1]
// 0040456e  3bc8                 cmp ecx, eax
// 00404570  7e7d                 jle 0x4045ef
// 00404572  3bcf                 cmp ecx, edi
// 00404574  7e79                 jle 0x4045ef
// 00404576  3b4e04               cmp ecx, dword ptr [esi + 4]
// 00404579  7c35                 jl 0x4045b0
// 0040457b  eb03                 jmp 0x404580
// 0040457d  8d4900               lea ecx, [ecx]
// 00404580  8b4604               mov eax, dword ptr [esi + 4]
// 00404583  3dffffff3f           cmp eax, 0x3fffffff
// 00404588  7f65                 jg 0x4045ef
// 0040458a  03c0                 add eax, eax
// 0040458c  3bc8                 cmp ecx, eax
// 0040458e  894604               mov dword ptr [esi + 4], eax
// 00404591  7ded                 jge 0x404580
// 00404593  33c9                 xor ecx, ecx
// 00404595  8b5608               mov edx, dword ptr [esi + 8]
// 00404598  7755                 ja 0x4045ef
// 0040459a  7205                 jb 0x4045a1
// 0040459c  83f8ff               cmp eax, -1
// 0040459f  774e                 ja 0x4045ef
// 004045a1  50                   push eax
// 004045a2  52                   push edx
// 004045a3  ff150c51b200         call dword ptr [0xb2510c]
// 004045a9  85c0                 test eax, eax
// 004045ab  7442                 je 0x4045ef
// 004045ad  894608               mov dword ptr [esi + 8], eax
// 004045b0  8b06                 mov eax, dword ptr [esi]
// 004045b2  85c0                 test eax, eax
// 004045b4  7c39                 jl 0x4045ef
// 004045b6  8b5604               mov edx, dword ptr [esi + 4]
// 004045b9  3bc2                 cmp eax, edx
// 004045bb  7d32                 jge 0x4045ef
// 004045bd  8bca                 mov ecx, edx
// 004045bf  2bc8                 sub ecx, eax
// 004045c1  3bca                 cmp ecx, edx
// 004045c3  7f2a                 jg 0x4045ef
// 004045c5  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004045c9  57                   push edi
// 004045ca  52                   push edx
// 004045cb  51                   push ecx
// 004045cc  8b4e08               mov ecx, dword ptr [esi + 8]
// 004045cf  03c8                 add ecx, eax
// 004045d1  51                   push ecx
// 004045d2  e8f9fbffff           call 0x4041d0
// 004045d7  8b5608               mov edx, dword ptr [esi + 8]
// 004045da  83c410               add esp, 0x10
// 004045dd  013e                 add dword ptr [esi], edi
// 004045df  8b06                 mov eax, dword ptr [esi]
// 004045e1  5f                   pop edi
// 004045e2  c6041000             mov byte ptr [eax + edx], 0
// 004045e6  b801000000           mov eax, 1
// 004045eb  5e                   pop esi
// 004045ec  c20800               ret 8
// 004045ef  5f                   pop edi
// 004045f0  33c0                 xor eax, eax
// 004045f2  5e                   pop esi
// 004045f3  c20800               ret 8
// library atl-8.0/atl.cpp (function ?Append@CParseBuffer@CRegParser@ATL@@QAEHPBDH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
