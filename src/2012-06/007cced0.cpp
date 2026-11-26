// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 007fa220  unit: RBX::MoveResizeJoinTool  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007fa220
//
// 007fa220  64a100000000         mov eax, dword ptr fs:[0]
// 007fa226  6aff                 push -1
// 007fa228  6819e7ab00           push 0xabe719
// 007fa22d  50                   push eax
// 007fa22e  64892500000000       mov dword ptr fs:[0], esp
// 007fa235  8d442410             lea eax, [esp + 0x10]
// 007fa239  50                   push eax
// 007fa23a  81c1c8000000         add ecx, 0xc8
// 007fa240  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007fa248  ff155826b200         call dword ptr [0xb22658]
// 007fa24e  8d4c2410             lea ecx, [esp + 0x10]
// 007fa252  c7442408ffffffff     mov dword ptr [esp + 8], 0xffffffff
// 007fa25a  ff153c26b200         call dword ptr [0xb2263c]
// 007fa260  8b0c24               mov ecx, dword ptr [esp]
// 007fa263  64890d00000000       mov dword ptr fs:[0], ecx
// 007fa26a  83c40c               add esp, 0xc
// 007fa26d  c21c00               ret 0x1c

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
        char pad[0xbc];
        String cursor;
        void setCursor(String newCursor);
    };
}

void RBX::MoveResizeJoinTool::setCursor(String newCursor)
{
    cursor = newCursor;
}
