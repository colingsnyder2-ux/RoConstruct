// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0042a1c0  unit: ThreadLogManager  size: 361 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042a1c0
//
// 0042a1c0  6aff                 push -1
// 0042a1c2  6806f47b00           push 0x7bf406
// 0042a1c7  64a100000000         mov eax, dword ptr fs:[0]
// 0042a1cd  50                   push eax
// 0042a1ce  64892500000000       mov dword ptr fs:[0], esp
// 0042a1d5  83ec20               sub esp, 0x20
// 0042a1d8  55                   push ebp
// 0042a1d9  56                   push esi
// 0042a1da  8bf1                 mov esi, ecx
// 0042a1dc  57                   push edi
// 0042a1dd  8d7e04               lea edi, [esi + 4]
// 0042a1e0  8974240c             mov dword ptr [esp + 0xc], esi
// 0042a1e4  c7070c038100         mov dword ptr [edi], 0x81030c
// 0042a1ea  c7470400000000       mov dword ptr [edi + 4], 0
// 0042a1f1  ff1598218000         call dword ptr [0x802198]
// 0042a1f7  894708               mov dword ptr [edi + 8], eax
// 0042a1fa  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0042a1fe  50                   push eax
// 0042a1ff  8d4f0c               lea ecx, [edi + 0xc]
// 0042a202  ff1558248000         call dword ptr [0x802458]
// 0042a208  c706cc048100         mov dword ptr [esi], 0x8104cc
// 0042a20e  c707c0048100         mov dword ptr [edi], 0x8104c0
// 0042a214  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0042a21c  c7462c00000000       mov dword ptr [esi + 0x2c], 0
// 0042a223  8d6e30               lea ebp, [esi + 0x30]
// 0042a226  8bcd                 mov ecx, ebp
// 0042a228  c644243401           mov byte ptr [esp + 0x34], 1
// 0042a22d  ff1560248000         call dword ptr [0x802460]
// 0042a233  55                   push ebp
// 0042a234  c644243802           mov byte ptr [esp + 0x38], 2
// 0042a239  e802df1700           call 0x5a8140
// 0042a23e  83c404               add esp, 4
// 0042a241  6a20                 push 0x20
// 0042a243  68ec048100           push 0x8104ec
// 0042a248  8bce                 mov ecx, esi
// 0042a24a  e8e1fcffff           call 0x429f30
// 0042a24f  6a20                 push 0x20
// 0042a251  68fc038100           push 0x8103fc
// 0042a256  8bce                 mov ecx, esi
// 0042a258  e8d3fcffff           call 0x429f30
// 0042a25d  6a20                 push 0x20
// 0042a25f  68f0038100           push 0x8103f0
// 0042a264  8bce                 mov ecx, esi
// 0042a266  e8c5fcffff           call 0x429f30
// 0042a26b  8d4c2410             lea ecx, [esp + 0x10]
// 0042a26f  51                   push ecx
// 0042a270  8bcf                 mov ecx, edi
// 0042a272  e8b9dcffff           call 0x427f30
// 0042a277  8b15e8238000         mov edx, dword ptr [0x8023e8]
// 0042a27d  8b02                 mov eax, dword ptr [edx]
// 0042a27f  50                   push eax
// 0042a280  8d4c2414             lea ecx, [esp + 0x14]
// 0042a284  c644243803           mov byte ptr [esp + 0x38], 3
// 0042a289  ff15f4238000         call dword ptr [0x8023f4]
// 0042a28f  83e804               sub eax, 4
// 0042a292  50                   push eax
// 0042a293  8d4c2418             lea ecx, [esp + 0x18]
// 0042a297  ff15ec238000         call dword ptr [0x8023ec]
// 0042a29d  68e0048100           push 0x8104e0
// 0042a2a2  8d4c2414             lea ecx, [esp + 0x14]
// 0042a2a6  ff1548248000         call dword ptr [0x802448]
// 0042a2ac  6a28                 push 0x28
// 0042a2ae  e86d662700           call 0x6a0920
// 0042a2b3  83c404               add esp, 4
// 0042a2b6  8944243c             mov dword ptr [esp + 0x3c], eax
// 0042a2ba  c644243404           mov byte ptr [esp + 0x34], 4
// 0042a2bf  85c0                 test eax, eax
// 0042a2c1  740e                 je 0x42a2d1
// 0042a2c3  6a00                 push 0
// 0042a2c5  8d4c2414             lea ecx, [esp + 0x14]
// 0042a2c9  51                   push ecx
// 0042a2ca  8bc8                 mov ecx, eax
// 0042a2cc  e8eff90d00           call 0x509cc0
// 0042a2d1  56                   push esi
// 0042a2d2  c644243803           mov byte ptr [esp + 0x38], 3
// 0042a2d7  8935fcd09600         mov dword ptr [0x96d0fc], esi
// 0042a2dd  e8cec81700           call 0x5a6bb0
// 0042a2e2  68e0864200           push 0x4286e0
// 0042a2e7  e824070e00           call 0x50aa10
// 0042a2ec  6890874200           push 0x428790
// 0042a2f1  e82a070e00           call 0x50aa20
// 0042a2f6  68a0824200           push 0x4282a0
// 0042a2fb  ff1540288000         call dword ptr [0x802840]
// 0042a301  83c410               add esp, 0x10
// 0042a304  8d4c2410             lea ecx, [esp + 0x10]
// 0042a308  c644243402           mov byte ptr [esp + 0x34], 2
// 0042a30d  ff1568248000         call dword ptr [0x802468]
// 0042a313  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0042a317  5f                   pop edi
// 0042a318  8bc6                 mov eax, esi
// 0042a31a  5e                   pop esi
// 0042a31b  5d                   pop ebp
// 0042a31c  64890d00000000       mov dword ptr fs:[0], ecx
// 0042a323  83c42c               add esp, 0x2c
// 0042a326  c20400               ret 4

