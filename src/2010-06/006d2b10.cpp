// from server: 100% by tester
struct S
{
    int get();
};

int S::get()
{
    struct T
    {
        int pad[66];
    };

    T* value = *(T**)((char*)this - 0x140);
    T* object = *(T**)((char*)value + 0xf4);
    return *(int*)((char*)object + 0x2c);
}