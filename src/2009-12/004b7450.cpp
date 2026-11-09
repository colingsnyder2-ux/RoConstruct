// from server: 68% by atomic.potato
extern "C" int __cdecl isalpha(int);

int IsPathLike(const char* p)
{
    if (isalpha((unsigned char)p[0]) && p[1] == ':')
        return 1;

    if (p[0] == '/' || p[0] == '\\')
        return 1;

    return 0;
}
