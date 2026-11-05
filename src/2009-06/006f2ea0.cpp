// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00665e20  unit: RBX::PartDragTool  size: 219 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00665e20
//
// 00665e20  64a100000000         mov eax, dword ptr fs:[0]
// 00665e26  6aff                 push -1
// 00665e28  68f0c07d00           push 0x7dc0f0
// 00665e2d  50                   push eax
// 00665e2e  64892500000000       mov dword ptr fs:[0], esp
// 00665e35  83ec10               sub esp, 0x10
// 00665e38  56                   push esi
// 00665e39  8bf1                 mov esi, ecx
// 00665e3b  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00665e3e  e89d7ffaff           call 0x60dde0
// 00665e43  84c0                 test al, al
// 00665e45  0f849e000000         je 0x665ee9
// 00665e4b  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00665e4e  8d44240c             lea eax, [esp + 0xc]
// 00665e52  50                   push eax
// 00665e53  e848fcffff           call 0x665aa0
// 00665e58  8d4c2404             lea ecx, [esp + 4]
// 00665e5c  51                   push ecx
// 00665e5d  8bc8                 mov ecx, eax
// 00665e5f  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00665e67  e8944cf6ff           call 0x5cab00
// 00665e6c  8b00                 mov eax, dword ptr [eax]
// 00665e6e  8b90cc010000         mov edx, dword ptr [eax + 0x1cc]
// 00665e74  8b5210               mov edx, dword ptr [edx + 0x10]
// 00665e77  8d88cc010000         lea ecx, [eax + 0x1cc]
// 00665e7d  8b442424             mov eax, dword ptr [esp + 0x24]
// 00665e81  6a00                 push 0
// 00665e83  50                   push eax
// 00665e84  c644242401           mov byte ptr [esp + 0x24], 1
// 00665e89  ffd2                 call edx
// 00665e8b  8b442408             mov eax, dword ptr [esp + 8]
// 00665e8f  c644241c00           mov byte ptr [esp + 0x1c], 0
// 00665e94  85c0                 test eax, eax
// 00665e96  742c                 je 0x665ec4
// 00665e98  8bf0                 mov esi, eax
// 00665e9a  83c004               add eax, 4
// 00665e9d  83c9ff               or ecx, 0xffffffff
// 00665ea0  f00fc108             lock xadd dword ptr [eax], ecx
// 00665ea4  751e                 jne 0x665ec4
// 00665ea6  8b16                 mov edx, dword ptr [esi]
// 00665ea8  8b4204               mov eax, dword ptr [edx + 4]
// 00665eab  8bce                 mov ecx, esi
// 00665ead  ffd0                 call eax
// 00665eaf  8d4e08               lea ecx, [esi + 8]
// 00665eb2  83caff               or edx, 0xffffffff
// 00665eb5  f00fc111             lock xadd dword ptr [ecx], edx
// 00665eb9  7509                 jne 0x665ec4
// 00665ebb  8b06                 mov eax, dword ptr [esi]
// 00665ebd  8b5008               mov edx, dword ptr [eax + 8]
// 00665ec0  8bce                 mov ecx, esi
// 00665ec2  ffd2                 call edx
// 00665ec4  8b442410             mov eax, dword ptr [esp + 0x10]
// 00665ec8  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00665ed0  85c0                 test eax, eax
// 00665ed2  7415                 je 0x665ee9
// 00665ed4  8bc8                 mov ecx, eax
// 00665ed6  83c008               add eax, 8
// 00665ed9  83caff               or edx, 0xffffffff
// 00665edc  f00fc110             lock xadd dword ptr [eax], edx
// 00665ee0  7507                 jne 0x665ee9
// 00665ee2  8b01                 mov eax, dword ptr [ecx]
// 00665ee4  8b5008               mov edx, dword ptr [eax + 8]
// 00665ee7  ffd2                 call edx
// 00665ee9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00665eed  5e                   pop esi
// 00665eee  64890d00000000       mov dword ptr fs:[0], ecx
// 00665ef5  83c41c               add esp, 0x1c
// 00665ef8  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Count {
    virtual ~Count();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use_count;
    long weak_count;
};

struct Event {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void fire(void*, int);
};

struct Object {
    char padding[0xa8];
    Event event;
};

struct Shared {
    Object* pointer;
    Count* count;
    ~Shared();
    Object* operator->() const;
};

struct Weak {
    Object* pointer;
    Count* count;
    ~Weak();
    Shared lock() const;
};

struct Owner {
    bool ready();
    Weak get() const;
};

struct Tool {
    char padding[0x1c];
    Owner* owner;
    void run(void*);
};

inline Shared::~Shared()
{
    if (count) {
        Count* p = count;
        if (_InterlockedDecrement(&p->use_count) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak_count) == 0)
                p->destroy();
        }
    }
}

inline Object* Shared::operator->() const
{
    return pointer;
}

inline Weak::~Weak()
{
    if (count) {
        Count* p = count;
        if (_InterlockedDecrement(&p->weak_count) == 0)
            p->destroy();
    }
}

void Tool::run(void* argument)
{
    if (owner->ready())
        owner->get().lock()->event.fire(argument, 0);
}
