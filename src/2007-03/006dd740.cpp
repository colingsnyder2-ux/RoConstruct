// from server: 100% by colin
struct S {
    void f();
};

extern "C" __declspec(dllimport) void __stdcall MessageBeep(unsigned int);

void S::f() {
    MessageBeep(0xFFFFFFFF);
}
