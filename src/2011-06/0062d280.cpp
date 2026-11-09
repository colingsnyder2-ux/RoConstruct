// from server: 62% by atomic.potato
extern "C" int __cdecl function_0062d140();
extern "C" int function_00794ec0(int *);

struct S
{
    int value;
    int field1;
    int field2;

    S();
};

S::S()
{
    ++*(int *)0x00cca3e4;
    value = function_0062d140();
    field1 = function_00794ec0(&field1);
    field2 = 0;
}
