// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Counted {
    virtual ~Counted();
    virtual void dispose();
    virtual void destroy();
    volatile long use;
    volatile long weak;
};

struct Frame {
    char padding[0x24];
    char value;
};

struct Object {
    char padding[0x14];
    char key;
    Frame* getFrame();
    void setParent(Object*);
};

struct Shared {
    Object* px;
    Counted* pn;
    ~Shared();
};

inline Shared::~Shared()
{
    if (pn) {
        Counted* p = pn;
        if (_InterlockedDecrement(&p->use) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

Shared __cdecl makeObject();

struct Property {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, const void*);
};

extern Property* frameProperty;
extern Property* scalarProperty;

struct Service {
    void setMode(int);
};

Service* __cdecl findService(Object*);

struct HammerTool {
    char padding[0x18];
    Object* parent;
    Object* object;
    int activate(void*);
};

int HammerTool::activate(void*)
{
    if (object) {
        Shared temporary = makeObject();
        void* key = temporary.px ? &temporary.px->key : 0;
        Frame* frame = object->getFrame();
        frameProperty->set(key, &frame->value);

        float value = 0.0f;
        scalarProperty->set(temporary.px ? &temporary.px->key : 0, &value);

        temporary.px->setParent(parent);
        object->setParent(0);
        findService(parent)->setMode(2);
    }
    return 0;
}
