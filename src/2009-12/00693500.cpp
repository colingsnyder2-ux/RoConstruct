// from server: 100% by atomic.potato
struct FactoryProduct {
    char pad[4];
    char f4;
    char f5;
};

extern "C" void __cdecl sub_6931D0(void*, void*, int, int);

void __cdecl sub_693500(void* self, int a, int b)
{
    if (b != 4) {
        char tmp = 0;
        sub_6931D0(self, (void*)a, b, *(int*)&tmp);
        return;
    }
    FactoryProduct* p = (FactoryProduct*)a;
    *(int*)p = 0xb38228;
    p->f4 = 0;
    p->f5 = 0;
}
