// from server: 72% by Intel
extern "C" void __stdcall sink(int);
extern "C" void __cdecl other(int);

struct S {
    virtual ~S();
    int m_x;
    int m_y;
    int* m_z;
    void func();
};

S::~S() {}

void S::func()
{
    if (m_x == 0) return;
    int* end = reinterpret_cast<int*>(m_x + m_y * 4);
    int* p = m_z;
    for (; p != end; ++p) {
        int val = *p;
        *p = 0;
        sink(val);
    }
    other(m_x);
}
