// from server: 100% by auto
// roc 2007-03 0071e210  unit: seg_00710000  size: 156 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071e210
//
// 0071e210  56                   push esi
// 0071e211  57                   push edi
// 0071e212  8bf1                 mov esi, ecx
// 0071e214  e8e7120000           call 0x71f500
// 0071e219  6a05                 push 5
// 0071e21b  8bce                 mov ecx, esi
// 0071e21d  e8ae5dfdff           call 0x6f3fd0
// 0071e222  8b3d50ee7700         mov edi, dword ptr [0x77ee50]
// 0071e228  50                   push eax
// 0071e229  8b4620               mov eax, dword ptr [esi + 0x20]
// 0071e22c  6a00                 push 0
// 0071e22e  680a100000           push 0x100a
// 0071e233  50                   push eax
// 0071e234  ffd7                 call edi
// 0071e236  6a05                 push 5
// 0071e238  8bce                 mov ecx, esi
// 0071e23a  e8915dfdff           call 0x6f3fd0
// 0071e23f  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0071e242  50                   push eax
// 0071e243  6a04                 push 4
// 0071e245  680a100000           push 0x100a
// 0071e24a  51                   push ecx
// 0071e24b  ffd7                 call edi
// 0071e24d  6a08                 push 8
// 0071e24f  8bce                 mov ecx, esi
// 0071e251  e87a5dfdff           call 0x6f3fd0
// 0071e256  8b5620               mov edx, dword ptr [esi + 0x20]
// 0071e259  50                   push eax
// 0071e25a  6a01                 push 1
// 0071e25c  680a100000           push 0x100a
// 0071e261  52                   push edx
// 0071e262  ffd7                 call edi
// 0071e264  6a02                 push 2
// 0071e266  8bce                 mov ecx, esi
// 0071e268  e8635dfdff           call 0x6f3fd0
// 0071e26d  50                   push eax
// 0071e26e  8b4620               mov eax, dword ptr [esi + 0x20]
// 0071e271  6a02                 push 2
// 0071e273  680a100000           push 0x100a
// 0071e278  50                   push eax
// 0071e279  ffd7                 call edi
// 0071e27b  6a09                 push 9
// 0071e27d  8bce                 mov ecx, esi
// 0071e27f  e84c5dfdff           call 0x6f3fd0
// 0071e284  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0071e287  50                   push eax
// 0071e288  6a03                 push 3
// 0071e28a  680a100000           push 0x100a
// 0071e28f  51                   push ecx
// 0071e290  ffd7                 call edi
// 0071e292  6a11                 push 0x11
// 0071e294  8bce                 mov ecx, esi
// 0071e296  e8355dfdff           call 0x6f3fd0
// 0071e29b  8b5620               mov edx, dword ptr [esi + 0x20]
// 0071e29e  50                   push eax
// 0071e29f  6a05                 push 5
// 0071e2a1  680a100000           push 0x100a
// 0071e2a6  52                   push edx
// 0071e2a7  ffd7                 call edi
// 0071e2a9  5f                   pop edi
// 0071e2aa  5e                   pop esi
// 0071e2ab  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectComboBox.cpp (function ?RefreshMetrics@CXTPSkinObjectMonthCal@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectComboBox.cpp
