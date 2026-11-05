// from server: 34% by atomic.potato
struct Inner {
    char pad[0x1c];
    void* m_p;
};

struct Outer {
    void* m_p;
    Inner m_inner;
    void init(void* p, void* q);
};

extern "C" void __stdcall sub_496770(Inner* self, void* a, void* b);
extern "C" void __stdcall sub_75a4e0(void* a, void* b, void* c);

void Outer::init(void* p, void* q)
{
    m_p = p;
    sub_496770(&m_inner, p, q);
    void* r = 0;
    if (p != 0)
        r = (char*)p + 0x20;
    sub_75a4e0(&m_inner, r, p);
}
