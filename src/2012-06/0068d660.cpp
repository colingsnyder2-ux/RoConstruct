// from server: 45% by atomic.potato
struct VModelInstance {
    char pad[0x1c];
    void* field_1c;
    void Init(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

extern "C" void* __stdcall sub_7092A0();
extern "C" void* __stdcall sub_6C1590();
extern "C" void* __stdcall sub_67F2E0(void*, void*, void*);
extern "C" void __stdcall sub_709480(void*, void*);

void VModelInstance::Init(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)
{
    void* p;
    void* q;
    void* r;
    void* s;

    field_1c = sub_7092A0();
    p = sub_6C1590();
    sub_67F2E0(&s, p, &q);
    sub_709480(&field_1c, s);
    if (q) {
        void (__stdcall *fn)(void*) = *(void (__stdcall **)(void*))((char*)q + 4);
        fn(&r);
    }
}
