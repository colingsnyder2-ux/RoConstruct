// from server: 100% by king_originala
void __cdecl alignedFree(void *);
void __cdecl operator delete(void *);

struct Object {
    ~Object();
};

struct Buffer {
    void *data;
    int size;
    int capacity;
    ~Buffer();
};

inline Buffer::~Buffer()
{
    alignedFree(data);
    data = 0;
    size = 0;
    capacity = 0;
}

struct S {
    unsigned char padding0[0x14];
    void *connection;
    unsigned char padding1[4];
    Buffer buffer;
    unsigned char padding2[4];
    Object *object;

    void disconnect(int);
    ~S();
};

S::~S()
{
    if (connection)
        disconnect(0);
    delete object;
    object = 0;
}
