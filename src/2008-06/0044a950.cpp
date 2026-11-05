// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct CRbxPlayDocTemplate {
    int method(std::string value);
    int forward(std::string value);
};
int CRbxPlayDocTemplate::method(std::string value)
{
    return !forward(value);
}
