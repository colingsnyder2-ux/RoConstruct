// from server: 28% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
};

struct SharedPtr {
    void* ptr;
    RefCounted* control;
};

struct Selection {
    void* vptr;
    SharedPtr rootSelection;
    void* filteredBegin;
    void* filteredEnd;
    void* filteredCap;
};

struct FilteredSelection {
    void* vptr;
    SharedPtr rootSelection;
    void* filteredBegin;
    void* filteredEnd;
    void* filteredCap;
    void __cdecl assign(SharedPtr* first, SharedPtr* last);
};

void __cdecl sub_560840(SharedPtr* dst, SharedPtr* src);
void __cdecl sub_55FBD0(void* p);

void FilteredSelection::assign(SharedPtr* first, SharedPtr* last)
{
    SharedPtr* it = first;
    while (it != last) {
        SharedPtr tmp;
        tmp.ptr = it->ptr;
        tmp.control = it->control;
        if (tmp.control != 0) {
            _InterlockedExchangeAdd(&tmp.control->refcount, 1);
        }
        sub_560840((SharedPtr*)&this->filteredBegin, &tmp);
        it++;
    }
    this->rootSelection.ptr = first->ptr;
    this->rootSelection.control = first->control;
    this->filteredBegin = 0;
    this->filteredEnd = 0;
    sub_55FBD0(&this->filteredBegin);
}
