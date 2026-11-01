// from server: 100% by colin
struct Base {
    virtual ~Base();
    unsigned char storage[84];
};

struct S : Base {
    unsigned int flags;
    virtual ~S();
    void close();
};

S::~S()
{
    try {
        if ((*reinterpret_cast<unsigned char*>(&flags) & 1) &&
            (static_cast<unsigned char>(flags >> 4) & 1))
            close();
    } catch (...) {
    }
}
