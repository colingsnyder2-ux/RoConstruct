// from server: 100% by auto
// roc 2009-06 00791a70  unit: CSelectionCaption  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00791a70
//
// 00791a70  8b442408             mov eax, dword ptr [esp + 8]
// 00791a74  53                   push ebx
// 00791a75  55                   push ebp
// 00791a76  56                   push esi
// 00791a77  8bf1                 mov esi, ecx
// 00791a79  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00791a7d  57                   push edi
// 00791a7e  898e84000000         mov dword ptr [esi + 0x84], ecx
// 00791a84  85c0                 test eax, eax
// 00791a86  7405                 je 0x791a8d
// 00791a88  8b4020               mov eax, dword ptr [eax + 0x20]
// 00791a8b  eb02                 jmp 0x791a8f
// 00791a8d  33c0                 xor eax, eax
// 00791a8f  8b3d98ee8900         mov edi, dword ptr [0x89ee98]
// 00791a95  894638               mov dword ptr [esi + 0x38], eax
// 00791a98  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00791a9b  50                   push eax
// 00791a9c  ffd7                 call edi
// 00791a9e  50                   push eax
// 00791a9f  e85e72f8ff           call 0x718d02
// 00791aa4  898688000000         mov dword ptr [esi + 0x88], eax
// 00791aaa  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00791aad  51                   push ecx
// 00791aae  ffd7                 call edi
// 00791ab0  50                   push eax
// 00791ab1  e84c72f8ff           call 0x718d02
// 00791ab6  8b9684000000         mov edx, dword ptr [esi + 0x84]
// 00791abc  8b2d14ee8900         mov ebp, dword ptr [0x89ee14]
// 00791ac2  89868c000000         mov dword ptr [esi + 0x8c], eax
// 00791ac8  8b4220               mov eax, dword ptr [edx + 0x20]
// 00791acb  8d9e98000000         lea ebx, [esi + 0x98]
// 00791ad1  53                   push ebx
// 00791ad2  50                   push eax
// 00791ad3  ffd5                 call ebp
// 00791ad5  8b8e88000000         mov ecx, dword ptr [esi + 0x88]
// 00791adb  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00791ade  8dbea8000000         lea edi, [esi + 0xa8]
// 00791ae4  57                   push edi
// 00791ae5  52                   push edx
// 00791ae6  ffd5                 call ebp
// 00791ae8  8b8e8c000000         mov ecx, dword ptr [esi + 0x8c]
// 00791aee  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00791af1  8d86b8000000         lea eax, [esi + 0xb8]
// 00791af7  50                   push eax
// 00791af8  52                   push edx
// 00791af9  ffd5                 call ebp
// 00791afb  8b4304               mov eax, dword ptr [ebx + 4]
// 00791afe  2b430c               sub eax, dword ptr [ebx + 0xc]
// 00791b01  6a05                 push 5
// 00791b03  2b4704               sub eax, dword ptr [edi + 4]
// 00791b06  8d8edc000000         lea ecx, [esi + 0xdc]
// 00791b0c  03470c               add eax, dword ptr [edi + 0xc]
// 00791b0f  89467c               mov dword ptr [esi + 0x7c], eax
// 00791b12  e80972f8ff           call 0x718d20
// 00791b17  8b8efc000000         mov ecx, dword ptr [esi + 0xfc]
// 00791b1d  51                   push ecx
// 00791b1e  ff15b4ee8900         call dword ptr [0x89eeb4]
// 00791b24  8b1ddced8900         mov ebx, dword ptr [0x89eddc]
// 00791b2a  6a2d                 push 0x2d
// 00791b2c  ffd3                 call ebx
// 00791b2e  8bf0                 mov esi, eax
// 00791b30  6a2e                 push 0x2e
// 00791b32  03f6                 add esi, esi
// 00791b34  ffd3                 call ebx
// 00791b36  03c0                 add eax, eax
// 00791b38  50                   push eax
// 00791b39  56                   push esi
// 00791b3a  57                   push edi
// 00791b3b  ff15bced8900         call dword ptr [0x89edbc]
// 00791b41  5f                   pop edi
// 00791b42  5e                   pop esi
// 00791b43  5d                   pop ebp
// 00791b44  5b                   pop ebx
// 00791b45  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTCaption.cpp (function ?SetChildWindow@CXTCaption@@UAEXPAVCWnd@@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaption.cpp
