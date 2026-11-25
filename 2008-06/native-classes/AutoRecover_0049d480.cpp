// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
#include <stdexcept>
#include <string>
#include <boost/shared_ptr.hpp>

// INFERRED: no native headers were shown, so every type here is a file-local
// stand-in and every callee is an fn_<addr> extern. Layout follows the disassembly.
struct Local_0049d480_Player;
struct Local_0049d480_Impersonator { void* a; void* prev; };

struct Local_0049d480_World {
    char pad[0x1a0];
    Local_0049d480_Player* localPlayer;               // +0x1a0
    boost::detail::shared_count localPlayerCount;     // +0x1a4
};

extern "C" {
void __fastcall fn_00409d50(void* self, int unusedEdx, const std::string* msg); // runtime_error ctor
void __fastcall fn_0042bc10(Local_0049d480_Impersonator* self, int unusedEdx, int identity);
boost::shared_ptr<Local_0049d480_Player>* __cdecl fn_004093b0(Local_0049d480_Impersonator* ret);
void* __cdecl fn_0042bbb0();                                              // Context::ptr (tss)
void* __fastcall fn_005a7570(void* tss, int unusedEdx);                   // tss::get
void __fastcall fn_005a76b0(void* tss, int unusedEdx, void* p);           // tss::set
void __fastcall fn_005a6ff0(void* tss, int unusedEdx, void* p);           // tss::cleanup
void __fastcall fn_00494830(Local_0049d480_Player* self, int unusedEdx, int userId);
void __fastcall fn_0055a8f0(Local_0049d480_Player* self, int unusedEdx, void* parent);
void __fastcall fn_0040db00(void* self, int unusedEdx, const void* desc);
void __fastcall fn_00496e20(void* notifier, int unusedEdx, bool autoJoin);
}

extern "C" boost::shared_ptr<Local_0049d480_Player>* __fastcall
fn_0049d480(Local_0049d480_World* self, int unusedEdx,
            boost::shared_ptr<Local_0049d480_Player>* out, int userId)
{
    if (self->localPlayer)
        throw std::runtime_error("Local player already exists");

    Local_0049d480_Impersonator imp;
    fn_0042bc10(&imp, 0, 6);

    boost::shared_ptr<Local_0049d480_Player>* p = fn_004093b0(&imp);
    self->localPlayer = p->get();
    self->localPlayerCount = p->_internal_count();

    // inlined ~Impersonator: restore previous security context
    void* tss = fn_0042bbb0();
    void* cur = fn_005a7570(tss, 0);
    if (cur != imp.prev) {
        fn_005a76b0(tss, 0, imp.prev);
        if (cur)
            fn_005a6ff0(tss, 0, cur);
    }

    fn_00494830(self->localPlayer, 0, userId);
    fn_0055a8f0(self->localPlayer, 0, self);
    fn_0040db00(self, 0, 0);

    bool joined = false;
    if (self->localPlayer)
        joined = false; // INFERRED: virtual query on the player, result passed to raise
    fn_00496e20((char*)self + 0x150, 0, joined);

    new (out) boost::shared_ptr<Local_0049d480_Player>(
        boost::shared_ptr<Local_0049d480_Player>(*(boost::shared_ptr<Local_0049d480_Player>*)&self->localPlayer));
    return out;
}
