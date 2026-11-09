// from server: 100% by coldek
// roc 2008-06 00666100  unit: RBX::PartDragTool  size: 313 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00666100
//
// 00666100  64a100000000         mov eax, dword ptr fs:[0]
// 00666106  6aff                 push -1
// 00666108  6880c17d00           push 0x7dc180
// 0066610d  50                   push eax
// 0066610e  64892500000000       mov dword ptr fs:[0], esp
// 00666115  83ec28               sub esp, 0x28
// 00666118  53                   push ebx
// 00666119  56                   push esi
// 0066611a  8bf1                 mov esi, ecx
// 0066611c  33db                 xor ebx, ebx
// 0066611e  385e34               cmp byte ptr [esi + 0x34], bl
// 00666121  7478                 je 0x66619b
// 00666123  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00666126  e8b57cfaff           call 0x60dde0
// 0066612b  84c0                 test al, al
// 0066612d  7426                 je 0x666155
// 0066612f  8b442440             mov eax, dword ptr [esp + 0x40]
// 00666133  50                   push eax
// 00666134  8d4c2418             lea ecx, [esp + 0x18]
// 00666138  51                   push ecx
// 00666139  8bce                 mov ecx, esi
// 0066613b  e8c0fbfaff           call 0x615d00
// 00666140  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00666143  50                   push eax
// 00666144  895c243c             mov dword ptr [esp + 0x3c], ebx
// 00666148  e883820000           call 0x66e3d0
// 0066614d  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 00666155  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00666158  e82386faff           call 0x60e780
// 0066615d  8b16                 mov edx, dword ptr [esi]
// 0066615f  8b02                 mov eax, dword ptr [edx]
// 00666161  8bce                 mov ecx, esi
// 00666163  885e34               mov byte ptr [esi + 0x34], bl
// 00666166  ffd0                 call eax
// 00666168  83c004               add eax, 4
// 0066616b  83781810             cmp dword ptr [eax + 0x18], 0x10
// 0066616f  7215                 jb 0x666186
// 00666171  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00666174  8b4004               mov eax, dword ptr [eax + 4]
// 00666177  51                   push ecx
// 00666178  50                   push eax
// 00666179  e84264f2ff           call 0x58c5c0
// 0066617e  83c408               add esp, 8
// 00666181  e995000000           jmp 0x66621b
// 00666186  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00666189  83c004               add eax, 4
// 0066618c  51                   push ecx
// 0066618d  50                   push eax
// 0066618e  e82d64f2ff           call 0x58c5c0
// 00666193  83c408               add esp, 8
// 00666196  e980000000           jmp 0x66621b
// 0066619b  395e24               cmp dword ptr [esi + 0x24], ebx
// 0066619e  747b                 je 0x66621b
// 006661a0  8b5618               mov edx, dword ptr [esi + 0x18]
// 006661a3  57                   push edi
// 006661a4  8954240c             mov dword ptr [esp + 0xc], edx
// 006661a8  895c2410             mov dword ptr [esp + 0x10], ebx
// 006661ac  895c2414             mov dword ptr [esp + 0x14], ebx
// 006661b0  6a01                 push 1
// 006661b2  8d4c2410             lea ecx, [esp + 0x10]
// 006661b6  c744244001000000     mov dword ptr [esp + 0x40], 1
// 006661be  e8fdbaf1ff           call 0x581cc0
// 006661c3  8bc8                 mov ecx, eax
// 006661c5  e80614f0ff           call 0x5675d0
// 006661ca  6a01                 push 1
// 006661cc  8d4c2410             lea ecx, [esp + 0x10]
// 006661d0  e8ebbaf1ff           call 0x581cc0
// 006661d5  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 006661d8  51                   push ecx
// 006661d9  8bc8                 mov ecx, eax
// 006661db  e84012f0ff           call 0x567420
// 006661e0  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006661e4  c744243cffffffff     mov dword ptr [esp + 0x3c], 0xffffffff
// 006661ec  3bfb                 cmp edi, ebx
// 006661ee  742a                 je 0x66621a
// 006661f0  8d4704               lea eax, [edi + 4]
// 006661f3  83c9ff               or ecx, 0xffffffff
// 006661f6  f00fc108             lock xadd dword ptr [eax], ecx
// 006661fa  751e                 jne 0x66621a
// 006661fc  8b17                 mov edx, dword ptr [edi]
// 006661fe  8b4204               mov eax, dword ptr [edx + 4]
// 00666201  8bcf                 mov ecx, edi
// 00666203  ffd0                 call eax
// 00666205  8d4f08               lea ecx, [edi + 8]
// 00666208  83caff               or edx, 0xffffffff
// 0066620b  f00fc111             lock xadd dword ptr [ecx], edx
// 0066620f  7509                 jne 0x66621a
// 00666211  8b07                 mov eax, dword ptr [edi]
// 00666213  8b5008               mov edx, dword ptr [eax + 8]
// 00666216  8bcf                 mov ecx, edi
// 00666218  ffd2                 call edx
// 0066621a  5f                   pop edi
// 0066621b  8b06                 mov eax, dword ptr [esi]
// 0066621d  8b5028               mov edx, dword ptr [eax + 0x28]
// 00666220  8bce                 mov ecx, esi
// 00666222  ffd2                 call edx
// 00666224  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00666228  5e                   pop esi
// 00666229  33c0                 xor eax, eax
// 0066622b  5b                   pop ebx
// 0066622c  64890d00000000       mov dword ptr fs:[0], ecx
// 00666233  83c434               add esp, 0x34
// 00666236  c20400               ret 4

template<class T> inline T roc_val(T v) { return v; }
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Service {
    void clear();
    void set(void*);
};

struct Context {
    int owner;
    void* object;
    Control* control;
    Context(int);
    Service* get(int);
    ~Context();
};

inline Context::Context(int value)
    : owner(value), object(0), control(0)
{
}

inline Context::~Context()
{
    Control* value = *const_cast<Control* volatile*>(&control);
    if (value) value->release();
}

struct Value {
    char data[28];
    ~Value();
};

inline Value::~Value()
{
    Control* p = 0;
    if (p)
        p->release();
}

struct Receiver {
    void consume(const Value&);
};

struct Worker {
    bool active();
    void stop();
};

struct String {
    int allocator;
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
    const char* c_str() const;
};

__forceinline const char* String::c_str() const
{
    return capacity >= 16 ? storage.pointer : storage.buffer;
}

struct Name {
    int prefix;
    String text;
};

namespace RBX {
    void handle(int, int);
}

struct S {
    virtual Name* name();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void finish();

    char padding0[20];
    int owner;
    Receiver* receiver;
    Worker* worker;
    void* item;
    char padding1[12];
    bool dragging;

    Value make(int);
    int run(int);
};

int S::run(int argument)
{
    if (dragging) {
        if (worker->active())
            receiver->consume(make(argument));

        worker->stop();
        dragging = false;
        RBX::handle(reinterpret_cast<int>(name()->text.c_str()), owner);
    } else if (item) {
        Context context(owner);
        context.get(1)->clear();
        Service* service = context.get(1);
        service->set(roc_val(item));
    }

    finish();
    return 0;
}
