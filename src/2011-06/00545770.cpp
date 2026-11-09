// from server: 100% by atomic.potato
extern "C" int __declspec(dllimport) __cdecl isalpha(int);

int IsAlpha(unsigned char value)
{
    return isalpha((int)value) != 0;
}
