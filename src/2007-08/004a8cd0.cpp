// from server: 55% by tester
struct FactoryProduct {
    void construct();
};

extern "C" void __cdecl sub_4A0640(void*, void*);
extern "C" void __cdecl sub_4A8100(void*);

void FactoryProduct::construct() {
    void* local;
    sub_4A0640(*(void**)((char*)this + 8), &local);
    sub_4A8100(&local);
}
