// from server: 49% by colin
struct Players {
    void* field0;
    Players(int, int);
};

extern "C" void* __cdecl operator_new(unsigned int);

Players::Players(int a, int b)
{
    field0 = 0;
    void* p = operator_new(0x14);
    if (p) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(int*)p = 0x79b9bc;
        *(int*)((char*)p + 0xc) = a;
    } else {
        p = 0;
    }
    field0 = p;
}
