// from server: 49% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RBXName {
    void* vptr;
    long refcount;
};

struct RefCounted {
    void* vptr;
    long refcount;
};

struct Inner {
    void* ptr;
    RefCounted* ref;
};

struct DataModel;

struct CNameItem {
    char pad[0x7c];
    void* field7c;
    RefCounted* field80;
    DataModel* field84;

    void construct(Inner* arg0, void* arg1);
};

struct DataModel {
    char pad[0xc8];
    void* fieldc8;
};

extern "C" void* __stdcall sub_77e6a8(void*);
extern "C" void __stdcall sub_77ddb8(void*, void*);
extern "C" void __cdecl sub_40d550(void*);
extern "C" void __cdecl sub_5595a0(void*);

void CNameItem::construct(Inner* arg0, void* arg1)
{
    Inner local;
    local.ptr = this->field7c;
    local.ref = this->field80;
    if (local.ref == 0) {
        _InterlockedExchangeAdd(&local.ref->refcount, 1);
    }
    sub_40d550(&local);

    void* p = sub_77e6a8(&this->field84->fieldc8);
    sub_77ddb8(arg1, p);

    sub_5595a0(&local);
}
