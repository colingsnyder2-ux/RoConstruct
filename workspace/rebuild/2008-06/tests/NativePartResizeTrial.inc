namespace RBX {
inline const G3D::Vector3& PartInstance::getPartSizeXml() const { return primitive.getGeometry()->getGridSize(); }
inline const G3D::CoordinateFrame& PartInstance::getCoordinateFrame() const { return primitive.getCoordinateFrame(); }
bool PartInstance::resize(NormalId normal,int amount) {
 if(amount==0)return false;
 G3D::Vector3 oldSize=getPartSizeXml();
 const G3D::CoordinateFrame& current=getCoordinateFrame();
 G3D::CoordinateFrame oldFrame=current;
 G3D::Vector3 ui;
 G3D::Vector3 delta;
 float sign=normal<3?1.0f:-1.0f;
 if(partType==Part::BLOCK_PART)delta[normal%3]=static_cast<float>(amount);
 else delta=G3D::Vector3(static_cast<float>(amount),static_cast<float>(amount),static_cast<float>(amount));
 ui=oldSize; switch(formFactor) {case BRICK:ui.y*=5.0f/6.0f;break;case PLATE:ui.y*=2.5f;break;}
 G3D::Vector3 newUiSize=ui+delta;
 G3D::Vector3 convertedSize=uiToXmlSize(newUiSize);
 G3D::Vector3 t;
 {G3D::Vector3 xmlDelta=convertedSize-oldSize; t=oldFrame.vectorToWorldSpace(xmlDelta)*0.5f*sign; t+=oldFrame.translation;}
 G3D::CoordinateFrame desired(oldFrame.rotation,t);
 setCoordinateFrame(desired);
 {G3D::Vector3 finalSize=uiToXmlSize(newUiSize); setPartSizeXml(finalSize);}
 join();
 if(Math::fuzzyEq(getCoordinateFrame(),desired,0.00001f,0.00001f))return true;
 setCoordinateFrame(oldFrame); setPartSizeXml(oldSize); return false;
}
}
