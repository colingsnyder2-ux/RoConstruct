// from server: 24% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl _invalid_parameter_noinfo();

struct RefCounted {
    void* vptr;
    long refCount;
    long weakRefCount;
};

struct String {
    char buf[16];
    unsigned int size;
    unsigned int capacity;
};

struct Vector {
    void* begin;
    void* end;
    void* cap;
};

struct DataState {
    char pad[0x104];
    Vector* selection;
};

struct Verb {
    char pad[0x14];
    DataState* getDataState(int);
};

struct DeleteSelectionVerb {
    char pad[0x20];
    void* dataModel;
    void doIt(void*);
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

void* __cdecl sub_55E290();
void* __cdecl sub_562300();
void* __cdecl sub_410D40();
void* __cdecl sub_40FC90();
void* __cdecl sub_541630();
void* __cdecl sub_55A920();
void* __cdecl sub_560380();
void* __cdecl sub_58C810();
void* __cdecl sub_410BB0();
void* __cdecl sub_4108B0();

void DeleteSelectionVerb::doIt(void* dataState)
{
    void* dm = *(void**)((char*)this + 0x20);
    sub_55E290();
    Verb* v = (Verb*)((char*)this + 0x14);
    DataState* ds = v->getDataState(1);
    Vector* sel = ds->selection;
    if (sel->begin == 0 || sel->end == sel->begin)
        return;

    void* dm2 = *(void**)((char*)this + 0x20);
    if (dm2 != 0)
        sub_410D40();

    void* obj1 = operator_new(0x2c);
    if (obj1 != 0) {
        *(void**)((char*)obj1 + 4) = (void*)0x786db0;
        *(void**)((char*)obj1 + 0x28) = (void*)0x786d0c;
        void* vt = *(void**)((char*)obj1 + 4);
        *(void**)obj1 = (void*)0x786d9c;
        void* vt2 = *(void**)((char*)vt + 4);
        *(void**)((char*)vt2 + (int)obj1 + 4) = (void*)0x786d94;
        void* g = *(void**)0x8c225c;
        *(void**)((char*)obj1 + 8) = 0;
        *(void**)((char*)obj1 + 0xc) = 0;
        *(void**)((char*)obj1 + 0x10) = 0;
        *(void**)((char*)obj1 + 0x14) = g;
        *(void**)((char*)obj1 + 0x18) = 0;
        *(void**)((char*)obj1 + 0x20) = 0;
        *(void**)((char*)obj1 + 0x24) = 0;
        void* vt3 = *(void**)((char*)obj1 + 4);
        *(void**)obj1 = (void*)0x786dac;
        void* vt4 = *(void**)((char*)vt3 + 4);
        *(void**)((char*)vt4 + (int)obj1 + 4) = (void*)0x786da4;
    }

    void* obj2 = operator_new(0x2c);
    if (obj2 != 0) {
        *(void**)((char*)obj2 + 4) = (void*)0x786db0;
        *(void**)((char*)obj2 + 0x28) = (void*)0x786d0c;
        void* vt = *(void**)((char*)obj2 + 4);
        *(void**)obj2 = (void*)0x786d9c;
        void* vt2 = *(void**)((char*)vt + 4);
        *(void**)((char*)vt2 + (int)obj2 + 4) = (void*)0x786d94;
        void* g = *(void**)0x8c225c;
        *(void**)((char*)obj2 + 8) = 0;
        *(void**)((char*)obj2 + 0xc) = 0;
        *(void**)((char*)obj2 + 0x10) = 0;
        *(void**)((char*)obj2 + 0x14) = g;
        *(void**)((char*)obj2 + 0x18) = 0;
        *(void**)((char*)obj2 + 0x20) = 0;
        *(void**)((char*)obj2 + 0x24) = 0;
        void* vt3 = *(void**)((char*)obj2 + 4);
        *(void**)obj2 = (void*)0x786dc4;
        void* vt4 = *(void**)((char*)vt3 + 4);
        *(void**)((char*)vt4 + (int)obj2 + 4) = (void*)0x786dbc;
    }

    DataState* ds2 = v->getDataState(1);
    Vector* sel2 = ds2->selection;
    void* end = sel2->end;
    if (sel2->begin > end)
        _invalid_parameter_noinfo();

    DataState* ds3 = v->getDataState(1);
    Vector* sel3 = ds3->selection;
    void* begin = sel3->begin;
    if (begin > sel3->end)
        _invalid_parameter_noinfo();

    void* tmp[4];
    tmp[0] = (void*)0x55ebb0;
    tmp[1] = begin;
    tmp[2] = end;
    tmp[3] = 0;

    sub_560380();

    void* dm3 = *(void**)((char*)this + 0x20);
    if (dm3 != 0)
        sub_55A920();
    else
        dm3 = 0;

    sub_58C810();

    if (obj1 != 0) {
        sub_410BB0();
    } else {
        sub_4108B0();
    }
}
