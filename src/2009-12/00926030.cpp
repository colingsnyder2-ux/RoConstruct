// from server: 100% by auto
// roc 2009-12 00926030  unit: seg_00920000  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00926030
//
// 00926030  55                   push ebp
// 00926031  8bec                 mov ebp, esp
// 00926033  83ec20               sub esp, 0x20
// 00926036  33c0                 xor eax, eax
// 00926038  8845ff               mov byte ptr [ebp - 1], al
// 0092603b  8a4dff               mov cl, byte ptr [ebp - 1]
// 0092603e  884de2               mov byte ptr [ebp - 0x1e], cl
// 00926041  8a55fe               mov dl, byte ptr [ebp - 2]
// 00926044  8855e3               mov byte ptr [ebp - 0x1d], dl
// 00926047  8b4508               mov eax, dword ptr [ebp + 8]
// 0092604a  8945e4               mov dword ptr [ebp - 0x1c], eax
// 0092604d  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00926050  8b55e4               mov edx, dword ptr [ebp - 0x1c]
// 00926053  8d048a               lea eax, [edx + ecx*4]
// 00926056  8945f8               mov dword ptr [ebp - 8], eax
// 00926059  33c9                 xor ecx, ecx
// 0092605b  884df7               mov byte ptr [ebp - 9], cl
// 0092605e  8a55f7               mov dl, byte ptr [ebp - 9]
// 00926061  8855eb               mov byte ptr [ebp - 0x15], dl
// 00926064  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00926067  8945ec               mov dword ptr [ebp - 0x14], eax
// 0092606a  8b4de4               mov ecx, dword ptr [ebp - 0x1c]
// 0092606d  894df0               mov dword ptr [ebp - 0x10], ecx
// 00926070  eb12                 jmp 0x926084
// 00926072  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00926075  83ea01               sub edx, 1
// 00926078  8955ec               mov dword ptr [ebp - 0x14], edx
// 0092607b  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 0092607e  83c004               add eax, 4
// 00926081  8945f0               mov dword ptr [ebp - 0x10], eax
// 00926084  837dec00             cmp dword ptr [ebp - 0x14], 0
// 00926088  760c                 jbe 0x926096
// 0092608a  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 0092608d  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00926090  8b02                 mov eax, dword ptr [edx]
// 00926092  8901                 mov dword ptr [ecx], eax
// 00926094  ebdc                 jmp 0x926072
// 00926096  8be5                 mov esp, ebp
// 00926098  5d                   pop ebp
// 00926099  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$unchecked_fill_n@PAHIH@stdext@@YAXPAHIABH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
