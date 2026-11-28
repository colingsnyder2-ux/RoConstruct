// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

extern "C" int __fastcall fn_0048dc30(void* self, int unusedEdx, int a1);

struct Local_0048dca0 {
    char pad[0x28];
    // INFERRED: holder copy-ctor, 0x28-byte object; 0x6a0920 is the global operator new
    __forceinline Local_0048dca0(const void* held) { fn_0048dc30(this, 0, (int)held); }
};

// boost::any::holder<boost::function<void(shared_ptr<Instance>)>>::clone
extern "C" Local_0048dca0* __fastcall fn_0048dca0(char* self, int unusedEdx)
{
    return new Local_0048dca0(self + 8);
}
