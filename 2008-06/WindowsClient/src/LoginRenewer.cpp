// >>> native-status (generated) -- do not edit >>>
// LoginRenewer | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src d093e4f5 | roc native-status --write
#include "LoginRenewer.h"
#include <boost/bind.hpp>
#include <string>
// Original functions 00427310 and 00427480; symbol identities provisional.
std::string loginRenewalUrl();
RBX::worker_thread::work_result renewLogin(std::string);
LoginRenewer::LoginRenewer()
    : RBX::worker_thread(boost::bind(renewLogin, loginRenewalUrl()), "LoginRenewer") {}
