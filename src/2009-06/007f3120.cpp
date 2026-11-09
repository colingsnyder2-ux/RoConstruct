// from server: 100% by tester
struct CXTPPropertyGridInplaceList {
    void f(unsigned int);
};

extern "C" void __cdecl sub_63023e();
extern "C" void __cdecl sub_682740(int);

void CXTPPropertyGridInplaceList::f(unsigned int arg) {
    sub_63023e();
    sub_682740(0);
    (*(void (__thiscall **)(void *))(*(int *)this + 0x168))(this);
    (*(void (__thiscall **)(void *))(*(int *)this + 0x68))(this);
}
