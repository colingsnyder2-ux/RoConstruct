// from server: 100% by auto
// roc 2009-12 0080a2e0  unit: CXTPImageManagerResource::CBitmapDC  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080a2e0
//
// 0080a2e0  83ec0c               sub esp, 0xc
// 0080a2e3  56                   push esi
// 0080a2e4  8bf1                 mov esi, ecx
// 0080a2e6  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0080a2e9  f7d8                 neg eax
// 0080a2eb  1bc0                 sbb eax, eax
// 0080a2ed  89442404             mov dword ptr [esp + 4], eax
// 0080a2f1  742b                 je 0x80a31e
// 0080a2f3  57                   push edi
// 0080a2f4  8d7e10               lea edi, [esi + 0x10]
// 0080a2f7  8d44240c             lea eax, [esp + 0xc]
// 0080a2fb  50                   push eax
// 0080a2fc  8d4c2414             lea ecx, [esp + 0x14]
// 0080a300  51                   push ecx
// 0080a301  8d542410             lea edx, [esp + 0x10]
// 0080a305  52                   push edx
// 0080a306  8bcf                 mov ecx, edi
// 0080a308  e813f5ffff           call 0x809820
// 0080a30d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0080a311  e8c69afeff           call 0x7f3ddc
// 0080a316  837c240800           cmp dword ptr [esp + 8], 0
// 0080a31b  75da                 jne 0x80a2f7
// 0080a31d  5f                   pop edi
// 0080a31e  8d4e10               lea ecx, [esi + 0x10]
// 0080a321  5e                   pop esi
// 0080a322  83c40c               add esp, 0xc
// 0080a325  e9f6c1feff           jmp 0x7f6520
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?RemoveAll@CXTPImageManagerImageList@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
