// from server: 48% by colin
struct CDataModelPropGrid {
    void dtor();
};

extern "C" void __cdecl sub_62FC62(void*);
extern "C" void __cdecl sub_725720(void*);
extern "C" void __cdecl sub_682930(void*);
extern "C" void __cdecl sub_441C70(void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_439DC0(void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_44EFC0(void*, void*, void*, void*, void*);

void CDataModelPropGrid::dtor()
{
    char* self = (char*)this;
    *(void**)(self + 0) = (void*)0x78f41c;
    *(void**)(self + 0x17c) = (void*)0x78f40c;

    {
        char* p = self + 0x1c4;
        void* a = *(void**)(self + 0x1c8);
        void* b = *(void**)a;
        int flag = 6;
        sub_441C70(p, &flag, b, p, a);
        sub_62FC62(*(void**)(p + 4));
        *(void**)(p + 4) = 0;
        *(void**)(p + 8) = 0;
    }

    {
        char* p = self + 0x1b8;
        void* a = *(void**)(self + 0x1bc);
        void* b = *(void**)a;
        char flag = 5;
        sub_439DC0(p, &flag, b, p, a);
        sub_62FC62(*(void**)(p + 4));
        *(void**)(p + 4) = 0;
        *(void**)(p + 8) = 0;
    }

    {
        char* p = self + 0x1a8;
        void* a = *(void**)(self + 0x1ac);
        void* b = *(void**)a;
        char flag = 4;
        sub_44EFC0(p, &flag, b, p, a);
        sub_62FC62(*(void**)(p + 4));
        *(void**)(p + 4) = 0;
        *(void**)(p + 8) = 0;
    }

    {
        char* p = self + 0x19c;
        void* a = *(void**)(self + 0x1a0);
        void* b = *(void**)a;
        char flag = 3;
        sub_44EFC0(p, &flag, b, p, a);
        sub_62FC62(*(void**)(p + 4));
        *(void**)(p + 4) = 0;
        *(void**)(p + 8) = 0;
    }

    {
        void* p = *(void**)(self + 0x190);
        if (p != 0) {
            sub_62FC62(p);
        }
        *(void**)(self + 0x190) = 0;
        *(void**)(self + 0x194) = 0;
        *(void**)(self + 0x198) = 0;
    }

    {
        char* p = self + 0x180;
        char flag = 1;
        sub_725720(&flag);
    }

    *(void**)(self + 0x17c) = (void*)0x788344;
    sub_682930(self);
}
