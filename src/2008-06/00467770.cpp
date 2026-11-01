// from server: 100% by king_originala
extern "C" long (__stdcall *InterlockedDecrement)(volatile long *);

typedef void (__thiscall *StringDestructor)(void *);
extern StringDestructor destroyString;

struct StringStorage {
    char storage[32];
    ~StringStorage() { destroyString(this); }
};

struct Control {
    virtual ~Control();
    volatile long references;
    void dispose();
};

struct S_func_00467770 {
    char pad0[4];
    StringStorage text;
    Control *control;

    ~S_func_00467770();
};

S_func_00467770::~S_func_00467770()
{
    if (control) {
        if (InterlockedDecrement(&control->references) == 0) {
            control->dispose();
            if (control)
                delete control;
        }
        control = 0;
    }
}
