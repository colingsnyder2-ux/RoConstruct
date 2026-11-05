// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class Adorn;
class DataModel;
class Controller {
public:
    enum ControllerType { NO_CONTROLLER, PRIMARY_CONTROLLER, SECONDARY_CONTROLLER, PAD_ONE_CONTROLLER, PAD_TWO_CONTROLLER, AI_CHASE_CONTROLLER, AI_FLEE_CONTROLLER, PLAYER_CONTROLLER };
};
enum SDLKey { SDLK_a = 'a', SDLK_d = 'd', SDLK_h = 'h', SDLK_j = 'j', SDLK_k = 'k', SDLK_s = 's', SDLK_u = 'u', SDLK_w = 'w' };
class Layout { public: enum Style { HORIZONTAL = 0, VERTICAL = 1 }; };
class B0 { public: virtual ~B0(); char pad[0xc]; };
class B10 { public: virtual void b10(); };
class B14a { public: virtual void b14(); char pad[8]; };
class B14b { public: virtual void b20(); };
class B14 : public B14a, public B14b {};
template<int N> class NotifierBase { public: virtual void notify(); char pad[0x1c]; };
class InstanceLike : public B0, public B10, public B14,
    public NotifierBase<0>, public NotifierBase<1>, public NotifierBase<2>,
    public NotifierBase<3>, public NotifierBase<4>, public NotifierBase<5>
{
    char pad[0x130 - 0xe4];
};
class GuiLike { public: virtual void render(); };
class TopMenuBar : public InstanceLike, public GuiLike {
public:
    TopMenuBar(const std::string& name, Layout::Style style, bool vertical);
    virtual ~TopMenuBar();
private:
    char pad[0x15c - 0x134];
};
class ArrowPanel : public TopMenuBar {
    DataModel* dataModel;                    // 0x15c
    Controller::ControllerType controllerType; // 0x160
    void init(Adorn* adorn, const std::string& title, const std::string& up, const std::string& down, const std::string& left, const std::string& right, SDLKey upKey, SDLKey downKey, SDLKey leftKey, SDLKey rightKey);
public:
    ArrowPanel(Adorn* adorn, DataModel* model, Controller::ControllerType type);
    virtual ~ArrowPanel();
};
ArrowPanel::ArrowPanel(Adorn* adorn, DataModel* model, Controller::ControllerType type)
    : TopMenuBar("ArrowPanel", Layout::HORIZONTAL, false)
{
    dataModel = model;
    controllerType = type;
    switch (type) {
    case Controller::PLAYER_CONTROLLER:
        init(adorn, "Character", "W_key", "S_key", "A_key", "D_key", SDLK_w, SDLK_s, SDLK_a, SDLK_d);
        break;
    case Controller::PRIMARY_CONTROLLER:
        init(adorn, "Controller1", "U_key", "J_key", "H_key", "K_key", SDLK_u, SDLK_j, SDLK_h, SDLK_k);
        break;
    case Controller::SECONDARY_CONTROLLER:
        init(adorn, "Controller2", "W_key", "S_key", "A_key", "D_key", SDLK_w, SDLK_s, SDLK_a, SDLK_d);
        break;
    }
}
}
