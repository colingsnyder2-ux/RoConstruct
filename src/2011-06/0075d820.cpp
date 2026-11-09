// from server: 23% by atomic.potato
struct Sub1 {
    char pad[0x20];
    void f1();
};

struct Sub2 {
    char pad[0x38];
    void* ptr;
    void f2();
};

struct Inner {
    char pad[0x4];
    void* ptr;
};

struct Arg {
    char pad[0x4];
    Inner* inner;
};

struct Outer {
    char pad[0x20];
    Sub1 sub1;
    char pad2[0x18];
    void* field3c;
    Sub2 sub2;

    void method(Arg* arg);
};

extern "C" void __stdcall func_75c610(void*, void*, void*, void*, void*, void*, void*);
extern "C" void __stdcall func_75c810(void*, void*, void*, void*, void*, void*, void*);
extern "C" void __stdcall func_4287e0(void*, void*, void*);
extern "C" void __stdcall func_75cce0(void*, void*);

void Outer::method(Arg* arg) {
    sub1.f1();
    void* v1 = field3c;
    void* v2 = arg->inner->ptr;
    char flag = 0;
    func_75c610(&flag, v1, v2, 0, 0, 0, 0);
    sub1.f1();
    void* v3 = field3c;
    void* v4 = arg->inner->ptr;
    func_75c810(&flag, v3, v4, 0, 0, 0, 0);
    if (&sub2 != (Sub2*)arg) {
        void* v5 = sub2.ptr;
        func_4287e0(&flag, v5, v5);
        sub2.f2();
    }
}
