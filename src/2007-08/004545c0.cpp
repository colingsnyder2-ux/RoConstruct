// from server: 29% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCountedBase {
    void* vptr;
    long refCount;
};

struct EventData {
    void* vptr;
    void* field_4;
    RefCountedBase* field_8;
    void* field_c;
    RefCountedBase* field_14;

    void destroy();
};

extern "C" void __cdecl sub_437B80(void*);

void EventData::destroy()
{
    this->vptr = (void*)0x7921f0;
    if (this->field_c) {
        sub_437B80(this);
    }
    if (this->field_14) {
        if (_InterlockedExchangeAdd(&this->field_14->refCount, -1) == 1) {
            void** vt = *(void***)this->field_14;
            ((void(__thiscall*)(RefCountedBase*))vt[1])(this->field_14);
            if (_InterlockedExchangeAdd(&this->field_14->refCount, -1) == 1) {
                void** vt2 = *(void***)this->field_14;
                ((void(__thiscall*)(RefCountedBase*))vt2[2])(this->field_14);
            }
        }
    }
    if (this->field_8) {
        if (_InterlockedExchangeAdd(&this->field_8->refCount, -1) == 1) {
            void** vt = *(void***)this->field_8;
            ((void(__thiscall*)(RefCountedBase*))vt[1])(this->field_8);
            if (_InterlockedExchangeAdd(&this->field_8->refCount, -1) == 1) {
                void** vt2 = *(void***)this->field_8;
                ((void(__thiscall*)(RefCountedBase*))vt2[2])(this->field_8);
            }
        }
    }
    this->vptr = (void*)0x787f68;
}
