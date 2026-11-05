// from server: 100% by atomic.potato
extern char g_00b7a898[];

struct Sub_0059b3f0 {
    void method_0059b3f0(int value, const char* file, int line);
};

struct Product_0059be00 {
    char pad_0000[0x54];
    Sub_0059b3f0 sub_0054;
    void method_0059be00(int arg);
};

void Product_0059be00::method_0059be00(int arg)
{
    sub_0054.method_0059b3f0(arg, g_00b7a898, 0xdee);
}
