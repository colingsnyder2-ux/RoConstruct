// from server: 100% by colin
// roc 2007-08 00535260  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00535260

extern "C" int __cdecl sub_5BF350(int, int, int);
extern "C" int __cdecl sub_5BF240(int, int, int);
extern "C" int __cdecl sub_56C740(int, int, int);

extern int dword_8ABE78;

int __cdecl sub_535260(int a)
{
    int v1 = sub_5BF350(a, 2, 0);
    int v2 = sub_5BF240(a, 1, dword_8ABE78);
    sub_56C740(v2, v1, a);
    return 0;
}
