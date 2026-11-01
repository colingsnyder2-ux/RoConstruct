// from server: 100% by king_originala
typedef void (__cdecl *Manager)(void*, void*, int);

struct Function
{
    Manager* manager;
    unsigned char padding[4];
    unsigned char storage[24];

    Function(const Function& function);
    ~Function();
};

inline Function::Function(const Function& function)
{
    manager = 0;
    if (function.manager)
    {
        manager = function.manager;
        (*function.manager)(
            const_cast<unsigned char*>(function.storage), storage, 0);
    }
}

inline Function::~Function()
{
    if (manager)
    {
        Manager callback = *manager;
        if (callback)
            callback(storage, storage, 1);
    }
}

struct Holder
{
    unsigned char padding0[4];
    Function function;
    unsigned long trailing;

    Holder(Function value);
    virtual ~Holder();
};

Holder::Holder(Function value)
    : function(value), trailing(0)
{
}
