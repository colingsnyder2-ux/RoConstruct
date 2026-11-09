// from server: 100% by king_originala
struct ExceptionObject
{
    unsigned long words[10];
    void __thiscall copy(const void *source);
};

extern "C" __declspec(noreturn) void __stdcall throw_exception(void *, void *);

void __cdecl raise_exception(const void *source)
{
    ExceptionObject object;
    object.copy(source);
    object.words[0] = 0x0080B8DCUL;
    throw_exception(&object, reinterpret_cast<void *>(0x008D161CUL));
}
