// from server: 100% by auto
// roc 2010-06 0053f690  unit: RBX::SceneManager  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0053f690
//
// 0053f690  55                   push ebp
// 0053f691  8bec                 mov ebp, esp
// 0053f693  83e4c0               and esp, 0xffffffc0
// 0053f696  83ec34               sub esp, 0x34
// 0053f699  53                   push ebx
// 0053f69a  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0053f69d  56                   push esi
// 0053f69e  57                   push edi
// 0053f69f  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 0053f6a7  33f6                 xor esi, esi
// 0053f6a9  8bfb                 mov edi, ebx
// 0053f6ab  eb03                 jmp 0x53f6b0
// 0053f6ad  8d4900               lea ecx, [ecx]
// 0053f6b0  d907                 fld dword ptr [edi]
// 0053f6b2  83ec08               sub esp, 8
// 0053f6b5  dd1c24               fstp qword ptr [esp]
// 0053f6b8  e8c30cfaff           call 0x4e0380
// 0053f6bd  83c408               add esp, 8
// 0053f6c0  84c0                 test al, al
// 0053f6c2  7423                 je 0x53f6e7
// 0053f6c4  46                   inc esi
// 0053f6c5  83c704               add edi, 4
// 0053f6c8  83fe03               cmp esi, 3
// 0053f6cb  7ce3                 jl 0x53f6b0
// 0053f6cd  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0053f6d1  40                   inc eax
// 0053f6d2  83c30c               add ebx, 0xc
// 0053f6d5  83f803               cmp eax, 3
// 0053f6d8  8944243c             mov dword ptr [esp + 0x3c], eax
// 0053f6dc  7cc9                 jl 0x53f6a7
// 0053f6de  b001                 mov al, 1
// 0053f6e0  5f                   pop edi
// 0053f6e1  5e                   pop esi
// 0053f6e2  5b                   pop ebx
// 0053f6e3  8be5                 mov esp, ebp
// 0053f6e5  5d                   pop ebp
// 0053f6e6  c3                   ret 
// 0053f6e7  5f                   pop edi
// 0053f6e8  5e                   pop esi
// 0053f6e9  32c0                 xor al, al
// 0053f6eb  5b                   pop ebx
// 0053f6ec  8be5                 mov esp, ebp
// 0053f6ee  5d                   pop ebp
// 0053f6ef  c3                   ret 
// copied from an identical function in another client (function ?method@ns_ROCX000000@ns_ROCX000001@@YA_NPAY02M@Z)

namespace ns_ROCX000000 {
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-view BevelMesh.cpp
}
