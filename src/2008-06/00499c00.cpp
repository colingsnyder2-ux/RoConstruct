// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct Empty {
    char value;
    Empty();
};

__forceinline Empty::Empty() {}

bool __cdecl func_0060a2f0(const Empty&);

struct Object {
    virtual ~Object();
    unsigned int unused;
};

struct Owner {
    Object* pointer;
    Owner(Object*);
    ~Owner();
};

__forceinline Owner::Owner(Object* p) : pointer(p) {}

__forceinline Owner::~Owner()
{
    if (pointer)
        delete pointer;
}

typedef void (__cdecl *Manager)(void*, void*, int);
extern Manager function_manager;

struct Function {
    Manager* manager;
    unsigned int unused;
    union Storage {
        char empty;
        char bytes[24];
        Storage();
    } storage;

    Function(Empty);
    ~Function();
};

__forceinline Function::Storage::Storage() {}

__forceinline Function::Function(Empty value)
{
    if (!func_0060a2f0(value)) {
        storage.empty = value.value;
        manager = &function_manager;
    } else {
        manager = 0;
    }
}

__forceinline Function::~Function()
{
    if (manager) {
        Manager callback = *manager;
        if (callback)
            callback(&storage, &storage, 1);
        manager = 0;
    }
}

struct Base {
    unsigned int data[2];
    Base(const Function&, const Owner&);
    ~Base();
};

struct MemberBase {
    unsigned int data[7];
    MemberBase();
};

struct Member : MemberBase {
    unsigned char flag;
    unsigned char padding[3];
    Member();
};

__forceinline Member::Member() : MemberBase()
{
    flag = 0;
}

struct S : Base {
    Member member;
    S(int, int);
};

S::S(int, int)
    : Base(Function(Empty()), Owner(new Object)), member()
{
}
