// from server: 100% by king_originala
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
    configure(directoryThree, 32);

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
