// from server: 100% by colin
// from server: 98% by king_originala
// roc 2008-06 00437070  unit: CStandardOutputView  size: 213 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00437070
//
// 00437070  6aff                 push -1
// 00437072  6830027c00           push 0x7c0230
// 00437077  64a100000000         mov eax, dword ptr fs:[0]
// 0043707d  50                   push eax
// 0043707e  64892500000000       mov dword ptr fs:[0], esp
// 00437085  83ec08               sub esp, 8
// 00437088  55                   push ebp
// 00437089  56                   push esi
// 0043708a  57                   push edi
// 0043708b  8bf9                 mov edi, ecx
// 0043708d  8d6f24               lea ebp, [edi + 0x24]
// 00437090  8bcd                 mov ecx, ebp
// 00437092  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0043709a  896c240c             mov dword ptr [esp + 0xc], ebp
// 0043709e  e83ddc1500           call 0x594ce0
// 004370a3  c644241001           mov byte ptr [esp + 0x10], 1
// 004370a8  837f2000             cmp dword ptr [edi + 0x20], 0
// 004370ac  c644241c01           mov byte ptr [esp + 0x1c], 1
// 004370b1  7516                 jne 0x4370c9
// 004370b3  8b8700ffffff         mov eax, dword ptr [edi - 0x100]
// 004370b9  6a00                 push 0
// 004370bb  6a00                 push 0
// 004370bd  6865040000           push 0x465
// 004370c2  50                   push eax
// 004370c3  ff150c2e8000         call dword ptr [0x802e0c]
// 004370c9  8d4c2428             lea ecx, [esp + 0x28]
// 004370cd  8d7704               lea esi, [edi + 4]
// 004370d0  51                   push ecx
// 004370d1  8bce                 mov ecx, esi
// 004370d3  e838ffffff           call 0x437010
// 004370d8  8b7f20               mov edi, dword ptr [edi + 0x20]
// 004370db  81fffa000000         cmp edi, 0xfa
// 004370e1  7630                 jbe 0x437113
// 004370e3  33ff                 xor edi, edi
// 004370e5  397e1c               cmp dword ptr [esi + 0x1c], edi
// 004370e8  7429                 je 0x437113
// 004370ea  8b4618               mov eax, dword ptr [esi + 0x18]
// 004370ed  8b5610               mov edx, dword ptr [esi + 0x10]
// 004370f0  8b0482               mov eax, dword ptr [edx + eax*4]
// 004370f3  8d4804               lea ecx, [eax + 4]
// 004370f6  ff1568248000         call dword ptr [0x802468]
// 004370fc  ff4618               inc dword ptr [esi + 0x18]
// 004370ff  8b4618               mov eax, dword ptr [esi + 0x18]
// 00437102  394614               cmp dword ptr [esi + 0x14], eax
// 00437105  7703                 ja 0x43710a
// 00437107  897e18               mov dword ptr [esi + 0x18], edi
// 0043710a  83461cff             add dword ptr [esi + 0x1c], -1
// 0043710e  7503                 jne 0x437113
// 00437110  897e18               mov dword ptr [esi + 0x18], edi
// 00437113  8bcd                 mov ecx, ebp
// 00437115  c644241c00           mov byte ptr [esp + 0x1c], 0
// 0043711a  e8e1db1500           call 0x594d00
// 0043711f  8d4c242c             lea ecx, [esp + 0x2c]
// 00437123  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043712b  ff1568248000         call dword ptr [0x802468]
// 00437131  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00437135  5f                   pop edi
// 00437136  5e                   pop esi
// 00437137  5d                   pop ebp
// 00437138  64890d00000000       mov dword ptr fs:[0], ecx
// 0043713f  83c414               add esp, 0x14
// 00437142  c22c00               ret 0x2c

extern "C" int (__stdcall *PostMessageA)(void*, unsigned int, unsigned int, long);
extern "C" void (__thiscall *destroyString)(void*);

struct String {
    unsigned char storage[28];
    ~String();
};

inline String::~String()
{
    destroyString(this);
}

struct Entry {
    unsigned int kind;
    unsigned int second;
    String text;
    unsigned char remainder[8];
};

struct Stored {
    unsigned int kind;
    String text;
};

struct Queue {
    unsigned int reserved[4];
    Stored** blocks;
    unsigned int capacity;
    unsigned int start;
    unsigned int count;
    void append(const void*);
    void pop_front();
};

inline void Queue::pop_front()
{
    if (count != 0) {
        unsigned int i = start;
        Stored* e = blocks[i];
        e->text.~String();
        ++start;
        if (capacity <= start)
            start = 0;
        if (--count == 0)
            start = 0;
    }
}

struct Mutex {
    void* handle;
    char flag;
    void lock();
    void unlock();
};

struct Guard {
    Mutex* mutex;
    bool locked;
    Guard(Mutex*);
    ~Guard();
};

inline Guard::Guard(Mutex* value) : mutex(value)
{
    mutex->lock();
    locked = true;
}

inline Guard::~Guard()
{
    if (locked)
        mutex->unlock();
}

struct View {
    unsigned int reserved;
    Queue queue;
    Mutex mutex;
    void submit(Entry value);
};

void View::submit(Entry value)
{
    Guard guard(&mutex);

    if (queue.count == 0)
        PostMessageA(*(void**)((char*)this - 256), 0x465, 0, 0);

    queue.append((const char*)&value + 4);

    unsigned int n = queue.count;
    if (n > 250)
        queue.pop_front();
}
