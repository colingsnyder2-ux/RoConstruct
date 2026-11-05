// from server: 100% by auto
// roc 2010-06 00813bc0  unit: CXTColorDialog  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00813bc0
//
// 00813bc0  56                   push esi
// 00813bc1  57                   push edi
// 00813bc2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00813bc6  57                   push edi
// 00813bc7  8bf1                 mov esi, ecx
// 00813bc9  ff1580c59e00         call dword ptr [0x9ec580]
// 00813bcf  8b4704               mov eax, dword ptr [edi + 4]
// 00813bd2  894604               mov dword ptr [esi + 4], eax
// 00813bd5  8b4f08               mov ecx, dword ptr [edi + 8]
// 00813bd8  894e08               mov dword ptr [esi + 8], ecx
// 00813bdb  8b570c               mov edx, dword ptr [edi + 0xc]
// 00813bde  89560c               mov dword ptr [esi + 0xc], edx
// 00813be1  8b4710               mov eax, dword ptr [edi + 0x10]
// 00813be4  894610               mov dword ptr [esi + 0x10], eax
// 00813be7  8b4f14               mov ecx, dword ptr [edi + 0x14]
// 00813bea  894e14               mov dword ptr [esi + 0x14], ecx
// 00813bed  8b5718               mov edx, dword ptr [edi + 0x18]
// 00813bf0  895618               mov dword ptr [esi + 0x18], edx
// 00813bf3  8b471c               mov eax, dword ptr [edi + 0x1c]
// 00813bf6  89461c               mov dword ptr [esi + 0x1c], eax
// 00813bf9  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 00813bfc  894e20               mov dword ptr [esi + 0x20], ecx
// 00813bff  8b5724               mov edx, dword ptr [edi + 0x24]
// 00813c02  8d4728               lea eax, [edi + 0x28]
// 00813c05  895624               mov dword ptr [esi + 0x24], edx
// 00813c08  8b08                 mov ecx, dword ptr [eax]
// 00813c0a  894e28               mov dword ptr [esi + 0x28], ecx
// 00813c0d  8b5004               mov edx, dword ptr [eax + 4]
// 00813c10  89562c               mov dword ptr [esi + 0x2c], edx
// 00813c13  8b4808               mov ecx, dword ptr [eax + 8]
// 00813c16  894e30               mov dword ptr [esi + 0x30], ecx
// 00813c19  8b500c               mov edx, dword ptr [eax + 0xc]
// 00813c1c  5f                   pop edi
// 00813c1d  895634               mov dword ptr [esi + 0x34], edx
// 00813c20  8bc6                 mov eax, esi
// 00813c22  5e                   pop esi
// 00813c23  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Common\XTPToolTipContext.cpp (function ??4TOOLITEM@CXTPToolTipContextToolTip@@QAEAAU01@ABU01@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPToolTipContext.cpp
