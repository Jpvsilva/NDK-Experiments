//
// Created by Zé Pedro on 17/12/2021.
//
#include "usersDB.h"

const char *getBalanceMessage() {
    return "\nYour Account Balance is: ";
}

const char *jstring2string(JNIEnv *env, jstring stringJava) {
    jboolean isCopy;
    const char *convertedValue = (env)->GetStringUTFChars(stringJava, &isCopy);
    LOGI("convertedValue: %s", convertedValue);
    return convertedValue;
}

const char *jfloat2string(JNIEnv *env, jfloat balance) {
    char buf[64]; // assumed large enough to cope with result
    sprintf(buf, "%.2f", balance);
    return jstring2string(env, (env)->NewStringUTF(buf));
}

extern "C" {
JNIEXPORT jobject JNICALL
Java_com_example_usersdataapplication_UsersDB_createUser(
        JNIEnv *env,
        jobject thiz,
        jstring name,
        jfloat balance) {
    // Create the object of the class UserData
    jclass userDataClass = env->FindClass("com/example/usersdataapplication/UserData");
    jobject newUserData = env->AllocObject(userDataClass);

    // Get the UserData fields to be set
    jfieldID nameField = env->GetFieldID(userDataClass, "name", "Ljava/lang/String;");
    jfieldID balanceField = env->GetFieldID(userDataClass, "balance", "F");

    env->SetObjectField(newUserData, nameField, name);
    env->SetFloatField(newUserData, balanceField, balance);

    return newUserData;
}

JNIEXPORT jstring JNICALL
Java_com_example_usersdataapplication_UsersDB_printUserData(
        JNIEnv *env,
        jobject thiz,
        jobject user) {

    // Find the id of the Java method to be called
    jclass userDataClass = env->GetObjectClass(user);

    jfieldID nameField = env->GetFieldID(userDataClass, "name", "Ljava/lang/String;");
    jfieldID balanceField = env->GetFieldID(userDataClass, "balance", "F");

    auto nameString = (jstring) (*env).GetObjectField(user, nameField);
    auto balance = (*env).GetFloatField(user, balanceField);

    std::string nameResult = jstring2string(env, nameString);
    std::string balanceResult = jfloat2string(env, balance);

    std::string result = "Hello: " + nameResult + getBalanceMessage() + balanceResult;
    return env->NewStringUTF(result.c_str());
}
JNIEXPORT void JNICALL
Java_com_example_usersdataapplication_UsersDB_addBalance(
        JNIEnv *env,
        jobject thiz,
        jfloat value_to_be_added,
        jobject user) {

    // Find the id of the Java method to be called
    jclass userDataClass = env->GetObjectClass(user);

    jfieldID balanceField = env->GetFieldID(userDataClass, "balance", "F");

    auto balance = (*env).GetFloatField(user, balanceField);
    balance += value_to_be_added;
    LOGI("NEW BALANCE: %f", balance);
    env->SetFloatField(user, balanceField, balance);
}

JNIEXPORT void JNICALL
Java_com_example_usersdataapplication_UsersDB_removeBalance(
        JNIEnv *env,
        jobject thiz,
        jfloat value_to_be_subtracted,
        jobject user) {
    // Find the id of the Java method to be called
    jclass userDataClass = env->GetObjectClass(user);

    jfieldID balanceField = env->GetFieldID(userDataClass, "balance", "F");

    auto balance = (*env).GetFloatField(user, balanceField);
    balance -= value_to_be_subtracted;
    LOGI("NEW BALANCE: %f", balance);
    env->SetFloatField(user, balanceField, balance);
}
}



