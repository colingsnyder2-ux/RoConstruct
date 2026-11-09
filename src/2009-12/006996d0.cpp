// from server: 48% by atomic.potato
struct Inner {
    int f(int);
};

struct S {
    char pad[0x20];
    Inner* p;
    int g(int, int);
};

int S::g(int a, int b) {
    int v;
    if (a) {
        v = ((Inner*)a)->f(b);
    } else {
        v = 0;
    }
    Inner* q = p;
    int* r = &v;
    return (*(int (__thiscall**)(Inner*, int*, int))(*((int*)q) + 0x10))(q, r, b);
}
