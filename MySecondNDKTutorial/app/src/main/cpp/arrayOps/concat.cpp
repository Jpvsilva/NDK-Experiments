//
// Created by Zé Pedro on 16/12/2021.
//
#include <jni.h>
#include <string>

std::string ConvertJString(JNIEnv* env, jstring str)
{
    if ( !str ) std::string();

    const jsize len = env->GetStringUTFLength(str);
    const char* strChars = env->GetStringUTFChars(str, (jboolean *)nullptr);

    std::string Result(strChars, len);

    env->ReleaseStringUTFChars(str, strChars);

    return Result;
}

extern "C"{
    JNIEXPORT jstring JNICALL
    Java_com_example_mysecondndkapplication_MainActivity_concat(
            JNIEnv *env,
            jobject thiz,
            jstring a,
            jstring b) {

        std::string aString = ConvertJString(env,a);
        std::string bString = ConvertJString(env,b);
        std::string result = aString + bString;
        return env->NewStringUTF(result.c_str());
    }
}
