// from server: 100% by auto
// roc 2009-12 007dca90  unit: RBX::GroupDragTool  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dca90
//
// 007dca90  55                   push ebp
// 007dca91  8b6c2408             mov ebp, dword ptr [esp + 8]
// 007dca95  837d000c             cmp dword ptr [ebp], 0xc
// 007dca99  56                   push esi
// 007dca9a  8bf0                 mov esi, eax
// 007dca9c  7440                 je 0x7dcade
// 007dca9e  8b06                 mov eax, dword ptr [esi]
// 007dcaa0  0fb6484b             movzx ecx, byte ptr [eax + 0x4b]
// 007dcaa4  53                   push ebx
// 007dcaa5  8b5e24               mov ebx, dword ptr [esi + 0x24]
// 007dcaa8  43                   inc ebx
// 007dcaa9  3bd9                 cmp ebx, ecx
// 007dcaab  57                   push edi
// 007dcaac  7e1e                 jle 0x7dcacc
// 007dcaae  81fbfa000000         cmp ebx, 0xfa
// 007dcab4  7c11                 jl 0x7dcac7
// 007dcab6  8b560c               mov edx, dword ptr [esi + 0xc]
// 007dcab9  6834fb9e00           push 0x9efb34
// 007dcabe  52                   push edx
// 007dcabf  e87c88ffff           call 0x7d5340
// 007dcac4  83c408               add esp, 8
// 007dcac7  8b06                 mov eax, dword ptr [esi]
// 007dcac9  88584b               mov byte ptr [eax + 0x4b], bl
// 007dcacc  ff4624               inc dword ptr [esi + 0x24]
// 007dcacf  8b4624               mov eax, dword ptr [esi + 0x24]
// 007dcad2  8d78ff               lea edi, [eax - 1]
// 007dcad5  8bdd                 mov ebx, ebp
// 007dcad7  e8a4feffff           call 0x7dc980
// 007dcadc  5f                   pop edi
// 007dcadd  5b                   pop ebx
// 007dcade  5e                   pop esi
// 007dcadf  5d                   pop ebp
// 007dcae0  c3                   ret 
// library lua-5.1/lcode.c (function _discharge2anyreg)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
