// from server: 100% by king_originala
typedef unsigned int size_t;

extern "C" void *(__cdecl *allocate_memory)(size_t);

struct Function
{
    typedef void (__cdecl *Manager)(void *, void *, int);

    Manager *manager;
    unsigned int reserved;
    unsigned char storage[24];

    Function(const Function &);
    ~Function();
};

inline Function::Function(const Function &other)
{
    manager = 0;
    if (other.manager)
    {
        manager = other.manager;
        (*other.manager)((void *)other.storage, storage, 0);
    }
}

inline Function::~Function()
{
    if (manager)
    {
        Manager operation = *manager;
        if (operation)
            operation(storage, storage, 1);
    }
}

struct Object
{
    unsigned char storage[0x178];

    Object(Function);
    static void *operator new(size_t);
    static void operator delete(void *);
};

inline void *Object::operator new(size_t size)
{
    return allocate_memory(size);
}

struct Empty
{
};

struct Result
{
    Object *pointer;
    void *control;

    Result(Object *, Empty);
    ~Result();
};

Result create(Function function)
{
    return Result(new Object(function), Empty());
}
