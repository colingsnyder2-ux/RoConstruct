// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0044fb80  unit: CRobloxDoc  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044fb80
//
// 0044fb80  64a100000000         mov eax, dword ptr fs:[0]
// 0044fb86  6aff                 push -1
// 0044fb88  68e18a7c00           push 0x7c8ae1
// 0044fb8d  50                   push eax
// 0044fb8e  64892500000000       mov dword ptr fs:[0], esp
// 0044fb95  83ec24               sub esp, 0x24
// 0044fb98  56                   push esi
// 0044fb99  57                   push edi
// 0044fb9a  8b7c243c             mov edi, dword ptr [esp + 0x3c]
// 0044fb9e  57                   push edi
// 0044fb9f  8bf1                 mov esi, ecx
// 0044fba1  e8f80d2500           call 0x6a099e
// 0044fba6  83be9400000000       cmp dword ptr [esi + 0x94], 0
// 0044fbad  0f8481000000         je 0x44fc34
// 0044fbb3  57                   push edi
// 0044fbb4  8d4c2414             lea ecx, [esp + 0x14]
// 0044fbb8  ff1558248000         call dword ptr [0x802458]
// 0044fbbe  8b8e94000000         mov ecx, dword ptr [esi + 0x94]
// 0044fbc4  8d442408             lea eax, [esp + 8]
// 0044fbc8  50                   push eax
// 0044fbc9  c744243800000000     mov dword ptr [esp + 0x38], 0
// 0044fbd1  e86aad0100           call 0x46a940
// 0044fbd6  8b08                 mov ecx, dword ptr [eax]
// 0044fbd8  8b11                 mov edx, dword ptr [ecx]
// 0044fbda  8b5204               mov edx, dword ptr [edx + 4]
// 0044fbdd  8d442410             lea eax, [esp + 0x10]
// 0044fbe1  50                   push eax
// 0044fbe2  c644243801           mov byte ptr [esp + 0x38], 1
// 0044fbe7  ffd2                 call edx
// 0044fbe9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0044fbed  c644243400           mov byte ptr [esp + 0x34], 0
// 0044fbf2  85c0                 test eax, eax
// 0044fbf4  742c                 je 0x44fc22
// 0044fbf6  8bf0                 mov esi, eax
// 0044fbf8  83c004               add eax, 4
// 0044fbfb  83c9ff               or ecx, 0xffffffff
// 0044fbfe  f00fc108             lock xadd dword ptr [eax], ecx
// 0044fc02  751e                 jne 0x44fc22
// 0044fc04  8b16                 mov edx, dword ptr [esi]
// 0044fc06  8b4204               mov eax, dword ptr [edx + 4]
// 0044fc09  8bce                 mov ecx, esi
// 0044fc0b  ffd0                 call eax
// 0044fc0d  8d4e08               lea ecx, [esi + 8]
// 0044fc10  83caff               or edx, 0xffffffff
// 0044fc13  f00fc111             lock xadd dword ptr [ecx], edx
// 0044fc17  7509                 jne 0x44fc22
// 0044fc19  8b06                 mov eax, dword ptr [esi]
// 0044fc1b  8b5008               mov edx, dword ptr [eax + 8]
// 0044fc1e  8bce                 mov ecx, esi
// 0044fc20  ffd2                 call edx
// 0044fc22  8d4c2410             lea ecx, [esp + 0x10]
// 0044fc26  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 0044fc2e  ff1568248000         call dword ptr [0x802468]
// 0044fc34  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0044fc38  5f                   pop edi
// 0044fc39  5e                   pop esi
// 0044fc3a  64890d00000000       mov dword ptr fs:[0], ecx
// 0044fc41  83c430               add esp, 0x30
// 0044fc44  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct String {
    unsigned char storage[28];
    String(const char*);
    ~String();
};

typedef void (__thiscall *StringConstructor)(String*, const char*);
typedef void (__thiscall *StringDestructor)(String*);
extern StringConstructor constructString;
extern StringDestructor destroyString;

__forceinline String::String(const char* text)
{
    constructString(this, text);
}

__forceinline String::~String()
{
    destroyString(this);
}

struct Counted {
    virtual ~Counted();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long use_count;
    volatile long weak_count;
};

struct Object {
    virtual ~Object();
    virtual void set(const String&) = 0;
};

struct Pointer {
    Object* object;
    Counted* count;
    ~Pointer();
};

__forceinline Pointer::~Pointer()
{
    if (count) {
        Counted* p = count;
        if (_InterlockedDecrement(&p->use_count) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak_count) == 0)
                p->destroy();
        }
    }
}

struct Holder {
    Pointer get();
};

struct S {
    unsigned char padding[0x9c];
    Holder* holder;
    void prior(const char*);
    void f(const char*);
};

void S::f(const char* text)
{
    prior(text);
    if (holder) {
        String value(text);
        holder->get().object->set(value);
    }
}
