// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

#include <string>
#include <vector>
#include <time.h>
#include <stdarg.h>

extern std::string __cdecl formatText(const char*, char*);

struct Stream {
    Stream& appendText(int, const char*);
};

struct StreamProvider {
    virtual Stream* getStream() = 0;
};

extern StreamProvider* streamProvider;

struct Mutex {
    void* handle;
    char kind;
    void acquire();
    void release();
};

struct Lock {
    Mutex* mutex;
    bool locked;
    Lock(Mutex&);
    ~Lock();
};

__forceinline Lock::Lock(Mutex& m) : mutex(&m) {
    mutex->acquire();
    locked = true;
}

inline Lock::~Lock() {
    if (locked)
        mutex->release();
}

struct Record {
    int severity;
    std::string text;
    __int64 timestamp;

    Record(int s, const char* p) : severity(s), text(p) {
        _time64(&timestamp);
    }
};

struct Provider {
    char prefix[16];
    void** begin;
    void** end;
    char reserved[16];
    unsigned size() const { return end - begin; }
    Mutex mutex;

    void emit(Record);
};

static inline Stream* currentStream()
{
    return streamProvider ? streamProvider->getStream() : 0;
}

void __cdecl output(Provider* provider, int severity, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    std::string text = formatText(format, args);
    va_end(args);

    if (currentStream()) {
        if (severity == 3)
            currentStream()->appendText(2, text.c_str());
        else if (severity == 2)
            currentStream()->appendText(1, text.c_str());
        else if (severity == 1)
            currentStream()->appendText(0, text.c_str());
    }

    if (provider->size() > 0) {
        Lock lock(provider->mutex);
        if (provider->size() > 0)
            provider->emit(Record(severity, text.c_str()));
    }
}
