// from server: 100% by king_originala
extern double __cdecl currentTime();

struct Handle {
    void* value;

    Handle() : value(0) {}
    ~Handle();
};

#pragma pack(push, 4)
struct Receiver {
    virtual ~Receiver();

    void* owner;
    Handle handle;
    int padding;
    double timestamp;

    Receiver(void*);
};
#pragma pack(pop)

Receiver::Receiver(void* p)
    : owner(p), handle(), timestamp(currentTime())
{
}
