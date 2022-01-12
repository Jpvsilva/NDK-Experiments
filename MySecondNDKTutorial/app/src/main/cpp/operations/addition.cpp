//
// Created by Zé Pedro on 16/12/2021.
//
#include <jni.h>
#include <string>
#include <iostream>

extern "C" {
    JNIEXPORT jint
    Java_com_example_mysecondndkapplication_MainActivity_addInt(
            JNIEnv *env,
            jobject thiz,
            jint x,
            jint y) {
        return x + y;
    }

    JNIEXPORT jfloat
    Java_com_example_mysecondndkapplication_MainActivity_addFloat(
            JNIEnv *env,
            jobject thiz,
            jfloat x,
            jfloat y) {
        std::cout << "Hey";
        return x + y;
    }

    JNIEXPORT jdouble
    Java_com_example_mysecondndkapplication_MainActivity_addDouble(
            JNIEnv *env,
            jobject thiz,
            jdouble x,
            jdouble y) {
        return x + y;
    }
}




