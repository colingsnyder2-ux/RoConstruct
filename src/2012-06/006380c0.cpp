// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace G3D {
class Token {
public:
    std::string _string;
    int rest[7];
};
class TextInput {
public:
    Token readStringToken();
    std::string readString();
};
std::string TextInput::readString() {
    return readStringToken()._string;
}
}
