// from server: 58% by colin
struct DescribedBase {
    char pad[0xec];
};

struct GetSet {
    int pad0;
    int pad4;
    int offset8;
    int offsetc;
    void setValue(DescribedBase* object, const char* value);
};

void GetSet::setValue(DescribedBase* object, const char* value) {
    char* c = (char*)object;
    int* p = *(int**)(c + 0x298);
    *(int*)(c + 0x294) = 0x7a4cac;
    int* q = *(int**)((char*)p + 4);
    *(int*)((char*)q + (int)c + 0x298) = 0x7a4ca4;
    *(int*)((char*)c + 0xec) = 0x7b3bcc;
    *(int*)((char*)c + 4) = 0x7b3bc4;
    *(int*)((char*)c + 0x10) = 0x7b3bbc;
    *(int*)((char*)c + 0x14) = 0x7b3bac;
    *(int*)((char*)c + 0x2c) = 0x7b3b9c;
    *(int*)((char*)c + 0x44) = 0x7b3b8c;
    *(int*)((char*)c + 0x5c) = 0x7b3b7c;
    *(int*)((char*)c + 0x74) = 0x7b3b6c;
    *(int*)((char*)c + 0x8c) = 0x7b3b5c;
    *(int*)((char*)c + 0xe8) = 0x7b3b50;
    *(int*)((char*)c + 0x158) = 0x7b3b40;
    *(int*)((char*)c + 0x170) = 0x7b3b34;
    *(int*)((char*)c + 0x17c) = 0x7b3b1c;
    int* r = *(int**)((char*)c + 0xec);
    int* s = *(int**)((char*)r + 4);
    *(int*)((char*)s + (int)c + 0xec) = 0x7b3b10;
    int* t = *(int**)((char*)c + 0xec);
    int* u = *(int**)((char*)t + 8);
    *(int*)((char*)u + (int)c + 0xec) = 0x7b3b08;
    int* v = *(int**)((char*)c + 0xec);
    int* w = *(int**)((char*)v + 0xc);
    *(int*)((char*)w + (int)c + 0xec) = 0x7b3aec;
    int* x = *(int**)((char*)c + 0xec);
    int* y = *(int**)((char*)x + 4);
    *(int*)((char*)y + (int)c + 0xe8) = (int)y - 0x198;
    int* z = *(int**)((char*)c + 0xec);
    int* aa = *(int**)((char*)z + 8);
    *(int*)((char*)aa + (int)c + 0xe8) = (int)aa - 0x1a0;
    int* ab = *(int**)((char*)c + 0xec);
    int* ac = *(int**)((char*)ab + 0xc);
    *(int*)((char*)ac + (int)c + 0xe8) = (int)ac - 0x1a8;
}
