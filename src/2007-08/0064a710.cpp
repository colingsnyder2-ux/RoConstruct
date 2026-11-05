// from server: 30% by colin
extern "C" {
    __declspec(dllimport) void* __stdcall CreateDIBSection(void*, void*, unsigned int, void**, void*, unsigned int);
    __declspec(dllimport) int __stdcall DeleteObject(void*);
    __declspec(dllimport) int __stdcall GetDIBits(void*, void*, unsigned int, unsigned int, void*, void*, unsigned int);
}

extern "C" void __cdecl func_0062fc6e();
extern "C" void* __cdecl func_0062ff32(unsigned int);
extern "C" void __cdecl func_0062ff26(void*);

struct CXTPCommandBar
{
    char pad[4];
    int field_4;
    int field_8;
    char pad2[8];
    int field_14;
    int func(int a, int b, int c, int d, int e, int f, int g, int h);
};

int CXTPCommandBar::func(int a, int b, int c, int d, int e, int f, int g, int h)
{
    void* hdc = (void*)a;
    int width = b;
    int height = c;
    void** ppvBits = (void**)d;
    void* param5 = (void*)e;
    int param6 = f;
    int param7 = g;
    int param8 = h;

    if (CreateDIBSection(hdc, param5, 0, ppvBits, 0, 0) == 0)
    {
        func_0062fc6e();
    }

    field_4 = field_4 / width;
    field_14 = field_14 / width;

    unsigned int size = (unsigned int)width * 4;
    if (width != 0 && size / 4 != (unsigned int)width)
    {
        size = 0xFFFFFFFF;
    }

    void** array = (void**)func_0062ff32(size);

    for (int i = 0; i < width; i++)
    {
        void* result = CreateDIBSection(hdc, param5, 0, &array[i], 0, 0);
        ppvBits[i] = result;
        if (result == 0)
        {
            for (int j = 0; j < i; j++)
            {
                DeleteObject(ppvBits[j]);
            }
            func_0062ff26(array);
            func_0062fc6e();
        }
    }

    int counter = 0;
    while (counter < field_8)
    {
        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < field_4; y++)
            {
                *(int*)array[x] = *(int*)param5;
                array[x] = (char*)array[x] + 4;
                param5 = (char*)param5 + 4;
            }
        }
        counter++;
    }

    func_0062ff26(array);
    return 1;
}
