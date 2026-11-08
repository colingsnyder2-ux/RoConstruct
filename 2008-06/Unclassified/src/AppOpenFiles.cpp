// >>> native-status (generated) -- do not edit >>>
// AppOpenFiles | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 0704d61a | roc native-status --write
#include "CRobloxApp.h"
#include <algorithm>
#include <boost/bind.hpp>
BOOL CRobloxApp::openFiles(std::vector<std::string>::iterator first,
                          std::vector<std::string>::iterator last)
{
    return std::find_if(first, last, boost::bind(&CRobloxApp::openFileFailed, this, _1)) == last;
}

int CRobloxApp::openFileFailed(std::string file)
{
    return !openFile(file);
}
