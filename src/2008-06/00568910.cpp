// from server: 100% by king_originala
struct String;
struct Stream;
struct Product;

typedef void (__thiscall *StringDestructor)(String*);
typedef void (__thiscall *StreamConstructor)(Stream*, const char*, int, int, int);
typedef void (__thiscall *StreamDestructor)(Stream*);

extern StringDestructor destroyString;
extern StreamConstructor constructStream;
extern StreamDestructor destroyStream;

struct String
{
    unsigned int allocator;
    union
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;

    ~String();
};

inline String::~String()
{
    destroyString(this);
}

extern String __cdecl func_00568460();

struct Product
{
    void func_00413a70();
};

extern Product* __cdecl func_00591a30();
extern void __cdecl func_006a067a(void*);

struct Owner
{
    Product* pointer;
    explicit Owner(Product* p);
    ~Owner();
};

inline Owner::Owner(Product* p) : pointer(p)
{
}

inline Owner::~Owner()
{
    if (pointer)
    {
        pointer->func_00413a70();
        func_006a067a(pointer);
    }
}

struct Stream
{
    char storage[136];

    Stream(const char*, int, int);
    ~Stream();
};

inline Stream::Stream(const char* path, int mode, int protection)
{
    constructStream(this, path, mode, protection, 1);
}

inline Stream::~Stream()
{
    destroyStream(this);
}

struct WriterBase
{
    void func_004146d0();
};

extern char writerTable;

struct Writer
{
    void* table;
    char storage[36];

    explicit Writer(Stream*);
    ~Writer();

    void func_0058fff0(Stream*);
    void func_0058e810(Product*);
};

inline Writer::Writer(Stream* stream)
{
    func_0058fff0(stream);
    table = &writerTable;
}

inline Writer::~Writer()
{
    reinterpret_cast<WriterBase*>(storage)->func_004146d0();
}

struct S
{
    void func_00558110(Product*);
    void func_00568910();
};

void S::func_00568910()
{
    String path = func_00568460();
    if (path.length == 0)
        return;

    Owner product(func_00591a30());
    func_00558110(product.pointer);

    const char* filename =
        path.capacity >= 16 ? path.storage.pointer : path.storage.buffer;

    Stream stream(filename, 34, 64);
    Writer writer(&stream);
    writer.func_0058e810(product.pointer);
}
