// from server: 100% by colin
struct VerbContainer;

struct Verb {
    void* vtable;
    VerbContainer* container;
    int field_8;
    void* field_c;
};

extern "C" void __stdcall func_0057c3e0(void* p, void* result);

struct TToolVerb {
    void doIt(void* dataState);
};

void TToolVerb::doIt(void* dataState)
{
    Verb* verb = (Verb*)this;
    void* obj = verb->field_c;
    void* p = *(void**)((char*)obj + 0x188);
    void* fn = *(void**)((char*)verb->vtable + 0x14);
    typedef void* (__thiscall *Fn)(void*);
    void* result = ((Fn)fn)(verb);
    ((void (__thiscall*)(void*, void*))func_0057c3e0)(p, result);
}
