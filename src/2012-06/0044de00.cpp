// from server: 34% by atomic.potato
struct S {
    char pad0[4];
    char* begin;
    char* end;
    char* end_cap;
    void f(char* a, char* b, char* c, char* d, char* e);
};

void S::f(char* a, char* b, char* c, char* d, char* e)
{
    char* p = a;
    char* q = b;
loop:
    if (p == q) {
        c[0] = (char)e;
        c[4] = (char)q;
        c[8] = (char)e;
        c[12] = (char)e;
        return;
    }
    char* r = this->begin;
    char* s = this->end;
    if (this->end == this->end_cap) {
        c[0] = (char)e;
        c[4] = (char)q;
        c[8] = (char)e;
        c[12] = (char)e;
        return;
    }
    char* t = this->begin;
    char* u = this->end;
    char* v = p;
    while (v != q) {
        char* w = this->end;
        if (u == this->end_cap)
            break;
        if (*v != *u)
            break;
        ++v;
        ++u;
    }
    char* x = this->end;
    if (u != this->end_cap) {
        ++p;
        goto loop;
    }
    c[0] = (char)e;
    c[4] = (char)p;
    c[8] = (char)d;
    c[12] = (char)v;
}
