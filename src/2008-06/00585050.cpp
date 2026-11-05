// from server: 100% by king_originala
extern char instanceType[];
extern char modifierType[];

extern "C" void* __cdecl runtimeCast(
    void*, long, const void*, const void*, int);

struct Listener {
    void notify(void**);
};

struct S {
    char padding[0x1ec];
    Listener listener;
    void f(void*);
};

void S::f(void* object)
{
    object = runtimeCast(object, 0, instanceType, modifierType, 0);
    if (object)
        listener.notify(&object);
}
