// from server: 43% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct SharedPtr {
    void* px;
    long* pn;
};

struct Vec {
    void* begin;
    void* end;
    void* cap;
};

struct Selection {
    char pad[0x104];
    Vec filtered;
};

struct FilteredSelection {
    char pad0[0xec];
    Selection* rootSelection;
    SharedPtr filteredSelection;
    Vec items;
    void addFilteredSelection(FilteredSelection*);
    void removeFilteredSelection(FilteredSelection*);
    void constructor(void*);
};

extern "C" void __cdecl func_541960(FilteredSelection*, void*);
extern "C" void* __cdecl func_41eb40(void*);
extern "C" void* __cdecl func_49d670(void*, void*, void*);
extern "C" void __cdecl func_402a60(void*, void*);
extern "C" void __cdecl func_464ec0(void*, void*);
extern "C" void __cdecl func_532ba0(Selection*, void*);

void FilteredSelection::constructor(void* a)
{
    func_541960(this, a);
    if (this->rootSelection != 0)
        return;

    void* p = func_41eb40(*(void**)((char*)a + 8));
    void* tmp = 0;
    void* r = func_49d670(&tmp, p, 0);
    void* v = *(void**)r;
    r = (char*)r + 4;
    this->rootSelection = (Selection*)v;
    func_402a60(&this->filteredSelection, r);

    if (tmp != 0) {
        SharedPtr* sp = (SharedPtr*)tmp;
        if (_InterlockedExchangeAdd((volatile long*)((char*)sp->pn + 4), -1) == 1) {
            void** vt = *(void***)sp->px;
            ((void (__stdcall*)(void*))vt[1])(sp->px);
            if (_InterlockedExchangeAdd((volatile long*)((char*)sp + 8), -1) == 1) {
                void** vt2 = *(void***)sp->px;
                ((void (__stdcall*)(void*))vt2[2])(sp->px);
            }
        }
    }

    if (this->rootSelection == 0)
        return;

    Selection* sel = this->rootSelection;
    Vec* vec = (Vec*)((char*)sel + 0x104);
    void* first = vec->begin;
    void* last = vec->end;
    if (first > last)
        _invalid_parameter_noinfo();

    while (true) {
        Selection* s2 = this->rootSelection;
        Vec* v2 = (Vec*)((char*)s2 + 0x104);
        void* e2 = v2->end;
        if (v2->begin > e2)
            _invalid_parameter_noinfo();
        if (vec != v2)
            _invalid_parameter_noinfo();
        if (first == e2)
            break;
        if (first >= vec->end)
            _invalid_parameter_noinfo();
        void* item = *(void**)first;
        if (item != 0) {
            void* tmp2 = item;
            func_464ec0(&this->items, &tmp2);
        }
        if (first >= vec->end)
            _invalid_parameter_noinfo();
        first = (char*)first + 8;
    }

    func_532ba0(this->rootSelection, &this->pad0[0xe8]);
}
