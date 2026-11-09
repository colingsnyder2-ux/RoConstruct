/** @page guidecollision Collisions and Intersections 

  \htmlonly
<TABLE BORDER=0 WIDTH=80%><TR><TD><I><FONT FACE="Arial">
<A HREF="guidephysics.html"><IMG SRC="backarrow.gif" BORDER=0 ALIGN=MIDDLE>
Physics</A></I></FONT></TD><TD ALIGN=RIGHT><FONT FACE="Arial"><I>
<A HREF="guideeffects.html">
Effects<IMG SRC="forwardarrow.gif" BORDER=0 ALIGN=MIDDLE></A></I></FONT></TD></TR></TABLE>
\endhtmlonly

This section gives links to the documentation for functions which compute intersections between 
various geometry primitives. 
See also <A HREF="http://www.realtimerendering.com/int/">Real-Time Rendering</A> 
for links to descriptions of the algorithms.  
<table cellpadding="3" cellspacing="0" border="1" width="100%" summary="Links to G3D methods for calculating intersections between various geometry primitives">
 <tr>
  <th scope="col"></th>
  <th scope="col">Ray</th>  
  <th scope="col">Plane</th>  
  <th scope="col">Sphere</th>
  <th scope="col">Capsule (moving sphere)</th>
  <th scope="col">Triangle</th>
  <th scope="col">AABox</th>
  <th scope="col">Box</th>
 </tr>
 <tr>  <!------------ Ray ------------->
  <td>Ray</td>
  <!-- Ray -->
  <td>
  	G3D::CollisionDetection::closestPointsBetweenLineAndLine
  </td>
  <!-- Plane -->
  <td>
  	G3D::Ray::intersectionTime("G3D::Plane"), 
  	G3D::CollisionDetection::collisionTimeForMovingPointFixedPlane 
  </td>
  <!-- Sphere -->
  <td>
  	G3D::Ray::intersectionTime("G3D::Sphere"), 
  	G3D::CollisionDetection::collisionTimeForMovingPointFixedSphere
  </td>
  <td> 
  <!-- Capsule -->
  	G3D::CollisionDetection::collisionTimeForMovingPointFixedCapsule
  </td>
  <!-- Triangle -->
  <td>
  	G3D::Ray::intersectionTime("G3D::Triangle"), 
  	G3D::CollisionDetection::collisionTimeForMovingPointFixedTriangle
  </td>
  <!-- AABox -->
  <td>
  	G3D::Ray::intersectionTime("G3D::AABox"), 
  	G3D::CollisionDetection::collisionTimeForMovingPointFixedAABox, 
  	G3D::CollisionDetection::collisionLocationForMovingPointFixedAABox
  </td>
  <!-- Box -->
  <td>
  	G3D::Ray::intersectionTime("G3D::Box"), 
    G3D::CollisionDetection::collisionTimeForMovingPointFixedBox
  </td>
 </tr>
 <tr> <!------------ Plane ------------->
  <td>Plane</td>
  <!-- Ray -->
  <td>
  	G3D::Ray::intersectionTime("G3D::Plane"), 
  	G3D::CollisionDetection::collisionTimeForMovingPointFixedPlane 
  </td>
  <!-- Plane -->
  <td>
  	(none)
  </td>
  <!-- Sphere -->
  <td>
 	G3D::CollisionDetection::penetrationDepthForFixedSphereFixedPlane  
 	G3D::CollisionDetection::collisionTimeForMovingSphereFixedPlane  
  </td>
  <td> 
  <!-- Capsule -->
  	(none)
  </td>
  <!-- Triangle -->
  <td>
  	(none)
  </td>
  <!-- AABox -->
  <td>
  	(none)
  </td>
  <!-- Box -->
  <td>
 	G3D::CollisionDetection::penetrationDepthForFixedBoxFixedPlane  	
  </td>
 </tr>
 <tr> <!------------ Sphere ------------->
  <td>Sphere</td>
  <!-- Ray -->
  <td>
    G3D::Ray::intersectionTime("G3D::Sphere"), 
  	G3D::CollisionDetection::collisionTimeForMovingPointFixedSphere
  </td>
  <!-- Plane -->
  <td>
   	G3D::CollisionDetection::penetrationDepthForFixedSphereFixedPlane  
 	G3D::CollisionDetection::collisionTimeForMovingSphereFixedPlane  
  </td>
  <!-- Sphere -->
  <td>
  	G3D::CollisionDetection::penetrationDepthForFixedSphereFixedSphere
  	G3D::CollisionDetection::collisionTimeForMovingSphereFixedSphere
  	G3D::CollisionDetection::fixedSolidSphereIntersectsFixedSolidSphere
  </td>
  <!-- Capsule -->
  <td> 
    G3D::CollisionDetection::collisionTimeForMovingSphereFixedCapsule
  </td>
  <!-- Triangle -->
  <td>
   	G3D::CollisionDetection::collisionTimeForMovingSphereFixedTriangle
  </td>
  <!-- AABox -->
  <td>
  	(none)
  </td>
  <!-- Box -->
  <td>
   	G3D::CollisionDetection::penetrationDepthForFixedSphereFixedBox
   	G3D::CollisionDetection::fixedSolidSphereIntersectsFixedSolidBox
  </td>
 </tr>
 <tr> <!------------ Capsule ------------->
  <td>Capsule</td>
  <!-- Ray -->
  <td>
    G3D::CollisionDetection::collisionTimeForMovingPointFixedCapsule
  </td>
  <!-- Plane -->
  <td>
  	(none)
  </td>
  <!-- Sphere -->
  <td>
   G3D::CollisionDetection::collisionTimeForMovingSphereFixedCapsule
  </td>
  <!-- Capsule -->
  <td> 
  	(none)
  </td>
  <!-- Triangle -->
  <td>
  	(none)
  </td>
  <!-- AABox -->
  <td>
  	(none)
  </td>
  <!-- Box -->
  <td>
  	(none)
  </td>
 </tr>
 <tr> <!------------ Triangle ------------->
  <td>Triangle</td>
  <!-- Ray -->
  <td>
    G3D::Ray::intersectionTime("G3D::Triangle"), 
  	G3D::CollisionDetection::collisionTimeForMovingPointFixedTriangle
  </td>
  <!-- Plane -->
  <td>
  	(none)
  </td>
  <!-- Sphere -->
  <td>
  	(none)
  </td>
  <!-- Capsule -->
  <td> 
  	(none)
  </td>
  <!-- Triangle -->
  <td>
   	G3D::CollisionDetection::collisionTimeForMovingSphereFixedTriangle
  </td>
  <!-- AABox -->
  <td>
  	(none)
  </td>
  <!-- Box -->
  <td>
  	(none)
  </td>
 </tr>
 <tr> <!------------ AABox ------------->
  <td>AABox</td>
  <!-- Ray -->
  <td>
    G3D::Ray::intersectionTime("G3D::AABox"), 
  	G3D::CollisionDetection::collisionTimeForMovingPointFixedAABox, 
  	G3D::CollisionDetection::collisionLocationForMovingPointFixedAABox
  </td>
  <!-- Plane -->
  <td>
  	(none)
  </td>
  <!-- Sphere -->
  <td>
  	(none)
  </td>
  <!-- Capsule -->
  <td> 
  	(none)
  </td>
  <!-- Triangle -->
  <td>
  	(none)
  </td>
  <!-- AABox -->
  <td>
  	(none)
  </td>
  <!-- Box -->
  <td>
  	(none)
  </td>
 </tr>
 <tr> <!------------ Box ------------->
  <td>Box</td>
  <!-- Ray -->
  <td>
    G3D::Ray::intersectionTime("G3D::Box"), 
    G3D::CollisionDetection::collisionTimeForMovingPointFixedBox
  </td>
  <!-- Plane -->
  <td>
   	G3D::CollisionDetection::penetrationDepthForFixedBoxFixedPlane
  </td>
  <!-- Sphere -->
  <td>
	G3D::CollisionDetection::penetrationDepthForFixedSphereFixedBox
  </td>
  <!-- Capsule -->
  <td>
  	(none)
  </td>
  <!-- Triangle -->
  <td>
  	(none)  </td>
  <!-- AABox -->
  <td>
  	(none)
  </td>
  <!-- Box -->
  <td>
  	G3D::CollisionDetection::penetrationDepthForFixedBoxFixedBox
  </td>
 </tr>
</table>


  */