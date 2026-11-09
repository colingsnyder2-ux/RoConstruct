// from server: 83% by atomic.potato
struct ChatEnter
{
    void f(float* value);
};

void ChatEnter::f(float* value)
{
    value[0] = *(float*)((char*)this + 0xa0);
    value[1] = *(float*)((char*)this + 0xa4);
}
