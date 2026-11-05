// from server: 100% by king_originala
extern int liveCount;

struct Resource {
    void release(void*);
};

struct Base {
    virtual void function();
    ~Base();
};

struct TextureBase {
    virtual void function();
    ~TextureBase();
};

struct Texture : TextureBase {
    virtual void function();
    void cleanup();
    ~Texture();
};

struct __declspec(novtable) Holder : Base {
    unsigned char reserved0[8];
    Resource* resource;
    void* allocation;
    unsigned char reserved1[12];
    Texture texture;

    ~Holder();
};

inline Base::~Base()
{
}

inline TextureBase::~TextureBase()
{
}

inline Texture::~Texture()
{
    cleanup();
}

Holder::~Holder()
{
    --liveCount;
    if (allocation)
        resource->release(allocation);
}
