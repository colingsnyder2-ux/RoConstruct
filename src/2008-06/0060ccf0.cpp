// from server: 100% by king_originala
struct Object {
    ~Object();
};

void __cdecl operator delete(void*);

namespace G3D {
    struct System {
        static void __cdecl alignedFree(void*);
    };
}

struct Buffer {
    void* data;
    int size;
    int capacity;
    ~Buffer();
};

__forceinline Buffer::~Buffer()
{
    G3D::System::alignedFree(data);
    data = 0;
    size = 0;
    capacity = 0;
}

struct BallBlockContact {
    Object* object;
    int reserved;
    Buffer buffer;
    ~BallBlockContact();
};

BallBlockContact::~BallBlockContact()
{
    delete object;
}
