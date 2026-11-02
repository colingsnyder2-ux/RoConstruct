#include "v8datamodel/GameSettings.h"
namespace RBX {
template<> GlobalSettingsItem<GameSettings,sGameSettings>* GlobalSettingsItem<GameSettings,sGameSettings>::sing = 0;
}
