// from server: 100% by auto
// roc 2009-12 008e5ea0  unit: CXTCaptionButton  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e5ea0
//
// 008e5ea0  8b442404             mov eax, dword ptr [esp + 4]
// 008e5ea4  56                   push esi
// 008e5ea5  8bf1                 mov esi, ecx
// 008e5ea7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008e5eab  898e88000000         mov dword ptr [esi + 0x88], ecx
// 008e5eb1  8b8e9c000000         mov ecx, dword ptr [esi + 0x9c]
// 008e5eb7  898684000000         mov dword ptr [esi + 0x84], eax
// 008e5ebd  85c9                 test ecx, ecx
// 008e5ebf  740f                 je 0x8e5ed0
// 008e5ec1  e816dff0ff           call 0x7f3ddc
// 008e5ec6  c7869c00000000000000 mov dword ptr [esi + 0x9c], 0
// 008e5ed0  8b4620               mov eax, dword ptr [esi + 0x20]
// 008e5ed3  8b542410             mov edx, dword ptr [esp + 0x10]
// 008e5ed7  50                   push eax
// 008e5ed8  89969c000000         mov dword ptr [esi + 0x9c], edx
// 008e5ede  ff1584cc9800         call dword ptr [0x98cc84]
// 008e5ee4  85c0                 test eax, eax
// 008e5ee6  7415                 je 0x8e5efd
// 008e5ee8  837c241400           cmp dword ptr [esp + 0x14], 0
// 008e5eed  740e                 je 0x8e5efd
// 008e5eef  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008e5ef2  6a01                 push 1
// 008e5ef4  6a00                 push 0
// 008e5ef6  51                   push ecx
// 008e5ef7  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008e5efd  b801000000           mov eax, 1
// 008e5f02  5e                   pop esi
// 008e5f03  c21000               ret 0x10
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?SetIcon@CXTButton@@QAEHVCSize@@PAVCXTPImageManagerIcon@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
