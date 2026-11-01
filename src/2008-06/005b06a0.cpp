// from server: 100% by tester
struct RBX_ScriptContext {
    char pad[0x1ac];
    bool flag;
    void helper();
    void func(int);
};

void RBX_ScriptContext::func(int)
{
    if (flag)
        helper();
}
