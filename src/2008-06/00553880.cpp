// from server: 100% by king_originala
struct Pair {
    unsigned int first;
    unsigned int second;
};

extern unsigned int __cdecl copy_range(Pair first, Pair last,
                                      unsigned int destinationFirst,
                                      void* destinationSecond);

struct S {
    unsigned char prefix[8];
    unsigned char destination;
    unsigned int f(Pair first, Pair last, unsigned int destinationFirst);
};

#pragma optimize("", off)
unsigned int S::f(Pair first, Pair last, unsigned int destinationFirst)
{
    return copy_range(first, last, destinationFirst, &destination);
}
