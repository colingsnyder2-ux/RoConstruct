// from server: 100% by auto
// roc 2010-06 008161c0  unit: CXTPToolTipContextToolTip::PAUTOOLITEM::?$CArray  size: 275 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008161c0
//
// 008161c0  83ec18               sub esp, 0x18
// 008161c3  55                   push ebp
// 008161c4  56                   push esi
// 008161c5  8b357cbc9e00         mov esi, dword ptr [0x9ebc7c]
// 008161cb  6a01                 push 1
// 008161cd  8be9                 mov ebp, ecx
// 008161cf  ffd6                 call esi
// 008161d1  6685c0               test ax, ax
// 008161d4  0f8cf1000000         jl 0x8162cb
// 008161da  6a02                 push 2
// 008161dc  ffd6                 call esi
// 008161de  6685c0               test ax, ax
// 008161e1  0f8ce4000000         jl 0x8162cb
// 008161e7  6a04                 push 4
// 008161e9  ffd6                 call esi
// 008161eb  6685c0               test ax, ax
// 008161ee  0f8cd7000000         jl 0x8162cb
// 008161f4  53                   push ebx
// 008161f5  57                   push edi
// 008161f6  8d442410             lea eax, [esp + 0x10]
// 008161fa  50                   push eax
// 008161fb  ff1574bc9e00         call dword ptr [0x9ebc74]
// 00816201  33ff                 xor edi, edi
// 00816203  397d5c               cmp dword ptr [ebp + 0x5c], edi
// 00816206  0f8ea6000000         jle 0x8162b2
// 0081620c  8b1d28bc9e00         mov ebx, dword ptr [0x9ebc28]
// 00816212  85ff                 test edi, edi
// 00816214  0f8cac000000         jl 0x8162c6
// 0081621a  3b7d5c               cmp edi, dword ptr [ebp + 0x5c]
// 0081621d  0f8da3000000         jge 0x8162c6
// 00816223  8b4d58               mov ecx, dword ptr [ebp + 0x58]
// 00816226  8b34b9               mov esi, dword ptr [ecx + edi*4]
// 00816229  8b5620               mov edx, dword ptr [esi + 0x20]
// 0081622c  52                   push edx
// 0081622d  ffd3                 call ebx
// 0081622f  85c0                 test eax, eax
// 00816231  7475                 je 0x8162a8
// 00816233  8b4620               mov eax, dword ptr [esi + 0x20]
// 00816236  50                   push eax
// 00816237  e82e1af9ff           call 0x7a7c6a
// 0081623c  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0081623f  894c2418             mov dword ptr [esp + 0x18], ecx
// 00816243  8b5610               mov edx, dword ptr [esi + 0x10]
// 00816246  8954241c             mov dword ptr [esp + 0x1c], edx
// 0081624a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0081624d  894c2420             mov dword ptr [esp + 0x20], ecx
// 00816251  8b5618               mov edx, dword ptr [esi + 0x18]
// 00816254  89542424             mov dword ptr [esp + 0x24], edx
// 00816258  f6460801             test byte ptr [esi + 8], 1
// 0081625c  8d4c2418             lea ecx, [esp + 0x18]
// 00816260  51                   push ecx
// 00816261  740c                 je 0x81626f
// 00816263  8b5020               mov edx, dword ptr [eax + 0x20]
// 00816266  52                   push edx
// 00816267  ff153cbc9e00         call dword ptr [0x9ebc3c]
// 0081626d  eb07                 jmp 0x816276
// 0081626f  8bc8                 mov ecx, eax
// 00816271  e8ca1cf9ff           call 0x7a7f40
// 00816276  8b542414             mov edx, dword ptr [esp + 0x14]
// 0081627a  8b442410             mov eax, dword ptr [esp + 0x10]
// 0081627e  52                   push edx
// 0081627f  50                   push eax
// 00816280  8d4c2420             lea ecx, [esp + 0x20]
// 00816284  51                   push ecx
// 00816285  ff15e0bb9e00         call dword ptr [0x9ebbe0]
// 0081628b  85c0                 test eax, eax
// 0081628d  7419                 je 0x8162a8
// 0081628f  f6460801             test byte ptr [esi + 8], 1
// 00816293  7527                 jne 0x8162bc
// 00816295  8d542410             lea edx, [esp + 0x10]
// 00816299  52                   push edx
// 0081629a  6a00                 push 0
// 0081629c  8bcd                 mov ecx, ebp
// 0081629e  e80ddaffff           call 0x813cb0
// 008162a3  3b4620               cmp eax, dword ptr [esi + 0x20]
// 008162a6  7414                 je 0x8162bc
// 008162a8  47                   inc edi
// 008162a9  3b7d5c               cmp edi, dword ptr [ebp + 0x5c]
// 008162ac  0f8c60ffffff         jl 0x816212
// 008162b2  5f                   pop edi
// 008162b3  5b                   pop ebx
// 008162b4  5e                   pop esi
// 008162b5  33c0                 xor eax, eax
// 008162b7  5d                   pop ebp
// 008162b8  83c418               add esp, 0x18
// 008162bb  c3                   ret 
// 008162bc  5f                   pop edi
// 008162bd  5b                   pop ebx
// 008162be  8bc6                 mov eax, esi
// 008162c0  5e                   pop esi
// 008162c1  5d                   pop ebp
// 008162c2  83c418               add esp, 0x18
// 008162c5  c3                   ret 
// 008162c6  e88119f9ff           call 0x7a7c4c
// 008162cb  5e                   pop esi
// 008162cc  33c0                 xor eax, eax
// 008162ce  5d                   pop ebp
// 008162cf  83c418               add esp, 0x18
// 008162d2  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?FindTool@CXTPToolTipContextToolTip@@IAEPAUTOOLITEM@1@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
