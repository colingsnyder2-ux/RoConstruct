// from server: 100% by king_originala
struct Buffer {
    int bits;
    int capacity;
    int used;
    void* data;
    bool owned;

    ~Buffer();
};

struct Receiver {
    char padding[16];
    bool active;
    char reserved[7];
    Buffer buffer;

    void prepare();
    ~Receiver();
};

Receiver::~Receiver()
{
    if (active)
        prepare();
}
