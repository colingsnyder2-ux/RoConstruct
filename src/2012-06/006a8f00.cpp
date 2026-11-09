// from server: 100% by tajop

struct Str_006a8f00 {
    char d[0x1c];
};
extern Str_006a8f00& (Str_006a8f00::*g_strAssign_006a8f00)(const Str_006a8f00&);
struct Mid_006a8f00 {
    char d[0x10];
    Mid_006a8f00& operator=(const Mid_006a8f00&);
};
struct Elem_006a8f00 {
    Str_006a8f00 a;
    Str_006a8f00 b;
    Mid_006a8f00 c;
    double t;
    int v;
};
Elem_006a8f00* copy_backward_006a8f00(Elem_006a8f00* first, Elem_006a8f00* last, Elem_006a8f00* dest)
{
    while (first != last) {
        --last;
        --dest;
        (dest->a.*g_strAssign_006a8f00)(last->a);
        (dest->b.*g_strAssign_006a8f00)(last->b);
        dest->c = last->c;
        dest->t = last->t;
        dest->v = last->v;
    }
    return dest;
}
