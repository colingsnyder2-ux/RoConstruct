// from server: 100% by colin
// roc 2007-08 004915c0  unit: seg_00490000  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004915c0

extern "C" int __cdecl sub_486830(int);
extern "C" char __cdecl sub_49E5E0(int, int);

int __cdecl sub_4915C0(int a, int b)
{
    if (sub_486830(a) != 0) {
        if (sub_49E5E0(a, b) == 0) {
            return 1;
        }
    }
    return 0;
}
