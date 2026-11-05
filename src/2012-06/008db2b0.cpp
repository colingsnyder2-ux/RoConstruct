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

    T* value = *(T**)((char*)this - 0x148);
    T* object = *(T**)((char*)value + 0x108);
    return *(int*)((char*)object + 0x30);
}