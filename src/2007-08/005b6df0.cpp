// from server: 100% by colin
struct SurfaceGetSet {
    void* get;
    void* set;
    void invoke(void* instance);
};

extern "C" void* __fastcall sub_573890(void* p);

void SurfaceGetSet::invoke(void* instance)
{
    void* obj;
    if (instance != 0) {
        obj = sub_573890((char*)instance - 4);
    } else {
        obj = sub_573890(0);
    }
    void* fn = this->set;
    ((void (__fastcall*)(void*))fn)(obj);
}
