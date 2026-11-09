// from server: 100% by coldek
// from server: 100% by colin
// roc 2008-06 0046e180  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046e180
//
// 0046e180  55                   push ebp
// 0046e181  8bec                 mov ebp, esp
// 0046e183  6aff                 push -1
// 0046e185  68213e7c00           push 0x7c3e21
// 0046e18a  64a100000000         mov eax, dword ptr fs:[0]
// 0046e190  50                   push eax
// 0046e191  64892500000000       mov dword ptr fs:[0], esp
// 0046e198  83ec0c               sub esp, 0xc
// 0046e19b  53                   push ebx
// 0046e19c  56                   push esi
// 0046e19d  8b7508               mov esi, dword ptr [ebp + 8]
// 0046e1a0  57                   push edi
// 0046e1a1  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 0046e1a4  33db                 xor ebx, ebx
// 0046e1a6  8965f0               mov dword ptr [ebp - 0x10], esp
// 0046e1a9  8975ec               mov dword ptr [ebp - 0x14], esi
// 0046e1ac  895dfc               mov dword ptr [ebp - 4], ebx
// 0046e1af  90                   nop 
// 0046e1b0  3bfb                 cmp edi, ebx
// 0046e1b2  7646                 jbe 0x46e1fa
// 0046e1b4  89750c               mov dword ptr [ebp + 0xc], esi
// 0046e1b7  8975e8               mov dword ptr [ebp - 0x18], esi
// 0046e1ba  c645fc01             mov byte ptr [ebp - 4], 1
// 0046e1be  3bf3                 cmp esi, ebx
// 0046e1c0  740b                 je 0x46e1cd
// 0046e1c2  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0046e1c5  50                   push eax
// 0046e1c6  8bce                 mov ecx, esi
// 0046e1c8  e8e3fcffff           call 0x46deb0
// 0046e1cd  4f                   dec edi
// 0046e1ce  83c640               add esi, 0x40
// 0046e1d1  885dfc               mov byte ptr [ebp - 4], bl
// 0046e1d4  897508               mov dword ptr [ebp + 8], esi
// 0046e1d7  ebd7                 jmp 0x46e1b0

typedef unsigned int size_t;

inline void* __cdecl operator new(size_t, void* p)
{
    return p;
}

inline void __cdecl operator delete(void*, void*)
{
}

struct Element {
    unsigned char storage[64];
    Element(const Element&);
    ~Element();
};

void __cdecl construct_elements(Element* first, unsigned int count,
                                    const Element& value)
{
    Element* start = first;
    try {
        for (; count > 0; --count, ++first) {
        Element* cur = first;
        new (cur) Element(value);
    }
    }
    catch (...) {
        for (; start != first; ++start)
            start->~Element();
        throw;
    }

}
