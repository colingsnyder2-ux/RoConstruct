// from server: 100% by EspClaude
// from server: 96% by colin
// roc 2008-06 00436ce0  unit: COutputView  size: 336 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00436ce0
//
// 00436ce0  6aff                 push -1
// 00436ce2  6814027c00           push 0x7c0214
// 00436ce7  64a100000000         mov eax, dword ptr fs:[0]
// 00436ced  50                   push eax
// 00436cee  64892500000000       mov dword ptr fs:[0], esp
// 00436cf5  83ec1c               sub esp, 0x1c
// 00436cf8  55                   push ebp
// 00436cf9  56                   push esi
// 00436cfa  8bf1                 mov esi, ecx
// 00436cfc  57                   push edi
// 00436cfd  8dbe20010000         lea edi, [esi + 0x120]
// 00436d03  8974240c             mov dword ptr [esp + 0xc], esi
// 00436d07  c7064c328100         mov dword ptr [esi], 0x81324c
// 00436d0d  c70740328100         mov dword ptr [edi], 0x813240
// 00436d13  8d442418             lea eax, [esp + 0x18]
// 00436d17  50                   push eax
// 00436d18  c744243402000000     mov dword ptr [esp + 0x34], 2
// 00436d20  e8fb281300           call 0x569620
// 00436d25  83c404               add esp, 4
// 00436d28  8b00                 mov eax, dword ptr [eax]
// 00436d2a  8d6828               lea ebp, [eax + 0x28]
// 00436d2d  8bcd                 mov ecx, ebp
// 00436d2f  c644243003           mov byte ptr [esp + 0x30], 3
// 00436d34  896c2410             mov dword ptr [esp + 0x10], ebp
// 00436d38  e8a3df1500           call 0x594ce0
// 00436d3d  c644241401           mov byte ptr [esp + 0x14], 1
// 00436d42  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00436d46  c644243005           mov byte ptr [esp + 0x30], 5
// 00436d4b  85c0                 test eax, eax
// 00436d4d  742e                 je 0x436d7d
// 00436d4f  53                   push ebx
// 00436d50  8bd8                 mov ebx, eax
// 00436d52  83c004               add eax, 4
// 00436d55  83c9ff               or ecx, 0xffffffff
// 00436d58  f00fc108             lock xadd dword ptr [eax], ecx
// 00436d5c  751e                 jne 0x436d7c
// 00436d5e  8b13                 mov edx, dword ptr [ebx]
// 00436d60  8b4204               mov eax, dword ptr [edx + 4]
// 00436d63  8bcb                 mov ecx, ebx
// 00436d65  ffd0                 call eax
// 00436d67  8d4b08               lea ecx, [ebx + 8]
// 00436d6a  83caff               or edx, 0xffffffff
// 00436d6d  f00fc111             lock xadd dword ptr [ecx], edx
// 00436d71  7509                 jne 0x436d7c
// 00436d73  8b03                 mov eax, dword ptr [ebx]
// 00436d75  8b5008               mov edx, dword ptr [eax + 8]
// 00436d78  8bcb                 mov ecx, ebx
// 00436d7a  ffd2                 call edx
// 00436d7c  5b                   pop ebx
// 00436d7d  8d442420             lea eax, [esp + 0x20]
// 00436d81  50                   push eax
// 00436d82  e899281300           call 0x569620
// 00436d87  83c404               add esp, 4
// 00436d8a  8b08                 mov ecx, dword ptr [eax]
// 00436d8c  c644243006           mov byte ptr [esp + 0x30], 6
// 00436d91  85c9                 test ecx, ecx
// 00436d93  7406                 je 0x436d9b
// 00436d95  57                   push edi
// 00436d96  e8e5ec1a00           call 0x5e5a80
// 00436d9b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00436d9f  c644243005           mov byte ptr [esp + 0x30], 5
// 00436da4  85ff                 test edi, edi
// 00436da6  742a                 je 0x436dd2
// 00436da8  8d4f04               lea ecx, [edi + 4]
// 00436dab  83caff               or edx, 0xffffffff
// 00436dae  f00fc111             lock xadd dword ptr [ecx], edx
// 00436db2  751e                 jne 0x436dd2
// 00436db4  8b07                 mov eax, dword ptr [edi]
// 00436db6  8b5004               mov edx, dword ptr [eax + 4]
// 00436db9  8bcf                 mov ecx, edi
// 00436dbb  ffd2                 call edx
// 00436dbd  8d4708               lea eax, [edi + 8]
// 00436dc0  83c9ff               or ecx, 0xffffffff
// 00436dc3  f00fc108             lock xadd dword ptr [eax], ecx
// 00436dc7  7509                 jne 0x436dd2
// 00436dc9  8b17                 mov edx, dword ptr [edi]
// 00436dcb  8b4208               mov eax, dword ptr [edx + 8]
// 00436dce  8bcf                 mov ecx, edi
// 00436dd0  ffd0                 call eax
// 00436dd2  8bcd                 mov ecx, ebp
// 00436dd4  c644243002           mov byte ptr [esp + 0x30], 2
// 00436dd9  e822df1500           call 0x594d00
// 00436dde  8d8e44010000         lea ecx, [esi + 0x144]
// 00436de4  c644243001           mov byte ptr [esp + 0x30], 1
// 00436de9  e8c2de1500           call 0x594cb0
// 00436dee  8dbe24010000         lea edi, [esi + 0x124]
// 00436df4  897c2410             mov dword ptr [esp + 0x10], edi
// 00436df8  8bcf                 mov ecx, edi
// 00436dfa  c644243007           mov byte ptr [esp + 0x30], 7
// 00436dff  e8ccf8ffff           call 0x4366d0
// 00436e04  8b3f                 mov edi, dword ptr [edi]
// 00436e06  57                   push edi
// 00436e07  e86e982600           call 0x6a067a
// 00436e0c  83c404               add esp, 4
// 00436e0f  8bce                 mov ecx, esi
// 00436e11  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00436e19  e892fcffff           call 0x436ab0
// 00436e1e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00436e22  5f                   pop edi
// 00436e23  5e                   pop esi
// 00436e24  5d                   pop ebp
// 00436e25  64890d00000000       mov dword ptr fs:[0], ecx
// 00436e2c  83c428               add esp, 0x28
// 00436e2f  c3                   ret 

