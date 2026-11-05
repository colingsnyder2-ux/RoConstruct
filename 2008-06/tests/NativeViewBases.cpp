#include "../native-headers/VerbBinder.h"
#include "../native-headers/v8tree/VerbContainer.h"
#include "../native-headers/v8tree/Service.h"

class CRobloxView;
namespace RBX { namespace Network { class Players; class SuperSafeChanged; } }
// Base-only layout probe; does not represent the complete CRobloxView.
class NativeViewBases : public VerbBinder<CRobloxView, CView>,
    public RBX::VerbContainer,
    public RBX::Listener<RBX::ServiceProvider, RBX::ServiceAdded>,
    public RBX::Listener<RBX::ServiceProvider, RBX::ServiceRemoving>,
    public RBX::Listener<RBX::Network::Players, RBX::Network::SuperSafeChanged> {};
NativeViewBases* nativeViewBases;
