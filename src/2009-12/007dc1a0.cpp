// from server: 100% by auto
// roc 2009-12 007dc1a0  unit: RBX::GroupDragTool  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc1a0
//
// 007dc1a0  83380c               cmp dword ptr [eax], 0xc
// 007dc1a3  7515                 jne 0x7dc1ba
// 007dc1a5  8b4008               mov eax, dword ptr [eax + 8]
// 007dc1a8  a900010000           test eax, 0x100
// 007dc1ad  750b                 jne 0x7dc1ba
// 007dc1af  0fb65132             movzx edx, byte ptr [ecx + 0x32]
// 007dc1b3  3bc2                 cmp eax, edx
// 007dc1b5  7c03                 jl 0x7dc1ba
// 007dc1b7  ff4924               dec dword ptr [ecx + 0x24]
// 007dc1ba  c3                   ret 
// library lua-5.1/lcode.c (function _freeexp)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
