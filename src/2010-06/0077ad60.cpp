// from server: 100% by auto
// roc 2010-06 0077ad60  unit: RBX::PartDropTool  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0077ad60
//
// 0077ad60  55                   push ebp
// 0077ad61  56                   push esi
// 0077ad62  8bf0                 mov esi, eax
// 0077ad64  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 0077ad67  0fb64515             movzx eax, byte ptr [ebp + 0x15]
// 0077ad6b  57                   push edi
// 0077ad6c  83f804               cmp eax, 4
// 0077ad6f  0f87cd000000         ja 0x77ae42
// 0077ad75  ff248548ae7700       jmp dword ptr [eax*4 + 0x77ae48]
// 0077ad7c  8bfe                 mov edi, esi
// 0077ad7e  e8adfdffff           call 0x77ab30
// 0077ad83  5f                   pop edi
// 0077ad84  5e                   pop esi
// 0077ad85  33c0                 xor eax, eax
// 0077ad87  5d                   pop ebp
// 0077ad88  c3                   ret 
// 0077ad89  837d2400             cmp dword ptr [ebp + 0x24], 0
// 0077ad8d  740a                 je 0x77ad99
// 0077ad8f  5f                   pop edi
// 0077ad90  5e                   pop esi
// 0077ad91  8bc5                 mov eax, ebp
// 0077ad93  5d                   pop ebp
// 0077ad94  e997f8ffff           jmp 0x77a630
// 0077ad99  56                   push esi
// 0077ad9a  e841feffff           call 0x77abe0
// 0077ad9f  83c404               add esp, 4
// 0077ada2  5f                   pop edi
// 0077ada3  5e                   pop esi
// 0077ada4  33c0                 xor eax, eax
// 0077ada6  5d                   pop ebp
// 0077ada7  c3                   ret 
// 0077ada8  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0077adab  8b4d00               mov ecx, dword ptr [ebp]
// 0077adae  8b7d44               mov edi, dword ptr [ebp + 0x44]
// 0077adb1  8d0c81               lea ecx, [ecx + eax*4]
// 0077adb4  6afd                 push -3
// 0077adb6  51                   push ecx
// 0077adb7  40                   inc eax
// 0077adb8  56                   push esi
// 0077adb9  894518               mov dword ptr [ebp + 0x18], eax
// 0077adbc  e80ffbffff           call 0x77a8d0
// 0077adc1  8b5518               mov edx, dword ptr [ebp + 0x18]
// 0077adc4  83c40c               add esp, 0xc
// 0077adc7  3b5508               cmp edx, dword ptr [ebp + 8]
// 0077adca  7c04                 jl 0x77add0
// 0077adcc  c6451503             mov byte ptr [ebp + 0x15], 3
// 0077add0  8b4544               mov eax, dword ptr [ebp + 0x44]
// 0077add3  2bc7                 sub eax, edi
// 0077add5  014548               add dword ptr [ebp + 0x48], eax
// 0077add8  5f                   pop edi
// 0077add9  5e                   pop esi
// 0077adda  b80a000000           mov eax, 0xa
// 0077addf  5d                   pop ebp
// 0077ade0  c3                   ret 
// 0077ade1  8b4d20               mov ecx, dword ptr [ebp + 0x20]
// 0077ade4  8b7d44               mov edi, dword ptr [ebp + 0x44]
// 0077ade7  6a28                 push 0x28
// 0077ade9  51                   push ecx
// 0077adea  56                   push esi
// 0077adeb  e8e0faffff           call 0x77a8d0
// 0077adf0  83c40c               add esp, 0xc
// 0077adf3  894520               mov dword ptr [ebp + 0x20], eax
// 0077adf6  833800               cmp dword ptr [eax], 0
// 0077adf9  750d                 jne 0x77ae08
// 0077adfb  53                   push ebx
// 0077adfc  8bde                 mov ebx, esi
// 0077adfe  e85dfbffff           call 0x77a960
// 0077ae03  c6451504             mov byte ptr [ebp + 0x15], 4
// 0077ae07  5b                   pop ebx
// 0077ae08  8b5544               mov edx, dword ptr [ebp + 0x44]
// 0077ae0b  2bd7                 sub edx, edi
// 0077ae0d  015548               add dword ptr [ebp + 0x48], edx
// 0077ae10  5f                   pop edi
// 0077ae11  5e                   pop esi
// 0077ae12  b890010000           mov eax, 0x190
// 0077ae17  5d                   pop ebp
// 0077ae18  c3                   ret 
// 0077ae19  33c0                 xor eax, eax
// 0077ae1b  394530               cmp dword ptr [ebp + 0x30], eax
// 0077ae1e  741c                 je 0x77ae3c
// 0077ae20  e8abfbffff           call 0x77a9d0
// 0077ae25  8b4548               mov eax, dword ptr [ebp + 0x48]
// 0077ae28  83f864               cmp eax, 0x64
// 0077ae2b  7606                 jbe 0x77ae33
// 0077ae2d  83c09c               add eax, -0x64
// 0077ae30  894548               mov dword ptr [ebp + 0x48], eax
// 0077ae33  5f                   pop edi
// 0077ae34  5e                   pop esi
// 0077ae35  b864000000           mov eax, 0x64
// 0077ae3a  5d                   pop ebp
// 0077ae3b  c3                   ret 
// 0077ae3c  884515               mov byte ptr [ebp + 0x15], al
// 0077ae3f  89454c               mov dword ptr [ebp + 0x4c], eax
// 0077ae42  5f                   pop edi
// 0077ae43  5e                   pop esi
// 0077ae44  33c0                 xor eax, eax
// 0077ae46  5d                   pop ebp
// 0077ae47  c3                   ret 
// 0077ae48  7cad                 jl 0x77adf7
// 0077ae4a  7700                 ja 0x77ae4c
// 0077ae4c  89ad7700a8ad         mov dword ptr [ebp - 0x5257ff89], ebp
// 0077ae52  7700                 ja 0x77ae54
// 0077ae54  e1ad                 loope 0x77ae03
// 0077ae56  7700                 ja 0x77ae58
// library lua-5.1.1/lgc.c (function _singlestep)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
