// from server: 100% by auto
// roc 2011-06 00871460  unit: CXTColorDialog  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00871460
//
// 00871460  56                   push esi
// 00871461  57                   push edi
// 00871462  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00871466  57                   push edi
// 00871467  8bf1                 mov esi, ecx
// 00871469  ff156425a400         call dword ptr [0xa42564]
// 0087146f  8b4704               mov eax, dword ptr [edi + 4]
// 00871472  894604               mov dword ptr [esi + 4], eax
// 00871475  8b4f08               mov ecx, dword ptr [edi + 8]
// 00871478  894e08               mov dword ptr [esi + 8], ecx
// 0087147b  8b570c               mov edx, dword ptr [edi + 0xc]
// 0087147e  89560c               mov dword ptr [esi + 0xc], edx
// 00871481  8b4710               mov eax, dword ptr [edi + 0x10]
// 00871484  894610               mov dword ptr [esi + 0x10], eax
// 00871487  8b4f14               mov ecx, dword ptr [edi + 0x14]
// 0087148a  894e14               mov dword ptr [esi + 0x14], ecx
// 0087148d  8b5718               mov edx, dword ptr [edi + 0x18]
// 00871490  895618               mov dword ptr [esi + 0x18], edx
// 00871493  8b471c               mov eax, dword ptr [edi + 0x1c]
// 00871496  89461c               mov dword ptr [esi + 0x1c], eax
// 00871499  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 0087149c  894e20               mov dword ptr [esi + 0x20], ecx
// 0087149f  8b5724               mov edx, dword ptr [edi + 0x24]
// 008714a2  8d4728               lea eax, [edi + 0x28]
// 008714a5  895624               mov dword ptr [esi + 0x24], edx
// 008714a8  8b08                 mov ecx, dword ptr [eax]
// 008714aa  894e28               mov dword ptr [esi + 0x28], ecx
// 008714ad  8b5004               mov edx, dword ptr [eax + 4]
// 008714b0  89562c               mov dword ptr [esi + 0x2c], edx
// 008714b3  8b4808               mov ecx, dword ptr [eax + 8]
// 008714b6  894e30               mov dword ptr [esi + 0x30], ecx
// 008714b9  8b500c               mov edx, dword ptr [eax + 0xc]
// 008714bc  5f                   pop edi
// 008714bd  895634               mov dword ptr [esi + 0x34], edx
// 008714c0  8bc6                 mov eax, esi
// 008714c2  5e                   pop esi
// 008714c3  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Common\XTPToolTipContext.cpp (function ??4TOOLITEM@CXTPToolTipContextToolTip@@QAEAAU01@ABU01@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPToolTipContext.cpp
