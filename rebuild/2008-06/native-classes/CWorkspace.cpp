#include <afxwin.h>
#include "../native-headers/CWorkspace.h"

// 0046ab60: ATL/base constructors and both shared owners initialize themselves.
CWorkspace::CWorkspace() {}

// 0046a940: return the retained DataModel owner by value.
boost::shared_ptr<RBX::DataModel> CWorkspace::getDataModel() { return dataModel; }
