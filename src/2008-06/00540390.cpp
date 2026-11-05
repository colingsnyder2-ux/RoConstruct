// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
#pragma optimize("", off)

extern char G_0082cef0;

struct S_func_00472990 {
    void* p0;
    int z0;
    int z1;

    S_func_00472990();
    ~S_func_00472990();
};

struct Member {
    Member();
    ~Member();
    void f();
};

struct S : S_func_00472990 {
    Member member;

    S();
};

S::S()
{
    p0 = &G_0082cef0;
    member.f();
}
