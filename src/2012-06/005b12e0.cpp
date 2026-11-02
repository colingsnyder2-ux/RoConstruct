// from server: 67% by tajop
extern "C" double (__cdecl *_imp__ceil)(double);

struct Item {
    int pad0;
    int pad4;
    int pad8;
    unsigned int weight;
    int value;
    int extra;
};

struct __declspec(align(64)) AlignedLocal {
    int x;
};

struct ErrorCompPhysicsSender {
    char pad[0x8c];
    Item* first;
    Item* last;
    void update();
};

void ErrorCompPhysicsSender::update() {
    AlignedLocal aligned;
    int prev = (int)(*(Item* volatile*)&last - *(Item* volatile*)&first) - 1;
    int i = (int)(*(Item* volatile*)&last - *(Item* volatile*)&first) - 1;
    volatile bool isFirst = true;
    for (; i >= 0; --i) {
        if (first[i].weight == 0) {
            first[i].value = 0;
            first[i].extra = 0;
        } else {
            if (isFirst) {
                first[i].value = 1;
                first[i].extra = 0;
                isFirst = false;
            } else {
                first[i].value = (int)_imp__ceil(2.0f * first[i].weight / first[prev].weight * first[prev].value);
            }
            prev = i;
        }
    }
}
