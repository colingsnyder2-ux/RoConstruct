// from server: 100% by tester
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall RaiseException(unsigned long, unsigned long, unsigned long, const unsigned long*);

struct CXTIconHandle {
    int* data;
    int size;
    int* get(int index);
};

int* CXTIconHandle::get(int index)
{
    if (index < 0 || index >= size)
        RaiseException(0xc000008c, 1, 0, 0);
    return data + index;
}
