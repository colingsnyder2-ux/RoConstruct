// from server: 25% by Intel
typedef int DWORD;

extern "C" void __stdcall func_0xb22648(void* arg1, void* arg2);
extern "C" void __stdcall func_0xb2263c(void* arg1, void* arg2);
extern "C" int __stdcall func_0x6fb8c0(void* arg1, int arg2);
extern "C" void __stdcall func_0x62b600(void* arg1);

struct InsertModelFromRobloxVerb {
    int value;
    char pad[0x20];
    void ToggleMode();
};

void InsertModelFromRobloxVerb::ToggleMode()
{
    void* p1 = (void*)0xaa2e21;
    void* p2 = (void*)0xb5e374;
    func_0xb22648(p2, p1);

    int val = 0;
    func_0x6fb8c0(this, val);

    func_0xb2263c(this, (void*)2);

    this->value = 0xb5e358;
    func_0x62b600(this);
}
