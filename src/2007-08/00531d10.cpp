// from server: 64% by colin
struct VModelInstance {
    char pad[0x1c8];
    void construct();
};

extern "C" void __stdcall sub_475050(void*);
extern "C" void __stdcall sub_530660(void*, void*);
extern "C" void* __stdcall sub_52c940(void*, void*);
extern "C" void* __stdcall sub_407410(void*, void*);
extern "C" void __stdcall sub_4339d0(void*, void*);

extern char byte_8C1074;

void VModelInstance::construct()
{
    char* self = (char*)this;

    *(int*)(self + 0x04) = 0x7a4ec0;
    *(int*)(self + 0x10) = 0x7a4eb8;
    *(int*)(self + 0x14) = 0x7a4ea8;
    *(int*)(self + 0x2c) = 0x7a4e98;
    *(int*)(self + 0x44) = 0x7a4e88;
    *(int*)(self + 0x5c) = 0x7a4e78;
    *(int*)(self + 0x74) = 0x7a4e68;
    *(int*)(self + 0x8c) = 0x7a4e58;
    *(int*)(self + 0xe8) = 0x7a4e4c;
    *(int*)(self + 0x158) = 0x7a4e34;

    int* p4 = *(int**)(self + 0xec);
    *(int*)((char*)p4 + 0xec) = 0x7a4e28;

    int* p8 = *(int**)(self + 0xec);
    int* q8 = *(int**)((char*)p8 + 8);
    *(int*)((char*)q8 + 0xec) = 0x7a4e20;

    int* p12 = *(int**)(self + 0xec);
    int* q12 = *(int**)((char*)p12 + 0xc);
    *(int*)((char*)q12 + 0xec) = 0x7a4e04;

    int* r4 = *(int**)(self + 0xec);
    int* s4 = *(int**)((char*)r4 + 4);
    *(int*)((char*)s4 + 0xe8) = (int)s4 - 0x140;

    int* r8 = *(int**)(self + 0xec);
    int* s8 = *(int**)((char*)r8 + 8);
    *(int*)((char*)s8 + 0xe8) = (int)s8 - 0x148;

    int* r12 = *(int**)(self + 0xec);
    int* s12 = *(int**)((char*)r12 + 0xc);
    *(int*)((char*)s12 + 0xe8) = (int)s12 - 0x150;

    sub_475050(self + 0x168);

    *(int*)(self + 0x198) = 0;
    *(int*)(self + 0x19c) = 0;
    *(int*)(self + 0x1a0) = 0;

    *(int*)(self + 0x1b8) = 0x52fdb0;
    *(int*)(self + 0x1bc) = 0;

    *(int*)(self + 0x1ac) = 1;
    *(int*)(self + 0x1b0) = (int)self;
    *(int*)(self + 0x1c0) = 0;

    sub_530660(self + 0x1c8, self);
    sub_530660(self + 0x1f8, self);

    if (byte_8C1074 == 0) {
        void* h = sub_52c940((void*)0x7a51c0, (void*)-1);
        void* r = sub_407410(h, 0);
        sub_4339d0(r, 0);
        *(int*)r = 0x881360;
        byte_8C1074 = 1;
    }
}
