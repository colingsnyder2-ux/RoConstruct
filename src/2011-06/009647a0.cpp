// from server: 70% by atomic.potato
extern "C" void G1_func_00934700(void *, void *);

struct RbxCullableSceneNode
{
    void *f(void *);
};

void *RbxCullableSceneNode::f(void *arg)
{
    void *value;
    void *object;
    void (*method)(void *);

    object = *(void **)((char *)this - 0x1c4);
    method = *(void (**)(void *))((char *)object + 0x148);
    method((void *)((char *)this - 0x1c4));
    value = arg;
    G1_func_00934700(value, value);
    return value;
}
