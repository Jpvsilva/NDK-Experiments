//
// Created by Zé Pedro on 16/12/2021.
//
#include <jni.h>
#include <string>

extern "C"{

int multiply(const int x[], int n){

    int result = 1;
    for(int i=0;i<n;i++){
        result*=x[i];
    }

    return result;
}

JNIEXPORT jint JNICALL
Java_com_example_mysecondndkapplication_MainActivity_arrayMultiplication(
        JNIEnv *env,
        jobject thiz,
        jintArray a) {
    jint *b = (*env).GetIntArrayElements(a, nullptr);
    jsize n = (*env).GetArrayLength(a);

    int result = multiply(b,n);

    (*env).ReleaseIntArrayElements(a, b, 0);

    return result;
}
}
