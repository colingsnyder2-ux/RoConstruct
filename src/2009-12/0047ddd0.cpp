// from server: 62% by atomic.potato
extern "C" void __cdecl func_006bbf50(int *, int);

struct S
{
    S();
};

int g_00b7cb7c;

S::S()
{
    int value = g_00b7cb7c;
    g_00b7cb7c = value + 1;
    func_006bbf50(&value, 0);
}
