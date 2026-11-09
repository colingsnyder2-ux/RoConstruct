// from server: 17% by colin
struct EventHandler {
    bool sub_42B0F0();
    int func(int a, int b, int c, int d, int e, int f, int g, unsigned short* out);
};

int EventHandler::func(int a, int b, int c, int d, int e, int f, int g, unsigned short* out)
{
    out[0] = 0xb;
    bool r = this->sub_42B0F0();
    out[4] = r ? 1 : 0;
    return 1;
}
