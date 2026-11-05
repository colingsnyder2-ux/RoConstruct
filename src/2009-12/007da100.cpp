// from server: 71% by atomic.potato
typedef void (__thiscall *RemoveFromStageProc)(void *, void *);

struct EdgeStage
{
    void f(void *);
};

void EdgeStage::f(void *stage)
{
    void *assembly = *(void **)((char *)this + 8);
    ((void (__thiscall *)(void *, void *))0x007de840)(assembly, stage);
    ((RemoveFromStageProc)0x007b2f40)(stage, this);
}
