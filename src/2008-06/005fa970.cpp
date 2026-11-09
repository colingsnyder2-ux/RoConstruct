// from server: 100% by king_originala
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

struct S {
    Buffer a;
    Buffer b;
    Buffer c;
    Buffer d;
    Buffer e;
    ~S();
};

S::~S()
{
}
