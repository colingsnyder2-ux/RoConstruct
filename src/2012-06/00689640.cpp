// from server: 73% by atomic.potato
struct S {
    char pad0[4];
    bool f(int);
};

extern "C" int* __cdecl sub_67F5B0(int*);
extern "C" bool __fastcall sub_76BEB0(void*, int, int*);
extern "C" void __fastcall sub_76A190(void*, int, int*);

bool S::f(int arg) {
    int local;
    int* p = sub_67F5B0(&local);
    if (sub_76BEB0(this, 0, p)) {
        sub_76A190(this, 0, &local);
        return true;
    }
    return false;
}
