// from server: 96% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0044fad0  unit: CRobloxDoc  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044fad0
//
// 0044fad0  64a100000000         mov eax, dword ptr fs:[0]
// 0044fad6  6aff                 push -1
// 0044fad8  6868917d00           push 0x7d9168
// 0044fadd  50                   push eax
// 0044fade  64892500000000       mov dword ptr fs:[0], esp
// 0044fae5  83ec08               sub esp, 8
// 0044fae8  56                   push esi
// 0044fae9  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0044faed  897148               mov dword ptr [ecx + 0x48], esi
// 0044faf0  8b8994000000         mov ecx, dword ptr [ecx + 0x94]
// 0044faf6  85c9                 test ecx, ecx
// 0044faf8  746a                 je 0x44fb64
// 0044fafa  8d442404             lea eax, [esp + 4]
// 0044fafe  50                   push eax
// 0044faff  e83cae0100           call 0x46a940
// 0044fb04  8b00                 mov eax, dword ptr [eax]
// 0044fb06  8b90f0010000         mov edx, dword ptr [eax + 0x1f0]
// 0044fb0c  8b12                 mov edx, dword ptr [edx]
// 0044fb0e  8d88f0010000         lea ecx, [eax + 0x1f0]
// 0044fb14  83fe01               cmp esi, 1
// 0044fb17  0f94c0               sete al
// 0044fb1a  0fb6c0               movzx eax, al
// 0044fb1d  50                   push eax
// 0044fb1e  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0044fb26  ffd2                 call edx
// 0044fb28  8b442408             mov eax, dword ptr [esp + 8]
// 0044fb2c  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0044fb34  85c0                 test eax, eax
// 0044fb36  742c                 je 0x44fb64
// 0044fb38  8bf0                 mov esi, eax
// 0044fb3a  83c004               add eax, 4
// 0044fb3d  83c9ff               or ecx, 0xffffffff
// 0044fb40  f00fc108             lock xadd dword ptr [eax], ecx
// 0044fb44  751e                 jne 0x44fb64
// 0044fb46  8b16                 mov edx, dword ptr [esi]
// 0044fb48  8b4204               mov eax, dword ptr [edx + 4]
// 0044fb4b  8bce                 mov ecx, esi
// 0044fb4d  ffd0                 call eax
// 0044fb4f  8d4e08               lea ecx, [esi + 8]
// 0044fb52  83caff               or edx, 0xffffffff
// 0044fb55  f00fc111             lock xadd dword ptr [ecx], edx
// 0044fb59  7509                 jne 0x44fb64
// 0044fb5b  8b06                 mov eax, dword ptr [esi]
// 0044fb5d  8b5008               mov edx, dword ptr [eax + 8]
// 0044fb60  8bce                 mov ecx, esi
// 0044fb62  ffd2                 call edx
// 0044fb64  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044fb68  5e                   pop esi
// 0044fb69  64890d00000000       mov dword ptr fs:[0], ecx
// 0044fb70  83c414               add esp, 0x14
// 0044fb73  c20400               ret 4

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

struct Property
{
    virtual void set(bool value);
};

struct Object
{
    char padding[0x1f0];
    Property property;
};

struct Handle
{
    Object* object;
    Control* control;
    ~Handle();
};

inline Handle::~Handle()
{
    if (control)
        control->release();
}

struct Source
{
    Handle get();
};

struct CRobloxDoc
{
    char padding0[0x48];
    int state;
    char padding1[0x48];
    Source* source;

    void func_0044fad0(int value);
};

void CRobloxDoc::func_0044fad0(int value)
{
    state = value;
    if (source)
        source->get().object->property.set(value == 1);
}
