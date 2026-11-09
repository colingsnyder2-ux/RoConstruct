// from server: 100% by king_originala
struct S
{
    char storage[28];

    S(const S &);
    ~S();
};

typedef S *(__thiscall *CopyFunction)(S *, const S &);
typedef void (__thiscall *DestroyFunction)(S *);
typedef S (__cdecl *ConcatFunction)(const S &, const char *);

extern CopyFunction copyFunction;
extern DestroyFunction destroyFunction;
extern ConcatFunction concatenate;
extern S __cdecl construct();

__forceinline S::S(const S &other)
{
    copyFunction(this, other);
}

__forceinline S::~S()
{
    destroyFunction(this);
}

S __cdecl sub_55D0B0(const char *text)
{
    return static_cast<const S &>(concatenate(construct(), text));
}
