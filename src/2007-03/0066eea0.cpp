// from server: 100% by auto
// roc 2007-03 0066eea0  unit: seg_00660000  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066eea0
//
// 0066eea0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0066eea4  56                   push esi
// 0066eea5  57                   push edi
// 0066eea6  e855ec0000           call 0x67db00
// 0066eeab  8b3d50ee7700         mov edi, dword ptr [0x77ee50]
// 0066eeb1  6a00                 push 0
// 0066eeb3  6a00                 push 0
// 0066eeb5  8bf0                 mov esi, eax
// 0066eeb7  6860280000           push 0x2860
// 0066eebc  56                   push esi
// 0066eebd  ffd7                 call edi
// 0066eebf  85c0                 test eax, eax
// 0066eec1  7541                 jne 0x66ef04
// 0066eec3  50                   push eax
// 0066eec4  50                   push eax
// 0066eec5  6a7f                 push 0x7f
// 0066eec7  56                   push esi
// 0066eec8  ffd7                 call edi
// 0066eeca  85c0                 test eax, eax
// 0066eecc  7536                 jne 0x66ef04
// 0066eece  50                   push eax
// 0066eecf  6a01                 push 1
// 0066eed1  6a7f                 push 0x7f
// 0066eed3  56                   push esi
// 0066eed4  ffd7                 call edi
// 0066eed6  85c0                 test eax, eax
// 0066eed8  752a                 jne 0x66ef04
// 0066eeda  8b3d94ef7700         mov edi, dword ptr [0x77ef94]
// 0066eee0  6ade                 push -0x22
// 0066eee2  56                   push esi
// 0066eee3  ffd7                 call edi
// 0066eee5  85c0                 test eax, eax
// 0066eee7  751b                 jne 0x66ef04
// 0066eee9  6af2                 push -0xe
// 0066eeeb  56                   push esi
// 0066eeec  ffd7                 call edi
// 0066eeee  85c0                 test eax, eax
// 0066eef0  7512                 jne 0x66ef04
// 0066eef2  e899f4faff           call 0x61e390
// 0066eef7  68057f0000           push 0x7f05
// 0066eefc  6a00                 push 0
// 0066eefe  ff1560ed7700         call dword ptr [0x77ed60]
// 0066ef04  5f                   pop edi
// 0066ef05  5e                   pop esi
// 0066ef06  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?GetItemIcon@CXTPTabClientWnd@@MBEPAUHICON__@@PBVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
