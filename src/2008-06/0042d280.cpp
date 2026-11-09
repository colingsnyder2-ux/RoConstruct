// from server: 100% by king_originala
extern "C" int __cdecl sub_56cbc0();
extern "C" void* __cdecl sub_6a0920(unsigned int);
extern const int holder_vtable[];

struct Holder {
    int field0;
    void* field4;
    Holder* init(void* arg);
};

Holder* Holder::init(void* arg) {
    field0 = sub_56cbc0();
    void* p = sub_6a0920(8);
    if (p != 0) {
        *(const int**)p = holder_vtable;
        *(int*)((char*)p + 4) = *(int*)arg;
    } else {
        p = 0;
    }
    field4 = p;
    return this;
}
