// >>> native-status (generated) -- do not edit >>>
// ChangeHistoryPlayback | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 8130590e | roc native-status --write
#include "v8datamodel/ChangeHistoryService.h"
#include "v8datamodel/HistoryRecord.h"
#include <stdexcept>

namespace {
class RestoreFlag {
    bool& value;
    bool previous;
public:
    explicit RestoreFlag(bool& flag) : value(flag), previous(flag) { value = true; }
    ~RestoreFlag() { value = previous; }
};
}

void RBX::ChangeHistoryService::play()
{
    if (playing) throw std::runtime_error("ChangeHistoryService is currently playing");
    if (!enabled) throw std::runtime_error("ChangeHistoryService is disabled");
    if (forward == history.end()) throw std::runtime_error("Attempt to play beyond change history");
    RestoreFlag restore(playing);
    (*forward)->play();
    backward = forward;
    ++forward;
}

void RBX::ChangeHistoryService::unplay()
{
    if (playing) throw std::runtime_error("ChangeHistoryService is currently playing");
    if (!enabled) throw std::runtime_error("ChangeHistoryService is disabled");
    if (backward == history.begin()) throw std::runtime_error("Attempt to unplay before the change history");
    RestoreFlag restore(playing);
    (*backward)->unplay();
    forward = backward;
    --backward;
}
