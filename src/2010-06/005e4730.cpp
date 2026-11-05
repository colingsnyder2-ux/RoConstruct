// from server: 61% by colin
struct Verb {
    char pad[0x8];
    void* container;
    virtual void doIt(void*);
};

struct CameraVerb : Verb {
    void doIt(void* dataState);
};

extern "C" void* __stdcall sub_5e39f0(void* container, int id);
extern "C" void __fastcall sub_628bc0(void* p);

void CameraVerb::doIt(void* dataState) {
    void* p = sub_5e39f0(this->container, 0xb);
    sub_628bc0(p);
    void* v = *(void**)dataState;
    void (*fn)(void*) = *(void (**)(void*))v;
    fn(dataState);
}
