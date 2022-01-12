//
// Created by Zé Pedro on 16/12/2021.
//
#include <jni.h>
#include <string>

int sum(const int x[], int n){

    int result = 0;
    for(int i=0;i<n;i++){
        result+=x[i];
    }

    return result;
}

extern "C"{
    JNIEXPORT jint JNICALL
    Java_com_example_mysecondndkapplication_MainActivity_summation(
            JNIEnv *env,
            jobject thiz,
            jintArray a) {
        jint *b = (*env).GetIntArrayElements(a, nullptr);
        jsize n = (*env).GetArrayLength(a);

        int result = sum(b,n);

        (*env).ReleaseIntArrayElements(a, b, 0);

        return result;
    }
}
