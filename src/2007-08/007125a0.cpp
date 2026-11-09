// from server: 100% by colin
// roc 2007-08 007125a0  unit: seg_00710000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 007125a0

extern "C" int __cdecl sub_712590();
extern "C" char *__cdecl sub_6978f0();

int sub_7125a0()
{
    if (sub_712590())
        return 0;
    char *p = sub_6978f0();
    return *(int *)(p + 0x144) == 0;
}
