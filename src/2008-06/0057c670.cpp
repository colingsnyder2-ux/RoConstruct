// from server: 100% by king_originala
extern "C" bool __cdecl parseNumber(const char *, double *);

struct S {
    int reserved;
    int type;
    union {
        double number;
        float single;
        const char *text;
    } value;

    void clear();
    bool toNumber(double *);
};

bool S::toNumber(double *result)
{
    if (type == 9) {
        *result = value.number;
        return true;
    }

    if (type == 7) {
        *result = value.single;
        clear();
    } else {
        if (type != 2 || !parseNumber(value.text, result))
            return false;
        clear();
    }

    value.number = *result;
    type = 9;
    return true;
}
