// from server: 100% by Intel
struct ScriptMouseCommand
{
    int func_0089f8b0();
};

int ScriptMouseCommand::func_0089f8b0()
{
    int v1 = *(int *)((char *)this + 0x34);
    int v2 = *(int *)v1;
    int v3 = *(int *)(v2 + 0x58);
    return ((int (__thiscall *)(int))v3)(v1);
}
