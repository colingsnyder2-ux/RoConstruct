// from server: 100% by auto
// roc 2009-06 007871d0  unit: CXTPToolTipContextToolTip::PAUTOOLITEM::?$CArray  size: 275 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007871d0
//
// 007871d0  83ec18               sub esp, 0x18
// 007871d3  55                   push ebp
// 007871d4  56                   push esi
// 007871d5  8b3534ee8900         mov esi, dword ptr [0x89ee34]
// 007871db  6a01                 push 1
// 007871dd  8be9                 mov ebp, ecx
// 007871df  ffd6                 call esi
// 007871e1  6685c0               test ax, ax
// 007871e4  0f8cf1000000         jl 0x7872db
// 007871ea  6a02                 push 2
// 007871ec  ffd6                 call esi
// 007871ee  6685c0               test ax, ax
// 007871f1  0f8ce4000000         jl 0x7872db
// 007871f7  6a04                 push 4
// 007871f9  ffd6                 call esi
// 007871fb  6685c0               test ax, ax
// 007871fe  0f8cd7000000         jl 0x7872db
// 00787204  53                   push ebx
// 00787205  57                   push edi
// 00787206  8d442410             lea eax, [esp + 0x10]
// 0078720a  50                   push eax
// 0078720b  ff152cee8900         call dword ptr [0x89ee2c]
// 00787211  33ff                 xor edi, edi
// 00787213  397d5c               cmp dword ptr [ebp + 0x5c], edi
// 00787216  0f8ea6000000         jle 0x7872c2
// 0078721c  8b1de0ed8900         mov ebx, dword ptr [0x89ede0]
// 00787222  85ff                 test edi, edi
// 00787224  0f8cac000000         jl 0x7872d6
// 0078722a  3b7d5c               cmp edi, dword ptr [ebp + 0x5c]
// 0078722d  0f8da3000000         jge 0x7872d6
// 00787233  8b4d58               mov ecx, dword ptr [ebp + 0x58]
// 00787236  8b34b9               mov esi, dword ptr [ecx + edi*4]
// 00787239  8b5620               mov edx, dword ptr [esi + 0x20]
// 0078723c  52                   push edx
// 0078723d  ffd3                 call ebx
// 0078723f  85c0                 test eax, eax
// 00787241  7475                 je 0x7872b8
// 00787243  8b4620               mov eax, dword ptr [esi + 0x20]
// 00787246  50                   push eax
// 00787247  e8b61af9ff           call 0x718d02
// 0078724c  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0078724f  894c2418             mov dword ptr [esp + 0x18], ecx
// 00787253  8b5610               mov edx, dword ptr [esi + 0x10]
// 00787256  8954241c             mov dword ptr [esp + 0x1c], edx
// 0078725a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0078725d  894c2420             mov dword ptr [esp + 0x20], ecx
// 00787261  8b5618               mov edx, dword ptr [esi + 0x18]
// 00787264  89542424             mov dword ptr [esp + 0x24], edx
// 00787268  f6460801             test byte ptr [esi + 8], 1
// 0078726c  8d4c2418             lea ecx, [esp + 0x18]
// 00787270  51                   push ecx
// 00787271  740c                 je 0x78727f
// 00787273  8b5020               mov edx, dword ptr [eax + 0x20]
// 00787276  52                   push edx
// 00787277  ff15f4ed8900         call dword ptr [0x89edf4]
// 0078727d  eb07                 jmp 0x787286
// 0078727f  8bc8                 mov ecx, eax
// 00787281  e84c1df9ff           call 0x718fd2
// 00787286  8b542414             mov edx, dword ptr [esp + 0x14]
// 0078728a  8b442410             mov eax, dword ptr [esp + 0x10]
// 0078728e  52                   push edx
// 0078728f  50                   push eax
// 00787290  8d4c2420             lea ecx, [esp + 0x20]
// 00787294  51                   push ecx
// 00787295  ff15c0ed8900         call dword ptr [0x89edc0]
// 0078729b  85c0                 test eax, eax
// 0078729d  7419                 je 0x7872b8
// 0078729f  f6460801             test byte ptr [esi + 8], 1
// 007872a3  7527                 jne 0x7872cc
// 007872a5  8d542410             lea edx, [esp + 0x10]
// 007872a9  52                   push edx
// 007872aa  6a00                 push 0
// 007872ac  8bcd                 mov ecx, ebp
// 007872ae  e8edd9ffff           call 0x784ca0
// 007872b3  3b4620               cmp eax, dword ptr [esi + 0x20]
// 007872b6  7414                 je 0x7872cc
// 007872b8  47                   inc edi
// 007872b9  3b7d5c               cmp edi, dword ptr [ebp + 0x5c]
// 007872bc  0f8c60ffffff         jl 0x787222
// 007872c2  5f                   pop edi
// 007872c3  5b                   pop ebx
// 007872c4  5e                   pop esi
// 007872c5  33c0                 xor eax, eax
// 007872c7  5d                   pop ebp
// 007872c8  83c418               add esp, 0x18
// 007872cb  c3                   ret 
// 007872cc  5f                   pop edi
// 007872cd  5b                   pop ebx
// 007872ce  8bc6                 mov eax, esi
// 007872d0  5e                   pop esi
// 007872d1  5d                   pop ebp
// 007872d2  83c418               add esp, 0x18
// 007872d5  c3                   ret 
// 007872d6  e8091af9ff           call 0x718ce4
// 007872db  5e                   pop esi
// 007872dc  33c0                 xor eax, eax
// 007872de  5d                   pop ebp
// 007872df  83c418               add esp, 0x18
// 007872e2  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?FindTool@CXTPToolTipContextToolTip@@IAEPAUTOOLITEM@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
