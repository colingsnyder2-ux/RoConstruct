// from server: 45% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RBXName {
    void* data;
};

struct ICreator {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
};

struct FactoryProductBase {
    void* vptr;
    void* field4;
    void* field8;
};

struct Creator : ICreator {
    int field4;
    int field8;
    int fieldC;
    int field10;
};

extern "C" bool __cdecl sub_4879D0(void*);
extern "C" void* __cdecl sub_62FEF6(unsigned int);

struct VDHTMLWindowService_FactoryProduct : FactoryProductBase {
    void construct(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6);
};

void VDHTMLWindowService_FactoryProduct::construct(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6) {
    void* local18 = arg0;
    void* local1C = arg1;
    void* local20 = arg2;
    void* local24 = arg3;
    void* local28 = arg4;
    void* local2C = arg5;
    void* local30 = arg6;

    if (!sub_4879D0(&local18)) {
        this->field8 = (void*)0x41a970;
        this->vptr = (void*)0x416be0;
        void* p = sub_62FEF6(0x18);
        if (p) {
            *(void**)p = local18;
            *(void**)((char*)p + 4) = local1C;
            *(void**)((char*)p + 8) = local20;
            *(void**)((char*)p + 0xC) = local24;
            if (local24) {
                _InterlockedExchangeAdd((volatile long*)((char*)local24 + 4), 1);
            }
            *(void**)((char*)p + 0x10) = local28;
        }
        this->field4 = p;
    }

    if (local24) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)local24 + 4), -1) == 1) {
            void** vt = *(void***)local24;
            ((void (__thiscall*)(void*))vt[1])(local24);
            if (_InterlockedExchangeAdd((volatile long*)((char*)local24 + 8), -1) == 1) {
                void** vt2 = *(void***)local24;
                ((void (__thiscall*)(void*))vt2[2])(local24);
            }
        }
    }
}
