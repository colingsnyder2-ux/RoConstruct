// from server: 100% by EspClaude
// roc 2007-08 00448690  unit: CIDEDocManager
#include <string>
#include <stdexcept>
std::string formatMessage(int code, std::string message);
class CDocLoadError : public std::logic_error {
public:
    CDocLoadError(int code, std::string message);
    int m_code;
};
CDocLoadError::CDocLoadError(int code, std::string message)
    : std::logic_error(formatMessage(code, message)), m_code(code)
{
}
