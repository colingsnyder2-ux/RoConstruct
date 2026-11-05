// from server: 100% by king_originala
extern "C" {
    extern int (__cdecl *swprintf_s)(wchar_t *, unsigned int,
                                    const wchar_t *, ...);
    extern int (__cdecl *memcpy_s)(void *, unsigned int,
                                  const void *, unsigned int);
    void __cdecl check_error(int);
}

extern const wchar_t format[];

int __cdecl format_output(unsigned short value, void *destination)
{
    wchar_t buffer[9];
    int result = swprintf_s(buffer, 9, format, value);
    check_error(memcpy_s(destination, 18, buffer, 16));
    return result;
}
