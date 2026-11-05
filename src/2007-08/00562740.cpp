// from server: 6% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct RefCounted {
    long refCount;
    long weakRefCount;
    virtual void onZeroRefCount();
    virtual void onZeroWeakRefCount();
};

struct SelectionItem {
    void* instance;
};

struct SelectionList {
    SelectionItem* begin;
    SelectionItem* end;
    SelectionItem* capacity;
};

struct DataState {
    char pad[0xec];
    void* selection;
};

struct Verb {
    char pad[0x20];
    void* dataModel;
};

struct UngroupSelectionVerb {
    char pad[0x20];
    void* dataModel;
    void doIt(DataState* dataState);
};

extern "C" void __cdecl sub_55E290(void*);
extern "C" void* __cdecl sub_5619D0(void*);
extern "C" void __cdecl sub_41E0F0(void*, void*);
extern "C" void __cdecl sub_424410(void*, void*);
extern "C" void __cdecl sub_560C00(void*, void*);
extern "C" void __cdecl sub_41DCF0(void*, void*, void*, void*, void*);
extern "C" void* __cdecl sub_55A920(void*);
extern "C" void __cdecl sub_58C810(void*, int);
extern "C" void __cdecl sub_4108B0(void*, int);
extern "C" void __cdecl sub_62FC62(void*);
extern "C" void __cdecl sub_40DB50(void*, void*, void*, void*);

void UngroupSelectionVerb::doIt(DataState* dataState)
{
    void* dm = this->dataModel;
    sub_55E290(dm);

    void* sel = 0;
    if (this->dataModel != 0) {
        sel = sub_5619D0(this->dataModel);
    }

    SelectionList list;
    list.begin = 0;
    list.end = 0;
    list.capacity = 0;

    DataState* ds = dataState;
    SelectionList* src = (SelectionList*)((char*)ds + 0xf4);

    SelectionItem* it = src->begin;
    SelectionItem* end = src->end;

    while (it != end) {
        void* inst = it->instance;
        void* tmp = 0;
        sub_41E0F0((char*)inst + 0xa4, &tmp);
        sub_424410(&list, &tmp);

        if (tmp != 0) {
            RefCounted* rc = (RefCounted*)tmp;
            if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
                rc->onZeroRefCount();
                if (_InterlockedExchangeAdd(&rc->weakRefCount, -1) == 1) {
                    rc->onZeroWeakRefCount();
                }
            }
        }
        it++;
    }

    SelectionList outList;
    outList.begin = 0;
    outList.end = 0;
    outList.capacity = 0;

    bool changed = false;
    SelectionItem* oit = list.begin;
    SelectionItem* oend = list.end;
    while (oit != oend) {
        sub_560C00(&outList, oit);
        oit++;
    }

    if (changed) {
        void* selObj = *(void**)((char*)sel + 0xec);
        sub_41DCF0(selObj, &outList, outList.begin, outList.end, outList.end);
    }

    if (this->dataModel != 0) {
        void* v = sub_55A920(this->dataModel);
        sub_58C810(v, 8);
    } else {
        sub_58C810(0, 8);
    }

    if (list.begin != 0) {
        sub_62FC62(list.begin);
    }

    if (outList.begin != 0) {
        sub_40DB50(outList.begin, outList.end, outList.capacity, outList.end);
        sub_62FC62(outList.begin);
    }
}