// from server: 92% by colin
// roc 2008-06 00436ce0  unit: COutputView  size: 336 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00436ce0
//
// 00436ce0  6aff                 push -1
// 00436ce2  6814027c00           push 0x7c0214
// 00436ce7  64a100000000         mov eax, dword ptr fs:[0]
// 00436ced  50                   push eax
// 00436cee  64892500000000       mov dword ptr fs:[0], esp
// 00436cf5  83ec1c               sub esp, 0x1c
// 00436cf8  55                   push ebp
// 00436cf9  56                   push esi
// 00436cfa  8bf1                 mov esi, ecx
// 00436cfc  57                   push edi
// 00436cfd  8dbe20010000         lea edi, [esi + 0x120]
// 00436d03  8974240c             mov dword ptr [esp + 0xc], esi
// 00436d07  c7064c328100         mov dword ptr [esi], 0x81324c
// 00436d0d  c70740328100         mov dword ptr [edi], 0x813240
// 00436d13  8d442418             lea eax, [esp + 0x18]
// 00436d17  50                   push eax
// 00436d18  c744243402000000     mov dword ptr [esp + 0x34], 2
// 00436d20  e8fb281300           call 0x569620
// 00436d25  83c404               add esp, 4
// 00436d28  8b00                 mov eax, dword ptr [eax]
// 00436d2a  8d6828               lea ebp, [eax + 0x28]
// 00436d2d  8bcd                 mov ecx, ebp
// 00436d2f  c644243003           mov byte ptr [esp + 0x30], 3
// 00436d34  896c2410             mov dword ptr [esp + 0x10], ebp
// 00436d38  e8a3df1500           call 0x594ce0
// 00436d3d  c644241401           mov byte ptr [esp + 0x14], 1
// 00436d42  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00436d46  c644243005           mov byte ptr [esp + 0x30], 5
// 00436d4b  85c0                 test eax, eax
// 00436d4d  742e                 je 0x436d7d
// 00436d4f  53                   push ebx
// 00436d50  8bd8                 mov ebx, eax
// 00436d52  83c004               add eax, 4
// 00436d55  83c9ff               or ecx, 0xffffffff
// 00436d58  f00fc108             lock xadd dword ptr [eax], ecx
// 00436d5c  751e                 jne 0x436d7c
// 00436d5e  8b13                 mov edx, dword ptr [ebx]
// 00436d60  8b4204               mov eax, dword ptr [edx + 4]
// 00436d63  8bcb                 mov ecx, ebx
// 00436d65  ffd0                 call eax
// 00436d67  8d4b08               lea ecx, [ebx + 8]
// 00436d6a  83caff               or edx, 0xffffffff
// 00436d6d  f00fc111             lock xadd dword ptr [ecx], edx
// 00436d71  7509                 jne 0x436d7c
// 00436d73  8b03                 mov eax, dword ptr [ebx]
// 00436d75  8b5008               mov edx, dword ptr [eax + 8]
// 00436d78  8bcb                 mov ecx, ebx
// 00436d7a  ffd2                 call edx
// 00436d7c  5b                   pop ebx
// 00436d7d  8d442420             lea eax, [esp + 0x20]
// 00436d81  50                   push eax
// 00436d82  e899281300           call 0x569620
// 00436d87  83c404               add esp, 4
// 00436d8a  8b08                 mov ecx, dword ptr [eax]
// 00436d8c  c644243006           mov byte ptr [esp + 0x30], 6
// 00436d91  85c9                 test ecx, ecx
// 00436d93  7406                 je 0x436d9b
// 00436d95  57                   push edi
// 00436d96  e8e5ec1a00           call 0x5e5a80
// 00436d9b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00436d9f  c644243005           mov byte ptr [esp + 0x30], 5
// 00436da4  85ff                 test edi, edi
// 00436da6  742a                 je 0x436dd2
// 00436da8  8d4f04               lea ecx, [edi + 4]
// 00436dab  83caff               or edx, 0xffffffff
// 00436dae  f00fc111             lock xadd dword ptr [ecx], edx
// 00436db2  751e                 jne 0x436dd2
// 00436db4  8b07                 mov eax, dword ptr [edi]
// 00436db6  8b5004               mov edx, dword ptr [eax + 4]
// 00436db9  8bcf                 mov ecx, edi
// 00436dbb  ffd2                 call edx
// 00436dbd  8d4708               lea eax, [edi + 8]
// 00436dc0  83c9ff               or ecx, 0xffffffff
// 00436dc3  f00fc108             lock xadd dword ptr [eax], ecx
// 00436dc7  7509                 jne 0x436dd2
// 00436dc9  8b17                 mov edx, dword ptr [edi]
// 00436dcb  8b4208               mov eax, dword ptr [edx + 8]
// 00436dce  8bcf                 mov ecx, edi
// 00436dd0  ffd0                 call eax
// 00436dd2  8bcd                 mov ecx, ebp
// 00436dd4  c644243002           mov byte ptr [esp + 0x30], 2
// 00436dd9  e822df1500           call 0x594d00
// 00436dde  8d8e44010000         lea ecx, [esi + 0x144]
// 00436de4  c644243001           mov byte ptr [esp + 0x30], 1
// 00436de9  e8c2de1500           call 0x594cb0
// 00436dee  8dbe24010000         lea edi, [esi + 0x124]
// 00436df4  897c2410             mov dword ptr [esp + 0x10], edi
// 00436df8  8bcf                 mov ecx, edi
// 00436dfa  c644243007           mov byte ptr [esp + 0x30], 7
// 00436dff  e8ccf8ffff           call 0x4366d0
// 00436e04  8b3f                 mov edi, dword ptr [edi]
// 00436e06  57                   push edi
// 00436e07  e86e982600           call 0x6a067a
// 00436e0c  83c404               add esp, 4
// 00436e0f  8bce                 mov ecx, esi
// 00436e11  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00436e19  e892fcffff           call 0x436ab0
// 00436e1e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00436e22  5f                   pop edi
// 00436e23  5e                   pop esi
// 00436e24  5d                   pop ebp
// 00436e25  64890d00000000       mov dword ptr fs:[0], ecx
// 00436e2c  83c428               add esp, 0x28
// 00436e2f  c3                   ret 

