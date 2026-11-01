// from server: 100% by king_originala
namespace G3D {
struct System {
    static void __cdecl alignedFree(void *);
};
}

struct Base {
    unsigned char storage[0x134];
    ~Base();
};

struct S : Base {
    void *data;
    int size;
    int capacity;

    ~S();
};

S::~S()
{
    G3D::System::alignedFree(data);
    data = 0;
    size = 0;
    capacity = 0;
}
