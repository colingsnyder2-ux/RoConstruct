// from server: 52% by atomic.potato
extern "C" void Call651790(void *, int);

struct CameraTiltDownCommand
{
    int Execute();
    int parent;
};

int CameraTiltDownCommand::Execute()
{
    struct Object
    {
        int pad[72];
        void *vtable;
    };

    Object *object = *(Object **)((char *)this + 12);
    typedef void *(*Method)(Object *);
    Method method = *(Method *)((char *)*(void **)((char *)object + 0x120) + 8);
    void *result = method((Object *)((char *)object + 0x120));
    Call651790(result, 1);
    return 0;
}
