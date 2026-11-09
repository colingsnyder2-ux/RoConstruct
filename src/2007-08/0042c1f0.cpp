// from server: 71% by tester
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct InnerList {
    void* field0;
    void* field4;
    void clear();
};

struct RefCounted {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    long ref1;
    long ref2;
};

struct Base {
    virtual ~Base();
};

struct VCLuaFunction : Base {
    char pad[0xf4 - 4];
    RefCounted* ptr_f4;
    char pad2[0x100 - 0xf8];
    RefCounted* ptr_100;
    RefCounted* ptr_108;
    InnerList list_10c;
    ~VCLuaFunction();
};

void __cdecl sub_62FC62(void* p);

void InnerList::clear()
{
    void* p = this->field4;
    sub_62FC62(p);
    this->field4 = 0;
}

VCLuaFunction::~VCLuaFunction()
{
    *(void**)this = (void*)0x78a344;
    this->list_10c.clear();

    RefCounted* p108 = this->ptr_108;
    if (p108 != 0) {
        if (_InterlockedExchangeAdd(&p108->ref1, -1) == 1) {
            p108->slot1();
            if (_InterlockedExchangeAdd(&p108->ref2, -1) == 1) {
                p108->slot2();
            }
        }
    }

    RefCounted* p100 = this->ptr_100;
    if (p100 != 0) {
        if (_InterlockedExchangeAdd(&p100->ref1, -1) == 1) {
            p100->slot1();
            if (_InterlockedExchangeAdd(&p100->ref2, -1) == 1) {
                p100->slot2();
            }
        }
    }

    RefCounted* pF4 = this->ptr_f4;
    if (pF4 != 0) {
        pF4->slot2();
    }

    Base::~Base();
}
