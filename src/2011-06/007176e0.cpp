// from server: 21% by atomic.potato




struct String {
    char pad[0x1c];
    String(const char*);
    ~String();
};

extern "C" void __stdcall sub_6A7410(int);
extern "C" void __stdcall sub_6A76C0(int, int, int, int, int, int, int);
extern "C" void __stdcall sub_A404C4(int);
extern "C" void __stdcall sub_A404D0(int);

extern float g_a65810;
extern float g_a9f850;

struct Frame {
    char pad0[0x16c];
    int m_state;
    char pad1[4];
    int m_field170;
    void func(int);
};

void Frame::func(int a1) {
    switch (m_state) {
    case 0: {
        float z = 0.0f;
        String s("rbxasset://textures/blackBkg_round");
        float v0 = z, v1 = z, v2 = z, v3 = z;
        sub_A404C4(0);
        int f = m_field170;
        float g = g_a65810;
        short c1 = 0x14, c2 = 0x14;
        sub_6A76C0((int)this - 0x94, a1, (int)&s, (int)&v0, f, (int)&c1, (int)&c2);
        sub_A404D0((int)&s);
        break;
    }
    case 1: {
        float z = 0.0f;
        String s("rbxasset://textures/blackBkg_square");
        float v0 = z, v1 = z, v2 = z, v3 = z;
        sub_A404C4(0);
        int f = m_field170;
        float g = g_a65810;
        short c1 = 0x14, c2 = 0x14;
        sub_6A76C0((int)this - 0x94, a1, (int)&s, (int)&v0, f, (int)&c1, (int)&c2);
        sub_A404D0((int)&s);
        break;
    }
    case 2: {
        float z = 0.0f;
        String s("rbxasset://textures/chatBubble_botBlue_bkg");
        float v0 = z, v1 = z, v2 = z, v3 = z;
        sub_A404C4(0);
        int f = m_field170;
        float g = g_a65810;
        short c1 = 0x14, c2 = 0x14;
        sub_6A76C0((int)this - 0x94, a1, (int)&s, (int)&v0, f, (int)&c1, (int)&c2);
        sub_A404D0((int)&s);
        break;
    }
    case 3: {
        float z = 0.0f;
        String s("rbxasset://textures/chatBubble_botGreen_bkg");
        float v0 = z, v1 = z, v2 = z, v3 = z;
        sub_A404C4(0);
        int f = m_field170;
        float g = g_a9f850;
        short c1 = 7, c2 = 7;
        sub_6A76C0((int)this - 0x94, a1, (int)&s, (int)&v0, f, (int)&c1, (int)&c2);
        sub_A404D0((int)&s);
        break;
    }
    case 4: {
        float z = 0.0f;
        String s("rbxasset://textures/chatBubble_botRed_bkg");
        float v0 = z, v1 = z, v2 = z, v3 = z;
        sub_A404C4(0);
        int f = m_field170;
        float g = g_a9f850;
        short c1 = 7, c2 = 7;
        sub_6A76C0((int)this - 0x94, a1, (int)&s, (int)&v0, f, (int)&c1, (int)&c2);
        sub_A404D0((int)&s);
        break;
    }
    default:
        sub_6A7410(a1);
        break;
    }
}
