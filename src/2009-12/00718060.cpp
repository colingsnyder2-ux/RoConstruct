// from server: 30% by atomic.potato
struct Name {
    char pad0[0x94];
    void* field94;
};

struct Base {
    void sub_716fd0(void* arg);
};

struct VWeld : Base {
    void* field0;
    void* field4;
    char pad8[0x10];
    void* field18;
};

extern "C" void* __cdecl sub_7f3860(unsigned int size);
extern "C" void __cdecl sub_541d30(void* a, void* b, void* c);

struct JointsService {
    void __cdecl sub_718060(void* arg);
};

void JointsService::sub_718060(void* arg) {
    void* p = sub_7f3860(0xb8);
    void* q = 0;
    if (p) {
        ((Base*)p)->sub_716fd0(arg);
        q = p;
    }
    sub_541d30(this, q, 0);
}
