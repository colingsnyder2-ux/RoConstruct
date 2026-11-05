// from server: 58% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RbxMeshPartAdapter {
    void* vtable;
    int field4;
    int field8;
    float fieldC;
    void* field10;
    void* field14;
    void* field18;
    void* field1C;
    void construct(int, void*, void*);
};

void RbxMeshPartAdapter::construct(int a, void* b, void* c) {
    this->vtable = (void*)0xa8a1b8;
    this->field4 = a;
    this->field8 = 0;
    this->fieldC = 0.0f;
    this->field10 = *(void**)b;
    this->field14 = *(void**)((char*)b + 4);
    if (this->field14 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)this->field14 + 4), 1);
    }
    this->field18 = *(void**)c;
    this->field1C = *(void**)((char*)c + 4);
    if (this->field1C != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)this->field1C + 4), 1);
    }
}
