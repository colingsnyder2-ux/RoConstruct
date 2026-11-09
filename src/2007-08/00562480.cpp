// from server: 28% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct RefCounted {
    void* vptr;
    long refCount;
};

struct Selection;

struct FilteredSelection {
    char pad[0xE8];
    void* fieldE8;
    Selection* rootSelection;
    void* filteredSelection;
    void addFilteredSelection(Selection*);
    void removeFilteredSelection(Selection*);
    void setName(const char*);
};

struct Selection {
    char pad[0x104];
    void* vecBegin;
    void* vecEnd;
    void* vecCap;
    void removeFilteredSelection(FilteredSelection*);
};

extern "C" void __stdcall sub_541960(FilteredSelection*);
extern "C" void* __stdcall sub_41EB40(void*);
extern "C" void* __stdcall sub_49D670(void*, void*, void*);
extern "C" void __stdcall sub_402A60(void*, void*);
extern "C" void __stdcall sub_532BA0(Selection*, void*);
extern "C" void __stdcall sub_5B4070(void*, void*);
extern "C" void* __stdcall sub_630D36(void*, void*, void*, void*, void*);

void FilteredSelection::addFilteredSelection(Selection* sel) {
    sub_541960(this);

    if (rootSelection != 0)
        return;

    void* a = sub_41EB40(*(void**)((char*)sel + 8));
    void* local;
    sub_49D670(&local, a, 0);

    void* v = *(void**)local;
    rootSelection = (Selection*)v;
    sub_402A60(&fieldE8, (char*)local + 4);

    if (local != 0) {
        RefCounted* rc = (RefCounted*)local;
        if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
            void** vt = (void**)rc->vptr;
            ((void (__stdcall*)(RefCounted*))vt[1])(rc);
            if (_InterlockedExchangeAdd((volatile long*)((char*)rc + 8), -1) == 1) {
                void** vt2 = (void**)rc->vptr;
                ((void (__stdcall*)(RefCounted*))vt2[2])(rc);
            }
        }
    }

    if (rootSelection == 0)
        return;

    void* vec = *(void**)((char*)rootSelection + 0x104);
    void* begin = *(void**)vec;
    void* end = *(void**)((char*)vec + 4);
    void* cap = *(void**)((char*)vec + 8);

    if (begin > end)
        _invalid_parameter_noinfo();

    while (begin != end) {
        if (begin >= cap)
            _invalid_parameter_noinfo();

        void* item = *(void**)begin;
        void* result = sub_630D36(item, (void*)0x898FC0, (void*)0x881F4C, 0, 0);
        if (result != 0) {
            void* tmp = result;
            sub_5B4070(&filteredSelection, &tmp);
        }

        if (begin >= cap)
            _invalid_parameter_noinfo();
        begin = (char*)begin + 8;
    }

    sub_532BA0(rootSelection, &fieldE8);
}
