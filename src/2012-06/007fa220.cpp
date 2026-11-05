// from server: 100% by tajop
struct String {
    char storage[28];
    String& operator=(const String& other);
    ~String();
};

extern String& (String::*g_stringAssign)(const String&);
extern void (String::*g_stringDestroy)();

inline String& String::operator=(const String& other) { return (this->*g_stringAssign)(other); }
inline String::~String() { (this->*g_stringDestroy)(); }

namespace RBX {
    struct MoveResizeJoinTool {
        char pad[0xc8];
        String cursor;
        void setCursor(String newCursor);
    };
}

void RBX::MoveResizeJoinTool::setCursor(String newCursor)
{
    cursor = newCursor;
}
