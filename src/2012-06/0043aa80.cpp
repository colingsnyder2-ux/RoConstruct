// from server: 100% by Xemicl
// copied from an identical function in another client (function ?keep_00427310@ns_ROCX00009b@@YA?AUString@1@XZ)

namespace ns_ROCX00009b {
struct Temporary
{
    void *data;
    const char *text() const;
    ~Temporary();
};

typedef const char *(__thiscall *GetText)(const Temporary *);
typedef void (__thiscall *DestroyTemporary)(Temporary *);

extern GetText getText;
extern DestroyTemporary destroyTemporary;
extern Temporary __cdecl make_exception();

inline const char *Temporary::text() const
{
    return getText(this);
}

inline Temporary::~Temporary()
{
    destroyTemporary(this);
}

struct String
{
    unsigned char storage[28];
    String(const char *);
    ~String();
    String &append(const char *);
};

typedef void (__thiscall *ConstructString)(String *, const char *);
typedef String &(__thiscall *AppendString)(String *, const char *);

extern ConstructString constructString;
extern AppendString appendString;

inline String::String(const char *text)
{
    constructString(this, text);
}

inline String &String::append(const char *text)
{
    return appendString(this, text);
}

static String __cdecl fn_ROCX00009b_00427310()
{
    String result(make_exception().text());
    result.append("/Game/KeepAlivePinger.ashx");
    return result;
}

String __cdecl keep_00427310() { return fn_ROCX00009b_00427310(); }
}
