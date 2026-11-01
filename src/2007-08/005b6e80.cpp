// from server: 100% by colin
struct DescribedBase {
    void* vtable;
};

struct GetSet {
    void* vtable;
    void* get;
    void* set;
};

struct SurfaceGetSet : GetSet {
    void setValue(DescribedBase* instance) const;
};

extern "C" void* __fastcall sub_573890(void* p);

void SurfaceGetSet::setValue(DescribedBase* instance) const
{
    void* p;
    if (instance != 0) {
        p = sub_573890((char*)instance - 4);
    } else {
        p = sub_573890(0);
    }
    void* fn = *(void**)((char*)this + 4);
    ((void (__fastcall*)(void*))fn)((char*)p + 8);
}
