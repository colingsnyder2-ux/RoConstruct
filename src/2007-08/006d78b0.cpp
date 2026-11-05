// from server: 72% by colin
// roc 2007-08 006d78b0  unit: CXTRegistryManager  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d78b0
//
// 006d78b0  e86991f5ff           call 0x630a1e
// 006d78b5  81c428100000         add esp, 0x1028
// 006d78bb  c21000               ret 0x10
// library xtp-11.2.2-vc8/Source\Common\XTPRegistryManager.cpp (function ?SetRegistryKey@CXTRegistryManager@@QAEHPBD0@Z)

extern "C" int __cdecl sub_630a1e();

struct CXTRegistryManager
{
    int SetRegistryKey(const char* a, const char* b, const char* c, const char* d);
};

int CXTRegistryManager::SetRegistryKey(const char* a, const char* b, const char* c, const char* d)
{
    return sub_630a1e();
}
