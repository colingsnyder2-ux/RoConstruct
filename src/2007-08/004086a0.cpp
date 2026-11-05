// from server: 53% by colin
// roc 2007-08 004086a0  unit: VCApp::?$CComObject  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004086a0

extern "C" __declspec(dllimport) void* __stdcall SysAllocStringLen(const wchar_t*, unsigned int);
extern "C" __declspec(dllimport) void __stdcall SysFreeString(void*);
extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int, unsigned long, const char*, int, wchar_t*, int);
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();
extern "C" void __cdecl sub_401000(unsigned long);
extern "C" void __cdecl sub_401150(void*);

struct VCApp_CComObject {
    void* field0;
    void Assign(void* p);
};

void VCApp_CComObject::Assign(void* p)
{
    void* saved = this->field0;
    SysFreeString(saved);
    void* result = 0;
    if (p != 0) {
        unsigned long err = GetLastError();
        int len = MultiByteToWideChar(0, 0, (const char*)p, -1, 0, 0);
        wchar_t* buf = (wchar_t*)SysAllocStringLen(0, len - 1);
        if (buf != 0) {
            int n = MultiByteToWideChar(0, 0, (const char*)p, -1, buf, len);
            if (n != len) {
                SysFreeString(buf);
                sub_401150(&result);
                result = 0;
            } else {
                result = buf;
            }
        } else {
            sub_401150(&result);
        }
    }
    this->field0 = result;
    if (result == 0 && p != 0) {
        sub_401000(0x8007000e);
    }
}
