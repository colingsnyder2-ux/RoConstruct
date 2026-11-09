// from server: 75% by colin
struct StreamBuf {
    void* vtable;
    char pad[0x20];
    int* field_24;
    char pad2[0xc];
    int* field_34;
    char pad3[0x8];
    int field_40;
    char pad4[0x8];
    int field_4c;
    unsigned int field_5c;

    int put(int ch);
    int overflow(int ch);
    int flush();
};

int StreamBuf::put(int ch) {
    if ((field_5c >> 3) & 1) {
        if (*field_24 == 0) {
            void** vt = (void**)vtable;
            int (*fn)(StreamBuf*) = (int (*)(StreamBuf*))vt[0x58 / 4];
            fn(this);
        }
    }

    if (ch == -1) {
        return 0;
    }

    if ((field_5c >> 3) & 1) {
        int* p = field_24;
        int avail = *p;
        int* q = field_34;
        int total = *q;
        if (avail == avail + total) {
            flush();
            p = field_24;
            q = field_34;
            avail = *p;
            total = *q;
            if (avail == avail + total) {
                return -1;
            }
        }
        *p = (int)((char*)*p);
        *(char*)(*field_24) = (char)ch;
        *field_34 -= 1;
        *field_24 += 1;
        return ch;
    } else {
        char c = (char)ch;
        int r = 0;
        extern int __stdcall func_54dd50(int, void*, int);
        r = func_54dd50(field_4c, &c, 1);
        if (r != 1) {
            return -1;
        }
        return ch;
    }
}
