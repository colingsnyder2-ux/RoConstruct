// from server: 23% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct SharedPtr {
    void* px;
    void* pi;
};

struct RefCountBase {
    void* vfptr;
    long refcount;
};

struct Selection;

struct FilteredSelection {
    char pad[8];
    SharedPtr rootSelection;
    char pad2[8];
    void* filteredSelectionBegin;
    void* filteredSelectionEnd;
    void* filteredSelectionCap;

    bool contains(Selection* sel);
};

struct Selection {
    char pad[8];
    void* begin;
    void* end;
    void* cap;

    void removeFilteredSelection(FilteredSelection* fs);
};

struct Iterator {
    void* first;
    void* second;
};

extern "C" void* __cdecl sub_5BFAB0(void*, void*);
extern "C" int __cdecl sub_630D36(void*, void*, void*, void*, void*);
extern "C" char __cdecl sub_4A7E00(void*, void*);
extern "C" void __cdecl sub_492360(void*);

extern void* __stdcall sub_77E6D8();

bool FilteredSelection::contains(Selection* sel) {
    Iterator it;
    void* p = sub_5BFAB0((char*)sel + 8, &it);
    void* ebp = *(void**)p;
    void* esp1c = *(void**)((char*)p + 4);

    void* eax = *(void**)((char*)this + 0x10);
    void* ebx = *(void**)((char*)eax + 0x10);
    void* esi = (char*)eax + 8;
    if (*(unsigned int*)((char*)eax + 0xc) > (unsigned int)ebx) {
        sub_77E6D8();
    }

    if (ebp != 0 && ebp == esi) {
        sub_77E6D8();
    } else {
        sub_77E6D8();
    }

    if (esp1c == ebx) {
        goto cleanup;
    }

    if (ebp == 0) {
        sub_77E6D8();
    }
    if ((unsigned int)esp1c < *(unsigned int*)((char*)ebp + 8)) {
        sub_77E6D8();
    }

    {
        void* edx = esp1c;
        void* eax2 = *(void**)edx;
        int r = sub_630D36(eax2, 0, (void*)0x887174, (void*)0x887e68, 0);
        if (r == 0) {
            goto cleanup;
        }
    }

    {
        void* ebx2 = esp1c;
        if ((unsigned int)ebx2 < *(unsigned int*)((char*)ebp + 8)) {
            sub_77E6D8();
        }
        void* eax3 = *(void**)ebx2;
        Iterator it2;
        it2.first = eax3;
        it2.second = (char*)this + 4;
        char al = sub_4A7E00(&it2, (char*)this + 0x34);
        if (al == 0) {
            goto cleanup;
        }
    }

    sub_492360((char*)this + 0x34);
    return true;

cleanup:
    {
        void* esi2 = *(void**)((char*)this + 0x38);
        if (esi2 != 0) {
            long old = _InterlockedExchangeAdd((volatile long*)((char*)esi2 + 4), -1);
            if (old == 1) {
                void** vt = *(void***)esi2;
                void (*fn)(void*) = (void (*)(void*))vt[1];
                fn(esi2);
                long old2 = _InterlockedExchangeAdd((volatile long*)((char*)esi2 + 8), -1);
                if (old2 == 1) {
                    void** vt2 = *(void***)esi2;
                    void (*fn2)(void*) = (void (*)(void*))vt2[2];
                    fn2(esi2);
                }
            }
        }
    }
    return false;
}
