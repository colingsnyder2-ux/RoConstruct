// from server: 34% by atomic.potato
extern "C" int __cdecl sub_411170();
extern "C" int __cdecl sub_412BC0(int);

struct S {
    int f();
};

int S::f() {
    int buf[10];
    int r = sub_411170();
    sub_412BC0(r);
    return 0;
}
