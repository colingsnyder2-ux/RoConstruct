// from server: 100% by auto
// roc 2010-06 0081dc70  unit: CXTPPropertyGridView  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081dc70
//
// 0081dc70  8b442404             mov eax, dword ptr [esp + 4]
// 0081dc74  83ec10               sub esp, 0x10
// 0081dc77  53                   push ebx
// 0081dc78  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0081dc7c  55                   push ebp
// 0081dc7d  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0081dc81  56                   push esi
// 0081dc82  57                   push edi
// 0081dc83  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0081dc87  c70700000000         mov dword ptr [edi], 0
// 0081dc8d  c70300000000         mov dword ptr [ebx], 0
// 0081dc93  8bf1                 mov esi, ecx
// 0081dc95  c7450000000000       mov dword ptr [ebp], 0
// 0081dc9c  c70000000000         mov dword ptr [eax], 0
// 0081dca2  8d46ac               lea eax, [esi - 0x54]
// 0081dca5  85c0                 test eax, eax
// 0081dca7  7455                 je 0x81dcfe
// 0081dca9  83782000             cmp dword ptr [eax + 0x20], 0
// 0081dcad  744f                 je 0x81dcfe
// 0081dcaf  8b56cc               mov edx, dword ptr [esi - 0x34]
// 0081dcb2  8d4c2410             lea ecx, [esp + 0x10]
// 0081dcb6  51                   push ecx
// 0081dcb7  52                   push edx
// 0081dcb8  ff153cbc9e00         call dword ptr [0x9ebc3c]
// 0081dcbe  8d442434             lea eax, [esp + 0x34]
// 0081dcc2  50                   push eax
// 0081dcc3  8bce                 mov ecx, esi
// 0081dcc5  e8261efdff           call 0x7efaf0
// 0081dcca  85c0                 test eax, eax
// 0081dccc  740f                 je 0x81dcdd
// 0081dcce  5f                   pop edi
// 0081dccf  5e                   pop esi
// 0081dcd0  5d                   pop ebp
// 0081dcd1  b857000780           mov eax, 0x80070057
// 0081dcd6  5b                   pop ebx
// 0081dcd7  83c410               add esp, 0x10
// 0081dcda  c22000               ret 0x20
// 0081dcdd  8b442410             mov eax, dword ptr [esp + 0x10]
// 0081dce1  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0081dce5  8b542418             mov edx, dword ptr [esp + 0x18]
// 0081dce9  8901                 mov dword ptr [ecx], eax
// 0081dceb  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0081dcef  2bd0                 sub edx, eax
// 0081dcf1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0081dcf5  894d00               mov dword ptr [ebp], ecx
// 0081dcf8  2bc1                 sub eax, ecx
// 0081dcfa  8913                 mov dword ptr [ebx], edx
// 0081dcfc  8907                 mov dword ptr [edi], eax
// 0081dcfe  5f                   pop edi
// 0081dcff  5e                   pop esi
// 0081dd00  5d                   pop ebp
// 0081dd01  33c0                 xor eax, eax
// 0081dd03  5b                   pop ebx
// 0081dd04  83c410               add esp, 0x10
// 0081dd07  c22000               ret 0x20
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?AccessibleLocation@CXTPPropertyGridView@@MAEJPAJ000UtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
