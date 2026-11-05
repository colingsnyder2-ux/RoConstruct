// from server: 100% by auto
// roc 2010-06 00841520  unit: CXTPKeyboardManager  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00841520
//
// 00841520  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00841524  0faf442410           imul eax, dword ptr [esp + 0x10]
// 00841529  8a542418             mov dl, byte ptr [esp + 0x18]
// 0084152d  03c0                 add eax, eax
// 0084152f  80c9ff               or cl, 0xff
// 00841532  03c0                 add eax, eax
// 00841534  2aca                 sub cl, dl
// 00841536  85c0                 test eax, eax
// 00841538  7e47                 jle 0x841581
// 0084153a  53                   push ebx
// 0084153b  55                   push ebp
// 0084153c  0fb6e9               movzx ebp, cl
// 0084153f  0fb6ca               movzx ecx, dl
// 00841542  56                   push esi
// 00841543  8b742420             mov esi, dword ptr [esp + 0x20]
// 00841547  57                   push edi
// 00841548  894c2428             mov dword ptr [esp + 0x28], ecx
// 0084154c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00841550  8bf8                 mov edi, eax
// 00841552  8b442414             mov eax, dword ptr [esp + 0x14]
// 00841556  eb08                 jmp 0x841560
// 00841558  8da42400000000       lea esp, [esp]
// 0084155f  90                   nop 
// 00841560  0fb616               movzx edx, byte ptr [esi]
// 00841563  0fb619               movzx ebx, byte ptr [ecx]
// 00841566  0faf542428           imul edx, dword ptr [esp + 0x28]
// 0084156b  0fafdd               imul ebx, ebp
// 0084156e  03d3                 add edx, ebx
// 00841570  c1fa08               sar edx, 8
// 00841573  8810                 mov byte ptr [eax], dl
// 00841575  40                   inc eax
// 00841576  41                   inc ecx
// 00841577  46                   inc esi
// 00841578  83ef01               sub edi, 1
// 0084157b  75e3                 jne 0x841560
// 0084157d  5f                   pop edi
// 0084157e  5e                   pop esi
// 0084157f  5d                   pop ebp
// 00841580  5b                   pop ebx
// 00841581  c21800               ret 0x18
// library xtp-13.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ?AlphaBlendU@CXTPCommandBarAnimation@@IAEXPAE0HH0E@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
