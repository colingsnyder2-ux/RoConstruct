// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S_func_006159f0 {
    int f(int a1);
};

struct Object {
    char storage[32];
    Object(int a1);
};

inline Object::Object(int a1)
{
    ((S_func_006159f0*)this)->f(a1);
    *(char*)((char*)this + 28) = 0;
    *(int*)((char*)this + 0) = 0x8336a4;
    *(int*)((char*)this + 4) = 0x833688;
}

struct S {
    Object* f();
};

Object* S::f()
{
    return new Object(*(int*)((char*)this + 24));
}
