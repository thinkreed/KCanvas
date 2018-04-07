//
// Created by thinkreed on 2018/4/7.
//

#ifndef KCANVAS_SHADER_H
#define KCANVAS_SHADER_H
#include <android/log.h>
#include <GLES3/gl3.h>
#include <stdlib.h>
#include <string.h>
#include <jni.h>
#define LOG_TAG "kcanvas-jni"
#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

GLuint createProgram(const char *vtxSrc, const char *fragSrc);
bool checkGlError(const char *funcName);

#endif //KCANVAS_SHADER_H

