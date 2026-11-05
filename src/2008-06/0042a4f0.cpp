// from server: 100% by colin
// from server: 95% by king_originala
// roc 2008-06 0042a4f0  unit: ThreadLogManager  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042a4f0
//
// 0042a4f0  6aff                 push -1
// 0042a4f2  683bf47b00           push 0x7bf43b
// 0042a4f7  64a100000000         mov eax, dword ptr fs:[0]
// 0042a4fd  50                   push eax
// 0042a4fe  64892500000000       mov dword ptr fs:[0], esp
// 0042a505  51                   push ecx
// 0042a506  6800d19600           push 0x96d100
// 0042a50b  6890a44200           push 0x42a490
// 0042a510  e81bce1200           call 0x557330
// 0042a515  8b0df0d09600         mov ecx, dword ptr [0x96d0f0]
// 0042a51b  83c408               add esp, 8
// 0042a51e  e84dd01700           call 0x5a7570
// 0042a523  85c0                 test eax, eax
// 0042a525  0f8584000000         jne 0x42a5af
// 0042a52b  56                   push esi
// 0042a52c  57                   push edi
// 0042a52d  6a28                 push 0x28
// 0042a52f  e8ec632700           call 0x6a0920
// 0042a534  8bf0                 mov esi, eax
// 0042a536  83c404               add esp, 4
// 0042a539  89742408             mov dword ptr [esp + 8], esi
// 0042a53d  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0042a545  85f6                 test esi, esi
// 0042a547  742f                 je 0x42a578
// 0042a549  e812c91600           call 0x596e60
// 0042a54e  8bf8                 mov edi, eax
// 0042a550  c7060c038100         mov dword ptr [esi], 0x81030c
// 0042a556  c7460400000000       mov dword ptr [esi + 4], 0
// 0042a55d  ff1598218000         call dword ptr [0x802198]
// 0042a563  57                   push edi
// 0042a564  8d4e0c               lea ecx, [esi + 0xc]
// 0042a567  894608               mov dword ptr [esi + 8], eax
// 0042a56a  ff1558248000         call dword ptr [0x802458]
// 0042a570  c706b4048100         mov dword ptr [esi], 0x8104b4
// 0042a576  eb02                 jmp 0x42a57a
// 0042a578  33f6                 xor esi, esi
// 0042a57a  8b0df0d09600         mov ecx, dword ptr [0x96d0f0]
// 0042a580  53                   push ebx
// 0042a581  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0042a589  8bd9                 mov ebx, ecx
// 0042a58b  e8e0cf1700           call 0x5a7570
// 0042a590  8bf8                 mov edi, eax
// 0042a592  3bfe                 cmp edi, esi
// 0042a594  7414                 je 0x42a5aa
// 0042a596  56                   push esi
// 0042a597  8bcb                 mov ecx, ebx
// 0042a599  e812d11700           call 0x5a76b0
// 0042a59e  85ff                 test edi, edi
// 0042a5a0  7408                 je 0x42a5aa
// 0042a5a2  57                   push edi
// 0042a5a3  8bcb                 mov ecx, ebx
// 0042a5a5  e846ca1700           call 0x5a6ff0
// 0042a5aa  5b                   pop ebx
// 0042a5ab  5f                   pop edi
// 0042a5ac  8bc6                 mov eax, esi
// 0042a5ae  5e                   pop esi
// 0042a5af  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042a5b3  64890d00000000       mov dword ptr fs:[0], ecx
// 0042a5ba  83c410               add esp, 0x10
// 0042a5bd  c3                   ret 

typedef unsigned int DWORD;

extern DWORD (__stdcall *currentThreadId)();

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct StringData {
    unsigned int reserved;
    union {
        char buffer[16];
        char* pointer;
    };
    unsigned int length;
    unsigned int capacity;
};

struct Log {
    static StringData* get();
};

struct __declspec(dllimport) String {
    unsigned char storage[28];
    String(const char*);
    ~String();
};

extern String* (__thiscall *constructString)(String*, const char*);

struct LogBase {
    virtual ~LogBase();
    unsigned int reserved;
    DWORD threadId;
    String name;
    LogBase(const char*);
};

struct ThreadLog : LogBase {
    virtual ~ThreadLog();
    ThreadLog();
};

struct ThreadStorage {
    ThreadLog* get();
    void set(ThreadLog*);
    void dispose(ThreadLog*);
    void reset(ThreadLog*);
};

extern ThreadStorage* storage;
extern int initializationFlag;
extern void __cdecl initializeStorage();
extern void __cdecl callOnce(void (__cdecl*)(), int&);

// String constructor is imported.

inline LogBase::LogBase(const char* text)
    : reserved(0), threadId(currentThreadId()), name(text) {
}

inline ThreadLog::ThreadLog()
    : LogBase(reinterpret_cast<const char*>(Log::get())) {
}

inline void ThreadStorage::reset(ThreadLog* value) {
    ThreadLog* previous = get();
    if (previous != value) {
        set(value);
        if (previous)
            dispose(previous);
    }
}

ThreadLog* __cdecl getThreadLog() {
    callOnce(initializeStorage, initializationFlag);

    ThreadLog* result = storage->get();
    if (result == 0) {
        result = new ThreadLog;
        storage->reset(result);
    }
    return result;
}
