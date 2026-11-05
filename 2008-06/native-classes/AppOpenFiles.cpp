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