extern unsigned long (__stdcall *GetCurrentThreadId)();

struct String
{
    unsigned char storage[28];

    __declspec(dllimport) String(const char*);
    __declspec(dllimport) String();
    __declspec(dllimport) ~String();
    __declspec(dllimport) unsigned size() const;
    __declspec(dllimport) String& erase(unsigned, unsigned);
    __declspec(dllimport) String& append(const char*);
};

extern const volatile unsigned* stringNpos;

struct __declspec(novtable) Interface
{
    virtual void anchor();
};

struct ThreadLog
{
    unsigned value;
    unsigned long threadId;
    String name;

    ThreadLog(const char*);
    virtual ~ThreadLog();
    String path();
};

__forceinline ThreadLog::ThreadLog(const char* text)
    : value(0), threadId(GetCurrentThreadId()), name(text)
{
}

struct Log;

struct LogHolder
{
    Log* pointer;

    LogHolder();
    ~LogHolder();
};

__forceinline LogHolder::LogHolder() : pointer(0)
{
}

struct ThreadLogManager : Interface, ThreadLog
{
    LogHolder log;
    String buffer;

    ThreadLogManager(const char*);
    virtual ~ThreadLogManager();
    void configure(const char*, int);
};

struct Log
{
    unsigned char storage[40];
    Log(const String&, int);
};

typedef bool (__cdecl *AssertionHook)(
    const char*, const String&, const char*, int, bool&, bool);

extern void __cdecl initializeBuffer(String*);
extern void __cdecl registerManager(ThreadLogManager*);
extern void __cdecl setAssertionHook(AssertionHook);
extern void __cdecl setFailureHook(AssertionHook);
extern "C" void (__cdecl *_set_purecall_handler)(void (__cdecl*)());
extern void* __cdecl operator new(unsigned);
extern void __cdecl operator delete(void*);

extern bool __cdecl assertionHook(
    const char*, const String&, const char*, int, bool&, bool);
extern bool __cdecl failureHook(
    const char*, const String&, const char*, int, bool&, bool);
extern void __cdecl purecallHook();

extern const char directoryOne[];
extern const char directoryTwo[];
extern const char directoryThree[];
extern const char logSuffix[];
extern ThreadLogManager* currentManager;

ThreadLogManager::ThreadLogManager(const char* text)
    : ThreadLog(text), log(), buffer()
{
    initializeBuffer(&buffer);
    configure(directoryOne, 32);
    configure(directoryTwo, 32);

    String filename = path();
    filename.erase(filename.size() - 4, *stringNpos);
    filename.append(logSuffix);

    new Log(filename, 0);

    currentManager = this;
    registerManager(this);
    setAssertionHook(assertionHook);
    setFailureHook(failureHook);
    _set_purecall_handler(purecallHook);
}
