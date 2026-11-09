// from server: 35% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakRefCount;
};

struct CNameItem {
    void* vptr;
    char pad[0x78];
    int field7c;
    int field80;
    int field84;
    CNameItem(const char* name, int attributes, int value, int index, RefCounted* owner);
};

void __stdcall sub_4536a0(int* p);
void __stdcall sub_653f40(void* p);

CNameItem::CNameItem(const char* name, int attributes, int value, int index, RefCounted* owner)
{
    sub_4536a0(&this->field7c);
    sub_653f40(this);
    this->vptr = (void*)0x79201c;
    this->field84 = index;
    if (owner) {
        if (_InterlockedExchangeAdd(&owner->refCount, -1) == 1) {
            ((void (__stdcall*)(RefCounted*))(*(void***)owner)[1])(owner);
            if (_InterlockedExchangeAdd(&owner->weakRefCount, -1) == 1) {
                ((void (__stdcall*)(RefCounted*))(*(void***)owner)[2])(owner);
            }
        }
    }
}
