// from server: 78% by atomic.potato
extern "C" int __cdecl func_0048e470(void);

struct BaseScript
{
    int f();
};

int BaseScript::f()
{
    return func_0048e470() != 0;
}
