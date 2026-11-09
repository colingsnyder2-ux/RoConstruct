// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_qualityvolatile11857824d6c617cf.cpp

// Candidate translation unit (score above; library headers required).
struct Descriptor; extern Descriptor qualityProperty;
struct Settings { char prefix[0x328];volatile float value;void changed(const Descriptor&); void set(float v) {if(value!=v){value=v;changed(qualityProperty);}} };
struct Interface {void setQuality(float);};
void Interface::setQuality(float v) {Settings* owner=reinterpret_cast<Settings*>(reinterpret_cast<char*>(this)-0x3fc); if(v<3.f)owner->set(0.f);else if(v<6.f)owner->set(.5f);else owner->set(1.f);}
