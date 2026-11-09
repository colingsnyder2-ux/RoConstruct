// from server: 76% by atomic.potato
extern "C" void __cdecl sub_7e20e0(void *, const char *);
extern "C" void __cdecl sub_7f4878(void *, const char *);

void f(const char *arg)
{
    char buffer[40];
    sub_7e20e0(buffer, "Enums cannot be modified");
    sub_7f4878(buffer, "L$8PQ");
}
