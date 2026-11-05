// from server: 78% by atomic.potato
extern "C" unsigned long __stdcall GetLastError();

extern "C" int __cdecl Function006B9F30(int, int);

void __cdecl Function006BA310(char enabled, int first, int second)
{
    if (!enabled)
        Function006B9F30(first, second);
}
