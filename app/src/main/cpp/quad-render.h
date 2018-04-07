//
// Created by thinkreed on 2018/4/7.
//

#ifndef KCANVAS_QUAD_RENDER_H
#define KCANVAS_QUAD_RENDER_H

#include <GLES3/gl3.h>
#include "shader.h"

class Renderer {
 public:
  bool init();
  Renderer();
  ~Renderer();
  void resize(int w, int h);
  void render();
 private:
  enum {
    VB_INSTANCE, VB_SCALEROT, VB_OFFSET, VB_COUNT
  };
  float mScale[2];
  float mAngularVelocity;
  uint64_t mLastFrameNs;
  float mAngles;
  GLuint mProgram;
  GLuint mVB[VB_COUNT];
  GLuint mVBState;
  float *mapTransformBuf();
  void unmapTransformBuf();
  void draw();
  void calcSceneParams(int w, int h);
  void step();
};

Renderer *createRenderer();
#endif //KCANVAS_QUAD_RENDER_H
