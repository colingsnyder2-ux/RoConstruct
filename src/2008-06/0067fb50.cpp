// from server: 100% by king_originala
extern "C" void __cdecl release(void *);

struct MaterialPtr;
struct TexturePtr;

typedef void (__thiscall *MaterialDestructor)(MaterialPtr *);
typedef void (__thiscall *TextureDestructor)(TexturePtr *);

extern MaterialDestructor destroyMaterial;
extern TextureDestructor destroyTexture;

struct MaterialPtr {
    unsigned char storage[12];
    ~MaterialPtr();
};

struct TexturePtr {
    unsigned char storage[12];
    ~TexturePtr();
};

inline MaterialPtr::~MaterialPtr()
{
    destroyMaterial(this);
}

inline TexturePtr::~TexturePtr()
{
    destroyTexture(this);
}

struct Storage {
    void *allocation;
    unsigned char padding[8];
    void *begin;
    void *end;
    void *capacity;
};

struct S {
    MaterialPtr material0;
    MaterialPtr material1;
    MaterialPtr material2;
    MaterialPtr material3;
    unsigned char padding0[32];
    TexturePtr texture0;
    TexturePtr texture1;
    TexturePtr texture2;
    TexturePtr texture3;
    unsigned char padding1[4];
    Storage storage0;
    Storage storage1;

    virtual ~S();
};

S::~S()
{
    if (storage1.begin)
        release(storage1.begin);

    storage1.begin = 0;
    storage1.end = 0;
    storage1.capacity = 0;
    release(storage1.allocation);

    if (storage0.begin)
        release(storage0.begin);

    void *allocation = storage0.allocation;
    storage0.begin = 0;
    storage0.end = 0;
    storage0.capacity = 0;
    release(allocation);
}
