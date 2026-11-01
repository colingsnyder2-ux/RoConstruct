// from server: 60% by colin
extern "C" void __stdcall free(void*);

struct RakPeer {
    void* field0;
    void* field4;
    int field8;
    int fieldC;
    void clear();
};

void RakPeer::clear()
{
    int i;
    void* p;
    void* next;

    if (field8 > 0) {
        p = field0;
        do {
            free(*(void**)p);
            free(*(void**)((char*)p + 8));
            next = *(void**)((char*)p + 0xC);
            free(p);
            p = next;
        } while (p != field0);
    }

    if (fieldC > 0) {
        p = field4;
        do {
            free(*(void**)p);
            free(*(void**)((char*)p + 8));
            next = *(void**)((char*)p + 0xC);
            free(p);
            p = next;
        } while (p != field4);
    }

    fieldC = 0;
    field8 = 0;
}