// from server: 80% by king_originala
// roc 2008-06 00436ce0  unit: COutputView  size: 336 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00436ce0
//
// 00436ce0  6aff                 push -1
// 00436ce2  6814027c00           push 0x7c0214
// 00436ce7  64a100000000         mov eax, dword ptr fs:[0]
// 00436ced  50                   push eax
// 00436cee  64892500000000       mov dword ptr fs:[0], esp
// 00436cf5  83ec1c               sub esp, 0x1c
// 00436cf8  55                   push ebp
// 00436cf9  56                   push esi
// 00436cfa  8bf1                 mov esi, ecx
// 00436cfc  57                   push edi
// 00436cfd  8dbe20010000         lea edi, [esi + 0x120]
// 00436d03  8974240c             mov dword ptr [esp + 0xc], esi
// 00436d07  c7064c328100         mov dword ptr [esi], 0x81324c
// 00436d0d  c70740328100         mov dword ptr [edi], 0x813240
// 00436d13  8d442418             lea eax, [esp + 0x18]
// 00436d17  50                   push eax
// 00436d18  c744243402000000     mov dword ptr [esp + 0x34], 2
// 00436d20  e8fb281300           call 0x569620
// 00436d25  83c404               add esp, 4
// 00436d28  8b00                 mov eax, dword ptr [eax]
// 00436d2a  8d6828               lea ebp, [eax + 0x28]
// 00436d2d  8bcd                 mov ecx, ebp
// 00436d2f  c644243003           mov byte ptr [esp + 0x30], 3
// 00436d34  896c2410             mov dword ptr [esp + 0x10], ebp
// 00436d38  e8a3df1500           call 0x594ce0
// 00436d3d  c644241401           mov byte ptr [esp + 0x14], 1
// 00436d42  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00436d46  c644243005           mov byte ptr [esp + 0x30], 5
// 00436d4b  85c0                 test eax, eax
// 00436d4d  742e                 je 0x436d7d
// 00436d4f  53                   push ebx
// 00436d50  8bd8                 mov ebx, eax
// 00436d52  83c004               add eax, 4
// 00436d55  83c9ff               or ecx, 0xffffffff
// 00436d58  f00fc108             lock xadd dword ptr [eax], ecx
// 00436d5c  751e                 jne 0x436d7c
// 00436d5e  8b13                 mov edx, dword ptr [ebx]
// 00436d60  8b4204               mov eax, dword ptr [edx + 4]
// 00436d63  8bcb                 mov ecx, ebx
// 00436d65  ffd0                 call eax
// 00436d67  8d4b08               lea ecx, [ebx + 8]
// 00436d6a  83caff               or edx, 0xffffffff
// 00436d6d  f00fc111             lock xadd dword ptr [ecx], edx
// 00436d71  7509                 jne 0x436d7c
// 00436d73  8b03                 mov eax, dword ptr [ebx]
// 00436d75  8b5008               mov edx, dword ptr [eax + 8]
// 00436d78  8bcb                 mov ecx, ebx
// 00436d7a  ffd2                 call edx
// 00436d7c  5b                   pop ebx
// 00436d7d  8d442420             lea eax, [esp + 0x20]
// 00436d81  50                   push eax
// 00436d82  e899281300           call 0x569620
// 00436d87  83c404               add esp, 4
// 00436d8a  8b08                 mov ecx, dword ptr [eax]
// 00436d8c  c644243006           mov byte ptr [esp + 0x30], 6
// 00436d91  85c9                 test ecx, ecx
// 00436d93  7406                 je 0x436d9b
// 00436d95  57                   push edi
// 00436d96  e8e5ec1a00           call 0x5e5a80
// 00436d9b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00436d9f  c644243005           mov byte ptr [esp + 0x30], 5
// 00436da4  85ff                 test edi, edi
// 00436da6  742a                 je 0x436dd2
// 00436da8  8d4f04               lea ecx, [edi + 4]
// 00436dab  83caff               or edx, 0xffffffff
// 00436dae  f00fc111             lock xadd dword ptr [ecx], edx
// 00436db2  751e                 jne 0x436dd2
// 00436db4  8b07                 mov eax, dword ptr [edi]
// 00436db6  8b5004               mov edx, dword ptr [eax + 4]
// 00436db9  8bcf                 mov ecx, edi
// 00436dbb  ffd2                 call edx
// 00436dbd  8d4708               lea eax, [edi + 8]
// 00436dc0  83c9ff               or ecx, 0xffffffff
// 00436dc3  f00fc108             lock xadd dword ptr [eax], ecx
// 00436dc7  7509                 jne 0x436dd2
// 00436dc9  8b17                 mov edx, dword ptr [edi]
// 00436dcb  8b4208               mov eax, dword ptr [edx + 8]
// 00436dce  8bcf                 mov ecx, edi
// 00436dd0  ffd0                 call eax
// 00436dd2  8bcd                 mov ecx, ebp
// 00436dd4  c644243002           mov byte ptr [esp + 0x30], 2
// 00436dd9  e822df1500           call 0x594d00
// 00436dde  8d8e44010000         lea ecx, [esi + 0x144]
// 00436de4  c644243001           mov byte ptr [esp + 0x30], 1
// 00436de9  e8c2de1500           call 0x594cb0
// 00436dee  8dbe24010000         lea edi, [esi + 0x124]
// 00436df4  897c2410             mov dword ptr [esp + 0x10], edi
// 00436df8  8bcf                 mov ecx, edi
// 00436dfa  c644243007           mov byte ptr [esp + 0x30], 7
// 00436dff  e8ccf8ffff           call 0x4366d0
// 00436e04  8b3f                 mov edi, dword ptr [edi]
// 00436e06  57                   push edi
// 00436e07  e86e982600           call 0x6a067a
// 00436e0c  83c404               add esp, 4
// 00436e0f  8bce                 mov ecx, esi
// 00436e11  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00436e19  e892fcffff           call 0x436ab0
// 00436e1e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00436e22  5f                   pop edi
// 00436e23  5e                   pop esi
// 00436e24  5d                   pop ebp
// 00436e25  64890d00000000       mov dword ptr fs:[0], ecx
// 00436e2c  83c428               add esp, 0x28
// 00436e2f  c3                   ret 

