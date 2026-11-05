// from server: 14% by atomic.potato
struct Slot
{
    char pad[12];
    void __thiscall f(void*);
};

extern "C" void __stdcall helper(void*);

void Slot::f(void* value)
{
    helper(value);
}
