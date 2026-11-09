// from server: 29% by colin
struct GuiItem {
    char pad0[0xec];
    int m_fieldEC;
    char pad1[0x0c];
    int m_fieldFC;
};

struct TopMenuBar : GuiItem {
    char pad2[0x08];
    int m_fieldF8;
    int m_fieldFC_2;
    int process(int a, int b);
};

extern "C" int __cdecl sub_630D36(int, int, int, int, int);
extern "C" void __cdecl sub_556D80(int, int);
extern "C" void __cdecl sub_555860(int, int);
extern "C" void __cdecl sub_556900(int);

int TopMenuBar::process(int a, int b)
{
    int local8 = 0;
    int local4 = 0;
    int result = 0;
    int result2 = 0;

    int v = sub_630D36(m_fieldEC, 0x881f30, 0x89df5c, 0, 0);
    int* p = (int*)a;
    int state = *p;

    if (state >= 3) {
        if (state <= 4) {
            sub_556D80((int)((char*)this + 0xe8), (int)&local8);
            int val = local8;
            if (val != 0) {
                if (val == 2) {
                    sub_556900((int)this);
                }
            }
            if (m_fieldFC_2 != 0) {
                void** vt = *(void***)this;
                void (*fn)(void*) = (void (*)(void*))vt[0x68/4];
                m_fieldFC_2 = 0;
                fn(this);
            }
            result = val;
            result2 = local4;
        } else if (state == 5) {
            int ebx = 0;
            if (v != 0) {
                ebx = *(int*)(v + 0xfc);
            }
            sub_556D80((int)((char*)this + 0xe8), (int)&local8);
            if (v != 0) {
                int v2 = sub_630D36(m_fieldEC, 0x881f30, 0x89df5c, 0, 0);
                if (v2 != 0 && v2 != v) {
                    sub_555860(v2, ebx);
                }
            }
            result = 1;
            result2 = 0;
        }
    }

    int* out = (int*)b;
    out[0] = result;
    out[1] = result2;
    return 0;
}
