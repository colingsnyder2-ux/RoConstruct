// from server: 100% by coldek
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 100% by tester
// roc 2008-06 005bb060  unit: RBX::W4SoundType::?$EnumDesc  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bb060
//
// 005bb060  55                   push ebp
// 005bb061  8bec                 mov ebp, esp
// 005bb063  6aff                 push -1
// 005bb065  68703b7d00           push 0x7d3b70
// 005bb06a  64a100000000         mov eax, dword ptr fs:[0]
// 005bb070  50                   push eax
// 005bb071  64892500000000       mov dword ptr fs:[0], esp
// 005bb078  51                   push ecx
// 005bb079  53                   push ebx
// 005bb07a  56                   push esi
// 005bb07b  57                   push edi
// 005bb07c  8965f0               mov dword ptr [ebp - 0x10], esp
// 005bb07f  8bf1                 mov esi, ecx
// 005bb081  6a10                 push 0x10
// 005bb083  c70600000000         mov dword ptr [esi], 0
// 005bb089  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005bb090  e88b580e00           call 0x6a0920
// 005bb095  83c404               add esp, 4
// 005bb098  85c0                 test eax, eax
// 005bb09a  7419                 je 0x5bb0b5
// 005bb09c  b901000000           mov ecx, 1
// 005bb0a1  894804               mov dword ptr [eax + 4], ecx
// 005bb0a4  894808               mov dword ptr [eax + 8], ecx
// 005bb0a7  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005bb0aa  c700ac758300         mov dword ptr [eax], 0x8375ac
// 005bb0b0  89480c               mov dword ptr [eax + 0xc], ecx
// 005bb0b3  eb02                 jmp 0x5bb0b7
// 005bb0b5  33c0                 xor eax, eax
// 005bb0b7  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005bb0ba  8906                 mov dword ptr [esi], eax
// 005bb0bc  5f                   pop edi
// 005bb0bd  8bc6                 mov eax, esi
// 005bb0bf  5e                   pop esi
// 005bb0c0  64890d00000000       mov dword ptr fs:[0], ecx
// 005bb0c7  5b                   pop ebx
// 005bb0c8  8be5                 mov esp, ebp
// 005bb0ca  5d                   pop ebp
// 005bb0cb  c20400               ret 4

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Object {
    virtual ~Object();
};

struct CountBase {
    long useCount;
    long weakCount;

    CountBase() : useCount(1), weakCount(1) {}
    virtual ~CountBase();
    virtual void dispose() = 0;
    virtual void destroy();
    virtual void* getDeleter(const void*) = 0;
};

struct Count : CountBase {
    Object* object;

    explicit Count(Object* p) : object(p) {}
    virtual ~Count();
    virtual void dispose();
    virtual void* getDeleter(const void*);
};

extern void __cdecl deleteObject(Object*);

struct S {
    CountBase* count;
    explicit S(Object*);
};

S::S(Object* p) : count(0)
{
    try {
        count = new Count(p);
    }
    catch (...) {
        deleteObject(p);
        throw;
    }
}
