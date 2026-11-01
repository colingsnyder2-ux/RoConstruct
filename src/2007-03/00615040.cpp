// from server: 100% by auto
// roc 2007-03 00615040  unit: seg_00610000  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00615040
//
// 00615040  55                   push ebp
// 00615041  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00615045  837d000c             cmp dword ptr [ebp], 0xc
// 00615049  56                   push esi
// 0061504a  8bf0                 mov esi, eax
// 0061504c  7443                 je 0x615091
// 0061504e  8b06                 mov eax, dword ptr [esi]
// 00615050  0fb6484b             movzx ecx, byte ptr [eax + 0x4b]
// 00615054  53                   push ebx
// 00615055  8b5e24               mov ebx, dword ptr [esi + 0x24]
// 00615058  83c301               add ebx, 1
// 0061505b  3bd9                 cmp ebx, ecx
// 0061505d  57                   push edi
// 0061505e  7e1e                 jle 0x61507e
// 00615060  81fbfa000000         cmp ebx, 0xfa
// 00615066  7c11                 jl 0x615079
// 00615068  8b560c               mov edx, dword ptr [esi + 0xc]
// 0061506b  6894207c00           push 0x7c2094
// 00615070  52                   push edx
// 00615071  e8fabefeff           call 0x600f70
// 00615076  83c408               add esp, 8
// 00615079  8b06                 mov eax, dword ptr [esi]
// 0061507b  88584b               mov byte ptr [eax + 0x4b], bl
// 0061507e  83462401             add dword ptr [esi + 0x24], 1
// 00615082  8b4624               mov eax, dword ptr [esi + 0x24]
// 00615085  8d78ff               lea edi, [eax - 1]
// 00615088  8bdd                 mov ebx, ebp
// 0061508a  e8a1feffff           call 0x614f30
// 0061508f  5f                   pop edi
// 00615090  5b                   pop ebx
// 00615091  5e                   pop esi
// 00615092  5d                   pop ebp
// 00615093  c3                   ret 
// library lua-5.1.1/lcode.c (function _discharge2anyreg)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
