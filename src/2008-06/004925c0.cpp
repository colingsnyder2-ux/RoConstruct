// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

typedef void (__cdecl *InvalidParameterFunction)();
extern InvalidParameterFunction invalidParameter;

struct Object;

struct Counts {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct BackpackShared {
    Object* object;
    Counts* counts;
    ~BackpackShared();
};

struct Shared {
    Object* object;
    Counts* counts;
    Shared(const BackpackShared&);
    ~Shared();
};

__forceinline Shared::Shared(const BackpackShared& other)
    : object(other.object), counts(other.counts) {
    if (counts)
        _InterlockedIncrement(&counts->strong);
}

__forceinline BackpackShared::~BackpackShared() {
    if (counts) {
        Counts* p = counts;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

__forceinline Shared::~Shared() {
    if (counts) {
        Counts* p = counts;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Children {
    unsigned char padding[12];
    Shared* first;
    Shared* last;
};

struct Object {
    unsigned char padding[0x108];
    Children* children;
    void setParent(Object*);
    Shared getOwner();
    unsigned int childCount();
    Object* firstChild();
    void rebuildBackpack();
};

extern bool __cdecl isBackend(Object*, int);
extern BackpackShared __cdecl createBackpack();
extern Object* __cdecl findServiceProvider(Object*);

namespace std {
    struct string {
        unsigned char storage[28];
        string(const char*);
        ~string();
    };

    struct runtime_error {
        unsigned char storage[40];
        runtime_error(const string&);
        runtime_error(const runtime_error&);
        ~runtime_error();
    };
}

typedef void (__thiscall *StringConstructor)(std::string*, const char*);
extern StringConstructor constructString;

__forceinline std::string::string(const char* text) {
    constructString(this, text);
}

void Object::rebuildBackpack() {
    if (!isBackend(this, 1)) {
        std::string message(
            "rebuildBackpack can only be called by the backend server");
        throw std::runtime_error(message);
    }

    Object* child;
    while ((child = firstChild()) != 0)
        child->setParent(0);

    Shared backpack(createBackpack());
    backpack.object->setParent(this);

    Object* provider = findServiceProvider(this);
    if (provider) {
        for (unsigned int i = 0; i < provider->childCount(); ++i) {
            Children* list = provider->children;
            if (i >= static_cast<unsigned int>(list->last - list->first))
                invalidParameter();

            Object* entry = list->first[i].object;
            Shared owner(entry->getOwner());
            owner.object->setParent(backpack.object);
        }
    }
}
