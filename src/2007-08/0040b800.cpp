// from server: 100% by colin
struct S { int pad[6]; long m; };

long __stdcall sub_0040b800(S* p)
{
    ++p->m;
    return p->m;
}
