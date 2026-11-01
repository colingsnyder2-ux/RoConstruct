// from server: 100% by king_originala
struct Pair {
    unsigned int first;
    unsigned int second;
};

struct Tag {};

extern Tag __cdecl classify(const Pair&, const Pair&);
extern unsigned int __cdecl unwrap(const Pair&);
extern unsigned int __cdecl transfer(unsigned int, unsigned int, Pair, Tag, Tag);

#pragma optimize("", off)
unsigned int __cdecl copy_range(Pair first, Pair last, Pair destination)
{
    return transfer(unwrap(first), unwrap(last), destination,
                    classify(first, destination), Tag());
}
#pragma optimize("", on)
