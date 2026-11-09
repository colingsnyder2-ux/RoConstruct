// from server: 38% by atomic.potato
struct S {
    char pad0[0x1c];
    int field1c;
    char pad20[8];
    int field28;
    S(const S& other, int a, int b, int c, int d, int e, int f, int g, int h);
};

extern "C" void __stdcall sub_b22644(void* dst, void* src);
extern "C" void __stdcall sub_b2263c(void* p);
extern "C" int __cdecl sub_6ac2b0();
extern "C" void __fastcall sub_8518f0(S* self, void* dummy, void* arg);

extern int dword_e48a60;

S::S(const S& other, int a, int b, int c, int d, int e, int f, int g, int h)
{
    char buf[0x20];
    sub_b22644(buf, (void*)&other);
    *(int*)(buf + 0x1c) = h;
    sub_8518f0(this, 0, buf);
    field28 = sub_6ac2b0();
    dword_e48a60++;
    sub_b2263c(buf);
}
