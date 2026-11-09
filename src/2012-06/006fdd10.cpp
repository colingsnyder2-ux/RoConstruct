// from server: 100% by atomic.potato
// roc 2012-06 006fdd10  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 55 bytes

extern "C" void* __cdecl sub_98211a(unsigned int);

struct S {
    int f();
};

int S::f()
{
    char* p = (char*)sub_98211a(0x58);
    if (p) {
        *(int*)(p + 0) = 0;
    }
    int* q = (int*)(p + 4);
    if (q) {
        *q = 0;
    }
    int* r = (int*)(p + 8);
    if (r) {
        *r = 0;
    }
    *(char*)(p + 0x54) = 1;
    *(char*)(p + 0x55) = 0;
    return (int)p;
}
