// from server: 34% by colin
struct BrickMesh {
    void construct(int, int, int, int, int, int, int, int, int, int, int, int);
};

extern "C" int __stdcall InterlockedDecrement(int*);

extern "C" void __cdecl sub_4E3DE0();
extern "C" void __cdecl sub_4E3F40();
extern "C" void __cdecl sub_457DD0();

void BrickMesh::construct(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
    int* p;
    int v;

    p = 0;
    sub_4E3DE0();
    sub_4E3F40();

    v = *(int*)((char*)&a1 + 0x24);
    if (v != 0) {
        if (InterlockedDecrement((int*)(v + 4)) == 0) {
            sub_457DD0();
            (*(void(__thiscall**)(int, int))**(int**)v)(v, 1);
        }
    }
}
