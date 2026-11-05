// from server: 42% by atomic.potato
struct FloorWire {
    char pad0[0x1c];
    void* field1c;
    void construct(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

extern "C" void* __cdecl sub_6c16e0();
extern "C" void* __cdecl sub_67f2e0(void*, void*, void*);
extern "C" void __cdecl sub_709480();

void FloorWire::construct(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)
{
    void* p1 = sub_6c16e0();
    field1c = p1;
    void* p2 = sub_6c16e0();
    void* local = 0;
    void* tmp = 0;
    sub_67f2e0(&tmp, p2, &local);
    sub_709480();
    if (local) {
        void (*fn)(void*) = *(void (**)(void*))((char*)local + 4);
        fn(&local);
    }
}
