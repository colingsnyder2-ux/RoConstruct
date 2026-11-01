// from server: 100% by king_originala
extern "C" void* (__cdecl *malloc)(unsigned int);
extern "C" void __cdecl free(void*);

struct Function {
    typedef void (__cdecl *Manager)(const void*, void*, int);
    struct Table {
        Manager manage;
    };

    const Table* table;
    unsigned int reserved;
    unsigned char storage[24];

    Function(const Function&);
    ~Function();
};

inline Function::Function(const Function& other) : table(0) {
    if (other.table) {
        table = other.table;
        other.table->manage(other.storage, storage, 0);
    }
}

inline Function::~Function() {
    if (table) {
        Manager manager = table->manage;
        if (manager)
            manager(storage, storage, 1);
    }
}

struct Object {
    unsigned char storage[0x178];

    Object(Function);
    static void* operator new(unsigned int);
    static void operator delete(void*);
};

inline void* Object::operator new(unsigned int size) {
    return malloc(size);
}

inline void Object::operator delete(void* p) {
    free(p);
}

struct Deleter {
    unsigned char unused;
    Deleter();
};

inline Deleter::Deleter() : unused(0) {}

struct Result {
    Object* pointer;
    void* control;

    Result(Object*, Deleter);
    ~Result();
};

Result makeResult(Function function) {
    Deleter deleter;
    Result result(new Object(function), deleter);
    return result;
}
