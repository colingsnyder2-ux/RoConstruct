// from server: 100% by colin
extern "C" int __cdecl sub_486830(int);
extern "C" char __cdecl sub_49AF30(int, int);

int __cdecl sub_4915F0(int a, int b)
{
    if (sub_486830(a) != 0) {
        if (sub_49AF30(a, b) == 0) {
            return 1;
        }
    }
    return 0;
}
