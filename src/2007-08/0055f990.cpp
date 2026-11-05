// from server: 20% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct SharedPtr {
    void* px;
    long* pi;
};

struct Vec {
    void* begin;
    void* end;
    void* cap;
};

struct FilteredSelection {
    char pad[0x104];
    Vec* filteredSelection;
    SharedPtr back();
};

SharedPtr FilteredSelection::back()
{
    SharedPtr result;
    Vec* v = this->filteredSelection;
    void* b = v->begin;
    if (b != 0 && (char*)v->end - (char*)b != 0) {
        void* e = v->end;
        if (b > e)
            _invalid_parameter_noinfo();
        void* p = (char*)e - 8;
        if (p > v->end || p < v->begin)
            _invalid_parameter_noinfo();
        void* q = (char*)e - 8;
        if (q >= v->end)
            _invalid_parameter_noinfo();
        result.px = q;
        result.pi = 0;
        if (result.pi)
            _InterlockedExchangeAdd(result.pi + 1, 1);
        return result;
    }
    result.px = 0;
    result.pi = 0;
    return result;
}
