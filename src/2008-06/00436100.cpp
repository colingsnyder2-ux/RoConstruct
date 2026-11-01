// from server: 100% by king_originala
extern const wchar_t format[];

extern "C" {
    extern int (__cdecl *swprintf_s)(wchar_t *, unsigned int,
                                   const wchar_t *, ...);
    extern int (__cdecl *memcpy_s)(void *, unsigned int,
                                 const void *, unsigned int);
}

void __cdecl check_error(unsigned int);

int __cdecl format_output(const wchar_t *text, void *destination)
{
    wchar_t buffer[11];
    int result = swprintf_s(buffer, 11, format, text);
    check_error(memcpy_s(destination, 22, buffer, 20));
    return result;
}
