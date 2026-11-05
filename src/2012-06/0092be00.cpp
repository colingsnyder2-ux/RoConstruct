// from server: 18% by atomic.potato
struct S_func_0047dc20 {
    int m_x;
    int f();
};
int S_func_0047dc20::f()
{
    return m_x;
}

struct S_func_00750720 {
    char pad0[264];
    int m_x;
    int f();
};
int S_func_00750720::f()
{
    return m_x;
}

struct S_func_00928d20 {
    char pad0[0x1c];
    void f(void*);
};

struct S_func_00929f90 {
    double f();
};

struct S_func_0092a3a0 {
    void* f(void*, void*, void*, void*, void*, void*, void*, void*);
};

struct S_func_0092b990 {
    void* f(unsigned int);
};

struct S_func_00972290 {
    void f(void*, unsigned char);
};

extern "C" void* __cdecl sub_92b990(unsigned int);
extern "C" void* __cdecl sub_92a3a0(void*, void*, void*, void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_972290(void*, unsigned char);

extern unsigned char byte_E580B3;
extern void* dword_E5809C;

struct RBX_PolyPolyContact {
    char pad0[4];
    int m_field4;
    int m_field8;
    char pad1[8];
    int m_field18;
    int m_field1c;
    void* construct();
};

void* RBX_PolyPolyContact::construct()
{
    void* answer = sub_92b990(0xa0);
    if (answer != 0) {
        int a = ((S_func_0047dc20*)m_field1c)->f();
        int b = ((S_func_0047dc20*)m_field18)->f();
        char tmp1[0x1c];
        char tmp2[0x1c];
        ((S_func_00928d20*)m_field1c)->f(tmp1);
        ((S_func_00928d20*)m_field18)->f(tmp2);
        int c = ((S_func_00750720*)((char*)this + 0xc))->f();
        int d = ((S_func_00750720*)m_field8)->f();
        answer = sub_92a3a0(answer, (void*)d, (void*)c, tmp2, tmp1, (void*)b, (void*)a, 0);
    } else {
        answer = 0;
    }
    if (byte_E580B3) {
        double v = ((S_func_00929f90*)answer)->f();
        if (v != 0.0) {
            if (dword_E5809C != 0) {
                unsigned char r = ((unsigned char (__cdecl*)(int, const char*, const char*))dword_E5809C)(0x253, "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\v8world\\PolyPolyContact.cpp", "answer->computeOverlap()");
                if (r) {
                    return answer;
                }
            }
            sub_972290("answer->computeOverlap() file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\v8world\\PolyPolyContact.cpp line: 595", byte_E580B3);
        }
    }
    return answer;
}
