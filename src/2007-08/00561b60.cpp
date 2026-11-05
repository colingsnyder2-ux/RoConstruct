// from server: 42% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl _invalid_parameter_noinfo();

struct Instance {
    void* vfptr;
    int refCount;
    void AddRef();
    void Release();
};

struct Selection {
    void removeFilteredSelection(void*);
};

struct FilteredSelection {
    char pad[0xE8];
    void* fieldE8;
    Selection* rootSelection;
    void* fieldF0;
    void* fieldF4;

    void constructor(Instance* inst);
};

extern "C" void __stdcall sub_541960(Instance*);
extern "C" void* __cdecl sub_41EB40(int);
extern "C" void* __cdecl sub_49D670(void*, void*, int);
extern "C" void __stdcall sub_402A60(void*, void*);
extern "C" void __stdcall sub_532BA0(Selection*, void*);
extern "C" void __stdcall sub_5B4070(void*, void**);
extern "C" void* __cdecl sub_630D36(void*, void*, void*, int, int);

void FilteredSelection::constructor(Instance* inst)
{
    sub_541960(inst);

    if (this->rootSelection != 0)
        return;

    void* p = sub_41EB40(*(int*)((char*)inst + 8));
    void* tmp;
    void* r = sub_49D670(&tmp, p, 0);
    int val = *(int*)r;
    r = (char*)r + 4;
    sub_402A60(&this->fieldF0, r);
    this->rootSelection = (Selection*)val;

    if (tmp != 0) {
        Instance* obj = (Instance*)tmp;
        if (_InterlockedExchangeAdd((volatile long*)((char*)obj + 4), -1) == 1) {
            void** vt = *(void***)obj;
            ((void (__thiscall*)(Instance*))vt[1])(obj);
            if (_InterlockedExchangeAdd((volatile long*)((char*)obj + 8), -1) == 1) {
                void** vt2 = *(void***)obj;
                ((void (__thiscall*)(Instance*))vt2[2])(obj);
            }
        }
    }

    if (this->rootSelection == 0)
        return;

    void* vec = *(void**)((char*)this->rootSelection + 0x104);
    int* begin = *(int**)((char*)vec + 4);
    int* end = *(int**)((char*)vec + 8);
    void* savedVec = vec;

    if ((unsigned)begin > (unsigned)end)
        _invalid_parameter_noinfo();

    while (true) {
        void* vec2 = *(void**)((char*)this->rootSelection + 0x104);
        int* end2 = *(int**)((char*)vec2 + 8);
        if (*(int**)((char*)vec2 + 4) > end2)
            _invalid_parameter_noinfo();

        if (savedVec != vec2)
            _invalid_parameter_noinfo();

        if (begin == end2)
            break;

        if ((unsigned)begin >= *(unsigned*)((char*)savedVec + 8))
            _invalid_parameter_noinfo();

        void* item = sub_630D36((void*)*begin, (void*)0x881f4c, (void*)0x88c6b8, 0, 0);
        if (item != 0) {
            void* tmp2 = item;
            sub_5B4070(&this->fieldF4, &tmp2);
        }

        if ((unsigned)begin >= *(unsigned*)((char*)savedVec + 8))
            _invalid_parameter_noinfo();

        begin += 2;
    }

    sub_532BA0(this->rootSelection, &this->fieldE8);
}
