// from server: 100% by tajop
// roc 2007-08 004130f0  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004130f0

struct S_func_004130f0 {
    char pad[0x1226];
    unsigned short m_1226;
    int m_1228;
    int m_122c;
    int init();
};

extern "C" int __cdecl sub_004016e0(int);
extern "C" int __cdecl sub_00412d60();
extern "C" __declspec(dllimport) int __cdecl _mbsnbcpy_s(char*, unsigned int, const char*, unsigned int);

extern unsigned int g_786f98;

int S_func_004130f0::init()
{
    sub_00412d60();
    m_1228 = 2;
    m_122c = 4;
    m_1226 = 0x50;
    sub_004016e0(_mbsnbcpy_s((char*)this, 0x21, (const char*)g_786f98, 4));
    return (int)this;
}
