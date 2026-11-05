namespace RBX {
const char sPhysicsService[] = "PhysicsService";
const char sInstance[] = "Instance";
PhysicsService::~PhysicsService() {}
template boost::shared_ptr<PhysicsService> Creatable<Instance>::create<PhysicsService>();
}
