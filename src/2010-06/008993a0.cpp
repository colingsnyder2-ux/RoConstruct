// from server: 100% by auto
// roc 2010-06 008993a0  unit: CXTCaptionButtonThemeOffice2003  size: 363 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008993a0
//
// 008993a0  83ec44               sub esp, 0x44
// 008993a3  53                   push ebx
// 008993a4  8b5c2450             mov ebx, dword ptr [esp + 0x50]
// 008993a8  894c2404             mov dword ptr [esp + 4], ecx
// 008993ac  85db                 test ebx, ebx
// 008993ae  7504                 jne 0x8993b4
// 008993b0  33c0                 xor eax, eax
// 008993b2  eb03                 jmp 0x8993b7
// 008993b4  8b4320               mov eax, dword ptr [ebx + 0x20]
// 008993b7  50                   push eax
// 008993b8  ff1528bc9e00         call dword ptr [0x9ebc28]
// 008993be  85c0                 test eax, eax
// 008993c0  7507                 jne 0x8993c9
// 008993c2  5b                   pop ebx
// 008993c3  83c444               add esp, 0x44
// 008993c6  c20800               ret 8
// 008993c9  55                   push ebp
// 008993ca  56                   push esi
// 008993cb  8b742454             mov esi, dword ptr [esp + 0x54]
// 008993cf  8b4618               mov eax, dword ptr [esi + 0x18]
// 008993d2  57                   push edi
// 008993d3  50                   push eax
// 008993d4  e893390e00           call 0x97cd6c
// 008993d9  8d4e1c               lea ecx, [esi + 0x1c]
// 008993dc  51                   push ecx
// 008993dd  8d542418             lea edx, [esp + 0x18]
// 008993e1  52                   push edx
// 008993e2  8bf8                 mov edi, eax
// 008993e4  ff1548bc9e00         call dword ptr [0x9ebc48]
// 008993ea  8babac000000         mov ebp, dword ptr [ebx + 0xac]
// 008993f0  8b4610               mov eax, dword ptr [esi + 0x10]
// 008993f3  8944245c             mov dword ptr [esp + 0x5c], eax
// 008993f7  85ed                 test ebp, ebp
// 008993f9  7504                 jne 0x8993ff
// 008993fb  33c0                 xor eax, eax
// 008993fd  eb03                 jmp 0x899402
// 008993ff  8b4520               mov eax, dword ptr [ebp + 0x20]
// 00899402  50                   push eax
// 00899403  ff1528bc9e00         call dword ptr [0x9ebc28]
// 00899409  85c0                 test eax, eax
// 0089940b  0f84e5000000         je 0x8994f6
// 00899411  83bba000000000       cmp dword ptr [ebx + 0xa0], 0
// 00899418  750f                 jne 0x899429
// 0089941a  ff1584bc9e00         call dword ptr [0x9ebc84]
// 00899420  3b4320               cmp eax, dword ptr [ebx + 0x20]
// 00899423  7404                 je 0x899429
// 00899425  33c9                 xor ecx, ecx
// 00899427  eb05                 jmp 0x89942e
// 00899429  b901000000           mov ecx, 1
// 0089942e  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00899432  83e001               and eax, 1
// 00899435  7557                 jne 0x89948e
// 00899437  85c9                 test ecx, ecx
// 00899439  755f                 jne 0x89949a
// 0089943b  53                   push ebx
// 0089943c  8d4c2428             lea ecx, [esp + 0x28]
// 00899440  e86b5ef6ff           call 0x7ff2b0
// 00899445  8d4c2434             lea ecx, [esp + 0x34]
// 00899449  e8929bf4ff           call 0x7e2fe0
// 0089944e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00899452  8b11                 mov edx, dword ptr [ecx]
// 00899454  8b527c               mov edx, dword ptr [edx + 0x7c]
// 00899457  8d442434             lea eax, [esp + 0x34]
// 0089945b  50                   push eax
// 0089945c  55                   push ebp
// 0089945d  8d44242c             lea eax, [esp + 0x2c]
// 00899461  50                   push eax
// 00899462  ffd2                 call edx
// 00899464  6a00                 push 0
// 00899466  6a00                 push 0
// 00899468  8d44243c             lea eax, [esp + 0x3c]
// 0089946c  50                   push eax
// 0089946d  8d4c2420             lea ecx, [esp + 0x20]
// 00899471  51                   push ecx
// 00899472  57                   push edi
// 00899473  e8887ef6ff           call 0x801300
// 00899478  8bc8                 mov ecx, eax
// 0089947a  e8a181f6ff           call 0x801620
// 0089947f  5f                   pop edi
// 00899480  5e                   pop esi
// 00899481  5d                   pop ebp
// 00899482  b801000000           mov eax, 1
// 00899487  5b                   pop ebx
// 00899488  83c444               add esp, 0x44
// 0089948b  c20800               ret 8
// 0089948e  e88da6f4ff           call 0x7e3b20
// 00899493  0520010000           add eax, 0x120
// 00899498  eb0a                 jmp 0x8994a4
// 0089949a  e881a6f4ff           call 0x7e3b20
// 0089949f  0540010000           add eax, 0x140
// 008994a4  6a00                 push 0
// 008994a6  6a00                 push 0
// 008994a8  50                   push eax
// 008994a9  8d542420             lea edx, [esp + 0x20]
// 008994ad  52                   push edx
// 008994ae  57                   push edi
// 008994af  e84c7ef6ff           call 0x801300
// 008994b4  8bc8                 mov ecx, eax
// 008994b6  e86581f6ff           call 0x801620
// 008994bb  e860a6f4ff           call 0x7e3b20
// 008994c0  6a20                 push 0x20
// 008994c2  8bc8                 mov ecx, eax
// 008994c4  e817a0f4ff           call 0x7e34e0
// 008994c9  8bf0                 mov esi, eax
// 008994cb  e850a6f4ff           call 0x7e3b20
// 008994d0  56                   push esi
// 008994d1  6a20                 push 0x20
// 008994d3  8bc8                 mov ecx, eax
// 008994d5  e806a0f4ff           call 0x7e34e0
// 008994da  50                   push eax
// 008994db  8d44241c             lea eax, [esp + 0x1c]
// 008994df  50                   push eax
// 008994e0  8bcf                 mov ecx, edi
// 008994e2  e851f2f0ff           call 0x7a8738
// 008994e7  5f                   pop edi
// 008994e8  5e                   pop esi
// 008994e9  5d                   pop ebp
// 008994ea  b801000000           mov eax, 1
// 008994ef  5b                   pop ebx
// 008994f0  83c444               add esp, 0x44
// 008994f3  c20800               ret 8
// 008994f6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008994fa  53                   push ebx
// 008994fb  56                   push esi
// 008994fc  e8ef030100           call 0x8a98f0
// 00899501  5f                   pop edi
// 00899502  5e                   pop esi
// 00899503  5d                   pop ebp
// 00899504  5b                   pop ebx
// 00899505  83c444               add esp, 0x44
// 00899508  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawButtonThemeBackground@CXTCaptionButtonThemeOffice2003@@MAEHPAUtagDRAWITEMSTRUCT@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
