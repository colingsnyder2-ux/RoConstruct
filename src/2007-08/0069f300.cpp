// from server: 100% by auto
// roc 2007-08 0069f300  unit: CSelectionCaption  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0069f300
//
// 0069f300  8b442404             mov eax, dword ptr [esp + 4]
// 0069f304  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0069f308  57                   push edi
// 0069f309  8bf9                 mov edi, ecx
// 0069f30b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0069f30f  894770               mov dword ptr [edi + 0x70], eax
// 0069f312  8b87fc000000         mov eax, dword ptr [edi + 0xfc]
// 0069f318  50                   push eax
// 0069f319  c6878000000001       mov byte ptr [edi + 0x80], 1
// 0069f320  894f74               mov dword ptr [edi + 0x74], ecx
// 0069f323  895778               mov dword ptr [edi + 0x78], edx
// 0069f326  ff15bced7700         call dword ptr [0x77edbc]
// 0069f32c  85c0                 test eax, eax
// 0069f32e  7441                 je 0x69f371
// 0069f330  8b97dc000000         mov edx, dword ptr [edi + 0xdc]
// 0069f336  8b4774               mov eax, dword ptr [edi + 0x74]
// 0069f339  8b926c010000         mov edx, dword ptr [edx + 0x16c]
// 0069f33f  56                   push esi
// 0069f340  8db7dc000000         lea esi, [edi + 0xdc]
// 0069f346  50                   push eax
// 0069f347  8bce                 mov ecx, esi
// 0069f349  ffd2                 call edx
// 0069f34b  8b4f78               mov ecx, dword ptr [edi + 0x78]
// 0069f34e  8b06                 mov eax, dword ptr [esi]
// 0069f350  8b907c010000         mov edx, dword ptr [eax + 0x17c]
// 0069f356  51                   push ecx
// 0069f357  8bce                 mov ecx, esi
// 0069f359  ffd2                 call edx
// 0069f35b  8b3e                 mov edi, dword ptr [esi]
// 0069f35d  6a15                 push 0x15
// 0069f35f  ff1558ee7700         call dword ptr [0x77ee58]
// 0069f365  50                   push eax
// 0069f366  8b8778010000         mov eax, dword ptr [edi + 0x178]
// 0069f36c  8bce                 mov ecx, esi
// 0069f36e  ffd0                 call eax
// 0069f370  5e                   pop esi
// 0069f371  5f                   pop edi
// 0069f372  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaption.cpp (function ?SetCaptionColors@CXTCaption@@UAEXKKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaption.cpp
