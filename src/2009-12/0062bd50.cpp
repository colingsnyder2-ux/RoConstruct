// from server: 100% by atomic.potato
typedef double real64;

extern real64 g_value;

void __stdcall f(real64 value)
{
    g_value = value;
}
