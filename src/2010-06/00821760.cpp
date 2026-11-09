// from server: 100% by auto
// roc 2010-06 00821760  unit: CSelectionCaption  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00821760
//
// 00821760  8b442408             mov eax, dword ptr [esp + 8]
// 00821764  53                   push ebx
// 00821765  55                   push ebp
// 00821766  56                   push esi
// 00821767  8bf1                 mov esi, ecx
// 00821769  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0082176d  57                   push edi
// 0082176e  898e84000000         mov dword ptr [esi + 0x84], ecx
// 00821774  85c0                 test eax, eax
// 00821776  7405                 je 0x82177d
// 00821778  8b4020               mov eax, dword ptr [eax + 0x20]
// 0082177b  eb02                 jmp 0x82177f
// 0082177d  33c0                 xor eax, eax
// 0082177f  8b3d4cba9e00         mov edi, dword ptr [0x9eba4c]
// 00821785  894638               mov dword ptr [esi + 0x38], eax
// 00821788  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0082178b  50                   push eax
// 0082178c  ffd7                 call edi
// 0082178e  50                   push eax
// 0082178f  e8d664f8ff           call 0x7a7c6a
// 00821794  898688000000         mov dword ptr [esi + 0x88], eax
// 0082179a  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0082179d  51                   push ecx
// 0082179e  ffd7                 call edi
// 008217a0  50                   push eax
// 008217a1  e8c464f8ff           call 0x7a7c6a
// 008217a6  8b9684000000         mov edx, dword ptr [esi + 0x84]
// 008217ac  8b2d5cbc9e00         mov ebp, dword ptr [0x9ebc5c]
// 008217b2  89868c000000         mov dword ptr [esi + 0x8c], eax
// 008217b8  8b4220               mov eax, dword ptr [edx + 0x20]
// 008217bb  8d9e98000000         lea ebx, [esi + 0x98]
// 008217c1  53                   push ebx
// 008217c2  50                   push eax
// 008217c3  ffd5                 call ebp
// 008217c5  8b8e88000000         mov ecx, dword ptr [esi + 0x88]
// 008217cb  8b5120               mov edx, dword ptr [ecx + 0x20]
// 008217ce  8dbea8000000         lea edi, [esi + 0xa8]
// 008217d4  57                   push edi
// 008217d5  52                   push edx
// 008217d6  ffd5                 call ebp
// 008217d8  8b8e8c000000         mov ecx, dword ptr [esi + 0x8c]
// 008217de  8b5120               mov edx, dword ptr [ecx + 0x20]
// 008217e1  8d86b8000000         lea eax, [esi + 0xb8]
// 008217e7  50                   push eax
// 008217e8  52                   push edx
// 008217e9  ffd5                 call ebp
// 008217eb  8b4304               mov eax, dword ptr [ebx + 4]
// 008217ee  2b430c               sub eax, dword ptr [ebx + 0xc]
// 008217f1  6a05                 push 5
// 008217f3  2b4704               sub eax, dword ptr [edi + 4]
// 008217f6  8d8edc000000         lea ecx, [esi + 0xdc]
// 008217fc  03470c               add eax, dword ptr [edi + 0xc]
// 008217ff  89467c               mov dword ptr [esi + 0x7c], eax
// 00821802  e88164f8ff           call 0x7a7c88
// 00821807  8b8efc000000         mov ecx, dword ptr [esi + 0xfc]
// 0082180d  51                   push ecx
// 0082180e  ff15d8ba9e00         call dword ptr [0x9ebad8]
// 00821814  8b1d6cba9e00         mov ebx, dword ptr [0x9eba6c]
// 0082181a  6a2d                 push 0x2d
// 0082181c  ffd3                 call ebx
// 0082181e  8bf0                 mov esi, eax
// 00821820  6a2e                 push 0x2e
// 00821822  03f6                 add esi, esi
// 00821824  ffd3                 call ebx
// 00821826  03c0                 add eax, eax
// 00821828  50                   push eax
// 00821829  56                   push esi
// 0082182a  57                   push edi
// 0082182b  ff15dcbb9e00         call dword ptr [0x9ebbdc]
// 00821831  5f                   pop edi
// 00821832  5e                   pop esi
// 00821833  5d                   pop ebp
// 00821834  5b                   pop ebx
// 00821835  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTCaption.cpp (function ?SetChildWindow@CXTCaption@@UAEXPAVCWnd@@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaption.cpp
