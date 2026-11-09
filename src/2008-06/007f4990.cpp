// from server: 100% by king_originala
extern "C" void __cdecl callback_598cd0();
extern "C" void __cdecl callback_59db90();
extern "C" void __cdecl cleanup_7fdc70();
extern "C" int __cdecl register_cleanup(void (__cdecl *)());

struct Callback
{
    void (__cdecl *function)();
    int context;
    int reserved;

    Callback(void (__cdecl *f)());
};

inline Callback::Callback(void (__cdecl *f)())
    : function(f), context(0), reserved(0)
{
}

struct Descriptor
{
    void initialize(const char *, void *, Callback, Callback, int);
};

void initialize_7f4990()
{
    reinterpret_cast<Descriptor *>(0x976148)->initialize(
        reinterpret_cast<const char *>(0x8331a8),
        *reinterpret_cast<void **>(0x94a248),
        Callback(callback_598cd0),
        Callback(callback_59db90),
        4);
    register_cleanup(cleanup_7fdc70);
}
