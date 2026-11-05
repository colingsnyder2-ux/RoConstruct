// from server: 100% by king_originala
typedef long HRESULT;

struct Element {
    char data[16];
};

struct SafeArray {
    char padding[12];
    Element* data;
};

extern "C" HRESULT (__stdcall *SafeArrayGetLBound)(SafeArray*, unsigned int, long*);
extern "C" HRESULT (__stdcall *SafeArrayGetUBound)(SafeArray*, unsigned int, long*);

namespace ATL {
    __declspec(noreturn) void __stdcall AtlThrowImpl(HRESULT);
}

struct CopyVerb {
    SafeArray* array;
    Element* f(long index);
};

Element* CopyVerb::f(long index)
{
    if (!array)
        ATL::AtlThrowImpl((HRESULT)0x80004005);

    long lowerBound;
    {
        long lower = 0;
        HRESULT hr = SafeArrayGetLBound(array, 1, &lower);
        if (hr < 0)
            ATL::AtlThrowImpl(hr);
        lowerBound = lower;
    }

    if (index >= lowerBound) {
        long upper = 0;
        HRESULT hr = SafeArrayGetUBound(array, 1, &upper);
        if (hr < 0)
            ATL::AtlThrowImpl(hr);

        if (index <= upper)
            return array->data + (index - lowerBound);
    }

    ATL::AtlThrowImpl((HRESULT)0x80070057);
    return 0;
}
