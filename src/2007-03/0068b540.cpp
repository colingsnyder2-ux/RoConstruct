// from server: 100% by auto
// roc 2007-03 0068b540  unit: seg_00680000  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068b540
//
// 0068b540  57                   push edi
// 0068b541  8bf9                 mov edi, ecx
// 0068b543  e884f70a00           call 0x73accc
// 0068b548  80bf8000000000       cmp byte ptr [edi + 0x80], 0
// 0068b54f  756b                 jne 0x68b5bc
// 0068b551  53                   push ebx
// 0068b552  8b1d38ef7700         mov ebx, dword ptr [0x77ef38]
// 0068b558  6a12                 push 0x12
// 0068b55a  ffd3                 call ebx
// 0068b55c  6a0f                 push 0xf
// 0068b55e  894778               mov dword ptr [edi + 0x78], eax
// 0068b561  ffd3                 call ebx
// 0068b563  6a0f                 push 0xf
// 0068b565  894770               mov dword ptr [edi + 0x70], eax
// 0068b568  ffd3                 call ebx
// 0068b56a  894774               mov dword ptr [edi + 0x74], eax
// 0068b56d  8b87fc000000         mov eax, dword ptr [edi + 0xfc]
// 0068b573  50                   push eax
// 0068b574  ff1574ed7700         call dword ptr [0x77ed74]
// 0068b57a  85c0                 test eax, eax
// 0068b57c  743d                 je 0x68b5bb
// 0068b57e  8b97dc000000         mov edx, dword ptr [edi + 0xdc]
// 0068b584  8b4774               mov eax, dword ptr [edi + 0x74]
// 0068b587  8b926c010000         mov edx, dword ptr [edx + 0x16c]
// 0068b58d  56                   push esi
// 0068b58e  8db7dc000000         lea esi, [edi + 0xdc]
// 0068b594  50                   push eax
// 0068b595  8bce                 mov ecx, esi
// 0068b597  ffd2                 call edx
// 0068b599  8b4f78               mov ecx, dword ptr [edi + 0x78]
// 0068b59c  8b06                 mov eax, dword ptr [esi]
// 0068b59e  8b907c010000         mov edx, dword ptr [eax + 0x17c]
// 0068b5a4  51                   push ecx
// 0068b5a5  8bce                 mov ecx, esi
// 0068b5a7  ffd2                 call edx
// 0068b5a9  8b3e                 mov edi, dword ptr [esi]
// 0068b5ab  6a15                 push 0x15
// 0068b5ad  ffd3                 call ebx
// 0068b5af  50                   push eax
// 0068b5b0  8b8778010000         mov eax, dword ptr [edi + 0x178]
// 0068b5b6  8bce                 mov ecx, esi
// 0068b5b8  ffd0                 call eax
// 0068b5ba  5e                   pop esi
// 0068b5bb  5b                   pop ebx
// 0068b5bc  5f                   pop edi
// 0068b5bd  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaption.cpp (function ?OnSysColorChange@CXTCaption@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaption.cpp
