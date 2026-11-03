// from server: 97% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: atl-8.0 roc_espclaude_3984340d3efa32f8.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#define _DLL
#include <atlbase.h>
struct IDirectInputDevice8A : public IUnknown {
    STDMETHOD(GetCapabilities)(void*) = 0;
    STDMETHOD(EnumObjects)(void*, void*, DWORD) = 0;
    STDMETHOD(GetProperty)(const GUID&, void*) = 0;
    STDMETHOD(SetProperty)(const GUID&, const void*) = 0;
    STDMETHOD(Acquire)() = 0;
    STDMETHOD(Unacquire)() = 0;
    STDMETHOD(GetDeviceState)(DWORD, void*) = 0;
    STDMETHOD(GetDeviceData)(DWORD, void*, DWORD*, DWORD) = 0;
    STDMETHOD(SetDataFormat)(const void*) = 0;
    STDMETHOD(SetEventNotification)(HANDLE) = 0;
    STDMETHOD(SetCooperativeLevel)(HWND, DWORD) = 0;
};
class DirectInputDevice {
    char pad[0x34];
    CRITICAL_SECTION cs;
    char pad2[0x78 - 0x34 - sizeof(CRITICAL_SECTION)];
    bool wantAcquire;   // +0x78
    bool acquired;      // +0x79
    char cooperative;   // +0x7a
    char pad3[0x184 - 0x7b];
    HWND hwnd;          // +0x184
    char pad4[0x190 - 0x188];
    IDirectInputDevice8A* device; // +0x190
public:
    void updateAcquire();
};
void DirectInputDevice::updateAcquire()
{
    ATL::CCritSecLock lock(cs);
    if (device) {
        if (acquired && FAILED(device->Acquire()))
            acquired = false;
        if (wantAcquire != acquired || (acquired && cooperative != 1)) {
            device->Unacquire();
            if (wantAcquire) {
                cooperative = 1;
                if (device->SetCooperativeLevel(hwnd, 5) == 0)
                    acquired = SUCCEEDED(device->Acquire());
            }
            else
                acquired = false;
        }
    }
}
