// from server: 71% by atomic.potato
struct Out {
    int a;
    int b;
};

struct RakPeer {
    char pad0[8];
    unsigned short field8;
    char padA[0x53c - 0xA];
    char* field53c;
    void GetSomething(int idx, Out* out);
};

extern int g_b208b4;
extern int g_b208b8;

void RakPeer::GetSomething(int idx, Out* out) {
    if (idx < 0 || idx >= (int)field8) {
        out->a = g_b208b4;
        out->b = g_b208b8;
        return;
    }
    char* p = field53c + idx * 0x13d0;
    if (*p == 0) {
        out->a = g_b208b4;
        out->b = g_b208b8;
        return;
    }
    if (*(int*)(p + 0x13c8) != 8) {
        out->a = g_b208b4;
        out->b = g_b208b8;
        return;
    }
    out->a = *(int*)(p + 4);
    out->b = *(int*)(p + 8);
}
