//
// Created by Zé Pedro on 04/01/2022.
//

#ifndef MYFORTHNDKAPPLICATION_NATIVE_LIB_H
#define MYFORTHNDKAPPLICATION_NATIVE_LIB_H

#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_TAG "native-lib"
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)

#define ACTIVITY_FLAG 268435456

#endif //MYFORTHNDKAPPLICATION_NATIVE_LIB_H
