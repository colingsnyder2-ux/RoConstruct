// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: the class header pulls in OgreMaterial.h, which is not on the include path under these flags.
// A minimal AdornRbxGfx declaration gives the same mangled name (private member, __thiscall, std::string return).
namespace RBX
{
    class AdornRbxGfx
    {
    private:
        std::string uniqueName();
    };

    // INFERRED: StringConverter<int>::convertToString(const int&) returns std::string by hidden pointer;
    // the disassembly passes (result, &local) and ends with `ret 4` returning the result pointer.
    template<class T> struct StringConverter
    {
        static std::string convertToString(const T& value);
    };

    extern int nameCounter;   // global 0097da58
    int nameCounter;

    std::string AdornRbxGfx::uniqueName()
    {
        int n = 0;
        n = nameCounter;
        nameCounter = n + 1;
        return StringConverter<int>::convertToString(n);
    }
}
