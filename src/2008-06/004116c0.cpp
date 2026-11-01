// from server: 100% by colin
extern void (__thiscall *copy_bad_cast)(void *, const void *);
extern "C" __declspec(noreturn) void __stdcall throw_exception(void *, void *);

void __cdecl raise_bad_cast(const void *source)
{
    unsigned long object[3];
    copy_bad_cast(object, source);
    object[0] = 0x0080BA2CUL;
    throw_exception(object, reinterpret_cast<void *>(0x008D15C4UL));
}
