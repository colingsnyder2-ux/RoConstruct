// from server: 49% by colin
struct RBX_Network_Client
{
    void* construct(int a, int b);
};

extern "C" void* __cdecl sub_0062FEF6(unsigned int size);

void* RBX_Network_Client::construct(int a, int b)
{
    void* p;
    *(void**)this = 0;
    p = sub_0062FEF6(0x14);
    if (p)
    {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(int*)((char*)p + 0) = 0x79c08c;
        *(int*)((char*)p + 0xc) = a;
    }
    else
    {
        p = 0;
    }
    *(void**)this = p;
    return this;
}
