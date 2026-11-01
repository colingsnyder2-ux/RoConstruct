// from server: 100% by colin
// from server: 92% by colin
// roc 2008-06 00562730  unit: std::D::DU?$char_traits::?$basic_ifstream  size: 417 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00562730
//
// 00562730  6aff                 push -1
// 00562732  6860f07c00           push 0x7cf060
// 00562737  64a100000000         mov eax, dword ptr fs:[0]
// 0056273d  50                   push eax
// 0056273e  64892500000000       mov dword ptr fs:[0], esp
// 00562745  81ec1c010000         sub esp, 0x11c
// 0056274b  55                   push ebp
// 0056274c  8bac2434010000       mov ebp, dword ptr [esp + 0x134]
// 00562753  56                   push esi
// 00562754  57                   push edi
// 00562755  6a00                 push 0
// 00562757  6a01                 push 1
// 00562759  83ec20               sub esp, 0x20
// 0056275c  8bf4                 mov esi, esp
// 0056275e  c744243400000000     mov dword ptr [esp + 0x34], 0
// 00562766  8bf9                 mov edi, ecx
// 00562768  89642438             mov dword ptr [esp + 0x38], esp
// 0056276c  55                   push ebp
// 0056276d  8bce                 mov ecx, esi
// 0056276f  ff155c248000         call dword ptr [0x80245c]
// 00562775  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00562778  8bcf                 mov ecx, edi
// 0056277a  89461c               mov dword ptr [esi + 0x1c], eax
// 0056277d  e8fef1ffff           call 0x561980
// 00562782  8bf0                 mov esi, eax
// 00562784  85f6                 test esi, esi
// 00562786  7511                 jne 0x562799
// 00562788  8b842438010000       mov eax, dword ptr [esp + 0x138]
// 0056278f  8930                 mov dword ptr [eax], esi
// 00562791  897004               mov dword ptr [eax + 4], esi
// 00562794  e91e010000           jmp 0x5628b7
// 00562799  8daf70010000         lea ebp, [edi + 0x170]
// 0056279f  8bcd                 mov ecx, ebp
// 005627a1  896c2414             mov dword ptr [esp + 0x14], ebp
// 005627a5  e836250300           call 0x594ce0
// 005627aa  c644241801           mov byte ptr [esp + 0x18], 1
// 005627af  833e00               cmp dword ptr [esi], 0
// 005627b2  c784243001000001000000 mov dword ptr [esp + 0x130], 1
// 005627bd  0f85ba000000         jne 0x56287d
// 005627c3  8b4608               mov eax, dword ptr [esi + 8]
// 005627c6  83781810             cmp dword ptr [eax + 0x18], 0x10
// 005627ca  7205                 jb 0x5627d1
// 005627cc  8b4004               mov eax, dword ptr [eax + 4]
// 005627cf  eb03                 jmp 0x5627d4
// 005627d1  83c004               add eax, 4
// 005627d4  6a01                 push 1
// 005627d6  6a40                 push 0x40
// 005627d8  6a21                 push 0x21
// 005627da  50                   push eax
// 005627db  8d8c24ac000000       lea ecx, [esp + 0xac]
// 005627e2  ff1504248000         call dword ptr [0x802404]
// 005627e8  6a01                 push 1
// 005627ea  6a02                 push 2
// 005627ec  8d4c2424             lea ecx, [esp + 0x24]
// 005627f0  c684243801000002     mov byte ptr [esp + 0x138], 2
// 005627f8  ff1530248000         call dword ptr [0x802430]
// 005627fe  6800100000           push 0x1000
// 00562803  8d4c2420             lea ecx, [esp + 0x20]
// 00562807  51                   push ecx
// 00562808  8d9424a4000000       lea edx, [esp + 0xa4]
// 0056280f  52                   push edx
// 00562810  c684243c01000003     mov byte ptr [esp + 0x13c], 3
// 00562818  e8d3ccffff           call 0x55f4f0
// 0056281d  6a1c                 push 0x1c
// 0056281f  e8fce01300           call 0x6a0920
// 00562824  83c410               add esp, 0x10
// 00562827  89442410             mov dword ptr [esp + 0x10], eax
// 0056282b  c684243001000004     mov byte ptr [esp + 0x130], 4
// 00562833  85c0                 test eax, eax
// 00562835  740d                 je 0x562844
// 00562837  50                   push eax
// 00562838  8d4c2420             lea ecx, [esp + 0x20]
// 0056283c  ff1534248000         call dword ptr [0x802434]
// 00562842  eb02                 jmp 0x562846
// 00562844  33c0                 xor eax, eax
// 00562846  50                   push eax
// 00562847  8bce                 mov ecx, esi
// 00562849  c684243401000003     mov byte ptr [esp + 0x134], 3
// 00562851  e87ab9ffff           call 0x55e1d0
// 00562856  8d4c241c             lea ecx, [esp + 0x1c]
// 0056285a  c684243001000002     mov byte ptr [esp + 0x130], 2
// 00562862  ff1538248000         call dword ptr [0x802438]
// 00562868  8d8c249c000000       lea ecx, [esp + 0x9c]
// 0056286f  c684243001000001     mov byte ptr [esp + 0x130], 1
// 00562877  ff1508248000         call dword ptr [0x802408]
// 0056287d  8b06                 mov eax, dword ptr [esi]
// 0056287f  8bbc2438010000       mov edi, dword ptr [esp + 0x138]
// 00562886  8907                 mov dword ptr [edi], eax
// 00562888  8b7604               mov esi, dword ptr [esi + 4]
// 0056288b  897704               mov dword ptr [edi + 4], esi
// 0056288e  85f6                 test esi, esi
// 00562890  740c                 je 0x56289e
// 00562892  83c604               add esi, 4
// 00562895  b901000000           mov ecx, 1
// 0056289a  f00fc10e             lock xadd dword ptr [esi], ecx
// 0056289e  8bcd                 mov ecx, ebp
// 005628a0  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 005628a8  c684243001000000     mov byte ptr [esp + 0x130], 0
// 005628b0  e84b240300           call 0x594d00
// 005628b5  8bc7                 mov eax, edi
// 005628b7  8b8c2428010000       mov ecx, dword ptr [esp + 0x128]
// 005628be  5f                   pop edi
// 005628bf  5e                   pop esi
// 005628c0  64890d00000000       mov dword ptr fs:[0], ecx
// 005628c7  5d                   pop ebp
// 005628c8  81c428010000         add esp, 0x128
// 005628ce  c20800               ret 8

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


