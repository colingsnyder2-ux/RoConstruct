// from server: 100% by colin
struct RBX_ScriptContext {
    char pad[0x144];
    bool flag;
    void helper();
    void func(int);
};

void RBX_ScriptContext::func(int)
{
    if (flag)
        helper();
}
