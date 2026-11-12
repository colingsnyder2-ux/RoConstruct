// from server: 59% by EspClaude
// roc 2007-08 004f34e0  size: 215 bytes
// target (abridged): SEH + /GS frame; std::string name (dllimport ctor 0x77e6a4);
// temp std::string(0x79f680 "HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\"); bool 0x50a7f0(temp, name) cdecl; ~temp;
// ok ? copy(name) : string(0x79f660 "Could not determine CPU name"); ~name; return by value.
#include <string>

bool readCpuName(const std::string& key, std::string& value);

std::string getCpuName()
{
    std::string name;
    bool ok = readCpuName(std::string("HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\"), name);
    if (ok)
        return name;
    return "Could not determine CPU name";
}
