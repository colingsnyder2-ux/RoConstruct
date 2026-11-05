// from server: 43% by tester
struct Cluster {
    float m_idmass;
    float m_imass;
    float m_ndamping;
    float m_ldamping;
    float m_adamping;
    float m_matching;
    float m_maxSelfCollisionImpulse;
    float m_selfCollisionImpulseFactor;
    bool m_containsAnchor;
    bool m_collide;
    int m_clusterIndex;
    void* m_leaf;
};

extern "C" void InterlockedIncrement(int* value);

void __stdcall func_0090a240(Cluster* this_) {
    InterlockedIncrement((int*)&this_->m_idmass);
    this_->m_imass = 0.0f;
    this_->m_ndamping = 0.0f;
    this_->m_ldamping = 0.0f;
    this_->m_adamping = 0.0f;
    this_->m_matching = 0.0f;
    this_->m_maxSelfCollisionImpulse = 100.0f;
    this_->m_selfCollisionImpulseFactor = 0.01f;
    this_->m_containsAnchor = false;
    this_->m_collide = false;
    this_->m_clusterIndex = 0;
    this_->m_leaf = 0;
}
