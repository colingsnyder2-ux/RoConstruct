// from server: 63% by atomic.potato
struct Inner {
    int a;
    int b;
};

struct Outer {
    char pad0[4];
    char* p;
};

struct S {
    char pad0[4];
    Outer* f4;
    int method(int, Inner*);
};

extern "C" int __stdcall sub_534E00(char*, int*);

int S::method(int arg, Inner* out) {
    int tmp[2];
    sub_534E00((char*)f4 + 0x3c, tmp);
    out->a = (int)this;
    out->b = tmp[0];
    *(int*)((char*)out + 8) = tmp[1];
    return arg;
}
