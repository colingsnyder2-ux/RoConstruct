// Stub implementations for unresolved native-class dependencies.
// Provides dummy implementations so the client links and runs (playable but buggy).

#include <afxwin.h>
#include "CRobloxDoc.h"
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include <istream>

// Forward declarations for stubbed types not in headers
namespace RBX {
    class DataModel; // declared in v8datamodel/DataModel.h
    namespace Network {
        class Players; // stubbed below
    }
    class ChangeHistoryService; // stubbed below
}

class LuaAllocator; // stubbed below

CRobloxDoc* currentDocument = NULL;

void setCurrentDocument(bool, CRobloxDoc*) {}

// CRobloxDoc methods declared but not defined
void CRobloxDoc::handle_453c30(NMHDR*, LRESULT*) {}
void CRobloxDoc::handle_454c90() {}
void CRobloxDoc::handle_455c30() {}

namespace RBX {

double DataModel::getFrameRate() const { return 0.0; }
double DataModel::getDutyCycle() const { return 0.0; }

namespace Network {

class Players {
public:
    bool canReportAbuse() const { return false; }
};

bool Players::canReportAbuse() const { return false; }

} // namespace Network

class ChangeHistoryService {
public:
    void setEnabled(bool) {}
};

void ChangeHistoryService::setEnabled(bool) {}

} // namespace RBX

class LuaAllocator {
public:
    void getHeapStats(unsigned int&, unsigned int&) const {}
};

void LuaAllocator::getHeapStats(unsigned int&, unsigned int&) const {}

void CWorkspace::cleanup() {}
void CWorkspace::load(std::istream&) {}
