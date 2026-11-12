// from server: 100% by auto
// roc 2008-06 004bbf90  unit: ProfiledRakPeer  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bbf90
//
// 004bbf90  56                   push esi
// 004bbf91  8bf1                 mov esi, ecx
// 004bbf93  8b86a4080000         mov eax, dword ptr [esi + 0x8a4]
// 004bbf99  8b8ea8080000         mov ecx, dword ptr [esi + 0x8a8]
// 004bbf9f  8b96ac080000         mov edx, dword ptr [esi + 0x8ac]
// 004bbfa5  8986b8080000         mov dword ptr [esi + 0x8b8], eax
// 004bbfab  8b86b0080000         mov eax, dword ptr [esi + 0x8b0]
// 004bbfb1  898ebc080000         mov dword ptr [esi + 0x8bc], ecx
// 004bbfb7  8b8eb4080000         mov ecx, dword ptr [esi + 0x8b4]
// 004bbfbd  8996c0080000         mov dword ptr [esi + 0x8c0], edx
// 004bbfc3  57                   push edi
// 004bbfc4  8986c4080000         mov dword ptr [esi + 0x8c4], eax
// 004bbfca  898ec8080000         mov dword ptr [esi + 0x8c8], ecx
// 004bbfd0  33ff                 xor edi, edi
// 004bbfd2  e849810100           call 0x4d4120
// 004bbfd7  89843ea4080000       mov dword ptr [esi + edi + 0x8a4], eax
// 004bbfde  83c704               add edi, 4
// 004bbfe1  83ff14               cmp edi, 0x14
// 004bbfe4  7cec                 jl 0x4bbfd2
// 004bbfe6  e825d90000           call 0x4c9910
// 004bbfeb  0510270000           add eax, 0x2710
// 004bbff0  5f                   pop edi
// 004bbff1  8986a0080000         mov dword ptr [esi + 0x8a0], eax
// 004bbff7  5e                   pop esi
// 004bbff8  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ?GenerateSYNCookieRandomNumber@RakPeer@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
