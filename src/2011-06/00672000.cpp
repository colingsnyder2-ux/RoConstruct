// from server: 50% by atomic.potato
struct S_func_00672000 {
    char pad[0x17c];
    float value;
};

void S_func_00672000_set(S_func_00672000* p, float value);

void S_func_00672000_set(S_func_00672000* p, float value)
{
    if (value != p->value) {
        p->value = value;
        *(int*)0x00000004 = 0x00cce030;
    }
}
