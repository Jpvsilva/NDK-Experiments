package com.example.mysecondndkapplication

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.TextView
import com.example.mysecondndkapplication.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    private val TAG = MainActivity::class.java.simpleName

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        val exampleArray = intArrayOf(5,10,20)
        val stringResult = "DivideByZero: ${divideFloat(5f, 0f)}\n" +
                "NormalDivision: ${divideFloat(5f, 2f)}\n" +
                "ArraySummation: ${summation(exampleArray)}\n" +
                "ArrayMultiplication: ${arrayMultiplication(exampleArray)}\n" +
                "Concat: ${concat("Bom","Natal")}"

        // Example of a call to a native method
        binding.sampleText.text = stringResult
        Log.d(TAG, addFloat(5f, 6f).toString())

    }

    /**
     * A native method that is implemented by the 'mysecondndkapplication' native library,
     * which is packaged with this application.
     */
    private external fun stringFromJNI(): String

    private external fun addFloat(x: Float, y: Float): Float
    private external fun addInt(x: Int, y: Int): Int
    private external fun addDouble(x: Double, y: Double): Double

    private external fun subtractInt(x: Int, y: Int): Int

    private external fun multiplyInt(x: Int, y: Int): Int

    private external fun divideFloat(x: Float, y: Float): String

    private external fun summation(intArray: IntArray): Int
    private external fun arrayMultiplication(intArray: IntArray): Int

    private external fun concat(a:String,b:String): String

    companion object {
        // Used to load the 'mysecondndkapplication' library on application startup.
        init {
            System.loadLibrary("mysecondndkapplication")
        }
    }
}