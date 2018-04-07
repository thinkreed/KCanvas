//
// Created by thinkreed on 2018/4/7.
//
#include <linux/time.h>
#include "cube-render.h"

uint64_t lastFrameNs;

extern "C" {
JNIEXPORT jboolean JNICALL Java_thinkreed_kcanvas_KCanvasJni_init(JNIEnv *env, jobject obj);
JNIEXPORT void JNICALL Java_thinkreed_kcanvas_KCanvasJni_resize(JNIEnv *env, jobject obj, jint width, jint height);
JNIEXPORT void JNICALL Java_thinkreed_kcanvas_KCanvasJni_step(JNIEnv *env, jobject obj);
JNIEXPORT void JNICALL Java_thinkreed_kcanvas_KCanvasJni_destroy(JNIEnv *env, jclass type);
}

JNIEXPORT jboolean JNICALL Java_thinkreed_kcanvas_KCanvasJni_init(JNIEnv *env, jobject obj) {
  if (init()) {
    return JNI_TRUE;
  }
  return JNI_FALSE;
}

JNIEXPORT void JNICALL Java_thinkreed_kcanvas_KCanvasJni_resize(JNIEnv *env, jobject obj, jint width, jint height) {
  setAspect((GLfloat) width / (GLfloat) height);
  glViewport(0, 0, width, height);
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

JNIEXPORT void JNICALL Java_thinkreed_kcanvas_KCanvasJni_step(JNIEnv *env, jobject obj) {
  timespec now;
  clock_gettime(CLOCK_MONOTONIC, &now);
  auto nowNs = now.tv_sec * 1000000000ull + now.tv_nsec;
  if (lastFrameNs > 0) {
    float dt = float(nowNs - lastFrameNs) * 0.000000001f;
    update(dt);
    glDrawArrays(GL_TRIANGLES, 0, 36);
  }
  lastFrameNs = nowNs;
}


JNIEXPORT void JNICALL Java_thinkreed_kcanvas_KCanvasJni_destroy(JNIEnv *env, jclass type) {
  destroy();
}

