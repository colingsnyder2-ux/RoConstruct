// from server: 100% by Yeetserama
// roc 2007-08 0042a3d0  unit: ThreadLogManager  size: 214 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042a3d0
//
// 0042a3d0  6aff                 push -1
// 0042a3d2  688b827400           push 0x74828b
// 0042a3d7  64a100000000         mov eax, dword ptr fs:[0]
// 0042a3dd  50                   push eax
// 0042a3de  51                   push ecx
// 0042a3df  53                   push ebx
// 0042a3e0  56                   push esi
// 0042a3e1  57                   push edi
// 0042a3e2  a188518b00           mov eax, dword ptr [0x8b5188]
// 0042a3e7  33c4                 xor eax, esp
// 0042a3e9  50                   push eax
// 0042a3ea  8d442414             lea eax, [esp + 0x14]
// 0042a3ee  64a300000000         mov dword ptr fs:[0], eax
// 0042a3f4  68ecb88b00           push 0x8bb8ec
// 0042a3f9  6860a34200           push 0x42a360
// 0042a3fe  e81db12f00           call 0x725520
// 0042a403  8b0ddcb88b00         mov ecx, dword ptr [0x8bb8dc]
// 0042a409  83c408               add esp, 8
// 0042a40c  e85fbb2f00           call 0x725f70
// 0042a411  85c0                 test eax, eax
// 0042a413  757e                 jne 0x42a493
// 0042a415  6a28                 push 0x28
// 0042a417  e8da5a2000           call 0x62fef6
// 0042a41c  8bf0                 mov esi, eax
// 0042a41e  83c404               add esp, 4
// 0042a421  89742410             mov dword ptr [esp + 0x10], esi
// 0042a425  85f6                 test esi, esi
// 0042a427  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0042a42f  742f                 je 0x42a460
// 0042a431  e84a7d1400           call 0x572180
// 0042a436  8bf8                 mov edi, eax
// 0042a438  c706a49f7800         mov dword ptr [esi], 0x789fa4
// 0042a43e  c7460400000000       mov dword ptr [esi + 4], 0
// 0042a445  ff15c4d27700         call dword ptr [0x77d2c4]
// 0042a44b  57                   push edi
// 0042a44c  8d4e0c               lea ecx, [esi + 0xc]
// 0042a44f  894608               mov dword ptr [esi + 8], eax
// 0042a452  ff1598e67700         call dword ptr [0x77e698]
// 0042a458  c70658a17800         mov dword ptr [esi], 0x78a158
// 0042a45e  eb02                 jmp 0x42a462
// 0042a460  33f6                 xor esi, esi
// 0042a462  8b0ddcb88b00         mov ecx, dword ptr [0x8bb8dc]
// 0042a468  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0042a470  8bd9                 mov ebx, ecx
// 0042a472  e8f9ba2f00           call 0x725f70
// 0042a477  8bf8                 mov edi, eax
// 0042a479  3bfe                 cmp edi, esi
// 0042a47b  7414                 je 0x42a491
// 0042a47d  56                   push esi
// 0042a47e  8bcb                 mov ecx, ebx
// 0042a480  e88bbd2f00           call 0x726210
// 0042a485  85ff                 test edi, edi
// 0042a487  7408                 je 0x42a491
// 0042a489  57                   push edi
// 0042a48a  8bcb                 mov ecx, ebx
// 0042a48c  e88fb52f00           call 0x725a20
// 0042a491  8bc6                 mov eax, esi
// 0042a493  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042a497  64890d00000000       mov dword ptr fs:[0], ecx
// 0042a49e  59                   pop ecx
// 0042a49f  5f                   pop edi
// 0042a4a0  5e                   pop esi
// 0042a4a1  5b                   pop ebx
// 0042a4a2  83c410               add esp, 0x10
// 0042a4a5  c3                   ret 
// copied from an identical function in another client (function ?getThreadLog@@YAPAUThreadLog@@XZ)

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