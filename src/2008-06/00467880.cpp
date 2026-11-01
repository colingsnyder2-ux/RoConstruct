// from server: 100% by colin
// from server: 81% by king_originala
// roc 2008-06 00467880  unit: DxUserInput  size: 377 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00467880
//
// 00467880  6aff                 push -1
// 00467882  6822367c00           push 0x7c3622
// 00467887  64a100000000         mov eax, dword ptr fs:[0]
// 0046788d  50                   push eax
// 0046788e  64892500000000       mov dword ptr fs:[0], esp
// 00467895  83ec48               sub esp, 0x48
// 00467898  55                   push ebp
// 00467899  56                   push esi
// 0046789a  8bf1                 mov esi, ecx
// 0046789c  57                   push edi
// 0046789d  8d6e34               lea ebp, [esi + 0x34]
// 004678a0  55                   push ebp
// 004678a1  896c2410             mov dword ptr [esp + 0x10], ebp
// 004678a5  ff15d4228000         call dword ptr [0x8022d4]
// 004678ab  c644241001           mov byte ptr [esp + 0x10], 1
// 004678b0  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 004678b4  8b542464             mov edx, dword ptr [esp + 0x64]
// 004678b8  8b7c246c             mov edi, dword ptr [esp + 0x6c]
// 004678bc  8b07                 mov eax, dword ptr [edi]
// 004678be  8b4028               mov eax, dword ptr [eax + 0x28]
// 004678c1  6a00                 push 0
// 004678c3  51                   push ecx
// 004678c4  52                   push edx
// 004678c5  6a14                 push 0x14
// 004678c7  57                   push edi
// 004678c8  c744247000000000     mov dword ptr [esp + 0x70], 0
// 004678d0  ffd0                 call eax
// 004678d2  83e800               sub eax, 0
// 004678d5  0f8401010000         je 0x4679dc
// 004678db  83e801               sub eax, 1
// 004678de  b8d8c38100           mov eax, 0x81c3d8
// 004678e3  743f                 je 0x467924
// 004678e5  3bbe7c010000         cmp edi, dword ptr [esi + 0x17c]
// 004678eb  7405                 je 0x4678f2
// 004678ed  b8d0c38100           mov eax, 0x81c3d0
// 004678f2  50                   push eax
// 004678f3  8d4c243c             lea ecx, [esp + 0x3c]
// 004678f7  ff1558248000         call dword ptr [0x802458]
// 004678fd  8d4c2438             lea ecx, [esp + 0x38]
// 00467901  ff1568248000         call dword ptr [0x802468]
// 00467907  55                   push ebp
// 00467908  ff15f4218000         call dword ptr [0x8021f4]
// 0046790e  5f                   pop edi
// 0046790f  5e                   pop esi
// 00467910  32c0                 xor al, al
// 00467912  5d                   pop ebp
// 00467913  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 00467917  64890d00000000       mov dword ptr fs:[0], ecx
// 0046791e  83c454               add esp, 0x54
// 00467921  c20c00               ret 0xc
// 00467924  3bbe7c010000         cmp edi, dword ptr [esi + 0x17c]
// 0046792a  7405                 je 0x467931
// 0046792c  b8d0c38100           mov eax, 0x81c3d0
// 00467931  50                   push eax
// 00467932  8d4c243c             lea ecx, [esp + 0x3c]
// 00467936  ff1558248000         call dword ptr [0x802458]
// 0046793c  68bcc38100           push 0x81c3bc
// 00467941  8d4c243c             lea ecx, [esp + 0x3c]
// 00467945  51                   push ecx
// 00467946  8d542424             lea edx, [esp + 0x24]
// 0046794a  52                   push edx
// 0046794b  c644246801           mov byte ptr [esp + 0x68], 1
// 00467950  ff15e4238000         call dword ptr [0x8023e4]
// 00467956  8d442420             lea eax, [esp + 0x20]
// 0046795a  50                   push eax
// 0046795b  c644246c02           mov byte ptr [esp + 0x6c], 2
// 00467960  e8bb1c1000           call 0x569620
// 00467965  83c410               add esp, 0x10
// 00467968  8b30                 mov esi, dword ptr [eax]
// 0046796a  8d4c241c             lea ecx, [esp + 0x1c]
// 0046796e  c644245c03           mov byte ptr [esp + 0x5c], 3
// 00467973  ff1564248000         call dword ptr [0x802464]
// 00467979  50                   push eax
// 0046797a  6a03                 push 3
// 0046797c  56                   push esi
// 0046797d  e81e1a1000           call 0x5693a0
// 00467982  8b442424             mov eax, dword ptr [esp + 0x24]
// 00467986  83c40c               add esp, 0xc
// 00467989  c644245c02           mov byte ptr [esp + 0x5c], 2
// 0046798e  85c0                 test eax, eax
// 00467990  742c                 je 0x4679be
// 00467992  8bf0                 mov esi, eax
// 00467994  83c004               add eax, 4
// 00467997  83c9ff               or ecx, 0xffffffff
// 0046799a  f00fc108             lock xadd dword ptr [eax], ecx
// 0046799e  751e                 jne 0x4679be
// 004679a0  8b16                 mov edx, dword ptr [esi]
// 004679a2  8b4204               mov eax, dword ptr [edx + 4]
// 004679a5  8bce                 mov ecx, esi
// 004679a7  ffd0                 call eax
// 004679a9  8d4e08               lea ecx, [esi + 8]
// 004679ac  83caff               or edx, 0xffffffff
// 004679af  f00fc111             lock xadd dword ptr [ecx], edx
// 004679b3  7509                 jne 0x4679be
// 004679b5  8b06                 mov eax, dword ptr [esi]
// 004679b7  8b5008               mov edx, dword ptr [eax + 8]
// 004679ba  8bce                 mov ecx, esi
// 004679bc  ffd2                 call edx
// 004679be  8d4c241c             lea ecx, [esp + 0x1c]
// 004679c2  c644245c01           mov byte ptr [esp + 0x5c], 1
// 004679c7  ff1568248000         call dword ptr [0x802468]
// 004679cd  8d4c2438             lea ecx, [esp + 0x38]
// 004679d1  c644245c00           mov byte ptr [esp + 0x5c], 0
// 004679d6  ff1568248000         call dword ptr [0x802468]
// 004679dc  55                   push ebp
// 004679dd  ff15f4218000         call dword ptr [0x8021f4]
// 004679e3  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 004679e7  5f                   pop edi
// 004679e8  5e                   pop esi
// 004679e9  b001                 mov al, 1
// 004679eb  5d                   pop ebp
// 004679ec  64890d00000000       mov dword ptr fs:[0], ecx
// 004679f3  83c454               add esp, 0x54
// 004679f6  c20c00               ret 0xc

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct __declspec(dllimport) String
{
    unsigned char storage[28];
    String(const char*);
    ~String();
    const char* c_str() const;
};

