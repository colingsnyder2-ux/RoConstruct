// from server: 80% by colin
struct SignalSlot {
    char pad[0xa8];
    int state;
    char pad2[0xb0 - 0xac];
    double d_b0;
    double d_b8;
    double d_c0;
    double d_c8;
    char pad3[0xd8 - 0xd0];
    void* conn;
    void setState(int);
};

extern "C" void __stdcall helper(void*, int, int);

void SignalSlot::setState(int s)
{
    if (s == 1) {
        if (state == 0 || state == 2) {
            goto update;
        }
        return;
    } else if (s == 2) {
        if (state == 1) {
            goto update;
        }
        return;
    } else if (s == 0) {
        d_c8 = 0.0;
        d_b0 = 0.0;
        d_b8 = 0.0;
        d_c0 = 0.0;
    }

update:
    if (state != s) {
        int old = state;
        state = s;
        void* c = conn;
        if (c) {
            helper(c, old, s);
        }
    }
}
