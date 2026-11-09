// from server: 100% by auto
// roc 2011-06 00403880  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403880
//
// 00403880  56                   push esi
// 00403881  8bf1                 mov esi, ecx
// 00403883  8b0e                 mov ecx, dword ptr [esi]
// 00403885  33c0                 xor eax, eax
// 00403887  85c9                 test ecx, ecx
// 00403889  7416                 je 0x4038a1
// 0040388b  51                   push ecx
// 0040388c  ff150400a400         call dword ptr [0xa40004]
// 00403892  c70600000000         mov dword ptr [esi], 0
// 00403898  c7460400000000       mov dword ptr [esi + 4], 0
// 0040389f  5e                   pop esi
// 004038a0  c3                   ret 
// 004038a1  894604               mov dword ptr [esi + 4], eax
// 004038a4  5e                   pop esi
// 004038a5  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?Close@CRegKey@ATL@@QAEJXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
