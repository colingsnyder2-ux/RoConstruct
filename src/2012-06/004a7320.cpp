// from server: 100% by Xemicl
// roc 2012-06 004a7320  unit: CTaskSchedulerPaneView  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a7320
//
// 004a7320  6aff                 push -1
// 004a7322  686a21aa00           push 0xaa216a
// 004a7327  64a100000000         mov eax, dword ptr fs:[0]
// 004a732d  50                   push eax
// 004a732e  64892500000000       mov dword ptr fs:[0], esp
// 004a7335  51                   push ecx
// 004a7336  6880030000           push 0x380
// 004a733b  e8daad4d00           call 0x98211a
// 004a7340  83c404               add esp, 4
// 004a7343  890424               mov dword ptr [esp], eax
// 004a7346  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004a734e  85c0                 test eax, eax
// 004a7350  7416                 je 0x4a7368
// 004a7352  8bc8                 mov ecx, eax
// 004a7354  e817ffffff           call 0x4a7270
// 004a7359  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004a735d  64890d00000000       mov dword ptr fs:[0], ecx
// 004a7364  83c410               add esp, 0x10
// 004a7367  c3                   ret 
// 004a7368  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004a736c  33c0                 xor eax, eax
// 004a736e  64890d00000000       mov dword ptr fs:[0], ecx
// 004a7375  83c410               add esp, 0x10
// 004a7378  c3                   ret 
// copied from an identical function in another client (function ?f@@YAPAUT@@XZ)

void* __cdecl operator new(unsigned int);
struct T { char pad[0x380]; T(); };
T* f() { return new T; }