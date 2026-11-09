// from server: 45% by atomic.potato
struct S {
    void* field0;
    char pad[4];
    int field8;
    int fieldC;
    void assign(void* a, void* b);
};

extern "C" bool __cdecl func_00704780();

void S::assign(void* a, void* b)
{
    if (a == 0) {
        field0 = 0;
        return;
    }
    void* local4 = a;
    void* local8 = b;
    if (!func_00704780()) {
        int* p = (int*)((char*)this + 8);
        if (p != 0) {
            p[0] = (int)local4;
            p[1] = (int)local8;
        }
    }
    field0 = (void*)0xc66698;
}
