// from server: 83% by atomic.potato
struct BasicString
{
    char data[16];
};

extern "C" BasicString &assign_string(BasicString *, const BasicString *);

struct S
{
};

S *const g_object = (S *)0x00b91688;

void __cdecl f(const BasicString &value)
{
    assign_string((BasicString *)g_object, &value);
}
