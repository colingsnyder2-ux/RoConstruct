// from server: 40% by colin
struct ContentId {
    void* ptr;
    ContentId();
    ContentId(const ContentId&);
    ~ContentId();
};

struct SoundId : ContentId {
    SoundId(const ContentId& id);
};

extern "C" void* __stdcall func_0077ddb8(void*);
extern "C" void __stdcall func_0077e6ac(void*);
extern "C" void __cdecl func_00630a1e();
extern "C" void __cdecl func_00697d10();
extern "C" void __cdecl func_00698630();

SoundId::SoundId(const ContentId& id)
{
    func_0077ddb8((void*)0x785954);
    func_00698630();
    func_00697d10();
    func_0077e6ac((void*)((char*)this + 0x84));
    func_00630a1e();
}
