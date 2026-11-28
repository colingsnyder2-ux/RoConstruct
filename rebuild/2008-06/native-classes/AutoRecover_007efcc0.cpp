// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no Name.h excerpt was provided, so a minimal local RBX::Name declaration is used.
// The mangled callee name ?declare@Name@RBX@@SAABV12@PBDH@Z means
// static const Name& Name::declare(const char*, int).
namespace RBX {
    class Name {
    public:
        static const Name& declare(const char* name, int index);
    };
}

// INFERRED: global at 0x96ee48 is a reference to the declared Name. extern keeps external linkage
// so the dynamic initializer is emitted as ??__Etag_roblox_part@@YAXXZ.
extern const RBX::Name& tag_roblox_part;
const RBX::Name& tag_roblox_part = RBX::Name::declare("roblox_part", -1);
