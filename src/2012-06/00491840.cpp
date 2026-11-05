// from server: 35% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCountedBase {
    virtual void Release() = 0;
    virtual void DeleteThis() = 0;
};

struct StatsService {
    void* vptr;
    char padding1[0x58 - 4];
    RefCountedBase* field_58;
    char padding2[0x60 - 0x5C];
    int field_60;
    int field_64;
    char field_68[0x94 - 0x68];
    RefCountedBase* field_94;
    
    StatsService();
};

extern "C" void __cdecl sub_490530(void* thisptr);
extern "C" void __stdcall sub_982114(void* arg);
extern "C" void __cdecl sub_428a60(void* thisptr);
extern "C" void __cdecl sub_9B8F80(StatsService* thisptr);

StatsService::StatsService() {
    vptr = (void*)0xB5DE8C;
    
    RefCountedBase* obj94 = field_94;
    if (obj94) {
        long* refCount1 = (long*)((char*)obj94 + 4);
        if (_InterlockedExchangeAdd(refCount1, -1) == 1) {
            obj94->Release();
            long* refCount2 = (long*)((char*)obj94 + 8);
            if (_InterlockedExchangeAdd(refCount2, -1) == 1) {
                obj94->DeleteThis();
            }
        }
    }
    
    void* obj68 = &field_68;
    sub_490530(obj68);
    void* firstMember = *(void**)obj68;
    sub_982114(firstMember);
    
    sub_428a60(&field_64);
    sub_428a60(&field_60);
    
    RefCountedBase* obj58 = field_58;
    if (obj58) {
        long* refCount1 = (long*)((char*)obj58 + 4);
        if (_InterlockedExchangeAdd(refCount1, -1) == 1) {
            obj58->Release();
            long* refCount2 = (long*)((char*)obj58 + 8);
            if (_InterlockedExchangeAdd(refCount2, -1) == 1) {
                obj58->DeleteThis();
            }
        }
    }
    
    sub_9B8F80(this);
}
