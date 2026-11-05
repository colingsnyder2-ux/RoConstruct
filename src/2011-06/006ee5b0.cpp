// from server: 47% by atomic.potato
struct String {
    char pad[0x1c];
    String();
    String(const String&);
    ~String();
};

struct Widget {
    char pad0[0x10];
    char pad1[0x10];
    int check(const String&);
};

struct Prop {
    char pad0[0x1c];
    void* field1c;
    int f(int, String*);
};

extern "C" {
    void* __stdcall sub_592ce0();
    void* __stdcall sub_a404bc(void*);
    void* __stdcall sub_a404c8(void*, const String*);
    void* __stdcall sub_a404d0(void*);
}

int Prop::f(int a, String* b)
{
    if (((Widget*)a)->check(*b))
        return 0;

    String s;
    sub_a404bc(&s);

    void* g = sub_592ce0();

    if (((Widget*)((char*)a + 0x10))->check(s)) {
        String s2;
        sub_a404c8(&s2, &s);
        void* p = field1c;
        void** vt = *(void***)p;
        void (*fn)(void*, int, String*) = (void (*)(void*, int, String*))vt[3];
        fn(p, a, &s2);
        sub_a404d0(&s2);
    }
    sub_a404d0(&s);
    return 0;
}
