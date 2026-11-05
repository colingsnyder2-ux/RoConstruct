// from server: 45% by atomic.potato

struct S_004a7960 {
};

bool __cdecl f_004a7960(const char* a, const char* b, const char* c, const char* d)
{
    while (a != b) {
        if (*a != *c)
            return false;
        ++a;
        ++c;
    }
    return true;
}
