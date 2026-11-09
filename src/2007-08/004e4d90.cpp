// from server: 29% by colin
struct BrickMesh {
    void construct(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l);
};

extern "C" int __stdcall InterlockedDecrement(int*);

extern "C" void __stdcall sub_4E3DE0();
extern "C" void __stdcall sub_4E4390();
extern "C" void __stdcall sub_457DD0();

void BrickMesh::construct(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l)
{
    int local = 0;
    int* p = &local;
    sub_4E3DE0();
    sub_4E4390();
    int* q = (int*)p;
    if (q != 0) {
        if (InterlockedDecrement(q + 1) == 0) {
            sub_457DD0();
            (*(void(__thiscall**)(int*, int))(*q))(q, 1);
        }
    }
}
