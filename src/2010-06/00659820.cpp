// from server: 57% by atomic.potato
struct Elem {
    float f0;
    char pad[0x18];
};

struct Container {
    Elem* begin;
    Elem* end;
};

extern "C" void __stdcall sub_787810(void*, void*);
extern "C" void __stdcall sub_6587d0(Elem*, Elem*, Elem*);

void sub_659820(Elem* a, Elem* b)
{
    int n = (int)((b - a) / 7);
    if (n > 1) {
        Elem* p = b - 1;
        int off = 0x1c - (int)a;
        while (n > 1) {
            float v = p->f0;
            char buf[0x1c];
            *(float*)buf = v;
            sub_787810(buf + 4, &p->pad[0]);
            sub_6587d0(a, p, p);
            p = p - 1;
            n = (int)(((char*)p + off - (char*)a) / 0x1c);
            if (n <= 1) break;
        }
    }
}
