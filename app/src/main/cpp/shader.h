//
// Created by thinkreed on 2018/4/7.
//

#ifndef KCANVAS_SHADER_H
#define KCANVAS_SHADER_H
#include <GLES3/gl3.h>
#include <android/log.h>
#include <jni.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#define STR(s) #s
#define STRV(s) STR(s)
#define LOG_TAG "kcanvas-jni"
#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

GLuint createProgram(const char *vertex_file_path, const char *fragment_file_path);
bool checkGlError(const char *funcName);

#endif //KCANVAS_SHADER_H