#include <intrin.h>

extern const unsigned long primaryTable[];
extern const unsigned long secondaryTable[];
extern void __cdecl release(void *) throw();

struct RefCount {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Mutex {
    void *object;
    bool criticalSection;
    void lock();
    void unlock();
    ~Mutex();
};

struct Service {
    unsigned char padding[40];
    Mutex mutex;
    void detach(void *);
};

struct Shared {
    Service *pointer;
    RefCount *count;
    Service &operator*() const;
    void detach(void *) const;
    ~Shared();
};

__forceinline Service &Shared::operator*() const
{
    return *pointer;
}

__forceinline void Shared::detach(void *p) const
{
    if (pointer)
        pointer->detach(p);
}

__forceinline Shared::~Shared()
{
    if (count) {
        RefCount *p = count;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

extern Shared __cdecl getService();

struct Guard {
    Mutex *mutex;
    bool locked;
    Guard(Mutex &);
    ~Guard();
};

__forceinline Guard::Guard(Mutex &m) : mutex(&m)
{
    mutex->lock();
    locked = true;
}

__forceinline Guard::~Guard()
{
    if (locked)
        mutex->unlock();
}

struct Storage {
    char **slots;
    unsigned char padding[28];
    ~Storage();
};

inline Storage::~Storage()
{
    void* s = slots;
    release(s);
}

struct Container : Storage {
    void clear();
    ~Container();
};

__forceinline Container::~Container()
{
    clear();
}

class Base {
public:
    unsigned char padding[284];
    virtual ~Base();
};

class Second {
public:
    virtual void notify();
};

class COutputView : public Base, public Second {
public:
    Container contents;
    Mutex mutex;
    ~COutputView();
};

COutputView::~COutputView()
{
    Guard guard((*getService()).mutex);
    getService().detach(static_cast<Second*>(this));
}
