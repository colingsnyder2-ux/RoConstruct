// from server: 100% by tester
struct RBX_ScriptContext {
    char pad[0x125];
    bool flag;
    void helper();
    void func(int);
};

void RBX_ScriptContext::func(int)
{
    if (flag)
        helper();
}
