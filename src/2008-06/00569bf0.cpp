// from server: 100% by king_originala
typedef unsigned long DWORD;
typedef void* HKEY;
typedef long (__stdcall *OpenKeyFunction)(
    HKEY, const char*, DWORD, DWORD, HKEY*);

extern "C" OpenKeyFunction RegOpenKeyExA;
extern "C" long (__stdcall *RegQueryValueExA)(
    HKEY, const char*, DWORD*, DWORD*, unsigned char*, DWORD*);
extern "C" long (__stdcall *RegCloseKey)(HKEY);

const char userPath[] = "Software\\ROBLOX Corporation\\Roblox";
const char machinePath[] = "Software\\Roblox";
const char valueName[] = "SkipTrustCheck";
extern bool skipTrustCheck;

struct RegistryLocals {
    HKEY userKey;
    union {
        struct {
            DWORD size;
            DWORD type;
        } user;
        struct {
            HKEY key;
            DWORD size;
            DWORD type;
        } machine;
    };
};

void loadSkipTrustCheck()
{
    DWORD value = 0;
    RegistryLocals data;
    OpenKeyFunction openKey = RegOpenKeyExA;
    HKEY key = 0;
    data.userKey = 0;

    if (openKey(reinterpret_cast<HKEY>(0x80000001UL),
                userPath, 0, 0x20019, &data.userKey) == 0)
    {
        key = data.userKey;
        data.user.size = 4;
        RegQueryValueExA(
            key, valueName, 0, &data.user.type,
            reinterpret_cast<unsigned char*>(&value), &data.user.size);
    }
    else
    {
        data.machine.key = 0;
        if (openKey(reinterpret_cast<HKEY>(0x80000002UL),
                    machinePath, 0, 0x20019, &data.machine.key) == 0)
        {
            key = data.machine.key;
            data.machine.size = 4;
            RegQueryValueExA(
                key, valueName, 0, &data.machine.type,
                reinterpret_cast<unsigned char*>(&value),
                &data.machine.size);
        }
    }

    skipTrustCheck = value != 0;
    if (key)
        RegCloseKey(key);
}
