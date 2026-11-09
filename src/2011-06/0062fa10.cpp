// from server: 81% by atomic.potato
struct LegacyHopperService {
    void method();
};

extern "C" void __stdcall sub_4C0590(LegacyHopperService*);

void LegacyHopperService::method() {
    sub_4C0590((LegacyHopperService*)((char*)this + 0x1e0));
}
