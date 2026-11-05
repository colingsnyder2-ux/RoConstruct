// from server: 100% by king_originala
struct String {
    unsigned int allocator;
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;

    String();
    ~String();
    String& operator=(const String&);
};

extern void (__thiscall *stringConstruct)(String*);
extern void (__thiscall *stringDestroy)(String*);
extern String& (__thiscall *stringAssign)(String*, const String&);

inline String::String()
{
    stringConstruct(this);
}

inline String::~String()
{
    stringDestroy(this);
}

inline String& String::operator=(const String& other)
{
    return stringAssign(this, other);
}

struct FILE;

extern "C" {
    extern FILE* (__cdecl *fopen)(const char*, const char*);
    extern int (__cdecl *setvbuf)(FILE*, char*, int, unsigned int);
    extern int (__cdecl *fprintf)(FILE*, const char*, ...);
    extern __int64 (__cdecl *_time64)(__int64*);
    extern char* (__cdecl *_ctime64)(const __int64*);
    extern int (__cdecl *fflush)(FILE*);
}

struct Log {
    virtual ~Log();
    FILE* file;
    String name;
    int level;

    Log(const String&, int);
};

extern Log* currentLog;

Log::Log(const String& filename, int value)
{
    level = value;
    name = filename;

    const char* path = filename.capacity >= 16
        ? filename.storage.pointer
        : filename.storage.buffer;

    file = fopen(path, "w");
    if (file) {
        setvbuf(file, 0, 4, 0);
        int (__cdecl *print)(FILE*, const char*, ...) = fprintf;
        print(file, "Application Log\n");

        __int64 now;
        _time64(&now);
        print(file, "Start: %s\n", _ctime64(&now));
        fflush(file);
    }

    if (currentLog == 0)
        currentLog = this;
}
