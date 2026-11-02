// from server: 100% by tajop
typedef unsigned int size_t;

extern "C" char* (__stdcall *_imp__PathAddBackslashA)(char* pszPath);
extern "C" size_t (__cdecl *_imp__strnlen)(const char* str, size_t maxsize);

__declspec(noreturn) void __stdcall AtlThrowImpl(long hr);

struct CStringData {
    void* pStringMgr;
    int nDataLength;
    int nAllocLength;
    long nRefs;
};

struct CPathA {
    char* m_pszData;
    void PrepareWrite2(int nLength);
    void AddBackslash();
    CStringData* GetData() const { return (CStringData*)m_pszData - 1; }
    int GetLength() const { return GetData()->nDataLength; }
    char* PrepareWrite(int nLength) {
        CStringData* pOldData = GetData();
        int nShared = 1 - pOldData->nRefs;
        int nTooShort = pOldData->nAllocLength - nLength;
        if ((nShared | nTooShort) < 0)
            PrepareWrite2(nLength);
        return m_pszData;
    }
    static int StringLengthN(const char* psz, size_t sizeInXChar) {
        if (psz == 0)
            return 0;
        return (int)_imp__strnlen(psz, sizeInXChar);
    }
    void SetLength(int nLength) {
        if (nLength < 0 || nLength > GetData()->nAllocLength)
            AtlThrowImpl(0x80070057);
        GetData()->nDataLength = nLength;
        m_pszData[nLength] = 0;
    }
    void ReleaseBuffer() {
        int nAlloc = GetData()->nAllocLength;
        SetLength(StringLengthN(m_pszData, nAlloc));
    }
};

void CPathA::AddBackslash() {
    char* pszBuffer = PrepareWrite(GetLength() + 1);
    _imp__PathAddBackslashA(pszBuffer);
    ReleaseBuffer();
}
