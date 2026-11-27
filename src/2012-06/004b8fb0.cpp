// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* handle, unsigned long milliseconds);

struct CSourceStream {
    int field_0;
    void* m_hEvent;
    int field_8;
    int m_dwParam;
    int Check(int* pParam);
};

int CSourceStream::Check(int* pParam) {
    if (WaitForSingleObject(m_hEvent, 0) != 0) {
        return 0;
    }
    if (pParam) {
        *pParam = m_dwParam;
    }
    return 1;
}
