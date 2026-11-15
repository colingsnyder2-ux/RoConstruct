#include "v8datamodel/ChangeHistoryService.h"
#include "v8datamodel/HistoryRecord.h"

bool RBX::ChangeHistoryService::queryPlay(std::string& result, int count)
{
    if (!enabled) return false;
    std::list<HistoryRecord*>::iterator it = forward;
    for (int i = 0; i < count; ++i) {
        if (it == history.end()) return false;
        ++it;
    }
    if (it == history.end()) return false;
    result = (*it)->name;
    return true;
}

bool RBX::ChangeHistoryService::queryUnplay(std::string& result, int count)
{
    if (!enabled) return false;
    std::list<HistoryRecord*>::iterator it = backward;
    for (int i = 0; i < count; ++i) {
        if (it == history.begin()) return false;
        --it;
    }
    if (it == history.end()) return false;
    if (it == history.begin()) return false;
    result = (*it)->name;
    return true;
}
