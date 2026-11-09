// from server: 100% by auto
// roc 2012-06 004043d0  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004043d0
//
// 004043d0  56                   push esi
// 004043d1  8bf1                 mov esi, ecx
// 004043d3  8b0e                 mov ecx, dword ptr [esi]
// 004043d5  33c0                 xor eax, eax
// 004043d7  85c9                 test ecx, ecx
// 004043d9  7416                 je 0x4043f1
// 004043db  51                   push ecx
// 004043dc  ff150420b200         call dword ptr [0xb22004]
// 004043e2  c70600000000         mov dword ptr [esi], 0
// 004043e8  c7460400000000       mov dword ptr [esi + 4], 0
// 004043ef  5e                   pop esi
// 004043f0  c3                   ret 
// 004043f1  894604               mov dword ptr [esi + 4], eax
// 004043f4  5e                   pop esi
// 004043f5  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?Close@CRegKey@ATL@@QAEJXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
