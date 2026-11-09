// from server: 49% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl _invalid_parameter_noinfo();

struct RefCounted {
    char pad[4];
    long refCount;
    long weakRefCount;
};

struct Selection {
    char pad[0x104];
    unsigned int begin;
    unsigned int end;
};

struct DataState {
    char pad[0x0c];
    void* something;
};

struct GroupSelectionVerb {
    char pad[0x20];
    void* dataModel;
    void doIt(DataState* dataState);
};

extern "C" void __cdecl sub_55E290();
extern "C" void* __cdecl sub_410D40();
extern "C" void __cdecl sub_533250(void*, void*);
extern "C" void* __cdecl sub_55A920();
extern "C" void* __cdecl sub_5601B0(void*, void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_58C810(void*, int);
extern "C" void __cdecl sub_4108B0(void*, int);

void GroupSelectionVerb::doIt(DataState* dataState)
{
    void* dm = this->dataModel;
    sub_55E290();

    RefCounted* rc;
    if (this->dataModel != 0) {
        rc = (RefCounted*)sub_410D40();
    } else {
        rc = 0;
    }

    Selection* sel = (Selection*)((char*)rc + 0x104);
    unsigned int end = sel->end;
    if (sel->begin > end) {
        _invalid_parameter_noinfo();
    }

    Selection* sel2 = (Selection*)((char*)rc + 0x104);
    unsigned int begin = sel2->begin;
    if (begin > sel2->end) {
        _invalid_parameter_noinfo();
    }

    void* result;
    void* item = *(void**)sub_5601B0(sel2, (void*)begin, sel2, (void*)end, dataState, &result);

    if (rc != 0) {
        if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
            void** vt = *(void***)rc;
            ((void (__thiscall*)(RefCounted*))vt[1])(rc);
            if (_InterlockedExchangeAdd(&rc->weakRefCount, -1) == 1) {
                void** vt2 = *(void***)rc;
                ((void (__thiscall*)(RefCounted*))vt2[2])(rc);
            }
        }
    }

    sub_533250(this, item);

    void* dm2 = this->dataModel;
    void* r;
    if (dm2 != 0) {
        r = sub_55A920();
    } else {
        r = 0;
    }

    sub_58C810(r, 8);

    sub_4108B0(dataState, -1);

    void** vt = *(void***)dataState;
    void (*fn)(void*, int) = (void (*)(void*, int))vt[1];
    *(int*)((char*)dataState + 4) = -1;
    fn(dataState, 1);
}
