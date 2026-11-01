// from server: 100% by auto
// roc 2009-12 007d52a0  unit: seg_007d0000  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d52a0
//
// 007d52a0  83ec50               sub esp, 0x50
// 007d52a3  53                   push ebx
// 007d52a4  8b5c2458             mov ebx, dword ptr [esp + 0x58]
// 007d52a8  8b4340               mov eax, dword ptr [ebx + 0x40]
// 007d52ab  56                   push esi
// 007d52ac  6a50                 push 0x50
// 007d52ae  83c010               add eax, 0x10
// 007d52b1  50                   push eax
// 007d52b2  8d4c2410             lea ecx, [esp + 0x10]
// 007d52b6  51                   push ecx
// 007d52b7  e8e452fcff           call 0x79a5a0
// 007d52bc  8b54246c             mov edx, dword ptr [esp + 0x6c]
// 007d52c0  8b4304               mov eax, dword ptr [ebx + 4]
// 007d52c3  52                   push edx
// 007d52c4  8b5334               mov edx, dword ptr [ebx + 0x34]
// 007d52c7  50                   push eax
// 007d52c8  8d4c241c             lea ecx, [esp + 0x1c]
// 007d52cc  51                   push ecx
// 007d52cd  68b4ab9e00           push 0x9eabb4
// 007d52d2  52                   push edx
// 007d52d3  e8a852fcff           call 0x79a580
// 007d52d8  8bf0                 mov esi, eax
// 007d52da  8b842484000000       mov eax, dword ptr [esp + 0x84]
// 007d52e1  83c420               add esp, 0x20
// 007d52e4  85c0                 test eax, eax
// 007d52e6  743c                 je 0x7d5324
// 007d52e8  3d1c010000           cmp eax, 0x11c
// 007d52ed  7c18                 jl 0x7d5307
// 007d52ef  3d1e010000           cmp eax, 0x11e
// 007d52f4  7f11                 jg 0x7d5307
// 007d52f6  6a00                 push 0
// 007d52f8  e883feffff           call 0x7d5180
// 007d52fd  8b433c               mov eax, dword ptr [ebx + 0x3c]
// 007d5300  8b00                 mov eax, dword ptr [eax]
// 007d5302  83c404               add esp, 4
// 007d5305  eb0a                 jmp 0x7d5311
// 007d5307  50                   push eax
// 007d5308  53                   push ebx
// 007d5309  e832ffffff           call 0x7d5240
// 007d530e  83c408               add esp, 8
// 007d5311  8b4b34               mov ecx, dword ptr [ebx + 0x34]
// 007d5314  50                   push eax
// 007d5315  56                   push esi
// 007d5316  68e4f39e00           push 0x9ef3e4
// 007d531b  51                   push ecx
// 007d531c  e85f52fcff           call 0x79a580
// 007d5321  83c410               add esp, 0x10
// 007d5324  8b5334               mov edx, dword ptr [ebx + 0x34]
// 007d5327  6a03                 push 3
// 007d5329  52                   push edx
// 007d532a  e82125fcff           call 0x797850
// 007d532f  83c408               add esp, 8
// 007d5332  5e                   pop esi
// 007d5333  5b                   pop ebx
// 007d5334  83c450               add esp, 0x50
// 007d5337  c3                   ret 
// library lua-5.1/llex.c (function _luaX_lexerror)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 llex.c
