// from server: 100% by auto
// roc 2011-06 004624e0  unit: CRobloxApp  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004624e0
//
// 004624e0  56                   push esi
// 004624e1  8bf1                 mov esi, ecx
// 004624e3  56                   push esi
// 004624e4  ff15d80aa400         call dword ptr [0xa40ad8]
// 004624ea  85c0                 test eax, eax
// 004624ec  7c10                 jl 0x4624fe
// 004624ee  33c9                 xor ecx, ecx
// 004624f0  890e                 mov dword ptr [esi], ecx
// 004624f2  894e04               mov dword ptr [esi + 4], ecx
// 004624f5  894e08               mov dword ptr [esi + 8], ecx
// 004624f8  894e0c               mov dword ptr [esi + 0xc], ecx
// 004624fb  66890e               mov word ptr [esi], cx
// 004624fe  5e                   pop esi
// 004624ff  c3                   ret 
// library atl-9.0/atl.cpp (function ?ClearToZero@CComVariant@ATL@@QAEJXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
