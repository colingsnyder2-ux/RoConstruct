// from server: 23% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void AddRef();
    void Release();
};

struct COutputView {
    char pad[0x110];
    int field_110;
    void sub_437990();
    void sub_437D90();
    ~COutputView();
};

struct Helper {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    void sub_725750();
    void sub_725770();
};

extern "C" void* __cdecl sub_56C3B0(void*);
extern "C" void __cdecl sub_432530(void*);

COutputView::~COutputView()
{
    this->field_110 = 0x78d048;
    *(int*)this = 0x78d05c;

    Helper* h = (Helper*)((char*)sub_56C3B0(&this->field_110) + 0x20);
    h->sub_725750();

    void* p = sub_56C3B0(&this->field_110);
    if (p != 0) {
        sub_432530(&this->field_110);
    }

    h->sub_725770();
    this->sub_437990();
    this->sub_437D90();
}
