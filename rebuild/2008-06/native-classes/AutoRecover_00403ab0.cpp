// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

typedef long HRESULT_;

namespace ATL {

void __stdcall AtlThrowImpl(long hr);

class CCRTAllocator;

// INFERRED: reconstruction of ATL::CTempBuffer<char,256,CCRTAllocator> (m_p at +0, fixed buffer at +4)
template <typename T, int t_nFixedBytes, class Allocator>
class CTempBuffer
{
public:
    T* m_p;
    char m_abFixedBuffer[t_nFixedBytes];

    void AllocateHeap(unsigned int nBytes);

    T* Allocate(unsigned int nElements)
    {
        unsigned __int64 n64 = (unsigned __int64)nElements * (unsigned __int64)sizeof(T);
        if (n64 > 0xFFFFFFFFui64)
            AtlThrowImpl(0x80070057L); // E_INVALIDARG
        unsigned int nNewSize = (unsigned int)n64;
        if (nNewSize > (unsigned int)t_nFixedBytes)
            AllocateHeap(nNewSize);
        else
            m_p = (T*)m_abFixedBuffer;
        return m_p;
    }
};

} // namespace ATL

extern "C" char* __fastcall fn_00403ab0(ATL::CTempBuffer<char, 256, ATL::CCRTAllocator>* self, int unusedEdx, unsigned int nElements)
{
    return self->Allocate(nElements);
}
