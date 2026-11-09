// from server: 100% by tajop
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

extern "C" void* __cdecl malloc(unsigned int);

struct CSelectionTreeCtrl {
    void* field_0;
    void* field_4;
    void* field_8;
    void* field_c;
    void* field_10;
    char field_14;
    char field_15;
};

CSelectionTreeCtrl* __stdcall sub_421090(void* a, void* b, void* c, void* d, char e)
{
    CSelectionTreeCtrl* p = (CSelectionTreeCtrl*)malloc(0x18);
    if (p != 0)
    {
        p->field_0 = a;
        p->field_4 = b;
        p->field_8 = c;
        p->field_c = *(void**)d;
        void* ref = *(void**)((char*)d + 4);
        p->field_10 = ref;
        if (ref != 0)
        {
            _InterlockedIncrement((volatile long*)((char*)ref + 4));
        }
        p->field_14 = e;
        p->field_15 = 0;
    }
    return p;
}

