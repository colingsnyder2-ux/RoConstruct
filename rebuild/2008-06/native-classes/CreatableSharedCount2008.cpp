// boost::detail::shared_count::shared_count<T*, RBX::Creatable<RBX::Instance>::Deleter>(T*, Deleter) instances (2008-06,
// inactive). Each original is a 131-byte COMDAT (pinned extent: ret 8 at +0x6b, then the catch(...) funclet that
// calls the deleter and rethrows) storing the sp_counted_impl_pd<T*, Deleter> vtable named by its RTTI; the
// expected address and T of every instance are listed in tests/record_native_creatable_shared_count.py.
// Every T is the complete class of a committed native header (included read-only); nothing is declared here.
// DHTMLWindowService2008.h includes MFC and must precede the headers that include windows.h (afxv_w32.h C1189).
// >>> native-status (generated) -- do not edit >>>
// CreatableSharedCount2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 672bf1a4 | roc native-status --write
#include "AppLeaves2008/DHTMLWindowService2008.h"
#include "AuthoringSettings.h"
#include "ChatEnter.h"
#include "util/RunStateOwner.h"
#include "v8datamodel/Team.h"
#include "Network/Player.h"
#include "v8datamodel/Selection.h"
#include "reflection/Metadata.h"
#include "Network/Players.h"
#include "v8datamodel/ModelInstance.h"
#include "script/Script.h"
#include "v8datamodel/ChangeHistoryService.h"
#include "v8datamodel/Decal.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/SpecialShape.h"
#include "script/ScriptContext.h"
#include "v8datamodel/Accoutrement.h"
#include "util/Sound.h"
#include "v8datamodel/Visit.h"
#include "v8datamodel/UserController.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/Backpack.h"
#include "v8datamodel/TimerService.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/SpawnLocation.h"
#include "v8datamodel/SpawnerService.h"
#include "v8datamodel/Clothing.h"
#include "v8datamodel/BodyColors.h"
#include "v8datamodel/Teams.h"
#include "humanoid/Humanoid.h"
#include "Network/NetworkSettings.h"
#include "v8datamodel/Message.h"
#include "v8datamodel/JointsService.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/Sky.h"
#include "v8datamodel/GlobalSettings.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "gui/Gui.h"
#include "LocalBackpack2008/LocalBackpack2008.h"
#include "v8datamodel/Tool.h"
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/Feature.h"
#include "v8datamodel/Flag.h"
#include "v8datamodel/ClickDetector.h"
#include "v8datamodel/Explosion.h"
#include "v8datamodel/FlagStand.h"
#include "v8datamodel/FlagStandService.h"
#include "v8datamodel/BodyMovers.h"
#include "v8datamodel/Rocket.h"
#include "v8datamodel/Value.h"
#include "v8datamodel/Seat.h"
#include "v8datamodel/Sparkles.h"
#include "gui/WidgetMenuItem.h"
#include "gui/WidgetButtons.h"
#include "gui/ChatOutput.h"
#include "gui/WidgetChat.h"
#include "gui/ScoreHud.h"
#include "gui/HealthHud.h"
#include "gui/EquationDisplay.h"
#include "gui/ArrowPanel.h"

typedef RBX::Creatable<RBX::Instance>::Deleter CreatableInstanceDeleter;

