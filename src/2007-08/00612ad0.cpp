// from server: 100% by auto
// roc 2007-08 00612ad0  unit: seg_00610000  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00612ad0
//
// 00612ad0  53                   push ebx
// 00612ad1  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00612ad5  55                   push ebp
// 00612ad6  56                   push esi
// 00612ad7  8b742418             mov esi, dword ptr [esp + 0x18]
// 00612adb  57                   push edi
// 00612adc  8bd6                 mov edx, esi
// 00612ade  8bc3                 mov eax, ebx
// 00612ae0  e89bf3ffff           call 0x611e80
// 00612ae5  8be8                 mov ebp, eax
// 00612ae7  837d0800             cmp dword ptr [ebp + 8], 0
// 00612aeb  750c                 jne 0x612af9
// 00612aed  81fdb8327c00         cmp ebp, 0x7c32b8
// 00612af3  0f8587000000         jne 0x612b80
// 00612af9  8b4b14               mov ecx, dword ptr [ebx + 0x14]
// 00612afc  3b4b10               cmp ecx, dword ptr [ebx + 0x10]
// 00612aff  b8e0ffffff           mov eax, 0xffffffe0
// 00612b04  7613                 jbe 0x612b19
// 00612b06  014314               add dword ptr [ebx + 0x14], eax
// 00612b09  8b7b14               mov edi, dword ptr [ebx + 0x14]
// 00612b0c  837f1800             cmp dword ptr [edi + 0x18], 0
// 00612b10  740c                 je 0x612b1e
// 00612b12  8bd7                 mov edx, edi
// 00612b14  3b5310               cmp edx, dword ptr [ebx + 0x10]
// 00612b17  77ed                 ja 0x612b06
// 00612b19  014314               add dword ptr [ebx + 0x14], eax
// 00612b1c  eb04                 jmp 0x612b22
// 00612b1e  85ff                 test edi, edi
// 00612b20  751e                 jne 0x612b40
// 00612b22  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00612b26  55                   push ebp
// 00612b27  8bfe                 mov edi, esi
// 00612b29  8bc3                 mov eax, ebx
// 00612b2b  e880feffff           call 0x6129b0
// 00612b30  56                   push esi
// 00612b31  53                   push ebx
// 00612b32  55                   push ebp
// 00612b33  e888faffff           call 0x6125c0
// 00612b38  83c410               add esp, 0x10
// 00612b3b  5f                   pop edi
// 00612b3c  5e                   pop esi
// 00612b3d  5d                   pop ebp
// 00612b3e  5b                   pop ebx
// 00612b3f  c3                   ret 
// 00612b40  8d5510               lea edx, [ebp + 0x10]
// 00612b43  8bc3                 mov eax, ebx
// 00612b45  e836f3ffff           call 0x611e80
// 00612b4a  3bc5                 cmp eax, ebp
// 00612b4c  7427                 je 0x612b75
// 00612b4e  39681c               cmp dword ptr [eax + 0x1c], ebp
// 00612b51  7408                 je 0x612b5b
// 00612b53  8b401c               mov eax, dword ptr [eax + 0x1c]
// 00612b56  39681c               cmp dword ptr [eax + 0x1c], ebp
// 00612b59  75f8                 jne 0x612b53
// 00612b5b  89781c               mov dword ptr [eax + 0x1c], edi
// 00612b5e  b908000000           mov ecx, 8
// 00612b63  8bf5                 mov esi, ebp
// 00612b65  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00612b67  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00612b6b  33c0                 xor eax, eax
// 00612b6d  89451c               mov dword ptr [ebp + 0x1c], eax
// 00612b70  894508               mov dword ptr [ebp + 8], eax
// 00612b73  eb0b                 jmp 0x612b80
// 00612b75  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00612b78  89471c               mov dword ptr [edi + 0x1c], eax
// 00612b7b  897d1c               mov dword ptr [ebp + 0x1c], edi
// 00612b7e  8bef                 mov ebp, edi
// 00612b80  8b0e                 mov ecx, dword ptr [esi]
// 00612b82  894d10               mov dword ptr [ebp + 0x10], ecx
// 00612b85  8b5604               mov edx, dword ptr [esi + 4]
// 00612b88  895514               mov dword ptr [ebp + 0x14], edx
// 00612b8b  8b4608               mov eax, dword ptr [esi + 8]
// 00612b8e  894518               mov dword ptr [ebp + 0x18], eax
// 00612b91  b804000000           mov eax, 4
// 00612b96  394608               cmp dword ptr [esi + 8], eax
// 00612b99  7c1b                 jl 0x612bb6
// 00612b9b  8b0e                 mov ecx, dword ptr [esi]
// 00612b9d  f6410503             test byte ptr [ecx + 5], 3
// 00612ba1  7413                 je 0x612bb6
// 00612ba3  844305               test byte ptr [ebx + 5], al
// 00612ba6  740e                 je 0x612bb6
// 00612ba8  8b542414             mov edx, dword ptr [esp + 0x14]
// 00612bac  53                   push ebx
// 00612bad  52                   push edx
// 00612bae  e87dd3ffff           call 0x60ff30
// 00612bb3  83c408               add esp, 8
// 00612bb6  5f                   pop edi
// 00612bb7  5e                   pop esi
// 00612bb8  8bc5                 mov eax, ebp
// 00612bba  5d                   pop ebp
// 00612bbb  5b                   pop ebx
// 00612bbc  c3                   ret 
// library lua-5.1/ltable.c (function _newkey)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
