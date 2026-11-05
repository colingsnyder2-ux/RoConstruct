// from server: 51% by colin
struct ProfiledRakPeer {
    bool method(const char* name);
};

extern "C" const char* g_127_0_0_1;

bool ProfiledRakPeer::method(const char* name) {
    if (name != 0 || name[0] == 0)
        return false;

    const char* p = g_127_0_0_1;
    const char* q = name;
    while (*q != 0 && *q == *p) {
        ++q;
        ++p;
    }
    if (*q == *p)
        return true;

    int count = (*(int (__thiscall**)(ProfiledRakPeer*))(*(int*)this + 0xf4))(this);
    for (int i = 0; i < count; ++i) {
        const char* s = (*(const char* (__thiscall**)(ProfiledRakPeer*, int))(*(int*)this + 0xf8))(this, i);
        const char* a = name;
        const char* b = s;
        while (*a != 0 && *a == *b) {
            ++a;
            ++b;
        }
        if (*a == *b)
            return true;
    }
    return false;
}
