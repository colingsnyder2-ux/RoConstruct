// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 004163a0  unit: CIDEBrowserView  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004163a0
//
// 004163a0  6aff                 push -1
// 004163a2  686a21aa00           push 0xaa216a
// 004163a7  64a100000000         mov eax, dword ptr fs:[0]
// 004163ad  50                   push eax
// 004163ae  64892500000000       mov dword ptr fs:[0], esp
// 004163b5  51                   push ecx
// 004163b6  68b4020000           push 0x2b4
// 004163bb  e85abd5600           call 0x98211a
// 004163c0  83c404               add esp, 4
// 004163c3  890424               mov dword ptr [esp], eax
// 004163c6  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004163ce  85c0                 test eax, eax
// 004163d0  7416                 je 0x4163e8
// 004163d2  8bc8                 mov ecx, eax
// 004163d4  e8b7fcffff           call 0x416090
// 004163d9  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004163dd  64890d00000000       mov dword ptr fs:[0], ecx
// 004163e4  83c410               add esp, 0x10
// 004163e7  c3                   ret 
// 004163e8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004163ec  33c0                 xor eax, eax
// 004163ee  64890d00000000       mov dword ptr fs:[0], ecx
// 004163f5  83c410               add esp, 0x10
// 004163f8  c3                   ret 

// copied from an identical function in another client (function ?f@@YAPAUT@@XZ)

void* __cdecl operator new(unsigned int);
struct T { char pad[0xac]; T(); };
T* f() { return new T; }
