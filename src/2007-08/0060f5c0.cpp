// from server: 100% by auto
// roc 2007-08 0060f5c0  unit: RBX::Ball  size: 248 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0060f5c0
//
// 0060f5c0  53                   push ebx
// 0060f5c1  8bd8                 mov ebx, eax
// 0060f5c3  56                   push esi
// 0060f5c4  8b7324               mov esi, dword ptr [ebx + 0x24]
// 0060f5c7  0fb64604             movzx eax, byte ptr [esi + 4]
// 0060f5cb  804e0504             or byte ptr [esi + 5], 4
// 0060f5cf  83c0fb               add eax, -5
// 0060f5d2  83f804               cmp eax, 4
// 0060f5d5  0f87c4000000         ja 0x60f69f
// 0060f5db  ff2485a4f66000       jmp dword ptr [eax*4 + 0x60f6a4]
// 0060f5e2  8b4618               mov eax, dword ptr [esi + 0x18]
// 0060f5e5  56                   push esi
// 0060f5e6  53                   push ebx
// 0060f5e7  894324               mov dword ptr [ebx + 0x24], eax
// 0060f5ea  e8a1fbffff           call 0x60f190
// 0060f5ef  83c408               add esp, 8
// 0060f5f2  85c0                 test eax, eax
// 0060f5f4  7404                 je 0x60f5fa
// 0060f5f6  806605fb             and byte ptr [esi + 5], 0xfb
// 0060f5fa  8a4e07               mov cl, byte ptr [esi + 7]
// 0060f5fd  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0060f600  ba01000000           mov edx, 1
// 0060f605  d3e2                 shl edx, cl
// 0060f607  5e                   pop esi
// 0060f608  5b                   pop ebx
// 0060f609  8d445002             lea eax, [eax + edx*2 + 2]
// 0060f60d  c1e004               shl eax, 4
// 0060f610  c3                   ret 
// 0060f611  8b4e08               mov ecx, dword ptr [esi + 8]
// 0060f614  894b24               mov dword ptr [ebx + 0x24], ecx
// 0060f617  e814feffff           call 0x60f430
// 0060f61c  807e0600             cmp byte ptr [esi + 6], 0
// 0060f620  0fb64607             movzx eax, byte ptr [esi + 7]
// 0060f624  7409                 je 0x60f62f
// 0060f626  c1e004               shl eax, 4
// 0060f629  5e                   pop esi
// 0060f62a  83c018               add eax, 0x18
// 0060f62d  5b                   pop ebx
// 0060f62e  c3                   ret 
// 0060f62f  5e                   pop esi
// 0060f630  8d048514000000       lea eax, [eax*4 + 0x14]
// 0060f637  5b                   pop ebx
// 0060f638  c3                   ret 
// 0060f639  8b566c               mov edx, dword ptr [esi + 0x6c]
// 0060f63c  8b4328               mov eax, dword ptr [ebx + 0x28]
// 0060f63f  895324               mov dword ptr [ebx + 0x24], edx
// 0060f642  57                   push edi
// 0060f643  89466c               mov dword ptr [esi + 0x6c], eax
// 0060f646  897328               mov dword ptr [ebx + 0x28], esi
// 0060f649  806605fb             and byte ptr [esi + 5], 0xfb
// 0060f64d  53                   push ebx
// 0060f64e  8bfe                 mov edi, esi
// 0060f650  e87bfeffff           call 0x60f4d0
// 0060f655  8b4630               mov eax, dword ptr [esi + 0x30]
// 0060f658  8b562c               mov edx, dword ptr [esi + 0x2c]
// 0060f65b  83c404               add esp, 4
// 0060f65e  83c005               add eax, 5
// 0060f661  5f                   pop edi
// 0060f662  8d0c40               lea ecx, [eax + eax*2]
// 0060f665  c1e204               shl edx, 4
// 0060f668  5e                   pop esi
// 0060f669  8d04ca               lea eax, [edx + ecx*8]
// 0060f66c  5b                   pop ebx
// 0060f66d  c3                   ret 
// 0060f66e  8b4644               mov eax, dword ptr [esi + 0x44]
// 0060f671  53                   push ebx
// 0060f672  894324               mov dword ptr [ebx + 0x24], eax
// 0060f675  e8d6fcffff           call 0x60f350
// 0060f67a  8b4638               mov eax, dword ptr [esi + 0x38]
// 0060f67d  8b5628               mov edx, dword ptr [esi + 0x28]
// 0060f680  8d0c40               lea ecx, [eax + eax*2]
// 0060f683  8d0491               lea eax, [ecx + edx*4]
// 0060f686  034634               add eax, dword ptr [esi + 0x34]
// 0060f689  83c404               add esp, 4
// 0060f68c  034630               add eax, dword ptr [esi + 0x30]
// 0060f68f  03462c               add eax, dword ptr [esi + 0x2c]
// 0060f692  034624               add eax, dword ptr [esi + 0x24]
// 0060f695  5e                   pop esi
// 0060f696  8d04854c000000       lea eax, [eax*4 + 0x4c]
// 0060f69d  5b                   pop ebx
// 0060f69e  c3                   ret 
// 0060f69f  5e                   pop esi
// 0060f6a0  33c0                 xor eax, eax
// 0060f6a2  5b                   pop ebx
// 0060f6a3  c3                   ret 
// 0060f6a4  e2f5                 loop 0x60f69b
// 0060f6a6  60                   pushal 
// 0060f6a7  0011                 add byte ptr [ecx], dl
// 0060f6a9  f66000               mul byte ptr [eax]
// 0060f6ac  9f                   lahf 
// 0060f6ad  f66000               mul byte ptr [eax]
// 0060f6b0  39f6                 cmp esi, esi
// 0060f6b2  60                   pushal 
// 0060f6b3  006ef6               add byte ptr [esi - 0xa], ch
// 0060f6b6  60                   pushal 
// library lua-5.1/lgc.c (function _propagatemark)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
