// from server: 100% by Espeon



extern "C" __declspec(dllimport) void __stdcall _invalid_parameter_noinfo();

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);


struct SharedPtr;
void __cdecl copySharedPtr(SharedPtr*, const SharedPtr*);

struct SharedPtr {
    void* object;
    void* control;
    SharedPtr(const SharedPtr&);
    ~SharedPtr();
};

inline SharedPtr::SharedPtr(const SharedPtr& source) {
    copySharedPtr(this, &source);
}

struct Allocator {
    char storage[4];
    ~Allocator();
};

inline Allocator::~Allocator() {
}

struct String;
String* __cdecl initializeString(String*, const char*);

struct String {
    Allocator allocator;
    char storage[28];
    String(const char*);
    String(const String&);
    ~String();
};

inline String::String(const char* text) {
    initializeString(this, text);
}

struct Instance;

struct Vector {
    struct Proxy {
        Vector* owner;
        Proxy(Vector*);
    };

    Proxy* proxy;
    char allocator1[4];
    char allocator2[4];
    SharedPtr* first;
    SharedPtr* last;
    SharedPtr* limit;

    Vector();
    ~Vector();
};

inline Vector::Proxy::Proxy(Vector* value) : owner(value) {
}

struct VectorBuy : Vector {
    VectorBuy();
    ~VectorBuy();
    bool buy(unsigned int capacity)
    {
        first = 0; last = 0; limit = 0;
        if (capacity == 0)
            return false;
        first = (SharedPtr*)operator new(capacity * sizeof(SharedPtr));
        last = first;
        limit = first + capacity;
        return true;
    }
};

inline Vector::Vector()
    : proxy(new Proxy(this)) {
}

inline VectorBuy::VectorBuy() {
    buy(0);
}

String __cdecl makeString(const char*);

struct ServiceProvider {
    void load(String, Vector*);
};

ServiceProvider* __cdecl func_00465210(Instance*);

struct SlingshotTool {
    char padding[0x18];
    Instance* instance;
    SharedPtr func();
};

SharedPtr SlingshotTool::func() {
    VectorBuy result;
    func_00465210(instance)->load(
        makeString("Fonts\\Rocket.rbxm"), &result);

    SharedPtr* position = result.first;

    if (position > result.last)
        _invalid_parameter_noinfo();

    Vector::Proxy* aux = result.proxy;
    if (!(aux != 0))
        _invalid_parameter_noinfo();
    Vector* owner = aux ? aux->owner : 0;

    if (position >= owner->last)
        _invalid_parameter_noinfo();

    return *position;
}