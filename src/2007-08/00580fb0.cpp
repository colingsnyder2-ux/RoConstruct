// from server: 100% by colin
struct Sub {
    void method(int a, int b);
};

struct Accoutrement {
    char pad[0x100];
    Sub sub;
    int func(int value);
};

int Accoutrement::func(int value) {
    sub.method(value, 0);
    return value;
}
