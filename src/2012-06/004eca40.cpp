// from server: 32% by Intel
typedef unsigned long DWORD;

extern "C" void __stdcall ReallocFn(DWORD* pValue, int count, DWORD* curPtr);

namespace Ogre {
    struct RbxEntity {
        void Append(DWORD value);
    };
}

void Ogre::RbxEntity::Append(DWORD value)
{
    DWORD* base = *reinterpret_cast<DWORD**>(reinterpret_cast<char*>(this) + 0xE8);
    DWORD* current = *reinterpret_cast<DWORD**>(reinterpret_cast<char*>(this) + 0xE8);
    DWORD* end = *reinterpret_cast<DWORD**>(reinterpret_cast<char*>(this) + 0xEC);

    if (base == 0 || current >= end) {
        ReallocFn(&value, 1, current);
    } else {
        *current = value;
        ++current;
    }
}
