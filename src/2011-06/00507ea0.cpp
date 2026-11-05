// from server: 68% by atomic.potato
struct VReplicatorEventDesc {
    char pad0[0x24];
    int field24;
    void sub_506c00(int, void*);

    void sub_507ea0(int a, int b);
};

extern "C" int __cdecl sub_40de90(int);
extern "C" void __cdecl sub_419680(void*, void*);

void VReplicatorEventDesc::sub_507ea0(int a, int b) {
    int* p = (int*)a;
    if (p != 0) {
        p = (int*)((char*)p - 0x1c);
    } else {
        p = 0;
    }
    int esi = field24 + (int)p;
    int* edi = (int*)b;
    int eax = edi[1];
    eax += 4;
    char al = *(char*)sub_40de90(eax);
    edi = (int*)edi[1];
    char c = al;
    int ecx = (int)c;
    sub_419680((void*)&c, edi);
    ((VReplicatorEventDesc*)esi)->sub_506c00(ecx, (void*)&c);
}
