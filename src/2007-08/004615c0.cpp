// from server: 77% by colin
struct S_func_004615c0 {
    char pad[0x134];
    void* m_134;
    int f(int a, int b);
};

extern "C" int __stdcall sub_62ff50();
extern "C" void __stdcall sub_630016(void* p);
extern "C" void __stdcall sub_461270();
extern "C" void* __stdcall sub_77e6a8(void* p);

int S_func_004615c0::f(int a, int b)
{
    if (sub_62ff50() != 0) {
        void* p;
        if (m_134 == 0) {
            p = (void*)0x785954;
        } else {
            p = sub_77e6a8((char*)m_134 + 0xc8);
        }
        sub_630016((void*)sub_62ff50());
    }
    sub_461270();
    return 0;
}
