// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Reference {
    Control* control;
    Reference();
    Reference& operator=(const Reference&);
    ~Reference();
};

inline Reference::Reference() : control(0)
{
}

inline Reference::~Reference()
{
    if (control)
        control->release();
}

struct ScriptMouseCommand;

struct Product {
    char padding[0x164];
    ScriptMouseCommand* command;
};

struct SharedProduct {
    Product* object;
    Reference reference;
    SharedProduct();
    SharedProduct& operator=(const SharedProduct&);
};

inline SharedProduct::SharedProduct() : object(0)
{
}

inline SharedProduct& SharedProduct::operator=(const SharedProduct& other)
{
    object = other.object;
    reference = other.reference;
    return *this;
}

SharedProduct __cdecl createProduct();

struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct Base : Primary, Secondary {
    char storage[20];
    Base(int);
    ~Base();
};

struct ScriptMouseCommand : Base {
    SharedProduct product;
    ScriptMouseCommand(int);
    ~ScriptMouseCommand();
};

ScriptMouseCommand::ScriptMouseCommand(int argument)
    : Base(argument), product()
{
    product = createProduct();
    product.object->command = this;
}
