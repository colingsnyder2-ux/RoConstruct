// from server: 67% by atomic.potato
typedef void *Ptr;

extern "C" int __cdecl Function006AA690();

struct ScriptContext
{
    Ptr value;
    int field4;
    ScriptContext();
};

ScriptContext::ScriptContext()
{
    ++*(volatile int *)0x00B8FD60;
    value = (Ptr)Function006AA690();
    field4 = 0;
}
