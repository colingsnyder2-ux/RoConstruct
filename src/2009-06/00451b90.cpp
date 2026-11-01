// from server: 88% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004538b0  unit: CRobloxDoc  size: 209 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004538b0
//
// 004538b0  6aff                 push -1
// 004538b2  68f01e7c00           push 0x7c1ef0
// 004538b7  64a100000000         mov eax, dword ptr fs:[0]
// 004538bd  50                   push eax
// 004538be  64892500000000       mov dword ptr fs:[0], esp
// 004538c5  83ec18               sub esp, 0x18
// 004538c8  8b8994000000         mov ecx, dword ptr [ecx + 0x94]
// 004538ce  56                   push esi
// 004538cf  8d442408             lea eax, [esp + 8]
// 004538d3  50                   push eax
// 004538d4  e867700100           call 0x46a940
// 004538d9  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004538dd  83ec08               sub esp, 8
// 004538e0  8bc4                 mov eax, esp
// 004538e2  8908                 mov dword ptr [eax], ecx
// 004538e4  8b542414             mov edx, dword ptr [esp + 0x14]
// 004538e8  895004               mov dword ptr [eax + 4], edx
// 004538eb  8b442414             mov eax, dword ptr [esp + 0x14]
// 004538ef  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004538f7  8964240c             mov dword ptr [esp + 0xc], esp
// 004538fb  85c0                 test eax, eax
// 004538fd  740c                 je 0x45390b
// 004538ff  83c004               add eax, 4
// 00453902  b901000000           mov ecx, 1
// 00453907  f00fc108             lock xadd dword ptr [eax], ecx
// 0045390b  8d4c2418             lea ecx, [esp + 0x18]
// 0045390f  e82ce2fbff           call 0x411b40
// 00453914  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00453918  c644242401           mov byte ptr [esp + 0x24], 1
// 0045391d  e8def6ffff           call 0x453000
// 00453922  8bc8                 mov ecx, eax
// 00453924  e8574e1300           call 0x588780
// 00453929  8d4c2410             lea ecx, [esp + 0x10]
// 0045392d  c644242400           mov byte ptr [esp + 0x24], 0
// 00453932  e8893a1200           call 0x5773c0
// 00453937  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0045393b  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00453943  85f6                 test esi, esi
// 00453945  742a                 je 0x453971
// 00453947  8d5604               lea edx, [esi + 4]
// 0045394a  83c8ff               or eax, 0xffffffff
// 0045394d  f00fc102             lock xadd dword ptr [edx], eax
// 00453951  751e                 jne 0x453971
// 00453953  8b16                 mov edx, dword ptr [esi]
// 00453955  8b4204               mov eax, dword ptr [edx + 4]
// 00453958  8bce                 mov ecx, esi
// 0045395a  ffd0                 call eax
// 0045395c  8d4e08               lea ecx, [esi + 8]
// 0045395f  83caff               or edx, 0xffffffff
// 00453962  f00fc111             lock xadd dword ptr [ecx], edx
// 00453966  7509                 jne 0x453971
// 00453968  8b06                 mov eax, dword ptr [esi]
// 0045396a  8b5008               mov edx, dword ptr [eax + 8]
// 0045396d  8bce                 mov ecx, esi
// 0045396f  ffd2                 call edx
// 00453971  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00453975  64890d00000000       mov dword ptr fs:[0], ecx
// 0045397c  5e                   pop esi
// 0045397d  83c424               add esp, 0x24
// 00453980  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long use_count;
    volatile long weak_count;

    void release();
    void weak_release();
};

inline void Control::weak_release()
{
    if (_InterlockedDecrement(&weak_count) == 0)
        destroy();
}

inline void Control::release()
{
    if (_InterlockedDecrement(&use_count) == 0)
    {
        dispose();
        weak_release();
    }
}

struct Service
{
    void perform();
};

struct Object
{
    Service *getService();
};

struct Shared
{
    Object *object;
    Control *control;

    Shared(const Shared &);
    ~Shared();
};

inline Shared::Shared(const Shared &other)
    : object(other.object), control(other.control)
{
    if (control)
    {
        volatile long *count = &control->use_count;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Shared::~Shared()
{
    if (control)
        control->release();
}

struct Context
{
    Shared getObject();
};

struct Guard
{
    char storage[12];

    Guard(Shared);
    ~Guard();
};

struct CRobloxDoc
{
    char padding[0x94];
    Context *context;

    void func_004538b0();
};

void CRobloxDoc::func_004538b0()
{
    Shared object = context->getObject();
    Guard guard(object);
    object.object->getService()->perform();
}
