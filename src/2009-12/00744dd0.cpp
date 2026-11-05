// from server: 80% by atomic.potato
struct Flag
{
    void get(int* value);
};

void Flag::get(int* value)
{
    *value = *(int*)((char*)this + 0x2a4);
}
