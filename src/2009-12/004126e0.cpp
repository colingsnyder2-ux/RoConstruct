// from server: 37% by atomic.potato
extern "C" int __cdecl sub_411CD0(int);
extern "C" int __cdecl sub_412620(int, int);
extern "C" int __cdecl sub_7F4878(int, int);

struct S {
    int f(int);
};

int S::f(int a) {
    int buf[32];
    int tmp;
    sub_411CD0(a);
    sub_412620((int)&tmp, (int)buf);
    sub_7F4878((int)&buf[0], 0xa90ef0);
    return 0;
}
