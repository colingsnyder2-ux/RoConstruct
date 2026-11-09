// from server: 100% by EspClaude
// from server: 79% by EspClaude
// roc 2009-06 005c1290  unit: RBX::VChunk::?$WeakReferenceCountedPointer  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c1290
//
// 005c1290  55                   push ebp
// 005c1291  8bec                 mov ebp, esp
// 005c1293  6aff                 push -1
// 005c1295  68c81f8600           push 0x861fc8
// 005c129a  64a100000000         mov eax, dword ptr fs:[0]
// 005c12a0  50                   push eax
// 005c12a1  64892500000000       mov dword ptr fs:[0], esp
// 005c12a8  51                   push ecx
// 005c12a9  894df0               mov dword ptr [ebp - 0x10], ecx
// 005c12ac  8b4508               mov eax, dword ptr [ebp + 8]
// 005c12af  50                   push eax
// 005c12b0  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 005c12b3  e848030000           call 0x5c1600
// 005c12b8  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005c12bf  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005c12c2  51                   push ecx
// 005c12c3  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 005c12c6  83c10c               add ecx, 0xc
// 005c12c9  e8521c0000           call 0x5c2f20
// 005c12ce  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 005c12d5  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 005c12d8  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005c12db  64890d00000000       mov dword ptr fs:[0], ecx
// 005c12e2  8be5                 mov esp, ebp
// 005c12e4  5d                   pop ebp
// 005c12e5  c20800               ret 8

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
#pragma optimize("", off)

struct Base {
    char storage[12];
    Base(void*);
    ~Base();
};

struct S {
    void* pointer;
    void assign(void*);
    S(const S&);
};

struct Object : Base {
    S member;
    Object(void*, const S&);
};

Object::Object(void* arg, const S& other)
    : Base(arg), member(other)
{
}
