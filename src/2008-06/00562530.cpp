// from server: 100% by king_originala
struct StringCore {
    unsigned char data[24];
    unsigned int capacity;
};

extern StringCore* (__thiscall *copyString)(StringCore*, const StringCore&);

struct String : StringCore {
    unsigned int extra;
    String(const String&);
};

inline String::String(const String& s)
{
    copyString(this, s);
    extra = s.extra;
}

struct Stream {
    unsigned char data[140];
};

struct StringStream : Stream {
    StringStream(const StringCore&, int, Stream*&);
    ~StringStream();
};

struct FileStream : Stream {
    FileStream(const char*, int, int, Stream*&);
    ~FileStream();
};

extern Stream* (__thiscall *constructStringStream)(
    StringStream*, const StringCore&, int, int);
extern void (__thiscall *destroyStringStream)(StringStream*);
extern Stream* (__thiscall *constructFileStream)(
    FileStream*, const char*, int, int, int);
extern void (__thiscall *destroyFileStream)(FileStream*);

inline StringStream::StringStream(const StringCore& text, int mode, Stream*& result)
{
    result = constructStringStream(this, text, mode, 1);
}

inline StringStream::~StringStream()
{
    destroyStringStream(this);
}

inline FileStream::FileStream(const char* path, int mode, int share, Stream*& result)
{
    result = constructFileStream(this, path, mode, share, 1);
}

inline FileStream::~FileStream()
{
    destroyFileStream(this);
}

struct Callable {
    unsigned char data[24];
};

typedef void (__cdecl *Manager)(Callable*, Callable*, int);

struct Callback {
    Manager* manager;
    unsigned int reserved;
    Callable callable;
    void read(int, Stream*);
    ~Callback();
};

inline Callback::~Callback()
{
    Manager* table = manager;
    if (table) {
        Manager destroy = *table;
        if (destroy)
            destroy(&callable, &callable, 1);
    }
}

struct Resource {
    StringCore* text;
    unsigned int reserved;
    StringCore* filename;
};

struct S {
    Resource* find(String, int, Callback*);
    void f(const String&, Callback);
};

void S::f(const String& name, Callback callback)
{
    Resource* resource = find(name, 1, &callback);
    if (resource) {
        Stream* result;
        if (resource->text) {
            StringStream stream(*resource->text, 1, result);
            callback.read(1, result);
        } else {
            StringCore* filename = resource->filename;
            const char* path;
            if (filename->capacity >= 16)
                path = *reinterpret_cast<const char**>(filename->data + 4);
            else
                path = reinterpret_cast<const char*>(filename->data + 4);
            FileStream stream(path, 33, 64, result);
            callback.read(1, result);
        }
    }
}