struct __declspec(dllimport) StringName
{
    unsigned char storage[28];
    StringName(const char*);
    ~StringName();
};

__declspec(dllimport) String __cdecl operator+(const String&, const char*);
__declspec(dllimport) String __cdecl operator+(const StringName&, const char*);

struct RefCount
{
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* object;
    RefCount* count;

    void* get() const;
    ~Shared();
};

inline void* Shared::get() const
{
    return object;
}

inline Shared::~Shared()
{
    if (count)
    {
        RefCount* p = count;
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

Shared __cdecl getService();
void __cdecl report(void*, int, const char*);

struct Lock
{
    void* section;
    bool locked;

    Lock(void*);
    ~Lock();
};

inline Lock::Lock(void* p) : section(p)
{
    EnterCriticalSection(section);
    locked = true;
}

inline Lock::~Lock()
{
    if (locked)
        LeaveCriticalSection(section);
}

struct Device;
struct DeviceTable
{
    void* reserved[10];
    long (__stdcall* getData)(Device*, unsigned long, void*,
                             unsigned long*, unsigned long);
};

struct Device
{
    DeviceTable* table;
};

struct DxUserInput
{
    unsigned char prefix[0x34];
    unsigned char section[24];
    unsigned char padding[0x130];
    Device* keyboard;

    bool read(void*, unsigned long*, Device*);
};

bool DxUserInput::read(void* data, unsigned long* count, Device* device)
{
    Lock lock(section);
    switch (device->table->getData(device, 20, data, count, 0))
    {
    case 0:
        break;
    case 1:
        {
            StringName name(device == keyboard ? "Keyboard " : "Mouse ");
            String message = name + "DI_BUFFEROVERFLOW!\n";
            report(getService().get(), 3, message.c_str());
        }
        break;
    default:
        {
            StringName name(device == keyboard ? "Keyboard " : "Mouse ");
        }
        return false;
    }
    return true;
}
