// from server: 100% by colin
struct S {
    char pad[0x138];
    int* field;
    bool f();
};

extern S* g_players;

bool S::f()
{
    int* p = field;
    if (p) {
        S* q = g_players;
        int* v = *(int**)q;
        p = p + 1;
        return ((bool (__thiscall*)(S*, int*))v[1])(q, p);
    }
    return false;
}
