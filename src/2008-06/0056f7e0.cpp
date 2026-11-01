// from server: 100% by king_originala
struct String;

extern "C" {
    extern void (__thiscall *stringConstruct)(String *);
    extern void (__thiscall *stringDestroy)(String *);
}

struct String {
    unsigned char data[28];
    String();
    ~String();
};

__forceinline String::String() {
    stringConstruct(this);
}

__forceinline String::~String() {
    stringDestroy(this);
}

struct Name;
extern const Name &__cdecl getLocalScope();

struct Guid {
    String text;
    const Name *scope;
    Guid();
    ~Guid();
};

__forceinline Guid::Guid() : scope(&getLocalScope()) {
}

__forceinline Guid::~Guid() {
}

struct GuidReader {
    bool read(Guid &value);
};

struct Object {
    unsigned char padding[16];
    GuidReader reader;
    bool isLocal();
};

struct Setter {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void set(void *instance, const Guid &value) = 0;
};

struct S {
    unsigned char padding[24];
    Setter *setter;
    void f(void *instance, Object *object, void *unused);
};

void S::f(void *instance, Object *object, void *unused) {
    if (!object->isLocal()) {
        Guid value;
        if (object->reader.read(value))
            setter->set(instance, value);
    }
}
