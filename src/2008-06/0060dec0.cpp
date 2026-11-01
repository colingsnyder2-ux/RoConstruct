// from server: 100% by king_originala
struct Vector {
    float x, y, z;
};

extern void __cdecl alignedFree(void *);
extern char temporaryTable;

struct Buffer {
    void *data;
    int size;
    int capacity;

    Buffer();
    ~Buffer();
};

inline Buffer::Buffer() : size(0), capacity(0)
{
    data = 0;
}

inline Buffer::~Buffer()
{
    alignedFree(data);
}

struct Temporary {
    void *volatile table;
    char storage[24];

    ~Temporary();
};

inline Temporary::~Temporary()
{
    table = &temporaryTable;
}

extern void __cdecl prepare(void *, Buffer *);
extern Temporary __cdecl transform(void *, void *);
extern void __cdecl evaluate(void *, const Temporary &, Buffer *, Vector *);

struct Contact {
    char prefix[8];
    char storage[28];
    char *first;
    void *second;

    Vector compute(void *);
};

Vector Contact::compute(void *argument)
{
    Vector result = { 0.0f, 0.0f, 0.0f };
    Buffer buffer;
    prepare(storage, &buffer);
    evaluate(second, transform(argument, first ? first + 0x288 : 0),
             &buffer, &result);
    return result;
}
