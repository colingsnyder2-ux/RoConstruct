// from server: 100% by auto
// roc 2011-06 0087ee80  unit: CSelectionCaption  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0087ee80
//
// 0087ee80  8b442408             mov eax, dword ptr [esp + 8]
// 0087ee84  53                   push ebx
// 0087ee85  55                   push ebp
// 0087ee86  56                   push esi
// 0087ee87  8bf1                 mov esi, ecx
// 0087ee89  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0087ee8d  57                   push edi
// 0087ee8e  898e84000000         mov dword ptr [esi + 0x84], ecx
// 0087ee94  85c0                 test eax, eax
// 0087ee96  7405                 je 0x87ee9d
// 0087ee98  8b4020               mov eax, dword ptr [eax + 0x20]
// 0087ee9b  eb02                 jmp 0x87ee9f
// 0087ee9d  33c0                 xor eax, eax
// 0087ee9f  8b3db819a400         mov edi, dword ptr [0xa419b8]
// 0087eea5  894638               mov dword ptr [esi + 0x38], eax
// 0087eea8  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0087eeab  50                   push eax
// 0087eeac  ffd7                 call edi
// 0087eeae  50                   push eax
// 0087eeaf  e874b4f8ff           call 0x80a328
// 0087eeb4  898688000000         mov dword ptr [esi + 0x88], eax
// 0087eeba  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0087eebd  51                   push ecx
// 0087eebe  ffd7                 call edi
// 0087eec0  50                   push eax
// 0087eec1  e862b4f8ff           call 0x80a328
// 0087eec6  8b9684000000         mov edx, dword ptr [esi + 0x84]
// 0087eecc  8b2d7c1ca400         mov ebp, dword ptr [0xa41c7c]
// 0087eed2  89868c000000         mov dword ptr [esi + 0x8c], eax
// 0087eed8  8b4220               mov eax, dword ptr [edx + 0x20]
// 0087eedb  8d9e98000000         lea ebx, [esi + 0x98]
// 0087eee1  53                   push ebx
// 0087eee2  50                   push eax
// 0087eee3  ffd5                 call ebp
// 0087eee5  8b8e88000000         mov ecx, dword ptr [esi + 0x88]
// 0087eeeb  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0087eeee  8dbea8000000         lea edi, [esi + 0xa8]
// 0087eef4  57                   push edi
// 0087eef5  52                   push edx
// 0087eef6  ffd5                 call ebp
// 0087eef8  8b8e8c000000         mov ecx, dword ptr [esi + 0x8c]
// 0087eefe  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0087ef01  8d86b8000000         lea eax, [esi + 0xb8]
// 0087ef07  50                   push eax
// 0087ef08  52                   push edx
// 0087ef09  ffd5                 call ebp
// 0087ef0b  8b4304               mov eax, dword ptr [ebx + 4]
// 0087ef0e  2b430c               sub eax, dword ptr [ebx + 0xc]
// 0087ef11  6a05                 push 5
// 0087ef13  2b4704               sub eax, dword ptr [edi + 4]
// 0087ef16  8d8edc000000         lea ecx, [esi + 0xdc]
// 0087ef1c  03470c               add eax, dword ptr [edi + 0xc]
// 0087ef1f  89467c               mov dword ptr [esi + 0x7c], eax
// 0087ef22  e81fb4f8ff           call 0x80a346
// 0087ef27  8b8efc000000         mov ecx, dword ptr [esi + 0xfc]
// 0087ef2d  51                   push ecx
// 0087ef2e  ff152c1ba400         call dword ptr [0xa41b2c]
// 0087ef34  8b1de019a400         mov ebx, dword ptr [0xa419e0]
// 0087ef3a  6a2d                 push 0x2d
// 0087ef3c  ffd3                 call ebx
// 0087ef3e  8bf0                 mov esi, eax
// 0087ef40  6a2e                 push 0x2e
// 0087ef42  03f6                 add esi, esi
// 0087ef44  ffd3                 call ebx
// 0087ef46  03c0                 add eax, eax
// 0087ef48  50                   push eax
// 0087ef49  56                   push esi
// 0087ef4a  57                   push edi
// 0087ef4b  ff15e41ba400         call dword ptr [0xa41be4]
// 0087ef51  5f                   pop edi
// 0087ef52  5e                   pop esi
// 0087ef53  5d                   pop ebp
// 0087ef54  5b                   pop ebx
// 0087ef55  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTCaption.cpp (function ?SetChildWindow@CXTCaption@@UAEXPAVCWnd@@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaption.cpp
