// from server: 82% by atomic.potato
typedef unsigned int DWORD;

extern "C" int __stdcall CompareFloat(const float *a, const float *b)
{
    return (*a == *b) ? 1 : 0;
}
