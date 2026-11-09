// from server: 21% by Viper
struct RBX_KeyframeSequence {
    char pad0[144];
    int m_x;
    int m_y;
    int m_z;
    int m_w;
    void f(int a1);
};

extern "C" void __stdcall func_68bee0(int* a1, int a2);
extern "C" void __stdcall func_5980d0(int a1);

void RBX_KeyframeSequence::f(int a1) {
    int* ptr = (int*)((char*)this + 0x90);
    func_68bee0(ptr, 0);
    this->m_x = 0xa9f4a4;
    this->m_y = 0xa9f498;
    this->m_z = 0xa9f48c;
    this->m_w = 0xa9f480;
    func_5980d0(a1);
}
