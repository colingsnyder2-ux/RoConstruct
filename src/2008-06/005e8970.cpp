// from server: 83% by king_originala
struct Primitive {
    unsigned char padding[0xE49E];
    unsigned char value;
    void f(unsigned char* p);
};

void Primitive::f(unsigned char* p) {
    *p += (unsigned char)(unsigned int)p;
    value += (unsigned char)(unsigned int)this;
    p[0x645B5EC6] += (unsigned char)(unsigned int)this;
    *(volatile unsigned int*)0 = (unsigned int)this;
}
