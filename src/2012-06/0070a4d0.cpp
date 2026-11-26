// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 006c1130  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c1130
//
// 006c1130  64a100000000         mov eax, dword ptr fs:[0]
// 006c1136  6aff                 push -1
// 006c1138  686e9aab00           push 0xab9a6e
// 006c113d  50                   push eax
// 006c113e  b801000000           mov eax, 1
// 006c1143  64892500000000       mov dword ptr fs:[0], esp
// 006c114a  8405e8e1e200         test byte ptr [0xe2e1e8], al
// 006c1150  7536                 jne 0x6c1188
// 006c1152  0905e8e1e200         or dword ptr [0xe2e1e8], eax
// 006c1158  6a00                 push 0
// 006c115a  6858f9b600           push 0xb6f958
// 006c115f  b9cce1e200           mov ecx, 0xe2e1cc
// 006c1164  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006c116c  e84fe2ffff           call 0x6bf3c0
// 006c1171  689065b100           push 0xb16590
// 006c1176  c705cce1e2009868b900 mov dword ptr [0xe2e1cc], 0xb96898
// 006c1180  e870202c00           call 0x9831f5
// 006c1185  83c404               add esp, 4
// 006c1188  8b0c24               mov ecx, dword ptr [esp]
// 006c118b  b8cce1e200           mov eax, 0xe2e1cc
// 006c1190  64890d00000000       mov dword ptr fs:[0], ecx
// 006c1197  83c40c               add esp, 0xc
// 006c119a  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000000_005e58a0@@YAPAUTypeImpl@@XZ)

// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Type { Type(const char* name, int x); virtual ~Type(); };
struct TypeImpl : Type { TypeImpl() : Type("Function", 0) {} virtual ~TypeImpl() {} };
TypeImpl* func_005e58a0(){ static TypeImpl init; return &init; }