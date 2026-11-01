// from server: 100% by king_originala
struct Light;
struct Comparator {};

typedef bool (__thiscall *CompareFunction)(
    const Comparator *, const Light *, const Light *);

extern CompareFunction lightLess;

Light **upperBound(
    Light **first,
    Light **last,
    Light *const &value,
    Comparator comp)
{
    int count = last - first;
    while (count > 0) {
        int half = count / 2;
        if (!lightLess(&comp, value, first[half])) {
            first += half + 1;
            count -= half + 1;
        } else {
            count = half;
        }
    }
    return first;
}
