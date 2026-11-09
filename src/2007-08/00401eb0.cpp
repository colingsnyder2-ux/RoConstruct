// from server: 100% by auto
// roc 2007-08 00401eb0  unit: VCWorkspace::?$CComObject  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401eb0
//
// 00401eb0  f60584ae8b0001       test byte ptr [0x8bae84], 1
// 00401eb7  7553                 jne 0x401f0c
// 00401eb9  830d84ae8b0001       or dword ptr [0x8bae84], 1
// 00401ec0  c70564ae8b00384a7800 mov dword ptr [0x8bae64], 0x784a38
// 00401eca  66c70568ae8b000800   mov word ptr [0x8bae68], 8
// 00401ed3  c7056cae8b00344a7800 mov dword ptr [0x8bae6c], 0x784a34
// 00401edd  66c70570ae8b000840   mov word ptr [0x8bae70], 0x4008
// 00401ee6  c70574ae8b00304a7800 mov dword ptr [0x8bae74], 0x784a30
// 00401ef0  66c70578ae8b001300   mov word ptr [0x8bae78], 0x13
// 00401ef9  c7057cae8b002c4a7800 mov dword ptr [0x8bae7c], 0x784a2c
// 00401f03  66c70580ae8b001100   mov word ptr [0x8bae80], 0x11
// 00401f0c  53                   push ebx
// 00401f0d  8b1df0d27700         mov ebx, dword ptr [0x77d2f0]
// 00401f13  56                   push esi
// 00401f14  57                   push edi
// 00401f15  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00401f19  33f6                 xor esi, esi
// 00401f1b  eb03                 jmp 0x401f20
// 00401f1d  8d4900               lea ecx, [ecx]
// 00401f20  8b04f564ae8b00       mov eax, dword ptr [esi*8 + 0x8bae64]
// 00401f27  50                   push eax
// 00401f28  57                   push edi
// 00401f29  ffd3                 call ebx
// 00401f2b  85c0                 test eax, eax
// 00401f2d  740e                 je 0x401f3d
// 00401f2f  83c601               add esi, 1
// 00401f32  83fe04               cmp esi, 4
// 00401f35  7ce9                 jl 0x401f20
// 00401f37  5f                   pop edi
// 00401f38  5e                   pop esi
// 00401f39  33c0                 xor eax, eax
// 00401f3b  5b                   pop ebx
// 00401f3c  c3                   ret 
// 00401f3d  668b0cf568ae8b00     mov cx, word ptr [esi*8 + 0x8bae68]
// 00401f45  8b542414             mov edx, dword ptr [esp + 0x14]
// 00401f49  5f                   pop edi
// 00401f4a  5e                   pop esi
// 00401f4b  66890a               mov word ptr [edx], cx
// 00401f4e  b801000000           mov eax, 1
// 00401f53  5b                   pop ebx
// 00401f54  c3                   ret 
// library atl-8.0/atl.cpp (function ?VTFromRegType@CRegParser@ATL@@KAHPBDAAG@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
