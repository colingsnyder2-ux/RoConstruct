// from server: 100% by atomic.potato
extern "C" int __cdecl sub_78a770(int, int, int);
extern "C" int __cdecl sub_78a660(int, int, int);
extern "C" int __cdecl sub_78fb40(int, int, int);

extern int dword_B624CC;

int sub_69f090(int a)
{
    int v = sub_78a770(a, 2, 0);
    int w = sub_78a660(a, 1, dword_B624CC);
    sub_78fb40(w, v, a);
    return 0;
}
