// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005a04b0  unit: RBX::ArrowTool  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a04b0
//
// 005a04b0  6aff                 push -1
// 005a04b2  683bf47b00           push 0x7bf43b
// 005a04b7  64a100000000         mov eax, dword ptr fs:[0]
// 005a04bd  50                   push eax
// 005a04be  64892500000000       mov dword ptr fs:[0], esp
// 005a04c5  51                   push ecx
// 005a04c6  56                   push esi
// 005a04c7  57                   push edi
// 005a04c8  6a20                 push 0x20
// 005a04ca  8bf9                 mov edi, ecx
// 005a04cc  e84f041000           call 0x6a0920
// 005a04d1  8bf0                 mov esi, eax
// 005a04d3  83c404               add esp, 4
// 005a04d6  89742408             mov dword ptr [esp + 8], esi
// 005a04da  c744241400000000     mov dword ptr [esp + 0x14], 0
// 005a04e2  85f6                 test esi, esi
// 005a04e4  742f                 je 0x5a0515
// 005a04e6  8b4718               mov eax, dword ptr [edi + 0x18]
// 005a04e9  50                   push eax
// 005a04ea  8bce                 mov ecx, esi
// 005a04ec  e8ff540700           call 0x6159f0
// 005a04f1  5f                   pop edi
// 005a04f2  c6461c00             mov byte ptr [esi + 0x1c], 0
// 005a04f6  c706a4368300         mov dword ptr [esi], 0x8336a4
// 005a04fc  c7460488368300       mov dword ptr [esi + 4], 0x833688
// 005a0503  8bc6                 mov eax, esi
// 005a0505  5e                   pop esi
// 005a0506  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005a050a  64890d00000000       mov dword ptr fs:[0], ecx
// 005a0511  83c410               add esp, 0x10
// 005a0514  c3                   ret 
// 005a0515  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005a0519  5f                   pop edi
// 005a051a  33c0                 xor eax, eax
// 005a051c  5e                   pop esi
// 005a051d  64890d00000000       mov dword ptr fs:[0], ecx
// 005a0524  83c410               add esp, 0x10
// 005a0527  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S_func_006159f0 {
    int f(int a1);
};

struct Object {
    char storage[32];
    Object(int a1);
};

inline Object::Object(int a1)
{
    ((S_func_006159f0*)this)->f(a1);
    *(char*)((char*)this + 28) = 0;
    *(int*)((char*)this + 0) = 0x8336a4;
    *(int*)((char*)this + 4) = 0x833688;
}

struct S {
    Object* f();
};

Object* S::f()
{
    return new Object(*(int*)((char*)this + 24));
}
