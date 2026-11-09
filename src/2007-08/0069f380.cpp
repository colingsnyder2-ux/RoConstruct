// from server: 100% by auto
// roc 2007-08 0069f380  unit: CSelectionCaption  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0069f380
//
// 0069f380  57                   push edi
// 0069f381  8bf9                 mov edi, ecx
// 0069f383  e8f8910900           call 0x738580
// 0069f388  80bf8000000000       cmp byte ptr [edi + 0x80], 0
// 0069f38f  756b                 jne 0x69f3fc
// 0069f391  53                   push ebx
// 0069f392  8b1d58ee7700         mov ebx, dword ptr [0x77ee58]
// 0069f398  6a12                 push 0x12
// 0069f39a  ffd3                 call ebx
// 0069f39c  6a0f                 push 0xf
// 0069f39e  894778               mov dword ptr [edi + 0x78], eax
// 0069f3a1  ffd3                 call ebx
// 0069f3a3  6a0f                 push 0xf
// 0069f3a5  894770               mov dword ptr [edi + 0x70], eax
// 0069f3a8  ffd3                 call ebx
// 0069f3aa  894774               mov dword ptr [edi + 0x74], eax
// 0069f3ad  8b87fc000000         mov eax, dword ptr [edi + 0xfc]
// 0069f3b3  50                   push eax
// 0069f3b4  ff15bced7700         call dword ptr [0x77edbc]
// 0069f3ba  85c0                 test eax, eax
// 0069f3bc  743d                 je 0x69f3fb
// 0069f3be  8b97dc000000         mov edx, dword ptr [edi + 0xdc]
// 0069f3c4  8b4774               mov eax, dword ptr [edi + 0x74]
// 0069f3c7  8b926c010000         mov edx, dword ptr [edx + 0x16c]
// 0069f3cd  56                   push esi
// 0069f3ce  8db7dc000000         lea esi, [edi + 0xdc]
// 0069f3d4  50                   push eax
// 0069f3d5  8bce                 mov ecx, esi
// 0069f3d7  ffd2                 call edx
// 0069f3d9  8b4f78               mov ecx, dword ptr [edi + 0x78]
// 0069f3dc  8b06                 mov eax, dword ptr [esi]
// 0069f3de  8b907c010000         mov edx, dword ptr [eax + 0x17c]
// 0069f3e4  51                   push ecx
// 0069f3e5  8bce                 mov ecx, esi
// 0069f3e7  ffd2                 call edx
// 0069f3e9  8b3e                 mov edi, dword ptr [esi]
// 0069f3eb  6a15                 push 0x15
// 0069f3ed  ffd3                 call ebx
// 0069f3ef  50                   push eax
// 0069f3f0  8b8778010000         mov eax, dword ptr [edi + 0x178]
// 0069f3f6  8bce                 mov ecx, esi
// 0069f3f8  ffd0                 call eax
// 0069f3fa  5e                   pop esi
// 0069f3fb  5b                   pop ebx
// 0069f3fc  5f                   pop edi
// 0069f3fd  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaption.cpp (function ?OnSysColorChange@CXTCaption@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaption.cpp
