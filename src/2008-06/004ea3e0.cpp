// from server: 100% by king_originala
struct Observer {
    virtual void notify();
};

struct Registry {
    void remove(Observer*);
};

struct Owner {
    char padding[0x1a0];
    Registry registry;
};

struct Base {
    virtual ~Base();
    char padding0[0xb8];
    Owner* owner;
    char padding1[0x18];
};

struct Reference {
    ~Reference();
};

struct Texture : Base, Observer {
    Reference reference;
    virtual ~Texture();
};

Texture::~Texture()
{
    if (owner)
        owner->registry.remove(this);
}
