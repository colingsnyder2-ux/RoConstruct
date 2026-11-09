// from server: 56% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCount {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct String {
    unsigned char storage[28];
    String(const String&);
    ~String();
};

extern void (__thiscall *stringCopy)(String*, const String&);
extern void (__thiscall *stringDestroy)(String*);

inline String::String(const String& other) {
    stringCopy(this, other);
}

inline String::~String() {
    stringDestroy(this);
}

struct Shared;

struct Child {
    unsigned char padding[0x13c];
    float first;
    float second;
};

struct Element {
    void* object;
    RefCount* count;
};

struct Children {
    unsigned char padding[12];
    Element* begin;
    Element* end;
};

struct Object {
    unsigned char padding[0x108];
    Children* children;
    Child* child(unsigned int);
    void assign(Shared);
};

struct Shared {
    Object* object;
    RefCount* count;
    Shared(const Shared&);
    ~Shared();
};

struct Resource {
    void* get();
};

struct Context {
    unsigned char padding[0x2ec];
    Resource resource;
};

struct S {
    void* unused;
    Context* context;
    Shared build();
};

extern Shared __stdcall load(void*, const char*, String);
extern Shared __cdecl create();
extern const String imageName;
extern const char resourceName[];
extern const float firstValue;
extern const float secondValue;

inline Shared::Shared(const Shared& other)
    : object(other.object), count(other.count) {
    if (count)
        _InterlockedExchangeAdd(&count->strong, 1);
}

inline Shared::~Shared() {
    if (count) {
        RefCount* p = count;
        if (_InterlockedExchangeAdd(&p->strong, -1) == 1) {
            p->dispose();
            if (_InterlockedExchangeAdd(&p->weak, -1) == 1)
                p->destroy();
        }
    }
}

Shared S::build() {
    Shared result = create();
    {
        const Shared& value =
            load(context->resource.get(), resourceName, imageName);
        result.object->assign(value);
    }

    unsigned int i = 0;
    for (;;) {
        if (!result.object->children)
            break;
        if (i >= static_cast<unsigned int>(
                result.object->children->end -
                result.object->children->begin))
            break;

        Child* p = result.object->child(i);
        if (p) {
            p->first = firstValue;
            p->second = secondValue;
        }
        ++i;
    }
    return Shared(result);
}
