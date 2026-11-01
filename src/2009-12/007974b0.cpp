// from server: 100% by auto
// roc 2009-12 007974b0  unit: lua_exception  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007974b0
//
// 007974b0  53                   push ebx
// 007974b1  55                   push ebp
// 007974b2  6a10                 push 0x10
// 007974b4  57                   push edi
// 007974b5  56                   push esi
// 007974b6  e8c5690300           call 0x7cde80
// 007974bb  8bef                 mov ebp, edi
// 007974bd  2b6e20               sub ebp, dword ptr [esi + 0x20]
// 007974c0  8bd8                 mov ebx, eax
// 007974c2  83c40c               add esp, 0xc
// 007974c5  837b0806             cmp dword ptr [ebx + 8], 6
// 007974c9  740f                 je 0x7974da
// 007974cb  6898a99e00           push 0x9ea998
// 007974d0  57                   push edi
// 007974d1  56                   push esi
// 007974d2  e899400000           call 0x79b570
// 007974d7  83c40c               add esp, 0xc
// 007974da  8b4e08               mov ecx, dword ptr [esi + 8]
// 007974dd  3bcf                 cmp ecx, edi
// 007974df  761d                 jbe 0x7974fe
// 007974e1  8d41f0               lea eax, [ecx - 0x10]
// 007974e4  8b10                 mov edx, dword ptr [eax]
// 007974e6  8911                 mov dword ptr [ecx], edx
// 007974e8  8b5004               mov edx, dword ptr [eax + 4]
// 007974eb  895104               mov dword ptr [ecx + 4], edx
// 007974ee  8b5008               mov edx, dword ptr [eax + 8]
// 007974f1  895018               mov dword ptr [eax + 0x18], edx
// 007974f4  83e910               sub ecx, 0x10
// 007974f7  83e810               sub eax, 0x10
// 007974fa  3bcf                 cmp ecx, edi
// 007974fc  77e6                 ja 0x7974e4
// 007974fe  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00797501  2b4608               sub eax, dword ptr [esi + 8]
// 00797504  83f810               cmp eax, 0x10
// 00797507  7f19                 jg 0x797522
// 00797509  8b462c               mov eax, dword ptr [esi + 0x2c]
// 0079750c  83f801               cmp eax, 1
// 0079750f  7c06                 jl 0x797517
// 00797511  8d0c00               lea ecx, [eax + eax]
// 00797514  51                   push ecx
// 00797515  eb02                 jmp 0x797519
// 00797517  40                   inc eax
// 00797518  50                   push eax
// 00797519  56                   push esi
// 0079751a  e831fdffff           call 0x797250
// 0079751f  83c408               add esp, 8
// 00797522  83460810             add dword ptr [esi + 8], 0x10
// 00797526  8b4620               mov eax, dword ptr [esi + 0x20]
// 00797529  8b13                 mov edx, dword ptr [ebx]
// 0079752b  03c5                 add eax, ebp
// 0079752d  8910                 mov dword ptr [eax], edx
// 0079752f  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00797532  894804               mov dword ptr [eax + 4], ecx
// 00797535  8b5308               mov edx, dword ptr [ebx + 8]
// 00797538  5d                   pop ebp
// 00797539  895008               mov dword ptr [eax + 8], edx
// 0079753c  5b                   pop ebx
// 0079753d  c3                   ret 
// library lua-5.1/ldo.c (function _tryfuncTM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldo.c
