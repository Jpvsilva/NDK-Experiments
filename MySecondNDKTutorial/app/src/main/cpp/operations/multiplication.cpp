//
// Created by Zé Pedro on 16/12/2021.
//
#include <jni.h>
#include <string>

extern "C"{
    JNIEXPORT jint JNICALL
    Java_com_example_mysecondndkapplication_MainActivity_multiplyInt(
            JNIEnv *env,
            jobject thiz,
            jint x,
            jint y) {
        return x*y;
    }

    JNIEXPORT jfloat JNICALL
    Java_com_example_mysecondndkapplication_MainActivity_multiplyFloat(
            JNIEnv *env,
            jobject thiz,
            jint x,
            jint y) {
        return x*y;
    }

    JNIEXPORT jdouble JNICALL
    Java_com_example_mysecondndkapplication_MainActivity_multiplyDouble(
            JNIEnv *env,
            jobject thiz,
            jdouble x,
            jdouble y) {
        return x*y;
    }
}
