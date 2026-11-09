// from server: 100% by auto
// roc 2008-06 0065e850  unit: seg_00650000  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065e850
//
// 0065e850  53                   push ebx
// 0065e851  55                   push ebp
// 0065e852  56                   push esi
// 0065e853  8bf0                 mov esi, eax
// 0065e855  33ed                 xor ebp, ebp
// 0065e857  3bf5                 cmp esi, ebp
// 0065e859  7519                 jne 0x65e874
// 0065e85b  33db                 xor ebx, ebx
// 0065e85d  c1e605               shl esi, 5
// 0065e860  c74710d0c38400       mov dword ptr [edi + 0x10], 0x84c3d0
// 0065e867  037710               add esi, dword ptr [edi + 0x10]
// 0065e86a  885f07               mov byte ptr [edi + 7], bl
// 0065e86d  897714               mov dword ptr [edi + 0x14], esi
// 0065e870  5e                   pop esi
// 0065e871  5d                   pop ebp
// 0065e872  5b                   pop ebx
// 0065e873  c3                   ret 
// 0065e874  4e                   dec esi
// 0065e875  56                   push esi
// 0065e876  e8c53dfcff           call 0x622640
// 0065e87b  8bd8                 mov ebx, eax
// 0065e87d  43                   inc ebx
// 0065e87e  83c404               add esp, 4
// 0065e881  83fb1a               cmp ebx, 0x1a
// 0065e884  7e12                 jle 0x65e898
// 0065e886  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065e88a  6808c48400           push 0x84c408
// 0065e88f  50                   push eax
// 0065e890  e83b4ffcff           call 0x6237d0
// 0065e895  83c408               add esp, 8
// 0065e898  8bcb                 mov ecx, ebx
// 0065e89a  be01000000           mov esi, 1
// 0065e89f  d3e6                 shl esi, cl
// 0065e8a1  8d4e01               lea ecx, [esi + 1]
// 0065e8a4  81f9ffffff07         cmp ecx, 0x7ffffff
// 0065e8aa  7717                 ja 0x65e8c3
// 0065e8ac  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065e8b0  8bd6                 mov edx, esi
// 0065e8b2  c1e205               shl edx, 5
// 0065e8b5  52                   push edx
// 0065e8b6  55                   push ebp
// 0065e8b7  55                   push ebp
// 0065e8b8  50                   push eax
// 0065e8b9  e8321e0000           call 0x6606f0
// 0065e8be  83c410               add esp, 0x10
// 0065e8c1  eb0d                 jmp 0x65e8d0
// 0065e8c3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065e8c7  51                   push ecx
// 0065e8c8  e8031e0000           call 0x6606d0
// 0065e8cd  83c404               add esp, 4
// 0065e8d0  3bf5                 cmp esi, ebp
// 0065e8d2  894710               mov dword ptr [edi + 0x10], eax
// 0065e8d5  7e1f                 jle 0x65e8f6
// 0065e8d7  33c9                 xor ecx, ecx
// 0065e8d9  8bd6                 mov edx, esi
// 0065e8db  eb03                 jmp 0x65e8e0
// 0065e8dd  8d4900               lea ecx, [ecx]
// 0065e8e0  8b4710               mov eax, dword ptr [edi + 0x10]
// 0065e8e3  03c1                 add eax, ecx
// 0065e8e5  83c120               add ecx, 0x20
// 0065e8e8  83ea01               sub edx, 1
// 0065e8eb  89681c               mov dword ptr [eax + 0x1c], ebp
// 0065e8ee  896818               mov dword ptr [eax + 0x18], ebp
// 0065e8f1  896808               mov dword ptr [eax + 8], ebp
// 0065e8f4  75ea                 jne 0x65e8e0
// 0065e8f6  c1e605               shl esi, 5
// 0065e8f9  037710               add esi, dword ptr [edi + 0x10]
// 0065e8fc  885f07               mov byte ptr [edi + 7], bl
// 0065e8ff  897714               mov dword ptr [edi + 0x14], esi
// 0065e902  5e                   pop esi
// 0065e903  5d                   pop ebp
// 0065e904  5b                   pop ebx
// 0065e905  c3                   ret 
// library lua-5.1/ltable.c (function _setnodevector)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
