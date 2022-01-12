//
// Created by Zé Pedro on 17/12/2021.
//
#include <jni.h>
#include <string.h>
#include <ctime>
#include <iostream>
#include <android/log.h>

#define LOG_TAG    "userDB"
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)

#ifndef USERSDATAAPPLICATION_USERSDB_H
#define USERSDATAAPPLICATION_USERSDB_H

const char *getBalanceMessage();

const char *jstring2string(JNIEnv *env, jstring stringJava);

const char *jfloat2string(JNIEnv *env, jfloat balance);

#endif //USERSDATAAPPLICATION_USERSDB_H
