// from server: 43% by colin
// roc 2007-08 004890e0  unit: P8CRenderSettings::?$GetSetImpl  size: 196 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004890e0

struct S {
    char pad[0x74];
    void f(int);
};

extern "C" void __cdecl sub_42ae50();
extern "C" void __cdecl sub_728a70();
extern "C" void __cdecl sub_728b10();
extern "C" void __cdecl sub_728f10();

void S::f(int a) {
    char buf[0x74];
    sub_728f10();
    sub_42ae50();
    sub_728a70();
    sub_728f10();
    sub_728a70();
    sub_728f10();
    sub_728f10();
    sub_728f10();
    sub_728f10();
    sub_42ae50();
    sub_728a70();
    sub_728f10();
    sub_728a70();
    sub_728b10();
}
