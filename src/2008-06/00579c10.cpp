// from server: 100% by king_originala
struct String;
struct Stream;

extern void (__thiscall *string_default)(String *);
extern void (__thiscall *string_copy)(String *, const String &);
extern void (__thiscall *string_destroy)(String *);
extern void (__thiscall *stream_construct)(Stream *, int, int);
extern void (__thiscall *stream_destroy)(Stream *);
extern void *(__thiscall *stream_flush)(void *);

struct String {
    unsigned char storage[28];
    String();
    String(const String &);
    ~String();
};

inline String::String()
{
    string_default(this);
}

inline String::String(const String &s)
{
    string_copy(this, s);
}

inline String::~String()
{
    string_destroy(this);
}

struct Stream {
    unsigned char storage[136];
    Stream(int);
    ~Stream();
    void flush();
};

inline Stream::Stream(int mode)
{
    stream_construct(this, mode, 1);
}

inline Stream::~Stream()
{
    stream_destroy(this);
}

inline void Stream::flush()
{
    stream_flush(storage + 8);
}

struct Resource {
    void destroy();
};

extern Resource *__cdecl acquire_resource();
extern void __cdecl release_memory(void *);

struct Owner {
    Resource *p;
    Owner();
    ~Owner();
};

inline Owner::Owner() : p(acquire_resource())
{
}

inline Owner::~Owner()
{
    if (p) {
        p->destroy();
        release_memory(p);
    }
}

struct FirstPart {
    unsigned char storage[36];
    ~FirstPart();
};

struct SecondPart {
    unsigned char storage[36];
    ~SecondPart();
};

struct Context {
    unsigned char storage[4];
    FirstPart first;
    SecondPart second;
    Context(void *, void *);
    void use(Resource *);
};

struct Operation {
    String first;
    String second;
    Operation(const String &);
    void finish(Stream *, int, String *);
};

__forceinline Operation::Operation(const String &s) : first(s), second()
{
}

struct S {
    void attach(Resource *);
    void *get_context();
    void f(String, int);
};

void S::f(String text, int)
{
    Stream stream(3);
    {
        Owner resource;
        attach(resource.p);
        {
            Context context(this ? get_context() : 0, stream.storage + 8);
            context.use(resource.p);
            stream.flush();
        }
    }
    String result;
    {
        Operation operation(text);
        operation.finish(&stream, 1, &result);
    }
}
