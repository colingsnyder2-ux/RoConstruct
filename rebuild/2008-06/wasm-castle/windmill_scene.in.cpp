        sceneBuildId=1;
        Builder millRock(scene,"Dark stone grey",brickColour(199));
        millRock.castShadows=false;
        for(int layer=0;layer<5;++layer) millRock.brick(80,-2-layer*1.5f,0,30-layer*4,2,26-layer*3,false);
        millRock.finish(scene);
        Builder millGrass(scene,"Dark green",brickColour(28));
        millGrass.castShadows=false;millGrass.brick(80,-0.5f,0,28,1,24);millGrass.finish(scene);
        Builder millBody(scene,"White",brickColour(1));
        millBody.brick(80,7,0,10,14,8,false);
        for(int layer=0;layer<5;++layer) millBody.brick(80,14.5f+layer,0,10-layer*2,1,8,false);
        millBody.brick(72,3,0,6,4,7,false);
        millBody.brick(88,3,0,6,4,7,false);
        millBody.finish(scene);
        Builder millTrim(scene,"Dark orange",brickColour(38));
        millTrim.brick(80,4.5f,0,11,0.5f,9,false);
        for(int x=-1;x<=1;x+=2) {
            for(int z=-1;z<=1;z+=2) {
                millTrim.brick(80+x*5,7,z*4,0.5f,14,0.5f,false);
                millTrim.brick(80+x*10.5f,1,z*3,0.5f,2,0.5f,false);
            }
            for(int y=6;y<=10;y+=4) {
                millTrim.brick(80+x*2, y,4.5f,1,2.5f,0.5f,false);
                millTrim.brick(80+x*5,y,0,0.5f,2.5f,3,false);
            }
        }
        for(int step=0;step<3;++step) millTrim.brick(88,1+step*0.5f,6-step,3,1+step,1);
        millTrim.finish(scene);
        Builder millRoof(scene,"Bright red",brickColour(21));
        // Whole gable plates, with a long ridge rather than a pyramid roof.
        for(int layer=0;layer<7;++layer) millRoof.brick(80,14.5f+layer,0,14-layer*2,1,11);
        for(int layer=0;layer<3;++layer) millRoof.brick(72,5.5f+layer*0.5f,0,7-layer,0.5f,8-layer);
        millRoof.brick(88,5.5f,0,7,0.5f,8);millRoof.finish(scene);
        Builder millFrames(scene,"Light stone grey",brickColour(208));
        for(int y=6;y<=10;y+=4) {
            millFrames.brick(80,y,4.5f,2.5f,2.5f,0.5f,false);
            millFrames.brick(74.5f,y,0,0.5f,2.5f,2.5f,false);
        }
        millFrames.brick(80,17,4.5f,2,2,0.5f,false);
        for(int side=-1;side<=1;side+=2) millFrames.brick(80+side*8,3,4,2,2,0.5f,false);
        millFrames.finish(scene);
        Builder millDark(scene,"Medium blue",brickColour(102));
        millDark.brick(80,2.5f,4.5f,2,3,0.5f,false);
        millDark.brick(88,3,4,2,3,0.5f,false);
        for(int y=6;y<=10;y+=4) {
            millDark.brick(80,y,5,1.5f,1.5f,0.5f,false);
            millDark.brick(74,y,0,0.5f,1.5f,1.5f,false);
        }
        millDark.brick(80,17,5,1,1,0.5f,false);
        millDark.brick(72,3,4.5f,1,1,0.5f,false);millDark.finish(scene);
        Builder millDoor(scene,"Reddish brown",brickColour(192));
        millDoor.brick(80,2,5,2,4,0.5f,false);
        millDoor.brick(88,2.5f,4.5f,2,3,0.5f,false);millDoor.finish(scene);
        Builder trunks(scene,"Reddish brown",brickColour(192));
        Builder leaves(scene,"Earth green",brickColour(141));
        const float millTree[5][2]={{-11,-8},{11,-8},{-3,-9},{-11,8},{11,8}};
        for(int tree=0;tree<5;++tree) {
            float x=80+millTree[tree][0],z=millTree[tree][1];
            trunks.brick(x,1.5f,z,1,3,1,false);
            for(int tier=0;tier<3;++tier) leaves.brick(x,3.5f+tier,z,4-tier,1,4-tier);
        }
        trunks.finish(scene);leaves.finish(scene);
        // Lattice rails and open slots, not solid paddle blades. All geometry
        // moves through the recovered scene-node/entity transform and shadows.
        Builder sails(scene,"Brick yellow",brickColour(5));
        for(int arm=0;arm<4;++arm) {
            for(int rail=0;rail<2;++rail) {
                float x=rail*1.5f,y=4.5f;
                for(int turn=0;turn<arm;++turn) {float previous=x;x=-y;y=previous;}
                sails.brick(x,y,0,arm%2?7:0.5f,arm%2?0.5f:7,0.5f,false);
            }
            for(int rung=0;rung<8;++rung) {
                float x=0.5f,y=1+rung;
                for(int turn=0;turn<arm;++turn) {float previous=x;x=-y;y=previous;}
                sails.brick(x,y,0,arm%2?0.5f:1.5f,arm%2?1.5f:0.5f,0.5f,false);
            }
        }
        sails.brick(0,0,0,1.5f,1.5f,1,false);
        sails.finish(scene);windmillRotor=sails.object;
        windmillTransformKey=static_cast<DemoSceneManager*>(scene)->parts.size();
