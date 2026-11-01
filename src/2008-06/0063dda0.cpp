// from server: 100% by king_originala
extern char sourceType[];
extern char targetType[];

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

struct Renderable {
    typedef void (__thiscall *Method)(Renderable*, void*, int);
    Method* vtable;
};

struct S {
    char padding[24];
    void* instance;
    void f(void* argument);
};

void S::f(void* argument)
{
    if (instance) {
        Renderable* object = static_cast<Renderable*>(
            __RTDynamicCast(instance, 0, sourceType, targetType, 0));
        if (object)
            object->vtable[4](object, argument, 0);
    }
}
