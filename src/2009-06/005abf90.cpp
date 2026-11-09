// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
#pragma optimize("g", off)

struct R {
    int pad[3];
    ~R();
};

struct T : R {
    R m;
    ~T();
};

T::~T()
{
}
