// from server: 100% by auto
// roc 2009-12 007dd330  unit: RBX::GroupDragTool  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dd330
//
// 007dd330  55                   push ebp
// 007dd331  57                   push edi
// 007dd332  53                   push ebx
// 007dd333  56                   push esi
// 007dd334  8bf8                 mov edi, eax
// 007dd336  e8c5f9ffff           call 0x7dcd00
// 007dd33b  57                   push edi
// 007dd33c  56                   push esi
// 007dd33d  8be8                 mov ebp, eax
// 007dd33f  e8bcf9ffff           call 0x7dcd00
// 007dd344  83c410               add esp, 0x10
// 007dd347  83caff               or edx, 0xffffffff
// 007dd34a  833f0c               cmp dword ptr [edi], 0xc
// 007dd34d  7516                 jne 0x7dd365
// 007dd34f  8b7f08               mov edi, dword ptr [edi + 8]
// 007dd352  f7c700010000         test edi, 0x100
// 007dd358  750b                 jne 0x7dd365
// 007dd35a  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 007dd35e  3bf9                 cmp edi, ecx
// 007dd360  7c03                 jl 0x7dd365
// 007dd362  015624               add dword ptr [esi + 0x24], edx
// 007dd365  833b0c               cmp dword ptr [ebx], 0xc
// 007dd368  7516                 jne 0x7dd380
// 007dd36a  8b4b08               mov ecx, dword ptr [ebx + 8]
// 007dd36d  f7c100010000         test ecx, 0x100
// 007dd373  750b                 jne 0x7dd380
// 007dd375  0fb67e32             movzx edi, byte ptr [esi + 0x32]
// 007dd379  3bcf                 cmp ecx, edi
// 007dd37b  7c03                 jl 0x7dd380
// 007dd37d  015624               add dword ptr [esi + 0x24], edx
// 007dd380  837c241000           cmp dword ptr [esp + 0x10], 0
// 007dd385  7515                 jne 0x7dd39c
// 007dd387  837c240c17           cmp dword ptr [esp + 0xc], 0x17
// 007dd38c  740e                 je 0x7dd39c
// 007dd38e  8bcd                 mov ecx, ebp
// 007dd390  8be8                 mov ebp, eax
// 007dd392  8bc1                 mov eax, ecx
// 007dd394  c744241001000000     mov dword ptr [esp + 0x10], 1
// 007dd39c  8b542410             mov edx, dword ptr [esp + 0x10]
// 007dd3a0  50                   push eax
// 007dd3a1  8b442410             mov eax, dword ptr [esp + 0x10]
// 007dd3a5  52                   push edx
// 007dd3a6  50                   push eax
// 007dd3a7  8bc5                 mov eax, ebp
// 007dd3a9  8bce                 mov ecx, esi
// 007dd3ab  e850f4ffff           call 0x7dc800
// 007dd3b0  83c40c               add esp, 0xc
// 007dd3b3  5f                   pop edi
// 007dd3b4  894308               mov dword ptr [ebx + 8], eax
// 007dd3b7  c7030a000000         mov dword ptr [ebx], 0xa
// 007dd3bd  5d                   pop ebp
// 007dd3be  c3                   ret 
// library lua-5.1/lcode.c (function _codecomp)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
