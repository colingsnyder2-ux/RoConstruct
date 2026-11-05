// from server: 84% by atomic.potato
struct GlueJoint {
    int count;
    char pad1[0x20];
    void* field24;

    void remove(void* arg);
};

extern "C" void __cdecl sub_69b850(void*, void*);

void GlueJoint::remove(void* arg) {
    if (count > 1) {
        void* node;
        if (arg) {
            node = *(void**)((char*)arg + 4);
        } else {
            node = 0;
        }
        void* head = (char*)this + 4;
        void* target;
        if (node == head) {
            void* next = *(void**)head;
            if (next) {
                target = (char*)next - 4;
            } else {
                target = 0;
            }
        } else {
            if (node) {
                target = (char*)node - 4;
            } else {
                target = 0;
            }
        }
        sub_69b850(arg, target);
    }
    void* p;
    if (arg) {
        p = (char*)arg + 4;
    } else {
        p = 0;
    }
    void* first = *(void**)p;
    if (first) {
        void* second = *(void**)((char*)p + 4);
        *(void**)second = first;
        *(void**)((char*)first + 4) = second;
    }
    count--;
    *(void**)p = 0;
    *(void**)((char*)p + 4) = 0;
    void* f = field24;
    if (f) {
        *(void**)((char*)f + 0x5c) = 0;
    }
}
