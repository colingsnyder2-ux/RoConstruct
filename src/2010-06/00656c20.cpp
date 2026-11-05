// from server: 82% by atomic.potato
struct S_func_00656d10
{
    char pad0[148];
    char m_x;
    void f();
};

void S_func_00656d10::f()
{
    m_x = (char)0;
}

struct Keyframe
{
    char pad0[76];
    void* m_sequence;
    void f();
};

extern "C" void* __cdecl func_007a8bea(void*, void*, void*, void*, void*);

void Keyframe::f()
{
    void* p = func_007a8bea(m_sequence, (void*)0, (void*)0xB78E40, (void*)0xBB56CC, (void*)0);
    if (p != 0)
        ((S_func_00656d10*)p)->f();
}
