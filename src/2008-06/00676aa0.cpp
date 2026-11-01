// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Object {
    char storage[0x54];
    Object(void*, int, int);
};

struct Handle {
    Object* pointer;
    Handle(Object*);
    ~Handle();
    void assign(Object*);
};

__forceinline Handle::Handle(Object* value) : pointer(0) {
    assign(value);
}

struct S {
    char padding[8];
    char data;
    Handle f(int);
};

Handle S::f(int value) {
    return Handle(new Object(&data, value, 0));
}
