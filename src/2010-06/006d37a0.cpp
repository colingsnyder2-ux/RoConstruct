// from server: 52% by colin
struct Wheel {
    void* joint;
    bool grounded;
};

struct WheelArray {
    Wheel* data;
    int size;
};

struct Controller {
    char pad[0x3b8];
    void addWheel(Wheel* w);
};

struct S {
    void func(WheelArray* wheels);
};

void S::func(WheelArray* wheels)
{
    int i = 0;
    if (wheels->size > 0) {
        do {
            Wheel* w = &wheels->data[i];
            void* j = w->joint;
            char* p = (char*)j - 8;
            if (j != 0) p = 0;
            void* q = *(void**)(p + 0x2c);
            char* c = (char*)q - 0x20;
            if (q == 0) c = 0;
            if (c == 0) {
                i++;
                continue;
            }
            void** vt = *(void***)c;
            int (*f1)(void*) = (int (*)(void*))vt[4];
            if (f1(c) != 0) {
                i++;
                continue;
            }
            int (*f2)(void*) = (int (*)(void*))vt[5];
            if (f2(c) != 5) {
                i++;
                continue;
            }
            Controller* ctrl = (Controller*)((char*)this + 0x3b8);
            ctrl->addWheel(w);
            i++;
        } while (i < wheels->size);
    }
}
