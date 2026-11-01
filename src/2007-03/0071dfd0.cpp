// from server: 100% by auto
// roc 2007-03 0071dfd0  unit: seg_00710000  size: 156 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071dfd0
//
// 0071dfd0  56                   push esi
// 0071dfd1  57                   push edi
// 0071dfd2  8bf1                 mov esi, ecx
// 0071dfd4  e827150000           call 0x71f500
// 0071dfd9  6a05                 push 5
// 0071dfdb  8bce                 mov ecx, esi
// 0071dfdd  e8ee5ffdff           call 0x6f3fd0
// 0071dfe2  8b3d50ee7700         mov edi, dword ptr [0x77ee50]
// 0071dfe8  50                   push eax
// 0071dfe9  8b4620               mov eax, dword ptr [esi + 0x20]
// 0071dfec  6a00                 push 0
// 0071dfee  6806100000           push 0x1006
// 0071dff3  50                   push eax
// 0071dff4  ffd7                 call edi
// 0071dff6  6a05                 push 5
// 0071dff8  8bce                 mov ecx, esi
// 0071dffa  e8d15ffdff           call 0x6f3fd0
// 0071dfff  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0071e002  50                   push eax
// 0071e003  6a04                 push 4
// 0071e005  6806100000           push 0x1006
// 0071e00a  51                   push ecx
// 0071e00b  ffd7                 call edi
// 0071e00d  6a08                 push 8
// 0071e00f  8bce                 mov ecx, esi
// 0071e011  e8ba5ffdff           call 0x6f3fd0
// 0071e016  8b5620               mov edx, dword ptr [esi + 0x20]
// 0071e019  50                   push eax
// 0071e01a  6a01                 push 1
// 0071e01c  6806100000           push 0x1006
// 0071e021  52                   push edx
// 0071e022  ffd7                 call edi
// 0071e024  6a02                 push 2
// 0071e026  8bce                 mov ecx, esi
// 0071e028  e8a35ffdff           call 0x6f3fd0
// 0071e02d  50                   push eax
// 0071e02e  8b4620               mov eax, dword ptr [esi + 0x20]
// 0071e031  6a02                 push 2
// 0071e033  6806100000           push 0x1006
// 0071e038  50                   push eax
// 0071e039  ffd7                 call edi
// 0071e03b  6a09                 push 9
// 0071e03d  8bce                 mov ecx, esi
// 0071e03f  e88c5ffdff           call 0x6f3fd0
// 0071e044  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0071e047  50                   push eax
// 0071e048  6a03                 push 3
// 0071e04a  6806100000           push 0x1006
// 0071e04f  51                   push ecx
// 0071e050  ffd7                 call edi
// 0071e052  6a11                 push 0x11
// 0071e054  8bce                 mov ecx, esi
// 0071e056  e8755ffdff           call 0x6f3fd0
// 0071e05b  8b5620               mov edx, dword ptr [esi + 0x20]
// 0071e05e  50                   push eax
// 0071e05f  6a05                 push 5
// 0071e061  6806100000           push 0x1006
// 0071e066  52                   push edx
// 0071e067  ffd7                 call edi
// 0071e069  5f                   pop edi
// 0071e06a  5e                   pop esi
// 0071e06b  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectComboBox.cpp (function ?RefreshMetrics@CXTPSkinObjectDateTime@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectComboBox.cpp