template boost::detail::shared_count::shared_count(RBX::RunService*, CreatableInstanceDeleter); // 00405e60
template boost::detail::shared_count::shared_count(RBX::Team*, CreatableInstanceDeleter); // 00409000
template boost::detail::shared_count::shared_count(RBX::Network::Player*, CreatableInstanceDeleter); // 00409270
template boost::detail::shared_count::shared_count(RBX::Selection*, CreatableInstanceDeleter); // 004094e0
template boost::detail::shared_count::shared_count(RBX::Reflection::Metadata::Classes*, CreatableInstanceDeleter); // 0040b560
template boost::detail::shared_count::shared_count(RBX::Reflection::Metadata::Class*, CreatableInstanceDeleter); // 0040b810
template boost::detail::shared_count::shared_count(RBX::Reflection::Metadata::Properties*, CreatableInstanceDeleter); // 0040bcb0
template boost::detail::shared_count::shared_count(RBX::Reflection::Metadata::Functions*, CreatableInstanceDeleter); // 0040bf70
template boost::detail::shared_count::shared_count(RBX::Reflection::Metadata::Events*, CreatableInstanceDeleter); // 0040c260
template boost::detail::shared_count::shared_count(RBX::Reflection::Metadata::Member*, CreatableInstanceDeleter); // 0040c430
template boost::detail::shared_count::shared_count(AuthoringSettings*, CreatableInstanceDeleter); // 0040c620
template boost::detail::shared_count::shared_count(ChatEnter*, CreatableInstanceDeleter); // 004118a0
template boost::detail::shared_count::shared_count(RBX::Network::Players*, CreatableInstanceDeleter); // 00411940
template boost::detail::shared_count::shared_count(RBX::ModelInstance*, CreatableInstanceDeleter); // 00414820
template boost::detail::shared_count::shared_count(RBX::Script*, CreatableInstanceDeleter); // 00414a90
template boost::detail::shared_count::shared_count(RBX::LocalScript*, CreatableInstanceDeleter); // 00414d00
template boost::detail::shared_count::shared_count(RBX::ChangeHistoryService*, CreatableInstanceDeleter); // 00414f70
template boost::detail::shared_count::shared_count(DHTMLWindowService*, CreatableInstanceDeleter); // 0041ba00
template boost::detail::shared_count::shared_count(RBX::Decal*, CreatableInstanceDeleter); // 0041e100
template boost::detail::shared_count::shared_count(RBX::Texture*, CreatableInstanceDeleter); // 0041e190
template boost::detail::shared_count::shared_count(RBX::PartInstance*, CreatableInstanceDeleter); // 0041e880
template boost::detail::shared_count::shared_count(RBX::SpecialShape*, CreatableInstanceDeleter); // 0041eaf0
template boost::detail::shared_count::shared_count(RBX::ScriptContext*, CreatableInstanceDeleter); // 0042d0f0
template boost::detail::shared_count::shared_count(RBX::Accoutrement*, CreatableInstanceDeleter); // 004323e0
template boost::detail::shared_count::shared_count(RBX::Hat*, CreatableInstanceDeleter); // 00432650
template boost::detail::shared_count::shared_count(RBX::Soundscape::SoundService*, CreatableInstanceDeleter); // 00440840
template boost::detail::shared_count::shared_count(RBX::Soundscape::SoundChannel*, CreatableInstanceDeleter); // 00440ab0
template boost::detail::shared_count::shared_count(RBX::Visit*, CreatableInstanceDeleter); // 00452790
template boost::detail::shared_count::shared_count(RBX::ControllerService*, CreatableInstanceDeleter); // 0045b790
template boost::detail::shared_count::shared_count(RBX::Camera*, CreatableInstanceDeleter); // 0045da00
template boost::detail::shared_count::shared_count(RBX::Backpack*, CreatableInstanceDeleter); // 0048ac30
template boost::detail::shared_count::shared_count(RBX::TimerService*, CreatableInstanceDeleter); // 0048acc0
template boost::detail::shared_count::shared_count(RBX::HopperBin*, CreatableInstanceDeleter); // 0048e650
template boost::detail::shared_count::shared_count(RBX::StarterPackService*, CreatableInstanceDeleter); // 0048e8c0
template boost::detail::shared_count::shared_count(RBX::LegacyHopperService*, CreatableInstanceDeleter); // 0048eb30
template boost::detail::shared_count::shared_count(RBX::SpawnLocation*, CreatableInstanceDeleter); // 0048ee70
template boost::detail::shared_count::shared_count(RBX::SpawnerService*, CreatableInstanceDeleter); // 0048f0e0
template boost::detail::shared_count::shared_count(RBX::ShirtGraphic*, CreatableInstanceDeleter); // 0048f350
template boost::detail::shared_count::shared_count(RBX::Clothing*, CreatableInstanceDeleter); // 0048f5c0
template boost::detail::shared_count::shared_count(RBX::Pants*, CreatableInstanceDeleter); // 0048f900
template boost::detail::shared_count::shared_count(RBX::Shirt*, CreatableInstanceDeleter); // 0048fc00
template boost::detail::shared_count::shared_count(RBX::BodyColors*, CreatableInstanceDeleter); // 0048fe30
template boost::detail::shared_count::shared_count(RBX::Skin*, CreatableInstanceDeleter); // 004900a0
template boost::detail::shared_count::shared_count(RBX::Teams*, CreatableInstanceDeleter); // 00490310
template boost::detail::shared_count::shared_count(RBX::Humanoid*, CreatableInstanceDeleter); // 00490630
template boost::detail::shared_count::shared_count(RBX::NetworkSettings*, CreatableInstanceDeleter); // 0049e620
template boost::detail::shared_count::shared_count(RBX::Message*, CreatableInstanceDeleter); // 004a3710
template boost::detail::shared_count::shared_count(RBX::Hint*, CreatableInstanceDeleter); // 004a3a00
template boost::detail::shared_count::shared_count(RBX::JointsService*, CreatableInstanceDeleter); // 004ac710
template boost::detail::shared_count::shared_count(RBX::Snap*, CreatableInstanceDeleter); // 004b2270
template boost::detail::shared_count::shared_count(RBX::Weld*, CreatableInstanceDeleter); // 004b24e0
template boost::detail::shared_count::shared_count(RBX::Glue*, CreatableInstanceDeleter); // 004b2750
template boost::detail::shared_count::shared_count(RBX::Rotate*, CreatableInstanceDeleter); // 004b29c0
template boost::detail::shared_count::shared_count(RBX::RotateP*, CreatableInstanceDeleter); // 004b2c30
template boost::detail::shared_count::shared_count(RBX::RotateV*, CreatableInstanceDeleter); // 004b2ea0
template boost::detail::shared_count::shared_count(RBX::Motor*, CreatableInstanceDeleter); // 004b3110
template boost::detail::shared_count::shared_count(RBX::Sky*, CreatableInstanceDeleter); // 004d8b50
template boost::detail::shared_count::shared_count(RBX::GlobalSettings*, CreatableInstanceDeleter); // 00568600
template boost::detail::shared_count::shared_count(RBX::DataModel*, CreatableInstanceDeleter); // 00576630
template boost::detail::shared_count::shared_count(RBX::Workspace*, CreatableInstanceDeleter); // 005766c0
template boost::detail::shared_count::shared_count(RBX::GuiRoot*, CreatableInstanceDeleter); // 00576750
template boost::detail::shared_count::shared_count(RBX::LocalBackpack*, CreatableInstanceDeleter); // 00576810
template boost::detail::shared_count::shared_count(RBX::Tool*, CreatableInstanceDeleter); // 005782c0
template boost::detail::shared_count::shared_count(RBX::FilteredSelection<RBX::PVInstance>*, CreatableInstanceDeleter); // 0057ddc0
template boost::detail::shared_count::shared_count(RBX::FilteredSelection<RBX::ModelInstance>*, CreatableInstanceDeleter); // 0057de50
template boost::detail::shared_count::shared_count(RBX::MotorFeature*, CreatableInstanceDeleter); // 0057fe80
template boost::detail::shared_count::shared_count(RBX::Hole*, CreatableInstanceDeleter); // 005800f0
template boost::detail::shared_count::shared_count(RBX::VelocityMotor*, CreatableInstanceDeleter); // 00580360
template boost::detail::shared_count::shared_count(RBX::Flag*, CreatableInstanceDeleter); // 005a3070
template boost::detail::shared_count::shared_count(StockSound*, CreatableInstanceDeleter); // 005b7480
template boost::detail::shared_count::shared_count(SoundServiceStatsItem*, CreatableInstanceDeleter); // 005b7510
template boost::detail::shared_count::shared_count(RBX::ClickDetector*, CreatableInstanceDeleter); // 005c0a20
template boost::detail::shared_count::shared_count(RBX::Explosion*, CreatableInstanceDeleter); // 005c0c90
template boost::detail::shared_count::shared_count(RBX::FlagStand*, CreatableInstanceDeleter); // 005c0f00
template boost::detail::shared_count::shared_count(RBX::FlagStandService*, CreatableInstanceDeleter); // 005c1170
template boost::detail::shared_count::shared_count(RBX::BodyGyro*, CreatableInstanceDeleter); // 005c18c0
template boost::detail::shared_count::shared_count(RBX::BodyForce*, CreatableInstanceDeleter); // 005c1b30
template boost::detail::shared_count::shared_count(RBX::BodyThrust*, CreatableInstanceDeleter); // 005c1da0
template boost::detail::shared_count::shared_count(RBX::BodyPosition*, CreatableInstanceDeleter); // 005c2010
template boost::detail::shared_count::shared_count(RBX::BodyVelocity*, CreatableInstanceDeleter); // 005c2280
template boost::detail::shared_count::shared_count(RBX::BodyAngularVelocity*, CreatableInstanceDeleter); // 005c24f0
template boost::detail::shared_count::shared_count(RBX::Rocket*, CreatableInstanceDeleter); // 005c2760
template boost::detail::shared_count::shared_count(RBX::ObjectValue*, CreatableInstanceDeleter); // 005c2af0
template boost::detail::shared_count::shared_count(RBX::Seat*, CreatableInstanceDeleter); // 005c2f40
template boost::detail::shared_count::shared_count(RBX::Sparkles*, CreatableInstanceDeleter); // 005c31b0
template boost::detail::shared_count::shared_count(RBX::FilteredSelection<RBX::PartInstance>*, CreatableInstanceDeleter); // 005d7c80
template boost::detail::shared_count::shared_count(RBX::RelativePanel*, CreatableInstanceDeleter); // 006006a0
template boost::detail::shared_count::shared_count(RBX::MenuItem*, CreatableInstanceDeleter); // 00600730
template boost::detail::shared_count::shared_count(RBX::ImageButton*, CreatableInstanceDeleter); // 006007c0
template boost::detail::shared_count::shared_count(RBX::TopMenuBar*, CreatableInstanceDeleter); // 00600850
template boost::detail::shared_count::shared_count(RBX::ChatOutput*, CreatableInstanceDeleter); // 006008e0
template boost::detail::shared_count::shared_count(RBX::ChatWidget*, CreatableInstanceDeleter); // 00600970
template boost::detail::shared_count::shared_count(RBX::PercentPanel*, CreatableInstanceDeleter); // 00600a00
template boost::detail::shared_count::shared_count(RBX::ChatButton*, CreatableInstanceDeleter); // 00600a90
template boost::detail::shared_count::shared_count(RBX::ScoreHud*, CreatableInstanceDeleter); // 00600b20
template boost::detail::shared_count::shared_count(RBX::HealthHud*, CreatableInstanceDeleter); // 00600bb0
template boost::detail::shared_count::shared_count(RBX::TextDisplay*, CreatableInstanceDeleter); // 00600c40
template boost::detail::shared_count::shared_count(RBX::EquationDisplay*, CreatableInstanceDeleter); // 00600cd0
template boost::detail::shared_count::shared_count(RBX::ArrowPanel*, CreatableInstanceDeleter); // 00600df0
template boost::detail::shared_count::shared_count(RBX::MenuSpacer*, CreatableInstanceDeleter); // 00600e80
template boost::detail::shared_count::shared_count(RBX::FilteredSelection<RBX::Instance>*, CreatableInstanceDeleter); // 00616410
template boost::detail::shared_count::shared_count(RBX::IntValue*, CreatableInstanceDeleter); // 00635150
template boost::detail::shared_count::shared_count(RBX::BoolValue*, CreatableInstanceDeleter); // 006353c0
template boost::detail::shared_count::shared_count(RBX::DoubleValue*, CreatableInstanceDeleter); // 00635640
template boost::detail::shared_count::shared_count(RBX::StringValue*, CreatableInstanceDeleter); // 006358a0
template boost::detail::shared_count::shared_count(RBX::Vector3Value*, CreatableInstanceDeleter); // 00635ae0
template boost::detail::shared_count::shared_count(RBX::CFrameValue*, CreatableInstanceDeleter); // 00635d70
template boost::detail::shared_count::shared_count(RBX::Color3Value*, CreatableInstanceDeleter); // 00635fd0
template boost::detail::shared_count::shared_count(RBX::BrickColorValue*, CreatableInstanceDeleter); // 00636210
template boost::detail::shared_count::shared_count(RBX::ImageWidget*, CreatableInstanceDeleter); // 00656c90
template boost::detail::shared_count::shared_count(RBX::ArrowButton*, CreatableInstanceDeleter); // 00656d20
