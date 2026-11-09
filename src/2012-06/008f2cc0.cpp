// from server: 46% by Intel
struct Joint {
    Joint();
};

extern "C" void __cdecl sub_6CB830(int, int);
extern "C" int __cdecl sub_7CD1F0();
extern "C" void __cdecl sub_746CE0(int, int);

Joint::Joint() {
    int *vtable = (int *)0xBAF6A4;
    int *node1;
    int *node2;
    int zero = 0;

    sub_6CB830(0xDBAB7C, 0xBEF630);

    int *ebp = (int *)((char *)this + 0x34);
    node1 = (int *)sub_7CD1F0();
    ebp[1] = (int)node1;
    *((char *)node1 + 0x15) = 1;
    node1[1] = (int)node1;
    node1[0] = (int)node1;
    node1[2] = (int)node1;
    ebp[2] = 0;

    ebp = (int *)((char *)this + 0x40);
    node2 = (int *)sub_7CD1F0();
    ebp[1] = (int)node2;
    *((char *)node2 + 0x15) = 1;
    node2[1] = (int)node2;
    node2[0] = (int)node2;
    node2[2] = (int)node2;
    ebp[2] = 0;

    *((int *)this) = (int)vtable;

    int *fields = (int *)((char *)this + 0x50);
    for (int i = 0; i < 23; i++) {
        fields[i] = 0;
    }

    sub_746CE0(0xB582D4, 0);
    sub_746CE0(0xBE03F0, 1);
    sub_746CE0(0xBEF620, 2);
    sub_746CE0(0xBC5A60, 3);
}
