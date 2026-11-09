// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_dumpdistinctpatternae4a8e479c847b8e.cpp

// Candidate translation unit (score above; library headers required).





struct String;

extern int (__thiscall *stringLength)(const String*);
extern char* (__thiscall *stringBuffer)(String*, int);
extern void (__thiscall *stringRelease)(String*, int);
extern const char* (__thiscall *stringData)(const String*);
extern void (__thiscall *stringDestroy)(String*);

extern "C" char* (__stdcall *PathAddBackslashA)(char*);
extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char*, void*);
extern "C" int (__stdcall *FindNextFileA)(void*, void*);

struct String {
    char* data;
    __declspec(dllimport) ~String() throw();
    int length() const;
    char* buffer(int);
    void release(int);
    __declspec(dllimport) const char* c_str() const throw();
};

inline int String::length() const {
    return stringLength(this);
}

inline char* String::buffer(int n) {
    return stringBuffer(this, n);
}

inline void String::release(int n) {
    stringRelease(this, n);
}

struct Pattern { char* data; __declspec(dllimport) ~Pattern() throw(); __declspec(dllimport) const char* c_str() const throw(); };
extern Pattern __cdecl concatenate(const String&, const char*);

struct PathSource {
    String get();
};

struct MainLogManager {
    unsigned long prefix;
    PathSource source;
    bool hasDump();
};

bool MainLogManager::hasDump() {
    String path = source.get();
    PathAddBackslashA(path.buffer(path.length() + 1));
    path.release(-1);

    struct FindData {
        unsigned long attributes;
        unsigned char remaining[316];
    } data;

    void* handle = FindFirstFileA(concatenate(path, "*.dmp").c_str(), &data);
    if (handle != reinterpret_cast<void*>(-1)) {
        int (__stdcall *next)(void*, void*) = FindNextFileA;
        do {
            if (!(data.attributes & 0x10))
                return true;
        } while (next(handle, &data));
    }
    return false;
}