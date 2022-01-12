//
// Created by Zé Pedro on 16/12/2021.
//
#include <jni.h>
#include <string>
#include <iostream>

extern "C"{
    JNIEXPORT jint JNICALL
    Java_com_example_mysecondndkapplication_MainActivity_subtractInt(
            JNIEnv *env,
            jobject thiz,
            jint x,
            jint y) {
        std::cout << "Hi";
        return x-y;
    }

    JNIEXPORT jfloat JNICALL
    Java_com_example_mysecondndkapplication_MainActivity_subtractFloat(
            JNIEnv *env,
            jobject thiz,
            jfloat x,
            jfloat y) {
        return x-y;
    }

    JNIEXPORT jdouble JNICALL
    Java_com_example_mysecondndkapplication_MainActivity_subtractDouble(
            JNIEnv *env,
            jobject thiz,
            jdouble x,
            jdouble y) {
        std::cout << "Hi";
        return x-y;
    }
}
