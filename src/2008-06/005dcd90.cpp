// from server: 100% by king_originala
extern char instanceType;
extern char playerType;

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

struct Base {
    void first(void*);
    void second(void*);
};

struct S {
    char padding[0x24];
    unsigned int count;

    void f(void*);
};

void S::f(void* argument)
{
    if (count > 0) {
        void* object = *(void**)((char*)this - 0x2c);
        if (!__RTDynamicCast(object, 0, &instanceType, &playerType, 0)) {
            ((Base*)((char*)this - 0x130))->first(argument);
            return;
        }
        ((Base*)((char*)this - 0x130))->second(argument);
    }
}
