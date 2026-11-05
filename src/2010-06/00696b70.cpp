// from server: 50% by atomic.potato
struct Motor
{
    void SetValue(float value);
    char pad[0xb4];
    struct State
    {
        char pad[0xac];
        float value;
    };
};

void Motor::SetValue(float value)
{
    State* state = *(State**)((char*)this + 0xb4);
    if (value != state->value)
    {
        state->value = value;
        *(int*)0xc1e7b8 = 0xc1e7b8;
    }
}
