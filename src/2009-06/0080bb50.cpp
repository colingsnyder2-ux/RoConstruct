// from server: 100% by auto
// roc 2009-06 0080bb50  unit: CXTCaptionPopupWnd  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080bb50
//
// 0080bb50  83ec28               sub esp, 0x28
// 0080bb53  56                   push esi
// 0080bb54  e89dd1f0ff           call 0x718cf6
// 0080bb59  8b7008               mov esi, dword ptr [eax + 8]
// 0080bb5c  8d442404             lea eax, [esp + 4]
// 0080bb60  50                   push eax
// 0080bb61  68a8c69000           push 0x90c6a8
// 0080bb66  56                   push esi
// 0080bb67  ff154cec8900         call dword ptr [0x89ec4c]
// 0080bb6d  85c0                 test eax, eax
// 0080bb6f  756d                 jne 0x80bbde
// 0080bb71  8b0d5ced8900         mov ecx, dword ptr [0x89ed5c]
// 0080bb77  57                   push edi
// 0080bb78  33ff                 xor edi, edi
// 0080bb7a  c744240803000000     mov dword ptr [esp + 8], 3
// 0080bb82  894c240c             mov dword ptr [esp + 0xc], ecx
// 0080bb86  897c2410             mov dword ptr [esp + 0x10], edi
// 0080bb8a  897c2414             mov dword ptr [esp + 0x14], edi
// 0080bb8e  89742418             mov dword ptr [esp + 0x18], esi
// 0080bb92  897c241c             mov dword ptr [esp + 0x1c], edi
// 0080bb96  e85bd1f0ff           call 0x718cf6
// 0080bb9b  68007f0000           push 0x7f00
// 0080bba0  57                   push edi
// 0080bba1  ff15b0ed8900         call dword ptr [0x89edb0]
// 0080bba7  6a0f                 push 0xf
// 0080bba9  89442424             mov dword ptr [esp + 0x24], eax
// 0080bbad  ff1574ec8900         call dword ptr [0x89ec74]
// 0080bbb3  8d542408             lea edx, [esp + 8]
// 0080bbb7  52                   push edx
// 0080bbb8  89442428             mov dword ptr [esp + 0x28], eax
// 0080bbbc  897c242c             mov dword ptr [esp + 0x2c], edi
// 0080bbc0  c7442430a8c69000     mov dword ptr [esp + 0x30], 0x90c6a8
// 0080bbc8  e849080400           call 0x84c416
// 0080bbcd  5f                   pop edi
// 0080bbce  85c0                 test eax, eax
// 0080bbd0  750c                 jne 0x80bbde
// 0080bbd2  e87d030400           call 0x84bf54
// 0080bbd7  33c0                 xor eax, eax
// 0080bbd9  5e                   pop esi
// 0080bbda  83c428               add esp, 0x28
// 0080bbdd  c3                   ret 
// 0080bbde  b801000000           mov eax, 1
// 0080bbe3  5e                   pop esi
// 0080bbe4  83c428               add esp, 0x28
// 0080bbe7  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionPopupWnd.cpp (function ?RegisterWindowClass@CXTCaptionPopupWnd@@IAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionPopupWnd.cpp
