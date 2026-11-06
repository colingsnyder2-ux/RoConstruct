// from server: 53% by Intel
struct CRobloxApp {
    void Initialize();
};

void __stdcall sub_40A260(void* thisptr);
void __stdcall sub_630874(void* thisptr);

void CRobloxApp::Initialize() {
    int cookie = *reinterpret_cast<int*>(0x8B5188) ^ reinterpret_cast<int>(&cookie);
    void* seh_handler = reinterpret_cast<void*>(0x73FF58);
    void* prev_seh = *reinterpret_cast<void**>(0);
    *reinterpret_cast<void**>(0) = &seh_handler;
    *reinterpret_cast<int*>(&seh_handler + 1) = cookie;

    sub_40A260(reinterpret_cast<char*>(this) + 0x28);
    sub_630874(this);

    *reinterpret_cast<void**>(0) = prev_seh;
}
