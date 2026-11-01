#pragma once
#include <string>
namespace RBX {
// Partial interface: original service factory and history methods; layout open.
class ChangeHistoryService {
public:
    void setEnabled(bool);
    void unplay();
    void play();
    bool queryUnplay(std::string&, int);
    bool queryPlay(std::string&, int);
    void initializeBase();
};
}
