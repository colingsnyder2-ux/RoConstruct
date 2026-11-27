// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void __cdecl sub_972290(unsigned char, const char*);
extern unsigned char byte_E580B3;
extern char (__cdecl *dword_E5809C)(const char*, const char*, int);
struct Ball {
    bool func(int, int, int, int, int, int);
};
bool Ball::func(int, int, int, int, int, int)
{
    if (byte_E580B3 != 0) {
        if (dword_E5809C == 0 || !dword_E5809C("0", "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\V8World/Ball.h", 0x37))
            sub_972290(byte_E580B3, "0 file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\V8World/Ball.h line: 55");
    }
    return false;
}