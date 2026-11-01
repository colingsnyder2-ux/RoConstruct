// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-raknet roc_espeon_aug2007_rakpeer_historical_ping_20e57361c792704f.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASE
#pragma include_alias("ReliabilityLayer.h", "roc_espeon_aug2007_reliability_header_db733c89c2c48cf7.cpp")
#pragma include_alias(<ReliabilityLayer.h>, <roc_espeon_aug2007_reliability_header_db733c89c2c48cf7.cpp>)
#include "RakPeer.h"
int RakPeer::GetLastPing(const SystemAddress systemAddress) const {
 RemoteSystemStruct* remoteSystem = GetRemoteSystemFromSystemAddress(systemAddress, false, false);
 if (remoteSystem == 0) return -1;
 if (remoteSystem->pingAndClockDifferentialWriteIndex == 0)
  return remoteSystem->pingAndClockDifferential[PING_TIMES_ARRAY_SIZE - 1].pingTime;
 return remoteSystem->pingAndClockDifferential[remoteSystem->pingAndClockDifferentialWriteIndex - 1].pingTime;
}

bool RakPeer::IsNetworkSimulatorActive(void){return _maxSendBPS>0 || _minExtraPing>0 || _extraPingVariance>0;}
