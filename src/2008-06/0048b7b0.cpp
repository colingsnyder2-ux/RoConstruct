// from server: 100% by colin
// from server: 98% by colin
// roc 2008-06 0048b7b0  unit: boost::any::placeholder  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048b7b0
//
// 0048b7b0  56                   push esi
// 0048b7b1  8b742410             mov esi, dword ptr [esp + 0x10]
// 0048b7b5  8b4604               mov eax, dword ptr [esi + 4]
// 0048b7b8  57                   push edi
// 0048b7b9  8b38                 mov edi, dword ptr [eax]
// 0048b7bb  83ec08               sub esp, 8
// 0048b7be  8bd4                 mov edx, esp
// 0048b7c0  893a                 mov dword ptr [edx], edi
// 0048b7c2  8b4004               mov eax, dword ptr [eax + 4]
// 0048b7c5  8964241c             mov dword ptr [esp + 0x1c], esp
// 0048b7c9  894204               mov dword ptr [edx + 4], eax
// 0048b7cc  85c0                 test eax, eax
// 0048b7ce  740c                 je 0x48b7dc
// 0048b7d0  83c004               add eax, 4
// 0048b7d3  ba01000000           mov edx, 1
// 0048b7d8  f00fc110             lock xadd dword ptr [eax], edx
// 0048b7dc  8b06                 mov eax, dword ptr [esi]
// 0048b7de  8b00                 mov eax, dword ptr [eax]
// 0048b7e0  50                   push eax
// 0048b7e1  8b4108               mov eax, dword ptr [ecx + 8]
// 0048b7e4  83ec08               sub esp, 8
// 0048b7e7  8bd4                 mov edx, esp
// 0048b7e9  8902                 mov dword ptr [edx], eax
// 0048b7eb  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0048b7ee  89642428             mov dword ptr [esp + 0x28], esp
// 0048b7f2  894204               mov dword ptr [edx + 4], eax
// 0048b7f5  85c0                 test eax, eax
// 0048b7f7  740c                 je 0x48b805
// 0048b7f9  83c004               add eax, 4
// 0048b7fc  ba01000000           mov edx, 1
// 0048b801  f00fc110             lock xadd dword ptr [eax], edx
// 0048b805  8b11                 mov edx, dword ptr [ecx]
// 0048b807  83ec08               sub esp, 8
// 0048b80a  8bc4                 mov eax, esp
// 0048b80c  8910                 mov dword ptr [eax], edx
// 0048b80e  8b4904               mov ecx, dword ptr [ecx + 4]
// 0048b811  89642430             mov dword ptr [esp + 0x30], esp
// 0048b815  894804               mov dword ptr [eax + 4], ecx
// 0048b818  85c9                 test ecx, ecx
// 0048b81a  740c                 je 0x48b828
// 0048b81c  83c104               add ecx, 4
// 0048b81f  b801000000           mov eax, 1
// 0048b824  f00fc101             lock xadd dword ptr [ecx], eax
// 0048b828  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0048b82c  8b11                 mov edx, dword ptr [ecx]
// 0048b82e  ffd2                 call edx
// 0048b830  83c41c               add esp, 0x1c
// 0048b833  5f                   pop edi
// 0048b834  5e                   pop esi
// 0048b835  c21000               ret 0x10

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


struct Control {
    void* table;
    volatile long references;

    void addReference();
};

__forceinline void Control::addReference() {
    volatile long* count =
        reinterpret_cast<volatile long*>(reinterpret_cast<char*>(this) + 4);
    _InterlockedIncrement(count);
}

struct Shared {
    void* pointer;
    Control* control;

    Shared(const Shared& other);
    ~Shared();
};

Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control) {
    if (control)
        control->addReference();
}

Shared::~Shared() {
}

struct Arguments {
    int* value;
    Shared* object;
    int get() const { return *value; }
};

typedef void (__cdecl *Callback)(Shared, Shared, int, Shared);

struct S {
    Shared first;
    Shared second;

    void invoke(void*, Callback*, Arguments*, void*);
};

void S::invoke(void*, Callback* callback, Arguments* arguments, void*) {
    (*callback)(first, second, arguments->get(), *arguments->object);
}
