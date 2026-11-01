// from server: 100% by colin
struct Inner {
    char pad[0x34];
    int value;
};

struct Outer {
    char pad[0xa8];
    Inner* ptr;
    int func();
};

int Outer::func() {
    return ptr->value != 0;
}
