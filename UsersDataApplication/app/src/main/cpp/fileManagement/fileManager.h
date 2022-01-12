//
// Created by Zé Pedro on 22/12/2021.
//
#include <jni.h>
#include <string.h>
#include <ctime>
#include <iostream>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <exception>
#include <android/log.h>
#include <android/asset_manager_jni.h>
#include <android/asset_manager.h>

#define LOG_TAG "fileManager"
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)

#ifndef USERSDATAAPPLICATION_FILEMANAGER_H
#define USERSDATAAPPLICATION_FILEMANAGER_H

#endif //USERSDATAAPPLICATION_FILEMANAGER_H
