//
// Created by Zé Pedro on 17/12/2021.
//
#include <jni.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <android/log.h>

#define LOG_TAG "native-lib"
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)

const char *get_welcome();

#ifndef USERSDATAAPPLICATION_MAIN_ACTIVITY_H
#define USERSDATAAPPLICATION_MAIN_ACTIVITY_H

#endif //USERSDATAAPPLICATION_MAIN_ACTIVITY_H
