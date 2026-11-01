// from server: 100% by tester
struct CSHA1 {
    void Reset(unsigned int seed);
};

void CSHA1::Reset(unsigned int seed) {
    unsigned int v = seed | 1;
    *(unsigned int*)((char*)this + 0x9c8) = 0;
    *(unsigned int*)this = v;
    unsigned int* p = (unsigned int*)((char*)this + 4);
    int count = 0x26f;
    do {
        v = v * 0x10dcd;
        *p = v;
        p++;
        count--;
    } while (count != 0);
}
