// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void __cdecl sub_972290(unsigned char, const char*);
extern unsigned char byte_E580B3;
extern char (__cdecl *dword_E5809C)(const char*, const char*, int);

struct IMoving {
    void* vt;
    void* iMovingManager;
    void check();
};

void IMoving::check()
{
    if (byte_E580B3 != 0 && iMovingManager != 0) {
        if (dword_E5809C == 0 || !dword_E5809C("!iMovingManager", "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\V8World/IMoving.h", 33))
            sub_972290(byte_E580B3, "!iMovingManager file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\V8World/IMoving.h line: 33");
    }
}
