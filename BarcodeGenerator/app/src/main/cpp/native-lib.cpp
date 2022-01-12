#include "utilities/utilities.h"

extern "C" {
    JNIEXPORT void JNICALL
    Java_com_example_barcodegenerator_MainActivity_code39 (
            JNIEnv * env,
            jobject  obj /* this */,
            jstring dataToEncode,
            jobject bitmapBarcode) {

        AndroidBitmapInfo infoBarcode;
        void *pixelsBarcode;
        int ret;

        LOGI("code39");
        const char * stringData = env->GetStringUTFChars(dataToEncode, nullptr) ;

        LOGI("data to print [%s]", stringData);
        if ((ret = AndroidBitmap_getInfo(env, bitmapBarcode, &infoBarcode)) < 0) {
            LOGE("AndroidBitmap_getInfo() failed ! error=%d", ret);
            return;
        }

        if ((ret = AndroidBitmap_lockPixels(env, bitmapBarcode, &pixelsBarcode)) < 0) {
            LOGE("AndroidBitmap_lockPixels() failed ! error=%d", ret);
        }

        createBarcode(infoBarcode, pixelsBarcode, stringData);
        AndroidBitmap_unlockPixels(env, bitmapBarcode);

    }

    JNIEXPORT jstring JNICALL
    Java_com_example_barcodegenerator_MainActivity_stringFromJNI(
            JNIEnv *env,
            jobject /* this */) {
        std::string hello = HELLO;
        return env->NewStringUTF(hello.c_str());
    }
}

void createBarcode(AndroidBitmapInfo infoBarcode, void *pixelsBarcode, const char *stringData) {
    auto *imagedata = (uint8_t *) pixelsBarcode;

    int y;
    int x;
    const int NARROW = 1;
    const int WIDE = 3;

    int left = 20; // start here
    const char *p = stringData; // walk the string via a pointer
    //int k=0;
    while (*p != 0)
    {
        const char * pattern = getSequence(*p);
        if (pattern != nullptr) {
            int thisWidth =  0;

            for (int k=0;k<4;k+=1) {
                LOGI("k is [%d]",k);
                // bar
                if (pattern[k*2] == 0) thisWidth = NARROW;
                if (pattern[k*2] == '1') thisWidth = WIDE;
                LOGI("thisWidth is [%d]\t[%d]", thisWidth, left);
                for (y=10; y <= infoBarcode.height - 10 - 1; y++) {
                    for (x=left;x<(left + thisWidth); x++) {
                        *(imagedata + x + (y * infoBarcode.width)) = 255;
                    }
                }
                left+=thisWidth;
                // space
                if (pattern[k*2+1] == '0') thisWidth = NARROW;
                if (pattern[k*2+1] == '1') thisWidth = WIDE;
                left += thisWidth;
                LOGI("thisWidth is [%d]\t[%d]", thisWidth, left);
            }
            // final bar
            if (pattern[8] == '0') thisWidth = NARROW;
            if (pattern[8] == '1') thisWidth = WIDE;
            LOGI("thisWidth is [%d]\t[%d]", thisWidth, left);
            for (y=10; y <= infoBarcode.height - 10 - 1; y++) {
                for (x=left;x<(left + thisWidth); x++) {
                    *(imagedata + x + (y * infoBarcode.width)) = 255;
                }
            }
            // inter character gap
            left += WIDE * 2;
        }
        p++;
    }
}
