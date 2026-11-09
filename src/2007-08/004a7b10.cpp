// from server: 100% by tajop
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct ChangePropertyItem {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    char field14;
    char field15;
};

extern "C" void* __cdecl operator_new(unsigned int);

ChangePropertyItem* __stdcall MakeChangePropertyItem(int a, int b, int c, int* d, char e)
{
    ChangePropertyItem* p = (ChangePropertyItem*)operator_new(0x18);
    if (p != 0) {
        p->field0 = a;
        p->field4 = b;
        p->field8 = c;
        p->fieldC = d[0];
        int ref = d[1];
        p->field10 = ref;
        if (ref != 0) {
            _InterlockedIncrement((volatile long*)(ref + 8));
        }
        p->field14 = e;
        p->field15 = 0;
    }
    return p;
}

