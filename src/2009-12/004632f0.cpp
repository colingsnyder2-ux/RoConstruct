// from server: 77% by atomic.potato
extern "C" void __stdcall Function_007e7f30(double, void *, void *);

struct UserInputJob
{
    UserInputJob *f(void *, void *);
};

double g_009ae8a8;

UserInputJob *UserInputJob::f(void *value, void *arg)
{
    Function_007e7f30(g_009ae8a8, value, arg);
    return this;
}
