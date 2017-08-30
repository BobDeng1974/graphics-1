xof 0303txt 0032
template XSkinMeshHeader {
 <3cf169ce-ff7c-44ab-93c0-f78f62d172e2>
 WORD nMaxSkinWeightsPerVertex;
 WORD nMaxSkinWeightsPerFace;
 WORD nBones;
}

template VertexDuplicationIndices {
 <b8d65549-d7c9-4995-89cf-53a9a8b031e3>
 DWORD nIndices;
 DWORD nOriginalVertices;
 array DWORD indices[nIndices];
}

template SkinWeights {
 <6f0d123b-bad2-4167-a0d0-80224f25fabb>
 STRING transformNodeName;
 DWORD nWeights;
 array DWORD vertexIndices[nWeights];
 array FLOAT weights[nWeights];
 Matrix4x4 matrixOffset;
}


Frame SCENE_ROOT {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
 }

 Frame groundPlane_transform {
  

  FrameTransformMatrix {
   10.000000,0.000000,0.000000,0.000000,0.000000,0.000000,10.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }
 }

 Frame persp {
  

  FrameTransformMatrix {
   -0.912120,-0.000000,0.409923,0.000000,0.165019,0.915393,0.367184,0.000000,-0.375241,0.402561,-0.834949,0.000000,-110.715416,118.776169,-246.352966,1.000000;;
  }
 }

 Frame top {
  

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,-1.000000,0.000000,0.000000,1.000000,0.000000,0.000000,-552.763062,10020.154297,128.411041,1.000000;;
  }
 }

 Frame front {
  

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,64.176056,1999.952515,10134.481445,1.000000;;
  }
 }

 Frame side {
  

  FrameTransformMatrix {
   0.000000,0.000000,-1.000000,0.000000,0.000000,1.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,10124.230469,1585.576538,76.173088,1.000000;;
  }
 }

 Frame pCube1 {
  

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Mesh pCubeShape1 {
   24;
   -50.000000;-50.000000;50.000000;,
   50.000000;-50.000000;50.000000;,
   -50.000000;50.000000;50.000000;,
   50.000000;50.000000;50.000000;,
   -50.000000;50.000000;-50.000000;,
   50.000000;50.000000;-50.000000;,
   -50.000000;-50.000000;-50.000000;,
   50.000000;-50.000000;-50.000000;,
   -50.000000;50.000000;50.000000;,
   50.000000;50.000000;50.000000;,
   -50.000000;50.000000;-50.000000;,
   50.000000;50.000000;-50.000000;,
   -50.000000;-50.000000;-50.000000;,
   50.000000;-50.000000;-50.000000;,
   50.000000;-50.000000;50.000000;,
   -50.000000;-50.000000;50.000000;,
   50.000000;-50.000000;50.000000;,
   50.000000;-50.000000;-50.000000;,
   50.000000;50.000000;-50.000000;,
   50.000000;50.000000;50.000000;,
   -50.000000;-50.000000;-50.000000;,
   -50.000000;-50.000000;50.000000;,
   -50.000000;50.000000;50.000000;,
   -50.000000;50.000000;-50.000000;;
   6;
   4;0,1,3,2;,
   4;8,9,5,4;,
   4;10,11,7,6;,
   4;12,13,14,15;,
   4;16,17,18,19;,
   4;20,21,22,23;;

   MeshNormals {
    6;
    -1.000000;0.000000;0.000000;,
    0.000000;-1.000000;0.000000;,
    0.000000;0.000000;-1.000000;,
    0.000000;0.000000;1.000000;,
    0.000000;1.000000;0.000000;,
    1.000000;0.000000;0.000000;;
    6;
    4;3,3,3,3;,
    4;4,4,4,4;,
    4;2,2,2,2;,
    4;1,1,1,1;,
    4;5,5,5,5;,
    4;0,0,0,0;;
   }

   MeshTextureCoords {
    24;
    0.000000;0.000000;,
    1.000000;0.000000;,
    0.000000;-1.000000;,
    1.000000;-1.000000;,
    0.000000;-2.000000;,
    1.000000;-2.000000;,
    0.000000;-3.000000;,
    1.000000;-3.000000;,
    0.000000;-1.000000;,
    1.000000;-1.000000;,
    0.000000;-2.000000;,
    1.000000;-2.000000;,
    0.000000;-3.000000;,
    1.000000;-3.000000;,
    1.000000;-4.000000;,
    0.000000;-4.000000;,
    1.000000;0.000000;,
    2.000000;0.000000;,
    2.000000;-1.000000;,
    1.000000;-1.000000;,
    -1.000000;0.000000;,
    0.000000;0.000000;,
    0.000000;-1.000000;,
    -1.000000;-1.000000;;
   }

   MeshMaterialList {
    1;
    6;
    0,
    0,
    0,
    0,
    0,
    0;

    Material Arm_left {
     0.800000;0.800000;0.800000;1.000000;;
     0.500000;
     0.500000;0.500000;0.500000;;
     0.000000;0.000000;0.000000;;

     TextureFilename {
      "../Tex/EX_1_c0_arm_left.png";
     }
    }
   }

   VertexDuplicationIndices {
    24;
    8;
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    2,
    3,
    4,
    5,
    6,
    7,
    1,
    0,
    1,
    7,
    5,
    3,
    6,
    0,
    2,
    4;
   }
  }
 }
}

AnimationSet {
 
}