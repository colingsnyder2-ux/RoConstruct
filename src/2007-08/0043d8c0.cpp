// from server: 41% by colin
struct ContentId {
    char pad[0x114];
};

struct SoundId : ContentId {
    void* field_114;
    void* field_118;
    void* method(void* a, void* b);
};

extern "C" void __stdcall sub_439850(void* out, void* in);
extern "C" void* __stdcall sub_5BFA80(void* a, void* b, void* c);
extern "C" void __stdcall sub_5595A0(void* p);

void* SoundId::method(void* a, void* b) {
    void* local;
    void* tmp;
    void* result;
    int flag;

    tmp = 0;
    flag = 0;

    void* p = *(void**)((char*)this + 0x114);
    void* q = *(void**)((char*)p + 0x188);
    sub_439850(&local, q);

    flag = 1;

    void* arg = a;
    if (arg != 0) {
        arg = (char*)arg + 4;
    } else {
        arg = 0;
    }

    void* r = sub_5BFA80(*(void**)((char*)this + 0x118), b, arg);

    flag = 1;
    sub_5595A0(&local);

    return r;
}
