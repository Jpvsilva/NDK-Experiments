//
// Created by Zé Pedro on 22/12/2021.
//
#include "fileManager.h"

extern "C" {

namespace FileManager {
    void get_date(int* date){
        // http://en.cppreference.com/w/cpp/chrono/c/time
        const std::time_t now = std::time(nullptr); // get the current time point

        // convert it to (local) calendar time
        // http://en.cppreference.com/w/cpp/chrono/c/localtime
        const std::tm calendar_time = *std::localtime(std::addressof(now));

        // print out some relevant fields http://en.cppreference.com/w/cpp/chrono/c/tm
        date[0] = calendar_time.tm_year + 1900;
        date[1] = calendar_time.tm_mon + 1; //jan=0
        date[2] = calendar_time.tm_mday;
        date[3] = calendar_time.tm_hour; //(24-hr clock)"
        date[4] = calendar_time.tm_min;
        date[5] = calendar_time.tm_sec;
    }

    const char *jstring2string(JNIEnv *env, jstring stringJava) {
        jboolean isCopy;
        const char *convertedValue = (env)->GetStringUTFChars(stringJava, &isCopy);
        LOGI("convertedValue: %s", convertedValue);
        return convertedValue;
    }

    void saveToFile(JNIEnv *env, const char *path, jstring content) {
        FILE *file = fopen(path, "a+");
        if (file) {
            fputs(FileManager::jstring2string(env, content), file);
            fclose(file);
            LOGI("Written successfully");
        } else {
            LOGE("File non existent");
        }
    }

    char *readFile(const char *path) {
        FILE *file = fopen(path, "rb");
        if (file) {
            fseek(file, 0, SEEK_END);
            long fsize = ftell(file);
            fseek(file, 0, SEEK_SET);

            char *string = (char *) malloc(fsize + 1);
            fread(string, fsize, 1, file);
            fclose(file);
            string[fsize] = 0;
            LOGI("Read successfully");
            return string;
        } else {
            LOGE("File non existent");
            return "Boas";
        }
    }

    char *load_file(const char *path) {
        FILE *fp;
        long lSize;
        char *buffer;

        fp = fopen(path, "rb");
        if (!fp) {
            perror(path);
            exit(1);
        }

        fseek(fp, 0L, SEEK_END);
        lSize = ftell(fp);
        rewind(fp);

        /* allocate memory for entire content */
        buffer = static_cast<char *>(calloc(1, lSize + 1));
        if (!buffer) {
            fclose(fp);
            fputs("memory alloc fails", stderr);
            exit(1);
        }

        /* copy the file into the buffer */
        if (1 != fread(buffer, lSize, 1, fp)) {
            fclose(fp);
            free(buffer);
            fputs("entire read fails", stderr);
            exit(1);
        }

        /* do your work here, buffer is a string contains the whole text */
        char *result = (char *) malloc(strlen(buffer) * sizeof(char));
        strcpy(result, buffer);

        fclose(fp);
        free(buffer);
        return result;
    }

    char *concat(const char *str1, const char *str2) {
        char *result = (char *) malloc((strlen(str1) + strlen(str2)) * sizeof(char));
        strcpy(result, str1);
        strcat(result, str2);
        return result;
    }
}

JNIEXPORT jstring JNICALL
Java_com_example_usersdataapplication_UsersActivity_saveUserToFile(
        JNIEnv *env,
        jobject thiz,
        jstring dir,
        jstring user) {

    std::string complete = std::string(FileManager::jstring2string(env, dir)) + "/userTest.txt";

    LOGI("CompletePath: %s", complete.c_str());
    FileManager::saveToFile(env, complete.c_str(), user);

    return (*env).NewStringUTF("Hello from JNI (with file io)!");
}

const char *get_build_version(JNIEnv *env, jobject thiz) {
    jclass localClass = env->FindClass("com/example/usersdataapplication/UsersActivity");
    jmethodID versionFunc = (*env).GetMethodID(localClass,
                                               "getBuildVersion", "()Ljava/lang/String;");
    if (!versionFunc) {
        LOGE("Failed to retrieve getBuildVersion() methodID @ line %d",
             __LINE__);
    } else {
        auto buildVersion = reinterpret_cast<jstring>((*env).CallObjectMethod(thiz, versionFunc));
        const char *version = (*env).GetStringUTFChars(buildVersion, nullptr);
        if (!version) {
            LOGE("Unable to get version string @ line %d", __LINE__);
        } else {
            LOGI("Version: %s", version);
            char *versionResult = FileManager::concat("Android:", version);
            return versionResult;
        }
    }
    return nullptr;
}

const char *get_model(JNIEnv *env, jobject thiz) {
    jclass localClass = env->FindClass("com/example/usersdataapplication/UsersActivity");
    jmethodID getModelName = (*env).GetMethodID(localClass,
                                                "getModel", "()Ljava/lang/String;");
    if (!getModelName) {
        LOGE("Failed to retrieve getModel() methodID @ line %d",
             __LINE__);
    } else {
        auto buildModelName = reinterpret_cast<jstring>((*env).CallObjectMethod(thiz,
                                                                                getModelName));
        const char *result = (*env).GetStringUTFChars(buildModelName, nullptr);
        if (!result) {
            LOGE("Unable to get result string @ line %d", __LINE__);
        } else {
            LOGI("Device: %s", result);
            char *versionResult = FileManager::concat("Device:", result);
            return versionResult;
        }
    }
    return nullptr;
}

JNIEXPORT jstring JNICALL
Java_com_example_usersdataapplication_UsersActivity_getCompiledAPI(JNIEnv *env, jobject thiz) {
#if defined(__arm__)
#if defined(__ARM_ARCH_7A__)
#if defined(__ARM_NEON__)
#if defined(__ARM_PCS_VFP)
#define ABI "armeabi-v7a/NEON (hard-float)"
#else
#define ABI "armeabi-v7a/NEON"
#endif
#else
#if defined(__ARM_PCS_VFP)
#define ABI "armeabi-v7a (hard-float)"
#else
#define ABI "armeabi-v7a"
#endif
#endif
#else
#define ABI "armeabi"
#endif
#elif defined(__i386__)
#define ABI "x86"
#elif defined(__x86_64__)
#define ABI "x86_64"
#elif defined(__mips64)  /* mips64el-* toolchain defines __mips__ too */
#define ABI "mips64"
#elif defined(__mips__)
#define ABI "mips"
#elif defined(__aarch64__)
#define ABI "arm64-v8a"
#else
#define ABI "unknown"
#endif

    int date[6] = {0,0,0,0,0,0};
    FileManager::get_date(date);
    std::string today = std::to_string(date[2]) + "/" +
                        std::to_string(date[1]) + "/" +
                        std::to_string(date[0]) + "; " +
                        std::to_string(date[3]) + ":" +
                        std::to_string(date[4]) + ":" +
                        std::to_string(date[5]) + "\n";
    const char *buildVersion = get_build_version(env, thiz);
    if (buildVersion) {
        char *compiled = "Compiled with ABI " ABI ".\n";
        char *pre_result = FileManager::concat(compiled, buildVersion);
        char *result = FileManager::concat(pre_result, "\n");
        const char *deviceModelName = get_model(env, thiz);
        if (deviceModelName) {
            char *deviceModel = FileManager::concat(result, deviceModelName);
            char *result2 = FileManager::concat(deviceModel, "\n");
            char *result_date = FileManager::concat(result2,today.c_str());
            return (*env).NewStringUTF(result_date);
        }

        char *result_date = FileManager::concat(result,today.c_str());
        return (*env).NewStringUTF(result_date);
    }
    return (*env).NewStringUTF("Compiled with ABI " ABI ".\n");
}

JNIEXPORT jstring JNICALL
Java_com_example_usersdataapplication_FileActivity_readFileText(
        JNIEnv *env,
        jobject thiz,
        jstring path) {

    std::string complete = std::string(FileManager::jstring2string(env, path)) + "/userTest.txt";
    const char *fileContent = FileManager::readFile(complete.c_str());
    if (fileContent) {
        return env->NewStringUTF(fileContent);
    } else {
        return path;
    }
}
}