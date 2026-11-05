// from server: 51% by atomic.potato
struct S {
    char pad0[0x20];
    void* head;
    int f(void* arg);
};

extern "C" void* __stdcall sub_b226cc(void*, int, int);
extern "C" void* __stdcall sub_b226d0(void*, void*);
extern "C" void* __stdcall sub_b2271c(void*);
extern "C" void* __stdcall sub_b22764(void*, void*, int, void*, int);
extern "C" void* __stdcall sub_44d230(void*, void*);
extern "C" void* __stdcall sub_4379a0(void*);

extern char byte_b4f3ec;
extern unsigned short word_e02754;

int S::f(void* arg) {
    char buf[0x1c];
    int count;
    void* node;
    void* end;

    sub_b226cc(arg, 0, 2);
    sub_b226d0(arg, buf);
    count = *(int*)((char*)buf + 8) + *(int*)buf;
    sub_b226cc(arg, 0, 0);

    while (count > 0) {
        void* q;
        if (arg != 0)
            q = (char*)arg + 8;
        else
            q = 0;
        sub_44d230(q, &byte_b4f3ec);
        count--;
    }

    sub_b2271c((char*)arg + 8);
    sub_b226cc(arg, 0, 0);

    node = *(void**)this->head;
    end = this->head;
    if (node != end) {
        do {
            unsigned short w = word_e02754;
            int lo = (int)(unsigned char)w;
            int hi = (int)(unsigned char)(w >> 8);
            void* q;
            if (arg != 0)
                q = (char*)arg + 8;
            else
                q = 0;
            sub_b22764(q, (char*)node + 0xc, hi, (char*)node + 0x28, lo);
            sub_4379a0(sub_b22764(q, (char*)node + 0xc, hi, (char*)node + 0x28, lo));
            if (*(char*)((char*)node + 0x45) == 0) {
                void* n = *(void**)((char*)node + 8);
                if (*(char*)((char*)n + 0x45) != 0) {
                    void* m = *(void**)((char*)node + 4);
                    if (*(char*)((char*)m + 0x45) == 0) {
                        while (node == *(void**)((char*)m + 8)) {
                            node = m;
                            m = *(void**)((char*)m + 4);
                            if (*(char*)((char*)m + 0x45) != 0)
                                break;
                        }
                    }
                    node = m;
                } else {
                    node = n;
                    n = *(void**)node;
                    while (*(char*)((char*)n + 0x45) == 0) {
                        node = n;
                        n = *(void**)node;
                    }
                }
            }
        } while (node != *(void**)((char*)this->head + 0x20));
    }

    sub_b2271c((char*)arg + 8);
    return 0;
}
