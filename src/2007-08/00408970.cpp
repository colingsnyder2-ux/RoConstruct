// from server: 45% by colin
// roc 2007-08 00408970  unit: VCApp::?$CComObject  size: 241 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00408970

extern "C" {
    typedef unsigned long DWORD;
    typedef unsigned short WORD;
    typedef void* PVOID;
    typedef const char* LPCSTR;
    typedef unsigned int UINT;
    typedef long HRESULT;
    typedef unsigned short OLECHAR;
    typedef OLECHAR* BSTR;

    BSTR __stdcall SysAllocStringByteLen(LPCSTR psz, UINT len);
    void __stdcall SysFreeString(BSTR bstr);
    UINT __stdcall SysStringByteLen(BSTR bstr);

    void __stdcall __CxxThrowException(PVOID pExceptionObject, PVOID pThrowInfo);
    void* __cdecl operator_new(unsigned int size);
    void __cdecl operator_delete(void* p);
}

struct CComBSTR {
    BSTR m_str;
};

struct CComVariant {
    WORD vt;
    WORD wReserved1;
    WORD wReserved2;
    WORD wReserved3;
    union {
        long lVal;
        double dblVal;
        BSTR bstrVal;
        void* p;
        int intVal;
    };
};

struct CComObject {
    HRESULT __stdcall get_String(BSTR* pRet);
};

struct _String {
    char* _Ptr;
    char* _Myptr;
    unsigned int _Mysize;
    unsigned int _Myres;
};

extern "C" void* __stdcall sub_62FF44();
extern "C" void __stdcall sub_62FF3E(void* p);
extern "C" void* __stdcall sub_62FF02();
extern "C" void __stdcall sub_62FF38(void* p, int n);
extern "C" void __stdcall sub_401180();
extern "C" void __stdcall sub_401000(int code);

extern "C" void* __stdcall sub_77E6A8();
extern "C" void* __stdcall sub_77E9CC(BSTR bstr);
extern "C" void* __stdcall sub_77E9C8(BSTR bstr, void* p);
extern "C" void __stdcall sub_77E9B0(BSTR bstr);

HRESULT __stdcall CComObject::get_String(BSTR* pRet)
{
    void* p1 = sub_62FF44();
    void* p2 = 0;
    sub_62FF3E(&p2);
    void* p3 = sub_62FF02();
    void* p4 = *(void**)((char*)p3 + 4);
    void* p5 = (char*)p4 + 0xf0;
    void* p6 = sub_77E6A8();
    BSTR bstr = 0;
    if (p6 != 0) {
        sub_401180();
        bstr = (BSTR)p6;
    }
    if (bstr == 0) {
        sub_401000(0x8007000e);
    }
    HRESULT hr;
    if (pRet == 0) {
        hr = 0x80004003;
    } else {
        if (bstr == 0) {
            *pRet = 0;
            hr = 0;
        } else {
            UINT len = SysStringByteLen(bstr);
            BSTR copy = SysAllocStringByteLen((LPCSTR)bstr, len);
            *pRet = copy;
            if (copy == 0) {
                hr = 0x8007000e;
            } else {
                hr = 0;
            }
        }
    }
    SysFreeString(bstr);
    if (p2 != 0) {
        sub_62FF38(p2, 0);
    }
    return hr;
}
