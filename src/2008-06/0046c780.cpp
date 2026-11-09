// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_unit_df783402a7119920.cpp

// Candidate translation unit (score above; library headers required).
#include <exception>
extern const unsigned char errorContext[16];
extern int __cdecl reportError(const void*, const char*, unsigned int);

#include <boost/shared_ptr.hpp>

struct Guard {
    int saved;
    int* target;
    void* token;
    int active;
    Guard(void*);
    ~Guard();
};

extern "C" void* __cdecl current_context();
void __stdcall release_context(int, void*);

inline Guard::~Guard()
{
    if (int* t = target)
        t[1] = saved;
    if (active)
        release_context(0, token);
}

struct Stream {
    char storage[136];
    Stream();
    ~Stream();
    void open(const char*);
};

extern void (__thiscall* stream_construct)(Stream*, int);
extern void (__thiscall* stream_destroy)(Stream*);
extern void (__thiscall* stream_open)(Stream*, const char*);

inline Stream::Stream()
{
    stream_construct(this, 1);
}

inline Stream::~Stream()
{
    stream_destroy(this);
}

inline void Stream::open(const char* name)
{
    stream_open(this, name);
}

struct __declspec(dllimport) Text {
    void* data;
    Text(const char*);
    ~Text();
    const char* convert(int, int);
};

extern Text* (__thiscall* text_construct)(Text*, const char*);
extern void (__thiscall* text_destroy)(Text*);
extern const char* (__thiscall* text_convert)(Text*, int, int);

typedef boost::shared_ptr<void> Shared;

struct Scope {
    char storage[12];
    Scope(Shared);
    ~Scope();
};

struct Owned {
    void destroy();
};

extern "C" void __cdecl free_owned(void*);

struct Owner {
    Owned* object;
    ~Owner();
    Owned* get() const { return object; }
};

inline Owner::~Owner()
{
    if (object) {
        Owned* p = object;
        p->destroy();
        free_owned(p);
    }
}

struct S {
    char padding[36];
    Shared shared;
    Owner acquire();
    int write(Owned*, Stream*);
};

int __stdcall function(S* source, const char* name)
{
    Guard guard(current_context());
    try {
        Stream stream;
        stream.open(Text(name).convert(34, 64));
        Scope scope(source->shared);
        return source->write(source->acquire().get(), &stream);
    }
    catch (const std::exception& error) {
        return reportError(errorContext, error.what(), 0);
    }
}
