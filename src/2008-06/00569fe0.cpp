// from server: 100% by king_originala
typedef long HRESULT;

namespace ATL {
    __declspec(noreturn) void __stdcall AtlThrowImpl(HRESULT hr);
}

extern "C" int (__cdecl *_mbslwr_s)(unsigned char *, unsigned int);
void __cdecl CheckError(int);

struct S {
    unsigned char *data;
    void PrepareWrite(int length);
    S &MakeLower();
};

S &S::MakeLower()
{
    int length = reinterpret_cast<int *>(data)[-3];

    if (((reinterpret_cast<int *>(data)[-2] - length) |
         (1 - reinterpret_cast<int *>(data)[-1])) < 0)
        PrepareWrite(length);

    unsigned char *buffer = data;
    unsigned int size = length + 1;
    CheckError(_mbslwr_s(buffer, size));

    if (length < 0 || length > reinterpret_cast<int *>(data)[-2])
        ATL::AtlThrowImpl((HRESULT)0x80070057L);

    reinterpret_cast<int *>(data)[-3] = length;
    data[length] = 0;
    return *this;
}
