// from server: 100% by EspClaude
// from server: 86% by colin
// roc 2008-06 00411c30  unit: ChatEnter  size: 293 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00411c30
//
// 00411c30  55                   push ebp
// 00411c31  8bec                 mov ebp, esp
// 00411c33  6aff                 push -1
// 00411c35  6851d77b00           push 0x7bd751
// 00411c3a  64a100000000         mov eax, dword ptr fs:[0]
// 00411c40  50                   push eax
// 00411c41  64892500000000       mov dword ptr fs:[0], esp
// 00411c48  83ec18               sub esp, 0x18
// 00411c4b  8b4508               mov eax, dword ptr [ebp + 8]
// 00411c4e  53                   push ebx
// 00411c4f  56                   push esi
// 00411c50  57                   push edi
// 00411c51  8bf1                 mov esi, ecx
// 00411c53  8965f0               mov dword ptr [ebp - 0x10], esp
// 00411c56  8975ec               mov dword ptr [ebp - 0x14], esi
// 00411c59  83f80d               cmp eax, 0xd
// 00411c5c  7446                 je 0x411ca4
// 00411c5e  83f81b               cmp eax, 0x1b
// 00411c61  7418                 je 0x411c7b
// 00411c63  e800f02800           call 0x6a0c68
// 00411c68  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00411c6b  64890d00000000       mov dword ptr fs:[0], ecx
// 00411c72  5f                   pop edi
// 00411c73  5e                   pop esi
// 00411c74  5b                   pop ebx
// 00411c75  8be5                 mov esp, ebp
// 00411c77  5d                   pop ebp
// 00411c78  c20c00               ret 0xc
// 00411c7b  a180b79200           mov eax, dword ptr [0x92b780]
// 00411c80  50                   push eax
// 00411c81  e894ef2800           call 0x6a0c1a
// 00411c86  8b8e88000000         mov ecx, dword ptr [esi + 0x88]
// 00411c8c  e897ed2800           call 0x6a0a28
// 00411c91  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00411c94  64890d00000000       mov dword ptr fs:[0], ecx
// 00411c9b  5f                   pop edi
// 00411c9c  5e                   pop esi
// 00411c9d  5b                   pop ebx
// 00411c9e  8be5                 mov esp, ebp
// 00411ca0  5d                   pop ebp
// 00411ca1  c20c00               ret 0xc
// 00411ca4  8d4d08               lea ecx, [ebp + 8]
// 00411ca7  ff15043f8000         call dword ptr [0x803f04]
// 00411cad  8d4d08               lea ecx, [ebp + 8]
// 00411cb0  51                   push ecx
// 00411cb1  33ff                 xor edi, edi
// 00411cb3  8bce                 mov ecx, esi
// 00411cb5  897dfc               mov dword ptr [ebp - 4], edi
// 00411cb8  e8bdef2800           call 0x6a0c7a
// 00411cbd  39bea4000000         cmp dword ptr [esi + 0xa4], edi
// 00411cc3  0f849c000000         je 0x411d65
// 00411cc9  8d4d08               lea ecx, [ebp + 8]
// 00411ccc  ff15d82f8000         call dword ptr [0x802fd8]
// 00411cd2  84c0                 test al, al
// 00411cd4  0f858b000000         jne 0x411d65
// 00411cda  8b969c000000         mov edx, dword ptr [esi + 0x9c]
// 00411ce0  83ec08               sub esp, 8
// 00411ce3  8bcc                 mov ecx, esp
// 00411ce5  8911                 mov dword ptr [ecx], edx
// 00411ce7  8b86a0000000         mov eax, dword ptr [esi + 0xa0]
// 00411ced  bb01000000           mov ebx, 1
// 00411cf2  885dfc               mov byte ptr [ebp - 4], bl
// 00411cf5  8965e8               mov dword ptr [ebp - 0x18], esp
// 00411cf8  894104               mov dword ptr [ecx + 4], eax
// 00411cfb  3bc7                 cmp eax, edi
// 00411cfd  7409                 je 0x411d08
// 00411cff  83c004               add eax, 4
// 00411d02  8bcb                 mov ecx, ebx
// 00411d04  f00fc108             lock xadd dword ptr [eax], ecx
// 00411d08  8d4ddc               lea ecx, [ebp - 0x24]
// 00411d0b  e830feffff           call 0x411b40
// 00411d10  8d4d08               lea ecx, [ebp + 8]
// 00411d13  c645fc02             mov byte ptr [ebp - 4], 2
// 00411d17  ff15e03e8000         call dword ptr [0x803ee0]
// 00411d1d  83ec1c               sub esp, 0x1c
// 00411d20  8bcc                 mov ecx, esp
// 00411d22  8965e8               mov dword ptr [ebp - 0x18], esp
// 00411d25  50                   push eax
// 00411d26  ff1558248000         call dword ptr [0x802458]
// 00411d2c  8b8ea4000000         mov ecx, dword ptr [esi + 0xa4]
// 00411d32  e8f9ad0800           call 0x49cb30
// 00411d37  8d4ddc               lea ecx, [ebp - 0x24]
// 00411d3a  885dfc               mov byte ptr [ebp - 4], bl
// 00411d3d  e87e561600           call 0x5773c0
// 00411d42  8b1580b79200         mov edx, dword ptr [0x92b780]
// 00411d48  52                   push edx
// 00411d49  8bce                 mov ecx, esi
// 00411d4b  e8caee2800           call 0x6a0c1a
// 00411d50  897dfc               mov dword ptr [ebp - 4], edi
// 00411d53  eb10                 jmp 0x411d65