struct Text;
struct Input;
struct Output;

extern void (__thiscall *copyText)(Text*, const Text&);
extern void (__thiscall *openInput)(Input*, const char*, int, int, int);
extern void (__thiscall *closeInput)(Input*);
extern void (__thiscall *openOutput)(Output*, int, int);
extern void (__thiscall *closeOutput)(Output*);
extern Text* (__thiscall *outputText)(const Output*, Text*);

struct Text {
    unsigned int unused;
    union {
        char local[16];
        char* heap;
    };
    unsigned int length;
    unsigned int capacity;

    Text(const Text&);
    Text(const Output&);
    const char* data() const;
};

inline Text::Text(const Text& other) {
    copyText(this, other);
}

inline Text::Text(const Output& output) {
    outputText(&output, this);
}

inline const char* Text::data() const {
    if (capacity >= 16)
        return heap;
    return local;
}

struct Key {
    Text text;
    unsigned int tag;
    Key(const Key&);
};

inline Key::Key(const Key& other)
    : text(other.text), tag(other.tag) {
}

struct Input {
    char storage[140];
    Input(const char*, int, int);
    ~Input();
};

inline Input::Input(const char* name, int mode, int protection) {
    openInput(this, name, mode, protection, 1);
}

inline Input::~Input() {
    closeInput(this);
}

struct Output {
    char storage[128];
    Output(int);
    ~Output();
    __declspec(dllimport) Text str() const;
};

inline Output::Output(int mode) {
    openOutput(this, mode, 1);
}

inline Output::~Output() {
    closeOutput(this);
}

struct Mutex {
    void* handle;
    bool kind;
    void lock();
    void unlock();
};

struct Guard {
    Mutex* mutex;
    bool locked;
    Guard(Mutex*);
    ~Guard();
};

inline Guard::Guard(Mutex* value) : mutex(value) {
    mutex->lock();
    locked = true;
}

inline Guard::~Guard() {
    if (locked)
        mutex->unlock();
}

struct Counter {
    void* table;
    volatile long references;
};

struct Entry {
    Text* object;
    Counter* counter;
    Text* filename;
    void assign(Text*);
};

struct Result {
    Text* object;
    Counter* counter;
    Result();
    Result(const Entry&);
    ~Result();
};

inline Result::Result() : object(0), counter(0) {
}

inline Result::Result(const Entry& entry)
    : object(entry.object), counter(entry.counter) {
    if (counter)
        _InterlockedIncrement(&counter->references);
}

extern void __cdecl transfer(Input*, Output*, unsigned int);
extern void* __cdecl operator new(unsigned int);
extern void __cdecl operator delete(void*);

struct S {
    char padding[0x170];
    Mutex mutex;
    Entry* find(Key, int, int);
    Result f(const Key&);
};

Result S::f(const Key& key) {
    Entry* entry = find(key, 1, 0);
    if (!entry)
        return Result();

    Guard guard(&mutex);
    if (!entry->object) {
        Input input(entry->filename->data(), 33, 64);
        Output output(2);
        transfer(&input, &output, 4096);
        entry->assign(new Text(output.str()));
    }
    return Result(*entry);
}
