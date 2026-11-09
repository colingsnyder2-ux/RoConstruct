// from server: 100% by colin
extern "C" {
    int __cdecl _errno(void);
    char* __cdecl strerror(int errnum);
    void* __cdecl tmpfile(void);
}

extern "C" {
    int __cdecl sub_5be5b0(int a, int b);
    int __cdecl sub_5bde00(int a, int b, int c);
    int __cdecl sub_5be160(int a, int b);
    int __cdecl sub_5bdb50(int a);
    int __cdecl sub_5bdb90(int a, int b);
    int __cdecl sub_5bdc90(int a, int b, int c);
}

extern int (__cdecl *off_77e880)();
extern int (__cdecl *off_77e850)();
extern int (__cdecl *off_77e840)(int);

struct lua_exception {
};

int __cdecl func(int a)
{
    int* p;
    int err;
    int* q;

    p = (int*)sub_5be5b0(a, 4);
    *p = 0;
    sub_5bde00(a, -10000, 0x7b9944);
    sub_5be160(a, -2);

    err = off_77e880();
    *p = err;
    if (err == 0) {
        q = (int*)off_77e850();
        err = *q;
        sub_5bdb50(a);
        sub_5bdc90(a, 0x78a05c, off_77e840(err));
        sub_5bdb90(a, err);
        return 3;
    }
    return 1;
}
