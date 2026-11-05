// from server: 60% by atomic.potato
struct Tool {
    char pad0[0x14];
    int field14;
    char pad18[0x1c];
    char field34;
    char pad35[0x3];
    char field38;

    void method(int arg);
};

extern "C" int __cdecl sub_699710(int);
extern "C" void __cdecl sub_6e0160(void*, void*);
extern "C" char __cdecl sub_695ec0(void*);
extern "C" void __cdecl sub_6e36e0(void*, void*);

void Tool::method(int arg)
{
    if (field34 != 0) {
        int v = sub_699710(field14);
        if (v != 0) {
            char buf[12];
            buf[0] = 0; buf[1] = 0; buf[2] = 0; buf[3] = 0;
            buf[4] = 0; buf[5] = 0; buf[6] = 0; buf[7] = 0;
            buf[8] = 0; buf[9] = 0; buf[10] = 0; buf[11] = 0;
            sub_6e0160(*(void**)(v + 0x98), buf);
            if (!sub_695ec0(buf)) {
                sub_6e36e0((void*)arg, &field38);
            }
        }
    }
}
