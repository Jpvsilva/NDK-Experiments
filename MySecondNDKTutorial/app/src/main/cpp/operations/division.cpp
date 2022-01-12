//
// Created by Zé Pedro on 16/12/2021.
//
#include <jni.h>
#include <string>

extern "C"{

    int divideInt(int x, int y){
        return x/y;
    }

    JNIEXPORT jstring
    Java_com_example_mysecondndkapplication_MainActivity_divideInt(
            JNIEnv *env,
            jobject thiz,
            jint x,
            jint y) {
        if(y==0){
            std::string result = "Can not divideInt by zero";
            return env->NewStringUTF(result.c_str());
        }else{
            char result[40];
            sprintf(result, "%d", divideInt(x, y));
            return env->NewStringUTF(result);
        }
    }

    JNIEXPORT jstring
    Java_com_example_mysecondndkapplication_MainActivity_divideFloat(
            JNIEnv *env,
            jobject thiz,
            jfloat x,
            jfloat y) {
        if(y==0){
            std::string result = "Can not divideInt by zero";
            return env->NewStringUTF(result.c_str());
        }else{
            char result[40];
            sprintf(result,"%f",x/y);
            return env->NewStringUTF(result);
        }
    }

    JNIEXPORT jstring
    Java_com_example_mysecondndkapplication_MainActivity_divideDouble(
            JNIEnv *env,
            jobject thiz,
            jdouble x,
            jdouble y) {
        if(y==0){
            std::string result = "Can not divideInt by zero";
            return env->NewStringUTF(result.c_str());
        }else{
            char result[40];
            sprintf(result,"%f",x/y);
            return env->NewStringUTF(result);
        }
    }
}
