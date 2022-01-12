//
// Created by Zé Pedro on 16/12/2021.
//
#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myfirstndkapplication_MainActivity_calculateArea(
        JNIEnv* env,
        jobject /*this*/,
        jdouble radius
){
    jdouble area = M_PI * radius * radius;
    char output[40];
    sprintf(output, "Result is: %f m^2", area);
    return env->NewStringUTF(output);
}