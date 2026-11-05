// from server: 47% by colin
struct VCApp_CComObject {
    void* f(int);
};

extern "C" void* __cdecl sub_62FEF6(unsigned int);
extern "C" int __cdecl sub_402AC0(int);
extern "C" void* __cdecl sub_630B60();

struct GlobalObj_8BAE44 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

extern GlobalObj_8BAE44* g_8BAE44;

void* VCApp_CComObject::f(int arg)
{
    if (arg == 0)
        return (void*)0x80004003;

    *(int*)arg = 0;

    char* mem = (char*)sub_62FEF6(0x1c);
    char* obj;
    if (mem != 0) {
        *(int*)(mem + 4) = 0;
        *(int*)(mem + 0x10) = 0;
        *(int*)(mem + 0xc) = 0;
        *(int*)(mem + 8) = 0;
        *(int*)(mem + 0x14) = 0;
        *(int*)(mem + 0x18) = 0;
        *(int*)(mem + 0) = 0x784fa8;

        GlobalObj_8BAE44* p = g_8BAE44;
        p->v1();

        obj = mem;
    } else {
        obj = 0;
    }

    if (obj != 0) {
        if ((*(unsigned char*)0x8baf50 & 1) == 0) {
            *(unsigned int*)0x8baf50 |= 1;
            *(unsigned int*)0x8baf48 = 4;
            *(unsigned int*)0x8baf4c = 0xffffffff;
        }

        if (sub_402AC0(4)) {
            void* p = sub_630B60();
            *(void**)p = 0;
        }
    }

    return obj;
}