// from server: 85% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Text
{
    unsigned char data[4];
    Text();
    __declspec(dllimport) ~Text() throw();
    bool empty() const;
    const char* c_str() const;
};

extern void (__thiscall *text_construct)(Text*);
extern void (__thiscall *text_destroy)(Text*);
extern bool (__thiscall *text_empty)(const Text*);
extern const char* (__thiscall *text_data)(const Text*);

__forceinline Text::Text()
{
    text_construct(this);
}

__forceinline bool Text::empty() const
{
    return text_empty(this);
}

__forceinline const char* Text::c_str() const
{
    return text_data(this);
}

struct String
{
    unsigned int allocator;
    union
    {
        char buffer[16];
        char* pointer;
    };
    unsigned int size;
    unsigned int capacity;

    __declspec(dllimport) String(const char*);
    ~String();
};

extern void (__thiscall *string_construct)(void*, const char*);
extern void (__thiscall *string_destroy)(void*);



__forceinline String::~String()
{
    string_destroy(this);
}

struct Control
{
    unsigned int unused;
    volatile long references;
};

struct Shared
{
    void* pointer;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

__forceinline Shared::Shared(const Shared& value)
{
    pointer = value.pointer;
    control = value.control;
    if (control)
    {
        volatile long* count = &control->references;
        _InterlockedExchangeAdd(count, 1);
    }
}

struct Guard
{
    void* pointer;
    Control* control;
    unsigned int state;

    Guard(Shared);
    ~Guard();
};

struct Receiver
{
    void send(String);
};

struct Widget
{
    void close();
};

extern int close_value;

struct ChatEnter
{
    unsigned char padding[136];
    Widget* widget;
    unsigned char padding2[16];
    Shared shared;
    Receiver* receiver;

    void key(int, int, int);
    void other();
    void close(int);
    void getText(Text*);
};

void ChatEnter::key(int key, int, int)
{
    switch (key)
    {
    default:
        other();
        return;
    case 27:
        close(close_value);
        widget->close();
        return;
    case 13:
        break;
    }

    Text text;
    getText(&text);
    if (receiver && !text.empty())
    {
        try
        {
            {
                Guard guard(shared);
                receiver->send(text.c_str());
            }
            close(close_value);
        }
        catch (...)
        {
        }
    }
    widget->close();
}
