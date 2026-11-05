// from server: 77% by atomic.potato
extern "C" void __cdecl func_00854a90();

struct S
{
    int f();
    int field_0c;
};

int S::f()
{
    int a = *(int *)((char *)field_0c + 0xA90);
    int b = *(int *)((char *)a + 0x140);
    int c = *(int *)((char *)b + 0xD0);
    func_00854a90();
    return c;
}
