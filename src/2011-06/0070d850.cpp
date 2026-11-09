// from server: 100% by atomic.potato
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

    T* value = *(T**)((char*)this - 0x138);
    T* object = *(T**)((char*)value + 0x108);
    return *(int*)((char*)object + 0x30);
}
