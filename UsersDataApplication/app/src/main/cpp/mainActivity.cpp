#include "mainActivity.h"
#include "utilities/utilities.h"
#include <jni.h>

void getOS(){
    if (getenv("ANDROID_PROPERTY_WORKSPACE")) {
        // running under Android 7 or older
        LOGI("Working on Android 7 or older");
    } else if (access("/dev/socket/property_service", F_OK) == 0) {
        // running under Android 8 or newer
        LOGI("Working on Android 8 or newer");
    } else {
        // running on desktop
        LOGI("Other OS");
    }
    int android_api_level = android_get_device_api_level();
    LOGI("Android Version %d", android_api_level);
}

const char *get_welcome() {
    int date[6] = {0,0,0,0,0,0};
    Utilities::get_date(date);
    const char *ordinalIndicator = Utilities::getOrdinalIndicator(date[2]);
    (std::string(ordinalIndicator));
    std::string of = " of ";

    const char *monthS = Utilities::getMonth(date[1]);
    (std::string(monthS));

    std::string today =
            std::to_string(date[2]) + ordinalIndicator + of + monthS + of + std::to_string(date[0]);

    const char *greeting = Utilities::getGreetings(date[3]);
    (std::string(greeting));

    std::string result = today + "\n" + greeting;
    const char *welcomeMessage = result.data();
    LOGI("WelcomeMessage: %s, Last Accessed: %d:%d:%d", welcomeMessage, date[3], date[4], date[5]);
    return welcomeMessage;
}

class MyNativeException : public std::exception
{
public:
    explicit MyNativeException(const char *msg) : message(msg) {}
    ~MyNativeException() noexcept override = default;
    const char *what() const noexcept override { return message.c_str(); }
protected:
    const std::string message;
};

extern "C" {
JNIEXPORT jstring JNICALL
Java_com_example_usersdataapplication_MainActivity_getWelcomeGreeting(
        JNIEnv *env,
        jobject thiz
) {
    getOS();

    LOGI("JNI Version: %d", env->GetVersion());
    std::string greeting = get_welcome();
    return env->NewStringUTF(greeting.c_str());
}

JNIEXPORT void JNICALL
Java_com_example_usersdataapplication_MainActivity_getNDKCrash(JNIEnv *env, jobject thiz) {
    //jclass jcls = env->FindClass("java/lang/IllegalArgumentException");
    //env->ThrowNew(jcls, "Argument cannot be null.");
    //try
    //{
        throw MyNativeException("abc123");
    //}
    //catch (std::exception& e)
    //{
    //    LOGE("MyNativeException");
    //}
}
}