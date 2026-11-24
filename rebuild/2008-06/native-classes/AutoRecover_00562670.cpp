// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: layout from disassembly (string at 0, int at 0x1c).
struct ContentId {
    std::string id;
    int type;
};

struct CachedContent {
    int pad0;
    int pad1;
    std::string data; // +8
};

struct ContentProvider;

extern "C" CachedContent* __fastcall fn_00561980(ContentProvider* self, int unusedEdx, ContentId id, int a, const void* b);
extern "C" bool __fastcall fn_0055bb50(const ContentId* self, int unusedEdx);
extern "C" bool __fastcall fn_0055f7b0(ContentProvider* self, int unusedEdx, const char* url);
extern "C" bool __fastcall fn_00560200(ContentProvider* self, int unusedEdx, CachedContent* c);

extern "C" void __fastcall fn_00562670(ContentProvider* self, int unusedEdx, const ContentId* id, int* result, std::string* out)
{
    CachedContent* c = fn_00561980(self, 0, *id, 1, 0);
    if (!c) {
        if (fn_0055bb50(id, 0) && !fn_0055f7b0(self, 0, id->id.c_str())) {
            *result = 0;
            return;
        }
        *result = 2;
        return;
    }
    if (!fn_00560200(self, 0, c)) {
        *result = 2;
        return;
    }
    *out = c->data;
    *result = 1;
}
