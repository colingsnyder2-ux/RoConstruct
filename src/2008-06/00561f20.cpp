// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct String;
extern void (__thiscall* string_copy_ctor)(String*, const String&);
extern void (__thiscall* string_dtor)(String*);

struct String {
    unsigned int allocator;
    union {
        char buffer[16];
        char* pointer;
    };
    unsigned int length;
    unsigned int capacity;

    String(const String&);
    ~String();

    const char* c_str() const {
        const char* p = pointer;
        if (capacity < 16)
            p = buffer;
        return p;
    }
};

inline String::String(const String& other) {
    string_copy_ctor(this, other);
}

inline String::~String() {
    string_dtor(this);
}

struct Content {
    String name;
    int context;
};

struct Entry {
    String* text;
    unsigned int unused;
    String* filename;
};

struct Stream {
    virtual ~Stream();
};

extern void (__thiscall* string_stream_ctor)(void*, const String&, int, int);
extern void (__thiscall* file_stream_ctor)(void*, const char*, int, int, int);
extern unsigned int string_stream_table[];
extern unsigned int file_stream_table[];

struct StringStream {
    char storage[132];
    StringStream(const String&, int);
};

struct FileStream {
    char storage[140];
    FileStream(const char*, int, int);
};

inline StringStream::StringStream(const String& text, int mode) {
    string_stream_ctor(this, text, mode, 1);
    *reinterpret_cast<unsigned int**>(storage + 80) = string_stream_table;
}

inline FileStream::FileStream(const char* path, int mode, int protection) {
    file_stream_ctor(this, path, mode, protection, 1);
    *reinterpret_cast<unsigned int**>(storage + 88) = file_stream_table;
}

struct Result {
    Stream* pointer;
    explicit Result(Stream* p);
    ~Result();
};

inline Result::Result(Stream* p) : pointer(p) {}

inline Result::~Result() {
    delete pointer;
}

struct Error {
    char storage[40];
    Error(const String&);
    Error(const Error&);
    ~Error();
};

String __cdecl format(const char*, ...);

struct Provider {
    Entry* lookup(Content, int, int);
    Result load(Content);
};

Result Provider::load(Content content) {
    Entry* entry = lookup(content, 2, 0);

    if (!entry)
        throw Error(format("Unable to load %s", content.name.c_str()));

    if (entry->text)
        return Result(reinterpret_cast<Stream*>(
            new StringStream(*entry->text, 1)));

    return Result(reinterpret_cast<Stream*>(
        new FileStream(entry->filename->capacity >= 16
                           ? entry->filename->pointer
                           : entry->filename->buffer,
                       33, 64)));
}
