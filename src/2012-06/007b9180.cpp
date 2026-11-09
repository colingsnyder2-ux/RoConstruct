// from server: 95% by Intel
extern unsigned char byte_e580b3;
extern int (__cdecl *func_e5809c)(const char*, const char*, int);
extern void (__cdecl func_972290)(const char*, unsigned char);

struct Ball {
    unsigned char func(int, int, int, int, int, int);
};

unsigned char Ball::func(int, int, int, int, int, int)
{
    if (!byte_e580b3) {
        return 0;
    }

    if (func_e5809c) {
        if (func_e5809c((const char*)0xb460cc, (const char*)0xbba450, 0x37)) {
            return 0;
        }
    }

    func_972290((const char*)0xbba4a0, byte_e580b3);
    return 0;
}
