// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0060b840[];   // INFERRED: unnamed global at 0x0060b840 in the original
extern "C" char g_0097bda8[];   // INFERRED: unnamed global at 0x0097bda8 in the original
// INFERRED: structure copied from the server-verified analog; helper names mapped to fn_ addresses.
#include <new>

extern "C" void __cdecl fn_00557330(void (__cdecl *)(), void *);
extern "C" void *__cdecl fn_0060b7e0();
extern "C" void *__cdecl fn_005c0940();
extern "C" void __cdecl destroyObject(void *);

struct Owner {
    void *pointer;

    Owner(void *);
    ~Owner();
    void *release();
};

inline Owner::Owner(void *value) : pointer(value)
{
}

inline Owner::~Owner()
{
    if (pointer)
        destroyObject(pointer);
}

inline void *Owner::release()
{
    void *result = pointer;
    pointer = 0;
    return result;
}

// INFERRED: getset helper returning an owning accessor
Owner __cdecl fn_0060aa20(
    unsigned long, unsigned long, unsigned long, unsigned long);

struct Local_0060c180;
extern "C" void *__fastcall fn_0056c650(void *self, int unusedEdx, void *, void *,
                                        const char *, const char *, unsigned long);

struct Local_0060c180Base {
    virtual ~Local_0060c180Base();
    unsigned long data[5];

    __forceinline Local_0060c180Base(void *settings, void *type, const char *name,
                       const char *category, unsigned long flags)
    {
        fn_0056c650(this, 0, settings, type, name, category, flags);
    }
};

struct Local_0060c180Enum : Local_0060c180Base {
    void *enumType;

    __forceinline Local_0060c180Enum(void *settings, void *type, const char *name,
                       const char *category, unsigned long flags)
        : Local_0060c180Base(settings, type, name, category, flags),
          enumType(type)
    {
    }
    ~Local_0060c180Enum();
};

struct Local_0060c180 : Local_0060c180Enum {
    Owner accessor;
    void *cachedEnum;

    __forceinline Local_0060c180(const char *, const char *,
                   unsigned long, unsigned long, unsigned long, unsigned long,
                   unsigned long);
    virtual ~Local_0060c180();
};

__forceinline Local_0060c180::Local_0060c180(const char *name, const char *category,
                               unsigned long a, unsigned long b,
                               unsigned long c, unsigned long d, unsigned long flags)
    : Local_0060c180Enum(
          fn_005c0940(),
          (fn_00557330(
               reinterpret_cast<void (__cdecl *)()>(((int)&g_0060b840)),
               reinterpret_cast<void *>(((int)&g_0097bda8))),
           fn_0060b7e0()),
          name, category, flags),
      accessor(fn_0060aa20(a, b, c, d).release())
{
    fn_00557330(
        reinterpret_cast<void (__cdecl *)()>(((int)&g_0060b840)),
        reinterpret_cast<void *>(((int)&g_0097bda8)));
    cachedEnum = fn_0060b7e0();
}

extern "C" Local_0060c180 *__fastcall fn_0060c180(Local_0060c180 *self, int unusedEdx,
                                                  const char *name, const char *category,
                                                  unsigned long a, unsigned long b,
                                                  unsigned long c, unsigned long d,
                                                  unsigned long flags)
{
    return new (self) Local_0060c180(name, category, a, b, c, d, flags);
}
