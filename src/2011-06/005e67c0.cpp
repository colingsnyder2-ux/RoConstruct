// from server: 84% by atomic.potato
struct Name
{
};

extern "C" Name * __cdecl getLocalScope();
extern "C" void tooManyArgs(Name *, double);

void __stdcall f(double value)
{
    tooManyArgs(getLocalScope(), value);
}
