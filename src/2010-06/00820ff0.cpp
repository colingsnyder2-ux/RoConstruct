// from server: 100% by auto
// roc 2010-06 00820ff0  unit: CSelectionCaption  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00820ff0
//
// 00820ff0  8b442404             mov eax, dword ptr [esp + 4]
// 00820ff4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00820ff8  57                   push edi
// 00820ff9  8bf9                 mov edi, ecx
// 00820ffb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00820fff  894770               mov dword ptr [edi + 0x70], eax
// 00821002  8b87fc000000         mov eax, dword ptr [edi + 0xfc]
// 00821008  50                   push eax
// 00821009  c6878000000001       mov byte ptr [edi + 0x80], 1
// 00821010  894f74               mov dword ptr [edi + 0x74], ecx
// 00821013  895778               mov dword ptr [edi + 0x78], edx
// 00821016  ff1528bc9e00         call dword ptr [0x9ebc28]
// 0082101c  85c0                 test eax, eax
// 0082101e  7441                 je 0x821061
// 00821020  8b97dc000000         mov edx, dword ptr [edi + 0xdc]
// 00821026  8b4774               mov eax, dword ptr [edi + 0x74]
// 00821029  8b9274010000         mov edx, dword ptr [edx + 0x174]
// 0082102f  56                   push esi
// 00821030  8db7dc000000         lea esi, [edi + 0xdc]
// 00821036  50                   push eax
// 00821037  8bce                 mov ecx, esi
// 00821039  ffd2                 call edx
// 0082103b  8b4f78               mov ecx, dword ptr [edi + 0x78]
// 0082103e  8b06                 mov eax, dword ptr [esi]
// 00821040  8b9084010000         mov edx, dword ptr [eax + 0x184]
// 00821046  51                   push ecx
// 00821047  8bce                 mov ecx, esi
// 00821049  ffd2                 call edx
// 0082104b  8b3e                 mov edi, dword ptr [esi]
// 0082104d  6a15                 push 0x15
// 0082104f  ff1504ba9e00         call dword ptr [0x9eba04]
// 00821055  50                   push eax
// 00821056  8b8780010000         mov eax, dword ptr [edi + 0x180]
// 0082105c  8bce                 mov ecx, esi
// 0082105e  ffd0                 call eax
// 00821060  5e                   pop esi
// 00821061  5f                   pop edi
// 00821062  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\Controls\XTCaption.cpp (function ?SetCaptionColors@CXTCaption@@UAEXKKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTCaption.cpp
