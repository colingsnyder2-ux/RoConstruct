// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Reference {
    Control* control;
    Reference(const Reference&);
    ~Reference();
    Reference& operator=(const Reference&);
};

__forceinline Reference::Reference(const Reference& other)
    : control(other.control) {
    if (control) {
        volatile long* c = &control->strong;
        _InterlockedExchangeAdd(c, 1);
    }
}

__forceinline Reference::~Reference() {
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct CChatPrompt;

struct Object {
    char padding[0x144];
    CChatPrompt* owner;
    void setValue(int);
};

struct Pair {
    Object* pointer;
    Reference reference;
};

struct Parent {
    char padding[0x224];
    int value;
    int query();
};

struct Guard {
    char storage[12];
    Guard(Pair);
    ~Guard();
};

Pair __cdecl lookup(Parent*);
Pair __cdecl createObject();

struct ObjectPair {
    Object* pointer;
    Reference reference;
    ObjectPair& operator=(const Pair&);
    void reset();
};

__forceinline ObjectPair& ObjectPair::operator=(const Pair& other) {
    pointer = other.pointer;
    reference = other.reference;
    return *this;
}

struct CChatPrompt {
    char padding0[0x20];
    int active;
    char padding1[0x64];
    int selection;
    ObjectPair object;
    char padding2[8];
    Pair context;
    int result;
    void update(Parent*, int);
    void setEnabled(int);
};

void CChatPrompt::update(Parent* parent, int selected) {
    context = lookup(parent);
    Guard guard(context);

    if (object.pointer) {
        object.pointer->owner = 0;
        object.pointer->setValue(0);
        object.reset();
    }

    selection = selected;
    result = parent ? parent->query() : 0;

    if (parent) {
        object = createObject();
        object.pointer->owner = this;
        int v = parent->value;
        object.pointer->setValue(v);
    }

    if (active) {
        int flag = (result != 0);
        setEnabled(flag);
    }
}
