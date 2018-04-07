//
// Created by thinkreed on 2018/4/7.
//
#include "quad-render.h"

static Renderer *g_renderer = NULL;

extern "C" {
JNIEXPORT jboolean JNICALL Java_thinkreed_kcanvas_KCanvasJni_init(JNIEnv *env, jobject obj);
JNIEXPORT void JNICALL Java_thinkreed_kcanvas_KCanvasJni_resize(JNIEnv *env, jobject obj, jint width, jint height);
JNIEXPORT void JNICALL Java_thinkreed_kcanvas_KCanvasJni_step(JNIEnv *env, jobject obj);
}

JNIEXPORT jboolean JNICALL Java_thinkreed_kcanvas_KCanvasJni_init(JNIEnv *env, jobject obj) {
  if (g_renderer) {
    delete g_renderer;
    g_renderer = NULL;
  }
  g_renderer = createRenderer();
  if (!g_renderer) {
    return JNI_FALSE;
  }
  return JNI_TRUE;
}

JNIEXPORT void JNICALL Java_thinkreed_kcanvas_KCanvasJni_resize(JNIEnv *env, jobject obj, jint width, jint height) {
  if (!g_renderer) {
    return;
  }
  g_renderer->resize(width, height);
}

JNIEXPORT void JNICALL Java_thinkreed_kcanvas_KCanvasJni_step(JNIEnv *env, jobject obj) {
  if (!g_renderer) {
    return;
  }
  g_renderer->render();
}

