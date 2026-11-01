// from server: 100% by colin
// from server: 96% by king_originala
extern "C" long (__stdcall *InterlockedDecrement)(volatile long *);

struct Object {
    virtual ~Object();
    volatile long references;
    void release();
};

struct Pointer {
    Object *value;
    Pointer(const Pointer &);
    ~Pointer();
    void assign(Object *);
};

inline Pointer::Pointer(const Pointer &p) : value(0) {
    assign(p.value);
}

inline Pointer::~Pointer() {
    if (value && InterlockedDecrement(&value->references) == 0) {
        value->release();
        if (value)
            delete value;
    }
}

struct String {
    char storage[28];
};

extern String &(__thiscall *assignString)(String *, const char *);

struct Base {
    virtual ~Base();
    char prefix[8];
    String name;
    char suffix[8];
    Base();
};

struct Holder8 {
    void *value;
    char storage[4];
    Holder8();
    ~Holder8();
};

inline Holder8::Holder8() {}

struct Holder16 {
    void *value;
    char storage[12];
    Holder16();
    ~Holder16();
};

inline Holder16::Holder16() : value(0) {}

struct TexturePtr;
extern void (__thiscall *constructTexturePtr)(TexturePtr *);

struct TexturePtr {
    void *value;
    void *count;
    TexturePtr();
    ~TexturePtr();
};

inline TexturePtr::TexturePtr() {
    constructTexturePtr(this);
}

struct TextureProxy : Base {
    int field30;
    bool field34;
    Holder8 field38;
    Pointer field40;
    Holder16 field44;
    TexturePtr field54;

    TextureProxy(Pointer);
    virtual ~TextureProxy();
};

TextureProxy::TextureProxy(Pointer p)
    : field30(0), field40((field34 = false, field38.value = 0, p)) {
    assignString(&name, "");
}
