package com.example.flatbuffersparser2

import java.nio.ByteBuffer

class NativeLib {

    /**
     * A native method that is implemented by the 'flatbuffersparser2' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    external fun parseJsonNative(json: String, schema: String) : ByteArray

    fun parseJson(json: String?, schema: String?): ByteBuffer? {
        val bytes = parseJsonNative(json!!, schema!!)
        return ByteBuffer.wrap(bytes)
    }

    companion object {
        // Used to load the 'flatbuffersparser2' library on application startup.
        init {
            System.loadLibrary("flatbuffersparser2")
        }
    }
}