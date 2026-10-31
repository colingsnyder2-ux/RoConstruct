// from server: 51% by Intel
extern "C" void __stdcall RegisterFactoryProduct(int);

struct FactoryProduct
{
    int vptr;
    int field4;

    int Initialize(int* arg);
};

int FactoryProduct::Initialize(int* arg)
{
    if (*(unsigned char*)0xE32E78)
    {
        int vptr_val = vptr;
        if (vptr_val != 0xE32E6C)
        {
            field4 = *arg;
            return (int)this;
        }
        if (vptr_val)
        {
            int (*func)(int*, int*) = (int(*)(int*, int*))*(int*)(vptr_val + 4);
            if (func)
            {
                func(&field4, arg);
            }
            vptr = 0;
        }
        if (&field4)
        {
            field4 = *arg;
        }
        vptr = 0xE32E6C;
        return (int)this;
    }

    *(unsigned char*)0xE32E78 = 1;
    *(int*)0xE32E6C = 0xDAFDA4;
    *(int*)0xE32E74 = 0x5708D0;
    *(int*)0xE32E70 = 0x59A790;
    RegisterFactoryProduct(0xB17B30);

    int vptr_val = vptr;
    if (vptr_val == 0xE32E6C)
    {
        field4 = *arg;
        return (int)this;
    }
    if (vptr_val)
    {
        int (*func)(int*, int*) = (int(*)(int*, int*))*(int*)(vptr_val + 4);
        if (func)
        {
            func(&field4, arg);
        }
        vptr = 0;
    }
    if (&field4)
    {
        field4 = *arg;
    }
    vptr = 0xE32E6C;
    return (int)this;
}
