// from server: 100% by colin
struct S {
    int f(int);
};

extern "C" int __cdecl sub_5BDEF0(int, int*);

int S::f(int a) {
    int local = 0;
    local = *(int*)0x97DA58;
    *(int*)0x97DA58 = local + 1;
    sub_5BDEF0(a, &local);
    return a;
}
