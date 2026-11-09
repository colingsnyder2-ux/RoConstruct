// from server: 30% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct Instance {
    void* vptr;
    int refcount;
};

struct SharedPtr {
    Instance* ptr;
    void addref() {
        if (ptr) {
            _InterlockedExchangeAdd((volatile long*)&ptr->refcount, 1);
        }
    }
};

struct SelectionChanged {
    SharedPtr addedItem;
    SharedPtr removedItem;
};

struct FilteredListener {
    void* vptr;
    Instance** begin;
    Instance** end;
    Instance** capacity;

    bool invoke(Instance* inst, SelectionChanged* changed);
    void remove(Instance* inst);
};

struct VSelection {
    void* vptr;
    Instance** begin;
    Instance** end;
    Instance** capacity;

    void removeFiltered(FilteredListener* listener);
};

void __stdcall destroySelectionChanged(SelectionChanged* changed);
void __stdcall destroySharedPtr(SharedPtr* ptr);

bool FilteredListener::invoke(Instance* inst, SelectionChanged* changed) {
    Instance** it = begin;
    Instance** last = end;

    if (it > last) {
        _invalid_parameter_noinfo();
    }

    Instance** cap = capacity;
    if (end > cap) {
        _invalid_parameter_noinfo();
    }

    if (it != 0) {
        _invalid_parameter_noinfo();
    }

    if (it != last) {
        SharedPtr sp;
        sp.ptr = changed->addedItem.ptr;
        sp.addref();
        SharedPtr sp2;
        sp2.ptr = changed->removedItem.ptr;
        sp2.addref();
        ((VSelection*)this)->removeFiltered(this);
        destroySelectionChanged(changed);
        return false;
    }

    while (it != last) {
        if (it >= end) {
            _invalid_parameter_noinfo();
        }

        Instance* item = *it;
        void** vtbl = *(void***)item;
        typedef bool (__thiscall *Fn)(void*, Instance*, SelectionChanged*);
        Fn fn = (Fn)vtbl[4];
        if (fn(item, inst, changed)) {
            if (it >= end) {
                _invalid_parameter_noinfo();
            }
            Instance* item2 = *it;
            if (item2->refcount == (int)inst) {
                break;
            }
            if (it >= end) {
                _invalid_parameter_noinfo();
            }
            Instance* item3 = *it;
            destroySharedPtr((SharedPtr*)item3);
            destroySelectionChanged(changed);
            return false;
        }
        if (it >= end) {
            _invalid_parameter_noinfo();
        }
        it++;
    }

    destroySelectionChanged(changed);
    return false;
}
