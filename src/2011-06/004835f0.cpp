// from server: 62% by atomic.potato
struct VerbBinder
{
    char pad[452];
    int field_1c4;
    void f();
};

extern "C" void __cdecl Function_00483450(int, int);

void VerbBinder::f()
{
    Function_00483450(field_1c4 == 0, 1);
}
