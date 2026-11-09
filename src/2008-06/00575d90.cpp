// from server: 100% by king_originala
// roc 2008-06 00575d90 unit: RBX::DataModel; complete1528-byte evaluate body.
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Existing-pointer evaluation view. No complete DataModel layout or inheritance claim.
// Boundary names below are recovery labels where original ownership is unproven.
#include <string>
#include <cstdio>
#include <cstddef>

namespace G3D {std::string format(const char*,...);}
namespace RBX {
class IMetric {
public:
 IMetric(){}
 virtual ~IMetric(){}
 virtual std::string getMetric(const std::string&)const=0;
};
class Log {public:static std::string formatTime(double);}; //005a6c60
template<class T>class StringConverter {public:static std::string convertToString(const T&);};
template<class T>inline T metricField(const void*p,unsigned offset){return *reinterpret_cast<const T*>(static_cast<const char*>(p)+offset);}
class NativeMetricKernel {
public:
 int solverIterations()const; //005fadd0 ret0
 int matrixSize()const; //005faa90 ret0
 int bodyCount()const; //005faa20 ret0
 int leafBodyCount()const; //005faa30 ret0
 int constraintCount()const; //005fa620 ret0
 int pointCount()const; //005faa40 ret0
 float bodyKineticEnergy()const; //005faa50 ret0
 float connectorSpringEnergy()const; //005fa630 ret0
 float totalKineticEnergy()const; //00575040 ret0
};
class NativeMetricWorld {
public:
 NativeMetricKernel& kernel()const; //005e9150 ret0 tail call
 int metric(int)const; //005e9160 ret4 tail call
 int hashNodes()const; //005e9170 ret0
 int maxBucketSize()const; //005e9180 ret0
};
class NativeMetricTimeState {
public:
 double idlePercent()const; //00575690 ret0
};
class NativeMetricWorkspace;
float nativeContactPairRatio(); //00606bc0 cdecl0
float nativeContactFeatureRatio(); //00606bf0 cdecl0
float nativeConnectorsActive(); //00606100 cdecl0, resets counters

static __declspec(noinline) std::string report(double seconds){
 if(seconds>0.0){
  std::string text=Log::formatTime(seconds);
  char buffer[256];
  int percent=int(3000.0*seconds);
  std::sprintf(buffer,"%i %%  %s (%.3gfps)",percent,text.c_str(),1.0/seconds);
  return std::string(buffer);
 }
 return Log::formatTime(seconds);
}

class DataModelMetricView {
public:
 char opaque00[0x10];
 NativeMetricWorkspace*workspace;
 char opaque14[4];
 NativeMetricTimeState*timeState;
 char opaque1c[0x40];
 int drawId;
 IMetric*tempMetric;
 std::string evaluate(const std::string&)const;
};

std::string DataModelMetricView::evaluate(const std::string&valueName)const{
 NativeMetricWorld*world=metricField<NativeMetricWorld*>(workspace,0x2e4);
 if(valueName=="SimCpu")return report(metricField<double>(timeState,0x1c8));
 else if(valueName=="GfxCpu")return report(metricField<double>(timeState,0x1d0));
 else if(valueName=="UiCpu")return report(metricField<double>(timeState,0x1d8));
 else if(valueName=="IdleCpu")return G3D::format("%.2g %%",timeState->idlePercent());
 else if(valueName=="FPS")return G3D::format("%.3g",metricField<double>(timeState,0x228));
 else if(valueName=="drawId")return StringConverter<int>::convertToString(drawId);
 else if(valueName=="graphicsMode")return tempMetric->getMetric(valueName);
 else if(valueName=="FRM")return tempMetric->getMetric(valueName);
 else if(valueName=="Particles")return tempMetric->getMetric(valueName);
 else if(valueName=="Shadows")return tempMetric->getMetric(valueName);
 else if(valueName=="antiAliasing")return tempMetric->getMetric(valueName);
 else if(valueName=="bevels")return tempMetric->getMetric(valueName);
 else if(valueName=="videoMemory")return tempMetric->getMetric(valueName);
 else if(valueName=="GfxTime")return tempMetric->getMetric(valueName);
 else if(valueName=="numPrimitives")return StringConverter<int>::convertToString(metricField<int>(world,0xb0));
 else if(valueName=="numJoints")return StringConverter<int>::convertToString(metricField<int>(world,0xe4));
 else if(valueName=="numContacts")return StringConverter<int>::convertToString(metricField<int>(world,0xe8));
 else if(valueName=="numContactsInCollisionStage")return StringConverter<int>::convertToString(world->metric(0));
 else if(valueName=="numSteppingContacts")return StringConverter<int>::convertToString(world->metric(1));
 else if(valueName=="numTouchingContacts")return StringConverter<int>::convertToString(world->metric(2));
 else if(valueName=="maxTreeDepth")return StringConverter<int>::convertToString(world->metric(3));
 else if(valueName=="contactPairHitRatio")return StringConverter<float>::convertToString(nativeContactPairRatio());
 else if(valueName=="contactFeatureHitRatio")return StringConverter<float>::convertToString(nativeContactFeatureRatio());
 else if(valueName=="numLinkCalls")return StringConverter<int>::convertToString(metricField<int>(world,0xec));
 else if(valueName=="numHashNodes")return StringConverter<int>::convertToString(world->hashNodes());
 else if(valueName=="maxBucketSize")return StringConverter<int>::convertToString(world->maxBucketSize());
 else if(valueName=="eThrottle")return StringConverter<float>::convertToString(metricField<float>(world,0x80));
 else if(valueName=="solverIterations")return StringConverter<int>::convertToString(world->kernel().solverIterations());
 else if(valueName=="matrixSize")return StringConverter<int>::convertToString(world->kernel().matrixSize());
 int groupJobs=world->kernel().bodyCount();
 int projectileJobs=0;
 if(valueName=="numBodies")return StringConverter<int>::convertToString(groupJobs+projectileJobs);
 else if(valueName=="numLeafBodies")return StringConverter<int>::convertToString(world->kernel().leafBodyCount());
 else if(valueName=="numGroupJobs")return StringConverter<int>::convertToString(groupJobs);
 else if(valueName=="numProjectileJobs")return StringConverter<int>::convertToString(projectileJobs);
 else if(valueName=="numConstraints")return StringConverter<int>::convertToString(world->kernel().constraintCount());
 else if(valueName=="numPoints")return StringConverter<int>::convertToString(world->kernel().pointCount());
 else if(valueName=="percentConnectorsActive")return StringConverter<float>::convertToString(nativeConnectorsActive());
 else if(valueName=="energyBody")return StringConverter<float>::convertToString(world->kernel().bodyKineticEnergy());
 else if(valueName=="energyConnector")return StringConverter<float>::convertToString(world->kernel().connectorSpringEnergy());
 else if(valueName=="energyTotal")return StringConverter<float>::convertToString(world->kernel().totalKineticEnergy());
 return "?";
}
}

typedef char native_metric_string_size[sizeof(std::string)==28?1:-1];
typedef char native_metric_interface_size[sizeof(RBX::IMetric)==4?1:-1];
typedef char native_metric_workspace_offset[offsetof(RBX::DataModelMetricView,workspace)==0x10?1:-1];
typedef char native_metric_time_offset[offsetof(RBX::DataModelMetricView,timeState)==0x18?1:-1];
typedef char native_metric_draw_offset[offsetof(RBX::DataModelMetricView,drawId)==0x5c?1:-1];
typedef char native_metric_delegate_offset[offsetof(RBX::DataModelMetricView,tempMetric)==0x60?1:-1];
