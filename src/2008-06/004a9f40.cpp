// from server: 100% by king_originala
extern "C" void (__cdecl * const invalid_parameter_noinfo)();
void __cdecl operator delete(void *) throw();

struct Object {
    virtual ~Object();
};

struct Base {
    virtual ~Base();
    unsigned char reserved[24];
    Object **first;
    Object **last;
    Object **limit;
    unsigned int extra[2];
};

struct String {
    unsigned char storage[32];
    ~String();
};

struct ContainerProxy {
    void *container;
    void *iterator;
};

struct Buffer {
    ContainerProxy *proxy;
    unsigned int reserved[2];
    void *first;
    void *last;
    void *limit;
    ~Buffer();
};

inline Buffer::~Buffer()
{
    if (first)
        operator delete(first);
    first = 0;
    last = 0;
    limit = 0;
    delete proxy;
}

struct Proxy {
    ContainerProxy *pointer;
    ~Proxy();
};

inline Proxy::~Proxy()
{
    delete pointer;
}

struct ObjectBuffer {
    Proxy proxy;
    unsigned int reserved[2];
    void *first;
    void *last;
    void *limit;
    void clear();
    ~ObjectBuffer();
};

inline ObjectBuffer::~ObjectBuffer()
{
    clear();
}

struct Settings : Base {
    String string1;
    String string2;
    Buffer buffer1;
    ObjectBuffer objects;
    Buffer buffer2;
    Buffer buffer3;
    Buffer buffer4;
    virtual ~Settings();
};

Settings::~Settings()
{
    Object **finish = last;
    void (__cdecl *report)() = invalid_parameter_noinfo;
    if (first > finish)
        report();

    Object **current = first;
    if (current > last)
        report();

    while (current != finish) {
        if (*current)
            delete *current;
        ++current;
    }
}
