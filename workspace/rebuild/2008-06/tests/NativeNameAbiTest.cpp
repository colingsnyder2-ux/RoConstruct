#include <cstdio>
#include <cstring>

struct Name;
extern "C" const Name* nativeNameNull();
extern "C" const Name* nativeNameDeclare(const char*, int);
extern "C" const Name* nativeNameLookup(const char*);
extern "C" unsigned nativeNameSize();
extern "C" int nativeNameIndex(const Name*);
extern "C" const char* nativeNameText(const Name*);
extern "C" const Name* donorNameNull();
extern "C" const Name* donorNameDeclare(const char*, int);
extern "C" const Name* donorNameLookup(const char*);
extern "C" unsigned donorNameSize();
extern "C" int donorNameIndex(const Name*);
extern "C" const char* donorNameText(const Name*);

int main() {
    if (nativeNameSize() != 32 || donorNameSize() != 32) return 1;
    if (nativeNameNull() != donorNameNull()) return 2;
    if (nativeNameLookup("missing-native-name-abi") != donorNameNull()) return 3;
    const Name* value = donorNameDeclare("native-name-abi", -1);
    if (nativeNameLookup("native-name-abi") != value) return 4;
    if (nativeNameDeclare("native-name-abi", 37) != value) return 5;
    if (nativeNameIndex(value) != 37 || donorNameIndex(value) != 37) return 6;
    if (std::strcmp(nativeNameText(value), "native-name-abi") || std::strcmp(donorNameText(value), "native-name-abi")) return 7;
    const Name* other = nativeNameDeclare("other-native-name-abi", -1);
    if (donorNameLookup("other-native-name-abi") != other || other == value) return 8;
    std::puts("PASS native/donor Name layout and shared intern table");
    return 0;
}
