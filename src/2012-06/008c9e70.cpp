// from server: 52% by atomic.potato
struct MoveAndJoinTool
{
    void f(void*);
};

extern "C" void sub_008c9e70(void*, const void*);

void MoveAndJoinTool::f(void* value)
{
    sub_008c9e70((char*)value, (const char*)this + 0x80);
}
