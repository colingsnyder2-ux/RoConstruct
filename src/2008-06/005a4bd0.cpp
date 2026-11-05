// from server: 100% by king_originala
extern "C" void* (__cdecl * const malloc)(unsigned int);

struct Buffer {
    char data[24];
};

typedef void (__cdecl *Manager)(const Buffer*, Buffer*, int);

struct Table {
    Manager manager;
};

struct Function {
    Table* table;
    unsigned int reserved;
    Buffer buffer;

    Function(const Function&);
    ~Function();
};

__forceinline Function::Function(const Function& other) : table(0) {
    if (other.table) {
        table = other.table;
        other.table->manager(&other.buffer, &buffer, 0);
    }
}

__forceinline Function::~Function() {
    if (table) {
        Manager manager = table->manager;
        if (manager)
            manager(&buffer, &buffer, 1);
    }
}

struct Tag {};

struct Object {
    char storage[0x178];

    Object(Function);
    static void* __cdecl operator new(unsigned int);
    static void __cdecl operator delete(void*);
};

__forceinline void* __cdecl Object::operator new(unsigned int size) {
    return malloc(size);
}

struct Result {
    Object* pointer;
    void* control;

    Result(Object*, Tag);
    ~Result();
};

Result __cdecl f(Function function) {
    return Result(new Object(function), Tag());
}
