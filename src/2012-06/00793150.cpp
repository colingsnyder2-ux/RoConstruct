// from server: 64% by Intel
struct Profiler {
    int m_field0;
    int m_field4;
    int m_field8;
    int m_fieldC;
    int m_field10;
    int m_field14;
    char m_field18;
    char m_field19;
    char m_field1A;
    char m_field1B;
    int m_field1C;
    int m_field20;
    int m_field24;
    char m_field28;

    int f(int arg0, char arg1, char arg2);
};

extern "C" int __stdcall TlsGetValue(int);
extern "C" int __stdcall TlsSetValue(int, int);

int __cdecl f_004436c0();
int __cdecl f_00975750(int);

extern int g_00E49104;
extern char g_00E49108;

int Profiler::f(int arg0, char arg1, char arg2)
{
    m_field0 = arg0;
    m_field8 = arg1;
    double zero = 0.0;
    *(double*)(&m_field10) = zero;

    char result;
    if (g_00E49108 == 0) {
        int v = f_004436c0();
        if (*(char*)(v + 0x93) == 0)
            result = 0;
        else
            result = 1;
    } else {
        result = 1;
    }

    m_field18 = result;
    *(double*)(&m_field1C) = 0.0;
    m_field28 = arg2;

    if (m_field18 != 0) {
        int local;
        f_00975750((int)&local);
        m_field10 = local;
        m_field14 = *(int*)((int)&local + 4);
        int tls = g_00E49104;
        TlsSetValue(tls, 0);
        m_field4 = TlsGetValue(tls);
        TlsSetValue(tls, (int)this);
    }

    return (int)this;
}
