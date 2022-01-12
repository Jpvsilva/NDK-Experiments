#include "native-lib.h"

extern "C" {

JNIEXPORT jstring JNICALL
Java_com_example_myforthndkapplication_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */
        ) {
    std::string hello = "Please choose a category of exercises:";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT void JNICALL
Java_com_example_myforthndkapplication_MainActivity_openEmptyActivity(
        JNIEnv *env,
        jobject thiz,
        jobject context
        ) {
    LOGI("Opening Empty Activity");
    jclass native_context = env->GetObjectClass(context);
    jclass intentClass = env->FindClass("android/content/Intent");
    jclass actionString = env->FindClass("com/example/myforthndkapplication/EmptyActivity");
    jmethodID newIntent = env->GetMethodID(intentClass, "<init>",
                                           "(Landroid/content/Context;Ljava/lang/Class;)V");
    jobject intent = env->NewObject(intentClass, newIntent, context, actionString);
    jmethodID methodFlag = env->GetMethodID(intentClass, "setFlags", "(I)Landroid/content/Intent;");
    jobject intentActivity = env->CallObjectMethod(intent, methodFlag, ACTIVITY_FLAG);
    jmethodID startActivityMethodId = env->GetMethodID(native_context, "startActivity",
                                                       "(Landroid/content/Intent;)V");
    env->CallVoidMethod(context, startActivityMethodId, intentActivity);
}

JNIEXPORT void JNICALL
Java_com_example_myforthndkapplication_MainActivity_openFileActivity(
        JNIEnv *env,
        jobject thiz,
        jobject context
        ) {
    LOGI("Opening File Activity");
    jclass native_context = env->GetObjectClass(context);
    jclass intentClass = env->FindClass("android/content/Intent");
    jclass actionString = env->FindClass("com/example/myforthndkapplication/FileActivity");
    jmethodID newIntent = env->GetMethodID(intentClass, "<init>",
                                           "(Landroid/content/Context;Ljava/lang/Class;)V");
    jobject intent = env->NewObject(intentClass, newIntent, context, actionString);
    jmethodID methodFlag = env->GetMethodID(intentClass, "setFlags", "(I)Landroid/content/Intent;");
    jobject intentActivity = env->CallObjectMethod(intent, methodFlag, ACTIVITY_FLAG);
    jmethodID startActivityMethodId = env->GetMethodID(native_context, "startActivity",
                                                       "(Landroid/content/Intent;)V");
    env->CallVoidMethod(context, startActivityMethodId, intentActivity);
}
}