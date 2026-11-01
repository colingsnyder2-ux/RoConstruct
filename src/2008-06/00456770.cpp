// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Control {
    void* vtable;
    volatile long count;
    void addRef();
};

inline void Control::addRef() {
    volatile long* p = &count;
    _InterlockedExchangeAdd(p, 1);
}

struct Shared {
    void* object;
    Control* control;
    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control) {
    if (control)
        control->addRef();
}

struct Guard {
    char storage[12];
    Guard(Shared);
    ~Guard();
};

struct Text {
    const char* c_str() const;
};

struct Result {
    void* data;
    Result(const char*);
    Result(const Result&);
    ~Result();
};

extern const char* (__thiscall *text_c_str)(const Text*);
extern void (__thiscall *result_construct)(Result*, const char*);

inline const char* Text::c_str() const {
    return text_c_str(this);
}

inline Result::Result(const char* text) {
    result_construct(this, text);
}

struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void update();

    char padding[0x134];
    Text text;
};

struct S {
    char padding[0x7c];
    Shared shared;
    Object* object;
    Result f(int);
};

Result S::f(int) {
    Guard guard(shared);
    Object* p = object;
    p->update();
    return Result(p->text.c_str());
}
