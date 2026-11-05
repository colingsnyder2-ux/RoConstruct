// from server: 100% by colin
struct ServiceProvider {
    bool isA();
};

extern "C" void* __fastcall sub_52CB30();

bool ServiceProvider::isA() {
    return sub_52CB30() == (void*)this;
}
