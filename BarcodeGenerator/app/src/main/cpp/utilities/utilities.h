//
// Created by Zé Pedro on 16/12/2021.
//
#include <jni.h>
#include <string>
#include <android/log.h>
#include <android/bitmap.h>

#define HELLO "Hello from C++"
#define LOG_TAG    "barcodeme"
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#ifndef BARCODEGENERATOR_UTILITIES_H
#define BARCODEGENERATOR_UTILITIES_H

const char *getSequence(char charWeWant);
void createBarcode(AndroidBitmapInfo infoBarcode, void *pixelsBarcode, const char *stringData);

#endif //BARCODEGENERATOR_UTILITIES_H
