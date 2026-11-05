// from server: 51% by atomic.potato
struct Sub {
    char pad[0x40];
    int (__stdcall *fn)(int);
};

struct Obj {
    char pad[0x104];
    Sub* m_sub;
    char pad2[0x1c];
    int m_arr[1];
};

bool __cdecl compare(Obj* a, Obj* b)
{
    int va = a->m_sub->fn(*(int*)b);
    int vb = b->m_sub->fn(*(int*)a);
    int x = a->m_arr[va];
    int y = b->m_arr[vb];
    if (x == 3) {
        if (y == 4 || y == 5) return true;
        return false;
    }
    if (x == 4) {
        if (y == 3) return true;
        if (y == 4 || y == 5) return true;
        return false;
    }
    if (x == 5) {
        if (y == 5 || y == 4 || y == 3) return true;
        return false;
    }
    return false;
}
