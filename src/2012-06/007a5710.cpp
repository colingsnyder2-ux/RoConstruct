// from server: 62% by Intel
struct std_string {
    std_string& operator=(const std_string& other);
};

struct AsyncResult {
    AsyncResult();
};

extern "C" int __cdecl sub_743730(void* arg2, void* string_ptr);
void* operator new(size_t, void* p) { return p; }

struct VirtualHardwareDevice {
    bool __stdcall someFunction(int unused, void* arg2);
};

bool VirtualHardwareDevice::someFunction(int unused, void* arg2)
{
    if (sub_743730(arg2, reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 4)))
    {
        std_string* str_ptr = reinterpret_cast<std_string*>(reinterpret_cast<char*>(this) + 4);
        *str_ptr = *reinterpret_cast<const std_string*>(arg2);
        *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 0x20) =
            *reinterpret_cast<const unsigned long*>(reinterpret_cast<const char*>(arg2) + 0x1c);
        AsyncResult* ar = reinterpret_cast<AsyncResult*>(reinterpret_cast<char*>(this) + 0x24);
        new (ar) AsyncResult();
        return true;
    }
    else
    {
        return false;
    }
}
