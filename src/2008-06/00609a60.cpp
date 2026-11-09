// from server: 100% by king_originala
extern char instanceType[];
extern char holeType[];
extern char motorFeatureType[];

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

int __cdecl matches(void* first, void* second)
{
    if ((__RTDynamicCast(first, 0, instanceType, holeType, 0) &&
         __RTDynamicCast(second, 0, instanceType, motorFeatureType, 0)) ||
        (__RTDynamicCast(second, 0, instanceType, holeType, 0) &&
         __RTDynamicCast(first, 0, instanceType, motorFeatureType, 0)))
        return 1;
    return 0;
}
