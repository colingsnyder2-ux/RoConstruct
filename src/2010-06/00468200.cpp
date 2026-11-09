// from server: 74% by atomic.potato
extern "C" void __stdcall sub_79BDD0(double, int, int);

struct UserInputJob
{
    UserInputJob* f(int, int);
};

extern double const g_00A0F7A0;

UserInputJob* UserInputJob::f(int a, int b)
{
    sub_79BDD0(g_00A0F7A0, b, a);
    return this;
}
