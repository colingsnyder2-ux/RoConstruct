// >>> native-status (generated) -- do not edit >>>
// AppOpenFiles | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by colin (+1) (chatgpt:gpt-6.1-sol)
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
