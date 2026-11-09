// from server: 38% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refCount;
    long weakRefCount;
};

struct Vector {
    void* begin;
    void* end;
    void* capacity;
};

struct DataModel {
    char pad[0x104];
    Vector* children;
};

struct JoinCommand {
    char pad[0xc];
    void* dataModel;
    void doIt(void* dataState);
};

extern "C" void __cdecl sub_55E290();
extern "C" void* __cdecl sub_410D40(void*);
extern "C" void __cdecl sub_40FC90(void*, void*);
extern "C" void __cdecl sub_55F990(void*, void*);
extern "C" void __cdecl sub_5DD730(void*, void*);

void JoinCommand::doIt(void* dataState)
{
    void* dm = this->dataModel;
    sub_55E290();
    void* obj;
    if (this->dataModel != 0) {
        obj = sub_410D40(this->dataModel);
    } else {
        obj = 0;
    }
    DataModel* model = (DataModel*)obj;
    Vector* vec = model->children;
    if (vec->begin != 0) {
        int count = ((char*)vec->end - (char*)vec->begin) >> 3;
        if (count == 2) {
            void* a = 0;
            void* b = 0;
            sub_40FC90(obj, &a);
            sub_55F990(obj, &b);
            sub_5DD730(a, b);
            RefCounted* rc = (RefCounted*)a;
            if (rc != 0) {
                if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
                    void** vt = (void**)rc->vptr;
                    ((void (__thiscall*)(RefCounted*))vt[1])(rc);
                    if (_InterlockedExchangeAdd(&rc->weakRefCount, -1) == 1) {
                        void** vt2 = (void**)rc->vptr;
                        ((void (__thiscall*)(RefCounted*))vt2[2])(rc);
                    }
                }
            }
            RefCounted* rc2 = (RefCounted*)b;
            if (rc2 != 0) {
                if (_InterlockedExchangeAdd(&rc2->refCount, -1) == 1) {
                    void** vt = (void**)rc2->vptr;
                    ((void (__thiscall*)(RefCounted*))vt[1])(rc2);
                    if (_InterlockedExchangeAdd(&rc2->weakRefCount, -1) == 1) {
                        void** vt2 = (void**)rc2->vptr;
                        ((void (__thiscall*)(RefCounted*))vt2[2])(rc2);
                    }
                }
            }
        }
    }
}
