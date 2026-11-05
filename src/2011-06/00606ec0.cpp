// from server: 51% by atomic.potato
struct S
{
    S& f(const char*);
};

extern "C" void G1_func_00606b80(S*);
extern "C" void G2_func_a404c4(void*, const char*);

S& S::f(const char* p)
{
    char buffer[28];
    G2_func_a404c4(buffer, "d$XP");
    G1_func_00606b80(this);
    return *this;
}
