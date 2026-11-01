// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 0044e500  unit: CRobloxControlColorSelector  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044e500
//
// 0044e500  55                   push ebp
// 0044e501  8bec                 mov ebp, esp
// 0044e503  6aff                 push -1
// 0044e505  6821157c00           push 0x7c1521
// 0044e50a  64a100000000         mov eax, dword ptr fs:[0]
// 0044e510  50                   push eax
// 0044e511  64892500000000       mov dword ptr fs:[0], esp
// 0044e518  83ec0c               sub esp, 0xc
// 0044e51b  53                   push ebx
// 0044e51c  56                   push esi
// 0044e51d  8b7510               mov esi, dword ptr [ebp + 0x10]
// 0044e520  57                   push edi
// 0044e521  8b7d08               mov edi, dword ptr [ebp + 8]
// 0044e524  33db                 xor ebx, ebx
// 0044e526  8965f0               mov dword ptr [ebp - 0x10], esp
// 0044e529  8975ec               mov dword ptr [ebp - 0x14], esi
// 0044e52c  895dfc               mov dword ptr [ebp - 4], ebx
// 0044e52f  90                   nop 
// 0044e530  3b7d0c               cmp edi, dword ptr [ebp + 0xc]
// 0044e533  7456                 je 0x44e58b
// 0044e535  897508               mov dword ptr [ebp + 8], esi
// 0044e538  8975e8               mov dword ptr [ebp - 0x18], esi
// 0044e53b  c645fc01             mov byte ptr [ebp - 4], 1
// 0044e53f  3bf3                 cmp esi, ebx
// 0044e541  7417                 je 0x44e55a
// 0044e543  8b07                 mov eax, dword ptr [edi]
// 0044e545  8906                 mov dword ptr [esi], eax
// 0044e547  8b4f04               mov ecx, dword ptr [edi + 4]
// 0044e54a  8d5708               lea edx, [edi + 8]
// 0044e54d  894e04               mov dword ptr [esi + 4], ecx
// 0044e550  52                   push edx
// 0044e551  8d4e08               lea ecx, [esi + 8]
// 0044e554  ff15d43e8000         call dword ptr [0x803ed4]
// 0044e55a  83c60c               add esi, 0xc
// 0044e55d  885dfc               mov byte ptr [ebp - 4], bl
// 0044e560  897510               mov dword ptr [ebp + 0x10], esi
// 0044e563  83c70c               add edi, 0xc
// 0044e566  ebc8                 jmp 0x44e530

typedef unsigned int size_t;

inline void *__cdecl operator new(size_t, void *address)
{
    return address;
}

inline void __cdecl operator delete(void *, void *)
{
}

typedef void (__thiscall *CopyObject)(void *, const void *);
extern CopyObject copyObject;

typedef void (__thiscall *DestroyObject)(void *);
extern DestroyObject destroyObject;

struct Value {
    unsigned long first;
    unsigned long second;
    unsigned long object;

    Value(const Value &source);
    ~Value() { destroyObject(&object); }
};

inline Value::Value(const Value &source)
    : first(source.first), second(source.second)
{
    copyObject(&object, &source.object);
}

Value *__cdecl copyValues(const Value *first, const Value *last,
                          Value *destination)
{
    Value *begin = destination;
    try {
        for (; first != last; ++destination, ++first)
        {
            Value *current = destination;
            new (current) Value(*first);
        }
    } catch (...) {
        for (; begin != destination; ++begin)
            begin->~Value();
        throw;
    }
    return destination;
}
