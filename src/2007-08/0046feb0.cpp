// from server: 53% by colin
// roc 2007-08 0046feb0  size: 268 bytes
// library glg3dcpp\Texture.cpp

extern "C" {
    int __stdcall MessageBoxA_impl(void*, const char*, const char*, unsigned int);
}

struct std_string {
    char pad[0x1c];
    std_string();
    std_string(const char*);
    ~std_string();
};

extern "C" void __cdecl _exit_impl(int);

struct Texture {
    bool checkSet(int mode);
};

extern "C" {
    void __cdecl sub_502880();
    void __cdecl sub_5028F0();
    int (__stdcall *off_8980FC)(void*, const char*, const char*, unsigned int, void*, int);
    void (__stdcall *off_77E698)(void*, const char*);
    void (__stdcall *off_77E6AC)(void*);
    void (__stdcall *off_77E938)(int);
}

extern char byte_8BD07C;
extern char byte_8B5188;

bool Texture::checkSet(int mode)
{
    int m = mode - 1;
    if ((unsigned)m > 5) {
        if (byte_8BD07C == 0) {
            sub_502880();
            if (off_8980FC != 0) {
                std_string s;
                off_77E698(&s, "Illegal interpolate mode");
                char flag = 0;
                int r = off_8980FC(&s, ".\\glg3dcpp\\Texture.cpp", "Illegal interpolate mode", 0x3cb, &byte_8BD07C, 1);
                if (r) {
                    flag = 1;
                }
                if (flag) {
                    off_77E938(-1);
                }
                off_77E6AC(&s);
            }
            sub_5028F0();
        }
        return false;
    }
    return true;
}
