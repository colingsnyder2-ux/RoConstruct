// from server: 100% by colin
// from server: 78% by coldek
// roc 2008-06 0046e0a0  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046e0a0
//
// 0046e0a0  55                   push ebp
// 0046e0a1  8bec                 mov ebp, esp
// 0046e0a3  6aff                 push -1
// 0046e0a5  68013e7c00           push 0x7c3e01
// 0046e0aa  64a100000000         mov eax, dword ptr fs:[0]
// 0046e0b0  50                   push eax
// 0046e0b1  64892500000000       mov dword ptr fs:[0], esp
// 0046e0b8  83ec0c               sub esp, 0xc
// 0046e0bb  53                   push ebx
// 0046e0bc  56                   push esi
// 0046e0bd  8b7510               mov esi, dword ptr [ebp + 0x10]
// 0046e0c0  57                   push edi
// 0046e0c1  8b7d08               mov edi, dword ptr [ebp + 8]
// 0046e0c4  33db                 xor ebx, ebx
// 0046e0c6  8965f0               mov dword ptr [ebp - 0x10], esp
// 0046e0c9  8975ec               mov dword ptr [ebp - 0x14], esi
// 0046e0cc  895dfc               mov dword ptr [ebp - 4], ebx
// 0046e0cf  90                   nop 
// 0046e0d0  3b7d0c               cmp edi, dword ptr [ebp + 0xc]
// 0046e0d3  7445                 je 0x46e11a
// 0046e0d5  897508               mov dword ptr [ebp + 8], esi
// 0046e0d8  8975e8               mov dword ptr [ebp - 0x18], esi
// 0046e0db  c645fc01             mov byte ptr [ebp - 4], 1
// 0046e0df  3bf3                 cmp esi, ebx
// 0046e0e1  7408                 je 0x46e0eb
// 0046e0e3  57                   push edi
// 0046e0e4  8bce                 mov ecx, esi
// 0046e0e6  e8c5fdffff           call 0x46deb0
// 0046e0eb  83c640               add esi, 0x40
// 0046e0ee  885dfc               mov byte ptr [ebp - 4], bl
// 0046e0f1  897510               mov dword ptr [ebp + 0x10], esi
// 0046e0f4  83c740               add edi, 0x40
// 0046e0f7  ebd7                 jmp 0x46e0d0
// 0046e0f9  8b75ec               mov esi, dword ptr [ebp - 0x14]
// 0046e0fc  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 0046e0ff  3bf7                 cmp esi, edi
// 0046e101  740e                 je 0x46e111
// 0046e103  8bce                 mov ecx, esi
// 0046e105  e826eaffff           call 0x46cb30
// 0046e10a  83c640               add esi, 0x40
// 0046e10d  3bf7                 cmp esi, edi
// 0046e10f  75f2                 jne 0x46e103
// 0046e111  33db                 xor ebx, ebx
// 0046e113  53                   push ebx
// 0046e114  53                   push ebx
// 0046e115  e872342300           call 0x6a158c
// 0046e11a  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0046e11d  5f                   pop edi
// 0046e11e  8bc6                 mov eax, esi
// 0046e120  5e                   pop esi
// 0046e121  64890d00000000       mov dword ptr fs:[0], ecx
// 0046e128  5b                   pop ebx
// 0046e129  8be5                 mov esp, ebp
// 0046e12b  5d                   pop ebp
// 0046e12c  c3                   ret 
// 0046e12d  cc                   int3 
// 0046e12e  cc                   int3 
// 0046e12f  cc                   int3 
// 0046e130  83ec08               sub esp, 8
// 0046e133  8b542414             mov edx, dword ptr [esp + 0x14]
// 0046e137  53                   push ebx
// 0046e138  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0046e13c  56                   push esi
// 0046e13d  8b742418             mov esi, dword ptr [esp + 0x18]
// 0046e141  57                   push edi
// 0046e142  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0046e146  32c0                 xor al, al
// 0046e148  88442410             mov byte ptr [esp + 0x10], al
// 0046e14c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0046e150  8844240c             mov byte ptr [esp + 0xc], al
// 0046e154  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0046e158  50                   push eax
// 0046e159  51                   push ecx
// 0046e15a  52                   push edx
// 0046e15b  57                   push edi
// 0046e15c  56                   push esi
// 0046e15d  53                   push ebx
// 0046e15e  e80dfeffff           call 0x46df70
// 0046e163  2bf3                 sub esi, ebx
// 0046e165  83c418               add esp, 0x18
// 0046e168  c1fe06               sar esi, 6
// 0046e16b  c1e606               shl esi, 6
// 0046e16e  8bc7                 mov eax, edi
// 0046e170  5f                   pop edi
// 0046e171  2bc6                 sub eax, esi
// 0046e173  5e                   pop esi
// 0046e174  5b                   pop ebx
// 0046e175  83c408               add esp, 8
// 0046e178  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 0046e0a0  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046e0a0
//
// 0046e0a0  55                   push ebp
// 0046e0a1  8bec                 mov ebp, esp
// 0046e0a3  6aff                 push -1
// 0046e0a5  68013e7c00           push 0x7c3e01
// 0046e0aa  64a100000000         mov eax, dword ptr fs:[0]
// 0046e0b0  50                   push eax
// 0046e0b1  64892500000000       mov dword ptr fs:[0], esp
// 0046e0b8  83ec0c               sub esp, 0xc
// 0046e0bb  53                   push ebx
// 0046e0bc  56                   push esi
// 0046e0bd  8b7510               mov esi, dword ptr [ebp + 0x10]
// 0046e0c0  57                   push edi
// 0046e0c1  8b7d08               mov edi, dword ptr [ebp + 8]
// 0046e0c4  33db                 xor ebx, ebx
// 0046e0c6  8965f0               mov dword ptr [ebp - 0x10], esp
// 0046e0c9  8975ec               mov dword ptr [ebp - 0x14], esi
// 0046e0cc  895dfc               mov dword ptr [ebp - 4], ebx
// 0046e0cf  90                   nop 
// 0046e0d0  3b7d0c               cmp edi, dword ptr [ebp + 0xc]
// 0046e0d3  7445                 je 0x46e11a
// 0046e0d5  897508               mov dword ptr [ebp + 8], esi
// 0046e0d8  8975e8               mov dword ptr [ebp - 0x18], esi
// 0046e0db  c645fc01             mov byte ptr [ebp - 4], 1
// 0046e0df  3bf3                 cmp esi, ebx
// 0046e0e1  7408                 je 0x46e0eb
// 0046e0e3  57                   push edi
// 0046e0e4  8bce                 mov ecx, esi
// 0046e0e6  e8c5fdffff           call 0x46deb0
// 0046e0eb  83c640               add esi, 0x40
// 0046e0ee  885dfc               mov byte ptr [ebp - 4], bl
// 0046e0f1  897510               mov dword ptr [ebp + 0x10], esi
// 0046e0f4  83c740               add edi, 0x40
// 0046e0f7  ebd7                 jmp 0x46e0d0

typedef unsigned int size_t;

inline void* operator new(size_t, void* p) { return p; }
inline void operator delete(void*, void*) {}

struct Element {
    unsigned char data[64];
    Element(const Element&);
    ~Element();
};

Element* __cdecl copy_elements(Element* first, Element* last, Element* destination)
{
    Element* start = destination;
    try {
        for (; first != last; ++destination, ++first) {
            void* storage = destination;
            new (storage) Element(*first);
        }
        return destination;
    }
    catch (...) {
        for (; start != destination; ++start)
            start->~Element();
        throw;
    }
}
