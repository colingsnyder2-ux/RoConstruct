// from server: 100% by tester
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

namespace RBX
{
    class Instance
    {
    public:
        virtual ~Instance();
        bool contains(Instance*);
    };

    class IRenderable
    {
    public:
        virtual ~IRenderable();
        virtual void reserved1();
        virtual void reserved2();
        virtual void reserved3();
        virtual void render(void*, void*);
    };
}

struct ControlBlock
{
    virtual ~ControlBlock();
    virtual void dispose();
    virtual void destroy();

    volatile long strongCount;
    volatile long weakCount;
};

struct InstancePtr
{
    RBX::Instance* object;
    ControlBlock* control;

    ~InstancePtr();
};

inline InstancePtr::~InstancePtr()
{
    ControlBlock* p = control;
    if (p)
    {
        if (_InterlockedDecrement(&p->strongCount) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weakCount) == 0)
                p->destroy();
        }
    }
}

void __cdecl renderInstance(
    InstancePtr instance,
    void* first,
    void* second,
    RBX::Instance* owner)
{
    RBX::IRenderable* renderable =
        dynamic_cast<RBX::IRenderable*>(instance.object);

    if (renderable && owner->contains(instance.object))
        renderable->render(first, second);
}
